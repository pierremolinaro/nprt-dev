//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

import AppKit
import MyAutoLayoutKit

//--------------------------------------------------------------------------------------------------
//   LEXIQUE oa_scanner
//--------------------------------------------------------------------------------------------------

@MainActor fileprivate let gFont_oa_scanner = EBPreferenceProperty <NSFont> (
  defaultValue: NSFont.monospacedSystemFont (ofSize: 13.0, weight: .regular),
  prefKey: "FontFor_" + oa_scanner_lexiqueIdentifier ()
)

//--------------------------------------------------------------------------------------------------

@MainActor fileprivate let gLineHeight_oa_scanner = EBPreferenceProperty <Int> (
  defaultValue: 12,
  prefKey: "LineHeightFor_" + oa_scanner_lexiqueIdentifier ()
)

//--------------------------------------------------------------------------------------------------

@MainActor fileprivate let gColors_oa_scanner : [EBPreferenceProperty <NSColor>] = [
  EBPreferenceProperty <NSColor> (defaultValue: .black, prefKey: "ColorFor_oa_scanner"),
  EBPreferenceProperty <NSColor> (defaultValue: .black, prefKey: "ColorFor_oa_scanner-identifier"),
  EBPreferenceProperty <NSColor> (defaultValue: .black, prefKey: "ColorFor_oa_scanner-keyWords"),
  EBPreferenceProperty <NSColor> (defaultValue: .black, prefKey: "ColorFor_oa_scanner-delimitors"),
  EBPreferenceProperty <NSColor> (defaultValue: .black, prefKey: "ColorFor_oa_scanner-integerStyle"),
  EBPreferenceProperty <NSColor> (defaultValue: .red, prefKey: "ColorFor_oa_scanner_lexical_error"),
  EBPreferenceProperty <NSColor> (defaultValue: .gray, prefKey: "ColorFor_oa_scanner_template")
]

//--------------------------------------------------------------------------------------------------

@MainActor fileprivate let gBoldStyle_oa_scanner : [EBPreferenceProperty <Bool>] = [
  EBPreferenceProperty <Bool> (defaultValue: false, prefKey: "BoldFor_oa_scanner"),
  EBPreferenceProperty <Bool> (defaultValue: false, prefKey: "BoldFor_oa_scanner-identifier"),
  EBPreferenceProperty <Bool> (defaultValue: false, prefKey: "BoldFor_oa_scanner-keyWords"),
  EBPreferenceProperty <Bool> (defaultValue: false, prefKey: "BoldFor_oa_scanner-delimitors"),
  EBPreferenceProperty <Bool> (defaultValue: false, prefKey: "BoldFor_oa_scanner-integerStyle"),
  EBPreferenceProperty <Bool> (defaultValue: true, prefKey: "BoldFor_oa_scanner_lexical_error"),
  EBPreferenceProperty <Bool> (defaultValue: false, prefKey: "BoldFor_oa_scanner_template")
]

//--------------------------------------------------------------------------------------------------

@MainActor fileprivate let gItalicStyle_oa_scanner : [EBPreferenceProperty <Bool>] = [
  EBPreferenceProperty <Bool> (defaultValue: false, prefKey: "ItalicFor_oa_scanner"),
  EBPreferenceProperty <Bool> (defaultValue: false, prefKey: "ItalicFor_oa_scanner-identifier"),
  EBPreferenceProperty <Bool> (defaultValue: false, prefKey: "ItalicFor_oa_scanner-keyWords"),
  EBPreferenceProperty <Bool> (defaultValue: false, prefKey: "ItalicFor_oa_scanner-delimitors"),
  EBPreferenceProperty <Bool> (defaultValue: false, prefKey: "ItalicFor_oa_scanner-integerStyle"),
  EBPreferenceProperty <Bool> (defaultValue: false, prefKey: "ItalicFor_oa_scanner_lexical_error"),
  EBPreferenceProperty <Bool> (defaultValue: false, prefKey: "ItalicFor_oa_scanner_template")
]

//--------------------------------------------------------------------------------------------------
//                           Template Replacements
//--------------------------------------------------------------------------------------------------



//--------------------------------------------------------------------------------------------------
//                           Template Delimiters
//--------------------------------------------------------------------------------------------------



//--------------------------------------------------------------------------------------------------
//         T E R M I N A L    S Y M B O L    E N U M E R A T I O N
//--------------------------------------------------------------------------------------------------

