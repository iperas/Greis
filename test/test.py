import subprocess
import json
result = subprocess.run(['build/bin/testBed', 'test/ifz-data-0.jps'], stdout=subprocess.PIPE)
epochs = json.loads(result.stdout.decode("utf-8"))
if len(epochs)==90:
    print("Test 1: pass")
