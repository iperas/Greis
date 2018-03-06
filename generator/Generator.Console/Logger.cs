// ***********************************************************************
// <author>Stepan Burguchev</author>
// <copyright company="Comindware">
//   Copyright (c) Comindware 2010-2014. All rights reserved.
// </copyright>
// <summary>
//   Logger.cs
// </summary>
// ***********************************************************************

using NLog;

namespace Generator.Console
{
    public class Logger
    {
        public static readonly NLog.Logger Instance = LogManager.GetLogger("");
    }
}