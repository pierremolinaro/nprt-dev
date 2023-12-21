//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#import "lexique-oa-5F-scanner-cocoa.h"
#import "PMDebug.h"

//--------------------------------------------------------------------------------------------------

@implementation OC_Lexique_oa_scanner

//--------------------------------------------------------------------------------------------------
//
//                           Template Replacements
//
//--------------------------------------------------------------------------------------------------



//--------------------------------------------------------------------------------------------------
//
//                           Template Delimiters
//
//--------------------------------------------------------------------------------------------------


//--------------------------------------------------------------------------------------------------

- (instancetype) init {
  self = [super init] ;
  if (self) {
    noteObjectAllocation (self) ;
    mLexicalAttribute_identifierString = [[NSMutableString alloc] init] ;
    mLexicalAttribute_ulongValue = 0 ;
  }
  return self ;
}

//--------------------------------------------------------------------------------------------------

- (void) dealloc {
  noteObjectDeallocation (self) ;
}

//--------------------------------------------------------------------------------------------------
//
//                 I N D E X I N G    T I T L E S
//
//--------------------------------------------------------------------------------------------------

- (NSArray *) indexingTitles { // Array of NSString

  return [NSArray array] ;
}

//--------------------------------------------------------------------------------------------------
//
//            Terminal Symbols as end of script in template mark
//
//--------------------------------------------------------------------------------------------------



//--------------------------------------------------------------------------------------------------
//
//             Key words table 'keyWordList'      
//
//--------------------------------------------------------------------------------------------------

static const C_cocoa_lexique_table_entry ktable_for_oa_5F_scanner_keyWordList [19] = {
  {"on", oa_scanner_1_on},
  {"can", oa_scanner_1_can},
  {"end", oa_scanner_1_end},
  {"van", oa_scanner_1_van},
  {"task", oa_scanner_1_task},
  {"every", oa_scanner_1_every},
  {"length", oa_scanner_1_length},
  {"offset", oa_scanner_1_offset},
  {"period", oa_scanner_1_period},
  {"system", oa_scanner_1_system},
  {"message", oa_scanner_1_message},
  {"network", oa_scanner_1_network},
  {"deadline", oa_scanner_1_deadline},
  {"duration", oa_scanner_1_duration},
  {"extended", oa_scanner_1_extended},
  {"priority", oa_scanner_1_priority},
  {"standard", oa_scanner_1_standard},
  {"processor", oa_scanner_1_processor},
  {"scalingfactor", oa_scanner_1_scalingfactor}
} ;

static NSInteger search_into_oa_5F_scanner_keyWordList (NSString * inSearchedString) {
  return searchStringInTable (inSearchedString, ktable_for_oa_5F_scanner_keyWordList, 19) ;
}


//--------------------------------------------------------------------------------------------------
//
//               I N T E R N A L    P A R S E    L E X I C A L    T O K E N
//
//--------------------------------------------------------------------------------------------------

- (BOOL) internalParseLexicalTokenForLexicalColoring {
  BOOL scanningOk = YES ;
  [mLexicalAttribute_identifierString setString:@""] ;
  mLexicalAttribute_ulongValue = 0 ;
  mTokenStartLocation = mCurrentLocation ;
  if (scanningOk && ([self testForInputFromChar:97 toChar:122] || [self testForInputFromChar:65 toChar:90])) {
    BOOL loop1124 = YES ;
    do {
      scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_identifierString, mPreviousChar) ;
      if (scanningOk && ([self testForInputFromChar:97 toChar:122] || [self testForInputFromChar:65 toChar:90] || [self testForInputChar:95] || [self testForInputFromChar:48 toChar:57])) {
      }else{
        loop1124 = NO ;
      }
    }while (loop1124 && scanningOk) ;
    if (mTokenCode == 0) {
      mTokenCode = search_into_oa_5F_scanner_keyWordList (mLexicalAttribute_identifierString) ;
    }
    if (mTokenCode == 0) {
      mTokenCode = oa_scanner_1_identifier ;
    }
  }else if (scanningOk && [self testForInputString:@".." advance:YES]) {
    mTokenCode = oa_scanner_1__2E__2E_ ;
  }else if (scanningOk && [self testForInputString:@";" advance:YES]) {
    mTokenCode = oa_scanner_1__3B_ ;
  }else if (scanningOk && [self testForInputString:@"," advance:YES]) {
    mTokenCode = oa_scanner_1__2C_ ;
  }else if (scanningOk && ([self testForInputFromChar:48 toChar:57])) {
    scanner_cocoa_routine_enterDigitIntoUInt (& scanningOk, mPreviousChar, & mLexicalAttribute_ulongValue) ;
    BOOL loop1815 = YES ;
    do {
      if (scanningOk && ([self testForInputFromChar:48 toChar:57])) {
        scanner_cocoa_routine_enterDigitIntoUInt (& scanningOk, mPreviousChar, & mLexicalAttribute_ulongValue) ;
      }else if (scanningOk && ([self testForInputChar:95])) {
      }else{
        loop1815 = NO ;
      }
    }while (loop1815 && scanningOk) ;
    mTokenCode = oa_scanner_1_literal_5F_integer ;
  }else if (scanningOk && ([self testForInputFromChar:1 toChar:32])) {
  }else if (scanningOk && ([self testForInputChar:35])) {
    BOOL loop2168 = YES ;
    do {
      if (scanningOk && ([self testForInputFromChar:1 toChar:9] || [self testForInputFromChar:11 toChar:126])) {
      }else{
        loop2168 = NO ;
      }
    }while (loop2168 && scanningOk) ;
    if (scanningOk && ([self testForInputChar:10])) {
    }else{
      scanningOk = NO ;
    }
  }else   if ([self testForInputChar:'\0']) { // End of source text ?
    mTokenCode = oa_scanner_1_ ; // Empty string code
  }else{ // Unknown input character
    scanningOk = NO ;
    [self advance] ;
  }
  return scanningOk ;
}

