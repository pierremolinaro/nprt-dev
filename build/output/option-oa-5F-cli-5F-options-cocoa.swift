//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

//----------------------------------------------------------------------------------------------------------------------

func enterOptions (_ ioBoolOptionArray : inout [SWIFT_CommandLineOption],
                   _ ioUIntOptionArray : inout [SWIFT_CommandLineOption],
                   _ ioStringOptionArray : inout [SWIFT_CommandLineOption],
                   _ ioStringListOptionArray : inout [SWIFT_CommandLineOption]) {
  ioBoolOptionArray.append (SWIFT_CommandLineOption (
    domainName: "oa_cli_options",
    identifier: "createIntermediateFiles",
    commandChar: "C",
    commandString: "create-intermediate-files",
    comment: "Create the intermediate files",
    defaultValue: ""
  ))
  ioBoolOptionArray.append (SWIFT_CommandLineOption (
    domainName: "oa_cli_options",
    identifier: "useCANmaxLegth",
    commandChar: "M",
    commandString: "use-can-max-length",
    comment: "Use only CAN messages max length",
    defaultValue: ""
  ))
  ioBoolOptionArray.append (SWIFT_CommandLineOption (
    domainName: "galgas_cli_options",
    identifier: "quiet_output",
    commandChar: "q",
    commandString: "quiet",
    comment: "Quiet output",
    defaultValue: ""
  ))
}

//----------------------------------------------------------------------------------------------------------------------

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2