let oa_scanner_1_ : UInt16 = 0
let oa_scanner_1_identifier : UInt16 = 1
let oa_scanner_1_literal_5F_integer : UInt16 = 2
let oa_scanner_1_system : UInt16 = 3
let oa_scanner_1_end : UInt16 = 4
let oa_scanner_1_task : UInt16 = 5
let oa_scanner_1_standard : UInt16 = 6
let oa_scanner_1_extended : UInt16 = 7
let oa_scanner_1_message : UInt16 = 8
let oa_scanner_1_length : UInt16 = 9
let oa_scanner_1_priority : UInt16 = 10
let oa_scanner_1_period : UInt16 = 11
let oa_scanner_1_offset : UInt16 = 12
let oa_scanner_1_on : UInt16 = 13
let oa_scanner_1_deadline : UInt16 = 14
let oa_scanner_1_duration : UInt16 = 15
let oa_scanner_1_processor : UInt16 = 16
let oa_scanner_1_can : UInt16 = 17
let oa_scanner_1_van : UInt16 = 18
let oa_scanner_1_network : UInt16 = 19
let oa_scanner_1_scalingfactor : UInt16 = 20
let oa_scanner_1_every : UInt16 = 21
let oa_scanner_1__2C_ : UInt16 = 22
let oa_scanner_1__3B_ : UInt16 = 23
let oa_scanner_1__2E__2E_ : UInt16 = 24
let oa_scanner_2_ERROR : UInt16 = 25
let oa_scanner_2_TEMPLATE : UInt16 = 26

//--------------------------------------------------------------------------------------------------

func oa_scanner_lexiqueIdentifier () -> String {
  return "oa_scanner"
}

//--------------------------------------------------------------------------------------------------

func oa_scanner_styleNameFor (styleIndex inIndex : UInt8) -> String {
  let kStyleArray : [String] = [
    "Default Style", // 0
    "Identifiers", // 1
    "Key words", // 2
    "Delimitors", // 3
    "Integer constants", // 4
    "Lexical error", // 5
    "Template" // 6
  ]
  return kStyleArray [Int (inIndex)]
}

//--------------------------------------------------------------------------------------------------

func oa_scanner_styleIdentifierFor (styleIndex inIndex : UInt8) -> String {
  let kStyleArray : [String] = [
    "oa_scanner", // 0
    "oa_scanner-identifier", // 1
    "oa_scanner-keyWords", // 2
    "oa_scanner-delimitors", // 3
    "oa_scanner-integerStyle", // 4
    "oa_scanner.ERROR", // 5
    "oa_scanner.TEMPLATE" // 6
  ]
  return kStyleArray [Int (inIndex)]
}

//--------------------------------------------------------------------------------------------------
//                     S C A N N E R    C L A S S
//--------------------------------------------------------------------------------------------------