//--------------------------------------------------------------------------------------------------
//
//               P A R S E    L E X I C A L    T O K E N
//
//--------------------------------------------------------------------------------------------------

- (void) parseLexicalTokenForLexicalColoring {
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

//--------------------------------------------------------------------------------------------------
//
//                   T E R M I N A L    C O U N T
//
//--------------------------------------------------------------------------------------------------

- (NSUInteger) terminalVocabularyCount {
  return 24 ;
}

//--------------------------------------------------------------------------------------------------
//
//                     S T Y L E   C O U N T
//
//--------------------------------------------------------------------------------------------------

- (NSUInteger) styleCount {
  return 5 ;
}

//--------------------------------------------------------------------------------------------------
//
//                I S    T E M P L A T E    L E X I Q U E
//
//--------------------------------------------------------------------------------------------------

- (BOOL) isTemplateLexique {
  return NO ;
}

//--------------------------------------------------------------------------------------------------
//
//   S T Y L E   I N D E X    F O R    T E R M I N A L
//
//--------------------------------------------------------------------------------------------------

- (NSUInteger) styleIndexForTerminal: (NSInteger) inTerminal {
  static const NSUInteger kTerminalSymbolStyles [25] = {0,
    1 /* oa_scanner_1_identifier */,
    4 /* oa_scanner_1_literal_5F_integer */,
    2 /* oa_scanner_1_system */,
    2 /* oa_scanner_1_end */,
    2 /* oa_scanner_1_task */,
    2 /* oa_scanner_1_standard */,
    2 /* oa_scanner_1_extended */,
    2 /* oa_scanner_1_message */,
    2 /* oa_scanner_1_length */,
    2 /* oa_scanner_1_priority */,
    2 /* oa_scanner_1_period */,
    2 /* oa_scanner_1_offset */,
    2 /* oa_scanner_1_on */,
    2 /* oa_scanner_1_deadline */,
    2 /* oa_scanner_1_duration */,
    2 /* oa_scanner_1_processor */,
    2 /* oa_scanner_1_can */,
    2 /* oa_scanner_1_van */,
    2 /* oa_scanner_1_network */,
    2 /* oa_scanner_1_scalingfactor */,
    2 /* oa_scanner_1_every */,
    3 /* oa_scanner_1__2C_ */,
    3 /* oa_scanner_1__3B_ */,
    3 /* oa_scanner_1__2E__2E_ */
  } ;
  return kTerminalSymbolStyles [inTerminal] ;
}

//--------------------------------------------------------------------------------------------------
//
//    A T O M I C    S E L E C T I O N   F O R    T E R M I N A L
//
//--------------------------------------------------------------------------------------------------

- (BOOL) atomicSelectionForToken: (NSUInteger) inTokenIndex {
  static const BOOL kTerminalAtomicSelection [25] = {NO,
    YES /* oa_scanner_1_identifier */,
    YES /* oa_scanner_1_literal_5F_integer */,
    YES /* oa_scanner_1_system */,
    YES /* oa_scanner_1_end */,
    YES /* oa_scanner_1_task */,
    YES /* oa_scanner_1_standard */,
    YES /* oa_scanner_1_extended */,
    YES /* oa_scanner_1_message */,
    YES /* oa_scanner_1_length */,
    YES /* oa_scanner_1_priority */,
    YES /* oa_scanner_1_period */,
    YES /* oa_scanner_1_offset */,
    YES /* oa_scanner_1_on */,
    YES /* oa_scanner_1_deadline */,
    YES /* oa_scanner_1_duration */,
    YES /* oa_scanner_1_processor */,
    YES /* oa_scanner_1_can */,
    YES /* oa_scanner_1_van */,
    YES /* oa_scanner_1_network */,
    YES /* oa_scanner_1_scalingfactor */,
    YES /* oa_scanner_1_every */,
    YES /* oa_scanner_1__2C_ */,
    YES /* oa_scanner_1__3B_ */,
    YES /* oa_scanner_1__2E__2E_ */
  } ;
  return kTerminalAtomicSelection [inTokenIndex] ;
}

//--------------------------------------------------------------------------------------------------
//
//             S T Y L E   N A M E    F O R    I N D E X
//
//--------------------------------------------------------------------------------------------------

- (NSString *) styleNameForStyleIndex: (NSInteger) inIndex {
  NSString * result = nil ;
  if ((inIndex >= 0) && (inIndex < 5)) {
    NSString * kStyleArray [5] = {
      @"Default Style",
      @"Identifiers",
      @"Key words",
      @"Delimitors",
      @"Integer constants"
    } ;
    result = kStyleArray [inIndex] ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//
//         S T Y L E   I D E N T I F I E R    F O R    I N D E X
//
//--------------------------------------------------------------------------------------------------

- (NSString *) styleIdentifierForStyleIndex: (NSInteger) inIndex {
  NSString * result = nil ;
  if ((inIndex >= 0) && (inIndex < 5)) {
    NSString * kStyleArray [5] = {
      @"oa_scanner",
      @"oa_scanner-identifier",
      @"oa_scanner-keyWords",
      @"oa_scanner-delimitors",
      @"oa_scanner-integerStyle"
    } ;
    result = kStyleArray [inIndex] ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//
//         L E X I Q U E   I D E N T I F I E R
//
//--------------------------------------------------------------------------------------------------

- (NSString *) lexiqueIdentifier {
  return @"oa_scanner" ;
}

//--------------------------------------------------------------------------------------------------

@end

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2


