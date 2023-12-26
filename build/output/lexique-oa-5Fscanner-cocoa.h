//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#import "OC_Lexique.h"

//--------------------------------------------------------------------------------------------------
//
//                    E X T E R N    R O U T I N E S
//
//--------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------
//
//                    E X T E R N    F U N C T I O N S
//
//--------------------------------------------------------------------------------------------------


//--------------------------------------------------------------------------------------------------
//
//         T E R M I N A L    S Y M B O L    E N U M E R A T I O N
//
//--------------------------------------------------------------------------------------------------

enum {oa_scanner_1_,
  oa_scanner_1_identifier,
  oa_scanner_1_literal_5F_integer,
  oa_scanner_1_system,
  oa_scanner_1_end,
  oa_scanner_1_task,
  oa_scanner_1_standard,
  oa_scanner_1_extended,
  oa_scanner_1_message,
  oa_scanner_1_length,
  oa_scanner_1_priority,
  oa_scanner_1_period,
  oa_scanner_1_offset,
  oa_scanner_1_on,
  oa_scanner_1_deadline,
  oa_scanner_1_duration,
  oa_scanner_1_processor,
  oa_scanner_1_can,
  oa_scanner_1_van,
  oa_scanner_1_network,
  oa_scanner_1_scalingfactor,
  oa_scanner_1_every,
  oa_scanner_1__2C_,
  oa_scanner_1__3B_,
  oa_scanner_1__2E__2E_
} ;

//--------------------------------------------------------------------------------------------------
//
//                     S C A N N E R    C L A S S
//
//--------------------------------------------------------------------------------------------------

@interface OC_Lexique_oa_scanner : OC_Lexique {
//--- Attributes
  @protected NSMutableString * mLexicalAttribute_identifierString ;
  @protected UInt32 mLexicalAttribute_ulongValue ;

}

- (NSUInteger) terminalVocabularyCount ;

- (NSUInteger) styleIndexForTerminal: (NSInteger) inTerminal ;

- (BOOL) internalParseLexicalTokenForLexicalColoring ;

- (void) parseLexicalTokenForLexicalColoring ;

- (NSUInteger) styleCount ;

- (NSString *) styleNameForStyleIndex: (NSInteger) inIndex ;

- (NSString *) styleIdentifierForStyleIndex: (NSInteger) inIndex ;

- (NSArray *) indexingTitles ; // Array of NSString

- (BOOL) isTemplateLexique ;

- (BOOL) atomicSelectionForToken: (NSUInteger) inTokenIndex ;

@end

//--------------------------------------------------------------------------------------------------
//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