class SWIFT_Lexique_oa_scanner : SWIFT_Lexique {

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  private var mLexicalAttribute_identifierString : String = ""
  private var mLexicalAttribute_ulongValue : UInt32 = 0

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func lexiqueIdentifier () -> String {
    return oa_scanner_lexiqueIdentifier ()
  }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func isTemplateLexique () -> Bool {
    return false
  }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func terminalVocabularyCount () -> Int {
    return 24
  }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  var font : EBPreferenceProperty <NSFont> { return gFont_oa_scanner }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  var lineHeight : EBPreferenceProperty <Int> { return gLineHeight_oa_scanner }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func color (forStyle inStyleIndex : UInt8) -> EBPreferenceProperty <NSColor> {
    return gColors_oa_scanner [Int (inStyleIndex)]
  }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func bold (forStyle inStyleIndex : UInt8) -> EBPreferenceProperty <Bool> {
    return gBoldStyle_oa_scanner [Int (inStyleIndex)]
  }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func italic (forStyle inStyleIndex : UInt8) -> EBPreferenceProperty <Bool> {
    return gItalicStyle_oa_scanner [Int (inStyleIndex)]
  }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func styleIndexFor (token inTokenIndex : UInt16) -> UInt8 {
    let kTerminalSymbolStyles : [UInt8] = [
      0, // Default
      1, // 1 : oa_scanner_1_identifier
      4, // 2 : oa_scanner_1_literal_5F_integer
      2, // 3 : oa_scanner_1_system
      2, // 4 : oa_scanner_1_end
      2, // 5 : oa_scanner_1_task
      2, // 6 : oa_scanner_1_standard
      2, // 7 : oa_scanner_1_extended
      2, // 8 : oa_scanner_1_message
      2, // 9 : oa_scanner_1_length
      2, // 10 : oa_scanner_1_priority
      2, // 11 : oa_scanner_1_period
      2, // 12 : oa_scanner_1_offset
      2, // 13 : oa_scanner_1_on
      2, // 14 : oa_scanner_1_deadline
      2, // 15 : oa_scanner_1_duration
      2, // 16 : oa_scanner_1_processor
      2, // 17 : oa_scanner_1_can
      2, // 18 : oa_scanner_1_van
      2, // 19 : oa_scanner_1_network
      2, // 20 : oa_scanner_1_scalingfactor
      2, // 21 : oa_scanner_1_every
      3, // 22 : oa_scanner_1__2C_
      3, // 23 : oa_scanner_1__3B_
      3, // 24 : oa_scanner_1__2E__2E_
      5, // 25 : oa_scanner_2_ERROR
      6  // 26 : oa_scanner_2_TEMPLATE
    ]
    return kTerminalSymbolStyles [Int (inTokenIndex)]
  }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func atomicSelectionFor (token inTokenIndex : UInt16) -> Bool {
    let kTerminalAtomicSelection : [Bool] = [
      false, // Default
      true, // 1 : oa_scanner_1_identifier
      true, // 2 : oa_scanner_1_literal_5F_integer
      true, // 3 : oa_scanner_1_system
      true, // 4 : oa_scanner_1_end
      true, // 5 : oa_scanner_1_task
      true, // 6 : oa_scanner_1_standard
      true, // 7 : oa_scanner_1_extended
      true, // 8 : oa_scanner_1_message
      true, // 9 : oa_scanner_1_length
      true, // 10 : oa_scanner_1_priority
      true, // 11 : oa_scanner_1_period
      true, // 12 : oa_scanner_1_offset
      true, // 13 : oa_scanner_1_on
      true, // 14 : oa_scanner_1_deadline
      true, // 15 : oa_scanner_1_duration
      true, // 16 : oa_scanner_1_processor
      true, // 17 : oa_scanner_1_can
      true, // 18 : oa_scanner_1_van
      true, // 19 : oa_scanner_1_network
      true, // 20 : oa_scanner_1_scalingfactor
      true, // 21 : oa_scanner_1_every
      true, // 22 : oa_scanner_1__2C_
      true, // 23 : oa_scanner_1__3B_
      true, // 24 : oa_scanner_1__2E__2E_
      false, // 25 : oa_scanner_2_ERROR
      false  // 26 : oa_scanner_2_TEMPLATE
    ]
    return kTerminalAtomicSelection [Int (inTokenIndex)]
  }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func indexingTitles () -> [String] {

    return []
  }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  //  S T Y L E S
  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func styleCount () -> UInt8 {
    return 4
  }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func styleNameFor (styleIndex inIndex : UInt8) -> String {
    return oa_scanner_styleNameFor (styleIndex: inIndex)
  }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func styleIdentifierFor (styleIndex inIndex : UInt8) -> String {
    return oa_scanner_styleIdentifierFor (styleIndex: inIndex)
  }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  //   Lexical analysis
  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func parseLexicalTokenForLexicalColoring () -> SWIFT_Token {
    var loop = true
    var scanningOk = true
    self.mLexicalAttribute_identifierString = ""
    self.mLexicalAttribute_ulongValue = 0
    var tokenCode : UInt16 = 0
    let startLocation = self.currentLocation
    if scanningOk && (self.testForInputFromChar (97, toChar:122) || self.testForInputFromChar (65, toChar:90)) {
      while (loop && scanningOk) {
        scanner_cocoa_routine_enterCharacterIntoString (&scanningOk, &self.mLexicalAttribute_identifierString, self.previousChar)
        if scanningOk && (self.testForInputFromChar (97, toChar:122) || self.testForInputFromChar (65, toChar:90) || self.testForInputChar (95) || self.testForInputFromChar (48, toChar:57)) {
        }else{
          loop = false
        }
      }
      loop = true
      if (tokenCode == 0) {
        tokenCode = search_into_oa_5F_scanner_keyWordList (mLexicalAttribute_identifierString) ;
      }
      if tokenCode == 0 {
        tokenCode = oa_scanner_1_identifier ;
      }
    }else if scanningOk && self.testForInputString ("..", advance: true) {
      tokenCode = oa_scanner_1__2E__2E_
    }else if scanningOk && self.testForInputString (";", advance: true) {
      tokenCode = oa_scanner_1__3B_
    }else if scanningOk && self.testForInputString (",", advance: true) {
      tokenCode = oa_scanner_1__2C_
    }else if scanningOk && (self.testForInputFromChar (48, toChar:57)) {
      scanner_cocoa_routine_enterDigitIntoUInt (&scanningOk, self.previousChar, &self.mLexicalAttribute_ulongValue)
      while (loop && scanningOk) {
        if scanningOk && (self.testForInputFromChar (48, toChar:57)) {
          scanner_cocoa_routine_enterDigitIntoUInt (&scanningOk, self.previousChar, &self.mLexicalAttribute_ulongValue)
        }else if scanningOk && (self.testForInputChar (95)) {
        }else{
          loop = false
        }
      }
      loop = true
      tokenCode = oa_scanner_1_literal_5F_integer
    }else if scanningOk && (self.testForInputFromChar (1, toChar:32)) {
    }else if scanningOk && (self.testForInputChar (35)) {
      while (loop && scanningOk) {
        if scanningOk && (self.testForInputFromChar (1, toChar:9) || self.testForInputFromChar (11, toChar:126)) {
        }else{
          loop = false
        }
      }
      loop = true
      if scanningOk && (self.testForInputChar (10)) {
      }else{
        scanningOk = false
      }
    }else if self.testForInputChar (0) { // End of source text ?
      tokenCode = oa_scanner_1_ ; // Empty string code
    }else{ // Unknown input character
      tokenCode = oa_scanner_2_TEMPLATE
      self.advance ()
    }
    return SWIFT_Token (
      range: NSRange (location: startLocation, length: self.currentLocation - startLocation),
      tokenCode: tokenCode,
      templateDelimiterIndex: self.mEndTemplateDelimiterIndex
    )
  }
  
  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

}


