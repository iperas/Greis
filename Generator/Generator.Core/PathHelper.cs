using System;
using System.IO;
using System.Reflection;

namespace Comindware.Localization.Lib.Utils
{
    /// <summary>Provides some useful implements missing in the FCL.</summary>
    public static class PathHelper
    {
        /// <summary>
        /// Gets the path for the executable file that started the application, including the executable
        /// name.
        /// </summary>
        /// <value>The path for the executable file that started the application.</value>
        public static string ExecutablePath
        {
            get
            {
                return GetExecutablePath();
            }
        }

        /// <summary>
        /// Gets the path for the executable file that started the application, not including the
        /// executable name.
        /// </summary>
        /// <value>
        /// The path for the executable file that started the application.
        /// </value>
        public static string StartupPath
        {
            get
            {
                return Path.GetDirectoryName(GetExecutablePath());
            }
        }

        private static string GetExecutablePath()
        {
            var location = Assembly.GetExecutingAssembly().Location;
            if (!string.IsNullOrEmpty(location))
            {
                return location;
            }
            var uriCodeBase = new Uri(Assembly.GetExecutingAssembly().CodeBase);
            location = uriCodeBase.AbsolutePath + uriCodeBase.Fragment;
            return location;
        }
    }
}
