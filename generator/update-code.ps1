param ($root)

"Root directory is: " + $root

$ErrorActionPreference = "Stop"

$msbuild = "C:\Windows\Microsoft.NET\Framework64\v4.0.30319\msbuild.exe"
$mstest = "C:\Program Files (x86)\Microsoft Visual Studio 12.0\Common7\IDE\mstest.exe"

$solutionFile = $root + 'Generator.sln'
$testContainer = '/testcontainer:' + $root + 'Generator.Tests\bin\Release\Generator.Tests.dll'

$buildDir = $root + 'build'
$outputMetaDir = $root + 'Output'
$outputDir = (get-item ($root + '..\')).FullName

$greisSource = $root + 'Data\greis-manual.txt'
$metaXmlDir = $buildDir
$metaXmlFile = $metaXmlDir + '\meta-info.xml'
$cppCodeDir = $buildDir + '\cppCode'
$sqlBaselineDir = $buildDir

mkdir $buildDir -force | Out-Null
mkdir $outputDir -force | Out-Null
mkdir $outputMetaDir -force | Out-Null

function build() {
    'building and testing...'

    &$msbuild $solutionFile /Target:Rebuild /p:Configuration=Release
    if ($LASTEXITCODE -ne 0) {
        throw "MSBuild failed"
    }
    &$mstest $testContainer
    if ($LASTEXITCODE -ne 0) {
        #throw "Tests failed"
    }
}

function generate() {
    'generating code...'

    rm $buildDir -force -recurse

    $generator = $root + 'Generator.Console\bin\Release\Generator.Console.exe'

    &$generator --command gen-xml --source $greisSource --target $metaXmlDir
    &$generator --command gen-cpp --source $metaXmlFile --target $cppCodeDir
    &$generator --command gen-sql --source $metaXmlFile --target $sqlBaselineDir
}

function updateFiles() {
    "updating local files in $outputDir..."

    cp $metaXmlFile $outputMetaDir -Force
    cp ($sqlBaselineDir + '\baseline.sql') $outputMetaDir -Force

    $includeDir = $outputDir + '\Greis'
    $srcDir = $outputDir + '\src'

    rmdir ($includeDir + '\StdMessage') -force -recurse
    rmdir ($includeDir + '\CustomType') -force -recurse
    rmdir ($srcDir + '\StdMessage') -force -recurse
    rmdir ($srcDir + '\CustomType') -force -recurse

    mkdir ($includeDir + '\StdMessage') -force | Out-Null
    mkdir ($includeDir + '\CustomType') -force | Out-Null
    mkdir ($srcDir + '\StdMessage') -force | Out-Null
    mkdir ($srcDir + '\CustomType') -force | Out-Null

    ls $cppCodeDir -Filter *.h | cp -Destination $includeDir -Force
    ls ($cppCodeDir + '\StdMessage') -Filter *.h | cp -Destination ($includeDir + '\StdMessage') -Force
    ls ($cppCodeDir + '\CustomType') -Filter *.h | cp -Destination ($includeDir + '\CustomType') -Force
    ls $cppCodeDir -Filter *.cpp | cp -Destination $srcDir -Force
    ls ($cppCodeDir + '\StdMessage') -Filter *.cpp | cp -Destination ($srcDir + '\StdMessage') -Force
    ls ($cppCodeDir + '\CustomType') -Filter *.cpp | cp -Destination ($srcDir + '\CustomType') -Force

    'Done.'
}

build
generate
updateFiles
