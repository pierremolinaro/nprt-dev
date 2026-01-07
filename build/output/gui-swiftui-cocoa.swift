//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

import SwiftUI

//--------------------------------------------------------------------------------------------------
//    Project file extensions
//--------------------------------------------------------------------------------------------------

func indexingDescriptorDictionary () -> [String : String] {
 return [:]
}

//--------------------------------------------------------------------------------------------------
//   Global functions
//--------------------------------------------------------------------------------------------------

@MainActor func scannerFor (extension inExtension : String) -> SWIFT_Scanner? {
  var result : SWIFT_Scanner? = nil
  if inExtension == "nprt" {
    result = ScannerFor_oa_scanner ()
  }
  return result
}

//--------------------------------------------------------------------------------------------------

/* @MainActor func tokenizers () -> [any SWIFT_Tokenizer_Protocol] {
  return [
    SettingViewFor_oa_scanner ()
  ]
} */

//--------------------------------------------------------------------------------------------------

struct SettingsView : View {
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  @ViewBuilder var body : some View {
    TabView {
      SettingViewFor_oa_scanner ().tabItem { Text ("Source") }
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

}


//--------------------------------------------------------------------------------------------------

/* func buildRunOption () -> String {
  return ""
} */

//--------------------------------------------------------------------------------------------------

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2


