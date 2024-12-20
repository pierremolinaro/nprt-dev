//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

//--------------------------------------------------------------------------------------------------

func enterOptions () -> [SWIFT_CommandLineOption] {
  var array = [SWIFT_CommandLineOption] ()
  array.append (SWIFT_CommandLineOption (
    domainName: "oa_cli_options",
    type: .bool,
    identifier: "createIntermediateFiles",
    commandChar: "C",
    commandString: "create-intermediate-files",
    comment: "Create the intermediate files"
  ))
  array.append (SWIFT_CommandLineOption (
    domainName: "oa_cli_options",
    type: .bool,
    identifier: "useCANmaxLegth",
    commandChar: "M",
    commandString: "use-can-max-length",
    comment: "Use only CAN messages max length"
  ))
  array.append (SWIFT_CommandLineOption (
    domainName: "galgas_cli_options",
    type: .bool,
    identifier: "quiet_output",
    commandChar: "q",
    commandString: "quiet",
    comment: "Quiet output"
  ))
  return array
}

//--------------------------------------------------------------------------------------------------

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2