//--------------------------------------------------------------------------------------------------

/* - (instancetype) init {
  self = [super init] ;
  if (self) {
    noteObjectAllocation (self) ;
    mLexicalAttribute_identifierString = [[NSMutableString alloc] init] ;
    mLexicalAttribute_ulongValue = 0 ;
  }
  return self ;
} */

//--------------------------------------------------------------------------------------------------
//
//            Terminal Symbols as end of script in template mark
//
//--------------------------------------------------------------------------------------------------

/*

*/


//--------------------------------------------------------------------------------------------------
//
//             Key words table 'keyWordList'      
//
//--------------------------------------------------------------------------------------------------

fileprivate func search_into_oa_5F_scanner_keyWordList (_ inSearchedString : String) -> UInt16 {
  let dictionary : [String : UInt16] = [
    "on" : oa_scanner_1_on,
    "can" : oa_scanner_1_can,
    "end" : oa_scanner_1_end,
    "van" : oa_scanner_1_van,
    "task" : oa_scanner_1_task,
    "every" : oa_scanner_1_every,
    "length" : oa_scanner_1_length,
    "offset" : oa_scanner_1_offset,
    "period" : oa_scanner_1_period,
    "system" : oa_scanner_1_system,
    "message" : oa_scanner_1_message,
    "network" : oa_scanner_1_network,
    "deadline" : oa_scanner_1_deadline,
    "duration" : oa_scanner_1_duration,
    "extended" : oa_scanner_1_extended,
    "priority" : oa_scanner_1_priority,
    "standard" : oa_scanner_1_standard,
    "processor" : oa_scanner_1_processor,
    "scalingfactor" : oa_scanner_1_scalingfactor
  ]
  return dictionary [inSearchedString, default: oa_scanner_1_]
}





//--------------------------------------------------------------------------------------------------
//
//               P A R S E    L E X I C A L    T O K E N
//
//--------------------------------------------------------------------------------------------------

/* - (void) parseLexicalTokenForLexicalColoring {
  BOOL scanningOk = YES ;
  mTokenCode = 0 ;
  while ((mTokenCode == 0) && (mCurrentChar != '\0')) {
    scanningOk = [self internalParseLexicalTokenForLexicalColoring] ;
  }
//--- Error ?
  if (! scanningOk) {
    mTokenCode = -1 ;
  }
}

*/

//--------------------------------------------------------------------------------------------------

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2


