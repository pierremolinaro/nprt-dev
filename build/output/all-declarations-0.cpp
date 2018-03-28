#include "galgas2/C_Compiler.h"
#include "galgas2/C_galgas_io.h"
#include "galgas2/C_galgas_CLI_Options.h"
#include "utilities/C_PrologueEpilogue.h"

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#include "all-declarations-0.h"

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//     L E X I Q U E                                                                                                   *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#include "strings/unicode_character_cpp.h"
#include "galgas2/scanner_actions.h"
#include "galgas2/cLexiqueIntrospection.h"

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

cTokenFor_oa_5F_scanner::cTokenFor_oa_5F_scanner (void) :
mLexicalAttribute_identifierString (),
mLexicalAttribute_ulongValue () {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_Lexique_oa_5F_scanner::C_Lexique_oa_5F_scanner (C_Compiler * inCallerCompiler,
                                                  const C_String & inSourceFileName
                                                  COMMA_LOCATION_ARGS) :
C_Lexique (inCallerCompiler, inSourceFileName COMMA_THERE) {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_Lexique_oa_5F_scanner::C_Lexique_oa_5F_scanner (C_Compiler * inCallerCompiler,
                                                  const C_String & inSourceString,
                                                  const C_String & inStringForError
                                                  COMMA_LOCATION_ARGS) :
C_Lexique (inCallerCompiler, inSourceString, inStringForError COMMA_THERE) {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                 I N D E X I N G    D I R E C T O R Y                                                                *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_String C_Lexique_oa_5F_scanner::indexingDirectory (void) const {
  return "" ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                        Lexical error message list                                                                   *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static const char * gLexicalMessage_oa_5F_scanner_decimalNumberTooLarge = "decimal number too large" ;

static const char * gLexicalMessage_oa_5F_scanner_incorrectEndOfComment = "incorrect end of comment" ;

static const char * gLexicalMessage_oa_5F_scanner_internalError = "internal error" ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//          Syntax error messages, for every terminal symbol                                                           *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

//--- Syntax error message for terminal '$identifier$' :
static const char * gSyntaxErrorMessage_oa_5F_scanner_identifier = "an identifier" ;

//--- Syntax error message for terminal '$literal_integer$' :
static const char * gSyntaxErrorMessage_oa_5F_scanner_literal_5F_integer = "a decimal number" ;

//--- Syntax error message for terminal '$system$' :
static const char * gSyntaxErrorMessage_oa_5F_scanner_system = "the 'system' key word" ;

//--- Syntax error message for terminal '$end$' :
static const char * gSyntaxErrorMessage_oa_5F_scanner_end = "the 'end' key word" ;

//--- Syntax error message for terminal '$task$' :
static const char * gSyntaxErrorMessage_oa_5F_scanner_task = "the 'task' key word" ;

//--- Syntax error message for terminal '$standard$' :
static const char * gSyntaxErrorMessage_oa_5F_scanner_standard = "the 'standard' key word" ;

//--- Syntax error message for terminal '$extended$' :
static const char * gSyntaxErrorMessage_oa_5F_scanner_extended = "the 'extended' key word" ;

//--- Syntax error message for terminal '$message$' :
static const char * gSyntaxErrorMessage_oa_5F_scanner_message = "the 'message' key word" ;

//--- Syntax error message for terminal '$length$' :
static const char * gSyntaxErrorMessage_oa_5F_scanner_length = "the 'length' key word" ;

//--- Syntax error message for terminal '$priority$' :
static const char * gSyntaxErrorMessage_oa_5F_scanner_priority = "the 'priority' key word" ;

//--- Syntax error message for terminal '$period$' :
static const char * gSyntaxErrorMessage_oa_5F_scanner_period = "the 'period' key word" ;

//--- Syntax error message for terminal '$offset$' :
static const char * gSyntaxErrorMessage_oa_5F_scanner_offset = "the 'offset' key word" ;

//--- Syntax error message for terminal '$on$' :
static const char * gSyntaxErrorMessage_oa_5F_scanner_on = "the 'on' key word" ;

//--- Syntax error message for terminal '$deadline$' :
static const char * gSyntaxErrorMessage_oa_5F_scanner_deadline = "the 'deadline' key word" ;

//--- Syntax error message for terminal '$duration$' :
static const char * gSyntaxErrorMessage_oa_5F_scanner_duration = "the 'duration' key word" ;

//--- Syntax error message for terminal '$processor$' :
static const char * gSyntaxErrorMessage_oa_5F_scanner_processor = "the 'processor' key word" ;

//--- Syntax error message for terminal '$can$' :
static const char * gSyntaxErrorMessage_oa_5F_scanner_can = "the 'can' key word" ;

//--- Syntax error message for terminal '$van$' :
static const char * gSyntaxErrorMessage_oa_5F_scanner_van = "the 'van' key word" ;

//--- Syntax error message for terminal '$network$' :
static const char * gSyntaxErrorMessage_oa_5F_scanner_network = "the 'network' key word" ;

//--- Syntax error message for terminal '$scalingfactor$' :
static const char * gSyntaxErrorMessage_oa_5F_scanner_scalingfactor = "the 'scalingfactor' key word" ;

//--- Syntax error message for terminal '$every$' :
static const char * gSyntaxErrorMessage_oa_5F_scanner_every = "the 'every' key word" ;

//--- Syntax error message for terminal '$,$' :
static const char * gSyntaxErrorMessage_oa_5F_scanner__2C_ = "the '','' delimitor" ;

//--- Syntax error message for terminal '$;$' :
static const char * gSyntaxErrorMessage_oa_5F_scanner__3B_ = "the '';'' delimitor" ;

//--- Syntax error message for terminal '$..$' :
static const char * gSyntaxErrorMessage_oa_5F_scanner__2E__2E_ = "the ''..'' delimitor" ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                getMessageForTerminal                                                                                *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_String C_Lexique_oa_5F_scanner::getMessageForTerminal (const int16_t inTerminalIndex) const {
  C_String result = "<unknown>" ;
  if ((inTerminalIndex >= 0) && (inTerminalIndex < 25)) {
    static const char * syntaxErrorMessageArray [25] = {kEndOfSourceLexicalErrorMessage,
        gSyntaxErrorMessage_oa_5F_scanner_identifier,
        gSyntaxErrorMessage_oa_5F_scanner_literal_5F_integer,
        gSyntaxErrorMessage_oa_5F_scanner_system,
        gSyntaxErrorMessage_oa_5F_scanner_end,
        gSyntaxErrorMessage_oa_5F_scanner_task,
        gSyntaxErrorMessage_oa_5F_scanner_standard,
        gSyntaxErrorMessage_oa_5F_scanner_extended,
        gSyntaxErrorMessage_oa_5F_scanner_message,
        gSyntaxErrorMessage_oa_5F_scanner_length,
        gSyntaxErrorMessage_oa_5F_scanner_priority,
        gSyntaxErrorMessage_oa_5F_scanner_period,
        gSyntaxErrorMessage_oa_5F_scanner_offset,
        gSyntaxErrorMessage_oa_5F_scanner_on,
        gSyntaxErrorMessage_oa_5F_scanner_deadline,
        gSyntaxErrorMessage_oa_5F_scanner_duration,
        gSyntaxErrorMessage_oa_5F_scanner_processor,
        gSyntaxErrorMessage_oa_5F_scanner_can,
        gSyntaxErrorMessage_oa_5F_scanner_van,
        gSyntaxErrorMessage_oa_5F_scanner_network,
        gSyntaxErrorMessage_oa_5F_scanner_scalingfactor,
        gSyntaxErrorMessage_oa_5F_scanner_every,
        gSyntaxErrorMessage_oa_5F_scanner__2C_,
        gSyntaxErrorMessage_oa_5F_scanner__3B_,
        gSyntaxErrorMessage_oa_5F_scanner__2E__2E_
    } ;
    result = syntaxErrorMessageArray [inTerminalIndex] ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                      U N I C O D E    S T R I N G S                                                                 *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

//--- Unicode string for '$_2C_$'
static const utf32 kUnicodeString_oa_5F_scanner__2C_ [] = {
  TO_UNICODE (','),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_2E__2E_$'
static const utf32 kUnicodeString_oa_5F_scanner__2E__2E_ [] = {
  TO_UNICODE ('.'),
  TO_UNICODE ('.'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3B_$'
static const utf32 kUnicodeString_oa_5F_scanner__3B_ [] = {
  TO_UNICODE (';'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$can$'
static const utf32 kUnicodeString_oa_5F_scanner_can [] = {
  TO_UNICODE ('c'),
  TO_UNICODE ('a'),
  TO_UNICODE ('n'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$deadline$'
static const utf32 kUnicodeString_oa_5F_scanner_deadline [] = {
  TO_UNICODE ('d'),
  TO_UNICODE ('e'),
  TO_UNICODE ('a'),
  TO_UNICODE ('d'),
  TO_UNICODE ('l'),
  TO_UNICODE ('i'),
  TO_UNICODE ('n'),
  TO_UNICODE ('e'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$duration$'
static const utf32 kUnicodeString_oa_5F_scanner_duration [] = {
  TO_UNICODE ('d'),
  TO_UNICODE ('u'),
  TO_UNICODE ('r'),
  TO_UNICODE ('a'),
  TO_UNICODE ('t'),
  TO_UNICODE ('i'),
  TO_UNICODE ('o'),
  TO_UNICODE ('n'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$end$'
static const utf32 kUnicodeString_oa_5F_scanner_end [] = {
  TO_UNICODE ('e'),
  TO_UNICODE ('n'),
  TO_UNICODE ('d'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$every$'
static const utf32 kUnicodeString_oa_5F_scanner_every [] = {
  TO_UNICODE ('e'),
  TO_UNICODE ('v'),
  TO_UNICODE ('e'),
  TO_UNICODE ('r'),
  TO_UNICODE ('y'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$extended$'
static const utf32 kUnicodeString_oa_5F_scanner_extended [] = {
  TO_UNICODE ('e'),
  TO_UNICODE ('x'),
  TO_UNICODE ('t'),
  TO_UNICODE ('e'),
  TO_UNICODE ('n'),
  TO_UNICODE ('d'),
  TO_UNICODE ('e'),
  TO_UNICODE ('d'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$length$'
static const utf32 kUnicodeString_oa_5F_scanner_length [] = {
  TO_UNICODE ('l'),
  TO_UNICODE ('e'),
  TO_UNICODE ('n'),
  TO_UNICODE ('g'),
  TO_UNICODE ('t'),
  TO_UNICODE ('h'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$message$'
static const utf32 kUnicodeString_oa_5F_scanner_message [] = {
  TO_UNICODE ('m'),
  TO_UNICODE ('e'),
  TO_UNICODE ('s'),
  TO_UNICODE ('s'),
  TO_UNICODE ('a'),
  TO_UNICODE ('g'),
  TO_UNICODE ('e'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$network$'
static const utf32 kUnicodeString_oa_5F_scanner_network [] = {
  TO_UNICODE ('n'),
  TO_UNICODE ('e'),
  TO_UNICODE ('t'),
  TO_UNICODE ('w'),
  TO_UNICODE ('o'),
  TO_UNICODE ('r'),
  TO_UNICODE ('k'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$offset$'
static const utf32 kUnicodeString_oa_5F_scanner_offset [] = {
  TO_UNICODE ('o'),
  TO_UNICODE ('f'),
  TO_UNICODE ('f'),
  TO_UNICODE ('s'),
  TO_UNICODE ('e'),
  TO_UNICODE ('t'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$on$'
static const utf32 kUnicodeString_oa_5F_scanner_on [] = {
  TO_UNICODE ('o'),
  TO_UNICODE ('n'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$period$'
static const utf32 kUnicodeString_oa_5F_scanner_period [] = {
  TO_UNICODE ('p'),
  TO_UNICODE ('e'),
  TO_UNICODE ('r'),
  TO_UNICODE ('i'),
  TO_UNICODE ('o'),
  TO_UNICODE ('d'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$priority$'
static const utf32 kUnicodeString_oa_5F_scanner_priority [] = {
  TO_UNICODE ('p'),
  TO_UNICODE ('r'),
  TO_UNICODE ('i'),
  TO_UNICODE ('o'),
  TO_UNICODE ('r'),
  TO_UNICODE ('i'),
  TO_UNICODE ('t'),
  TO_UNICODE ('y'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$processor$'
static const utf32 kUnicodeString_oa_5F_scanner_processor [] = {
  TO_UNICODE ('p'),
  TO_UNICODE ('r'),
  TO_UNICODE ('o'),
  TO_UNICODE ('c'),
  TO_UNICODE ('e'),
  TO_UNICODE ('s'),
  TO_UNICODE ('s'),
  TO_UNICODE ('o'),
  TO_UNICODE ('r'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$scalingfactor$'
static const utf32 kUnicodeString_oa_5F_scanner_scalingfactor [] = {
  TO_UNICODE ('s'),
  TO_UNICODE ('c'),
  TO_UNICODE ('a'),
  TO_UNICODE ('l'),
  TO_UNICODE ('i'),
  TO_UNICODE ('n'),
  TO_UNICODE ('g'),
  TO_UNICODE ('f'),
  TO_UNICODE ('a'),
  TO_UNICODE ('c'),
  TO_UNICODE ('t'),
  TO_UNICODE ('o'),
  TO_UNICODE ('r'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$standard$'
static const utf32 kUnicodeString_oa_5F_scanner_standard [] = {
  TO_UNICODE ('s'),
  TO_UNICODE ('t'),
  TO_UNICODE ('a'),
  TO_UNICODE ('n'),
  TO_UNICODE ('d'),
  TO_UNICODE ('a'),
  TO_UNICODE ('r'),
  TO_UNICODE ('d'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$system$'
static const utf32 kUnicodeString_oa_5F_scanner_system [] = {
  TO_UNICODE ('s'),
  TO_UNICODE ('y'),
  TO_UNICODE ('s'),
  TO_UNICODE ('t'),
  TO_UNICODE ('e'),
  TO_UNICODE ('m'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$task$'
static const utf32 kUnicodeString_oa_5F_scanner_task [] = {
  TO_UNICODE ('t'),
  TO_UNICODE ('a'),
  TO_UNICODE ('s'),
  TO_UNICODE ('k'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$van$'
static const utf32 kUnicodeString_oa_5F_scanner_van [] = {
  TO_UNICODE ('v'),
  TO_UNICODE ('a'),
  TO_UNICODE ('n'),
  TO_UNICODE (0)
} ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//             Key words table 'delimitorsList'                            *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static const int32_t ktable_size_oa_5F_scanner_delimitorsList = 3 ;

static const C_unicode_lexique_table_entry ktable_for_oa_5F_scanner_delimitorsList [ktable_size_oa_5F_scanner_delimitorsList] = {
  C_unicode_lexique_table_entry (kUnicodeString_oa_5F_scanner__2C_, 1, C_Lexique_oa_5F_scanner::kToken__2C_),
  C_unicode_lexique_table_entry (kUnicodeString_oa_5F_scanner__3B_, 1, C_Lexique_oa_5F_scanner::kToken__3B_),
  C_unicode_lexique_table_entry (kUnicodeString_oa_5F_scanner__2E__2E_, 2, C_Lexique_oa_5F_scanner::kToken__2E__2E_)
} ;

int16_t C_Lexique_oa_5F_scanner::search_into_delimitorsList (const C_String & inSearchedString) {
  return searchInList (inSearchedString, ktable_for_oa_5F_scanner_delimitorsList, ktable_size_oa_5F_scanner_delimitorsList) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//             Key words table 'keyWordList'                            *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static const int32_t ktable_size_oa_5F_scanner_keyWordList = 19 ;

static const C_unicode_lexique_table_entry ktable_for_oa_5F_scanner_keyWordList [ktable_size_oa_5F_scanner_keyWordList] = {
  C_unicode_lexique_table_entry (kUnicodeString_oa_5F_scanner_on, 2, C_Lexique_oa_5F_scanner::kToken_on),
  C_unicode_lexique_table_entry (kUnicodeString_oa_5F_scanner_can, 3, C_Lexique_oa_5F_scanner::kToken_can),
  C_unicode_lexique_table_entry (kUnicodeString_oa_5F_scanner_end, 3, C_Lexique_oa_5F_scanner::kToken_end),
  C_unicode_lexique_table_entry (kUnicodeString_oa_5F_scanner_van, 3, C_Lexique_oa_5F_scanner::kToken_van),
  C_unicode_lexique_table_entry (kUnicodeString_oa_5F_scanner_task, 4, C_Lexique_oa_5F_scanner::kToken_task),
  C_unicode_lexique_table_entry (kUnicodeString_oa_5F_scanner_every, 5, C_Lexique_oa_5F_scanner::kToken_every),
  C_unicode_lexique_table_entry (kUnicodeString_oa_5F_scanner_length, 6, C_Lexique_oa_5F_scanner::kToken_length),
  C_unicode_lexique_table_entry (kUnicodeString_oa_5F_scanner_offset, 6, C_Lexique_oa_5F_scanner::kToken_offset),
  C_unicode_lexique_table_entry (kUnicodeString_oa_5F_scanner_period, 6, C_Lexique_oa_5F_scanner::kToken_period),
  C_unicode_lexique_table_entry (kUnicodeString_oa_5F_scanner_system, 6, C_Lexique_oa_5F_scanner::kToken_system),
  C_unicode_lexique_table_entry (kUnicodeString_oa_5F_scanner_message, 7, C_Lexique_oa_5F_scanner::kToken_message),
  C_unicode_lexique_table_entry (kUnicodeString_oa_5F_scanner_network, 7, C_Lexique_oa_5F_scanner::kToken_network),
  C_unicode_lexique_table_entry (kUnicodeString_oa_5F_scanner_deadline, 8, C_Lexique_oa_5F_scanner::kToken_deadline),
  C_unicode_lexique_table_entry (kUnicodeString_oa_5F_scanner_duration, 8, C_Lexique_oa_5F_scanner::kToken_duration),
  C_unicode_lexique_table_entry (kUnicodeString_oa_5F_scanner_extended, 8, C_Lexique_oa_5F_scanner::kToken_extended),
  C_unicode_lexique_table_entry (kUnicodeString_oa_5F_scanner_priority, 8, C_Lexique_oa_5F_scanner::kToken_priority),
  C_unicode_lexique_table_entry (kUnicodeString_oa_5F_scanner_standard, 8, C_Lexique_oa_5F_scanner::kToken_standard),
  C_unicode_lexique_table_entry (kUnicodeString_oa_5F_scanner_processor, 9, C_Lexique_oa_5F_scanner::kToken_processor),
  C_unicode_lexique_table_entry (kUnicodeString_oa_5F_scanner_scalingfactor, 13, C_Lexique_oa_5F_scanner::kToken_scalingfactor)
} ;

int16_t C_Lexique_oa_5F_scanner::search_into_keyWordList (const C_String & inSearchedString) {
  return searchInList (inSearchedString, ktable_for_oa_5F_scanner_keyWordList, ktable_size_oa_5F_scanner_keyWordList) ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                          getCurrentTokenString                                                                      *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_String C_Lexique_oa_5F_scanner::getCurrentTokenString (const cToken * inTokenPtr) const {
  const cTokenFor_oa_5F_scanner * ptr = (const cTokenFor_oa_5F_scanner *) inTokenPtr ;
  C_String s ;
  if (ptr == NULL) {
    s.appendCString("$$") ;
  }else{
    switch (ptr->mTokenCode) {
    case kToken_:
      s.appendCString("$$") ;
      break ;
    case kToken_identifier:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("identifier") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendUnicodeCharacter (TO_UNICODE (' ') COMMA_HERE) ;
      s.appendCLiteralStringConstant (ptr->mLexicalAttribute_identifierString) ;
      break ;
    case kToken_literal_5F_integer:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("literal_integer") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendUnicodeCharacter (TO_UNICODE (' ') COMMA_HERE) ;
      s.appendUnsigned (ptr->mLexicalAttribute_ulongValue) ;
      break ;
    case kToken_system:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("system") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_end:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("end") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_task:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("task") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_standard:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("standard") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_extended:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("extended") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_message:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("message") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_length:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("length") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_priority:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("priority") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_period:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("period") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_offset:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("offset") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_on:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("on") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_deadline:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("deadline") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_duration:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("duration") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_processor:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("processor") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_can:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("can") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_van:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("van") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_network:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("network") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_scalingfactor:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("scalingfactor") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_every:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("every") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__2C_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString (",") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__3B_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString (";") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__2E__2E_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("..") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    default:
      break ;
    }
  }
  return s ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                           Template Delimiters                                                                       *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                           Template Replacements                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//            Terminal Symbols as end of script in template mark                                                       *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//            Unicode test functions                                                                                   *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
 
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//               P A R S E    L E X I C A L    T O K E N                                                               *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

bool C_Lexique_oa_5F_scanner::parseLexicalToken (void) {
  cTokenFor_oa_5F_scanner token ;
  mLoop = true ;
  token.mTokenCode = -1 ;
  while ((token.mTokenCode < 0) && (UNICODE_VALUE (mCurrentChar) != '\0')) {
    token.mLexicalAttribute_identifierString.setLengthToZero () ;
    token.mLexicalAttribute_ulongValue = 0 ;
    mTokenStartLocation = mCurrentLocation ;
    try{
      if (testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('z')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('Z'))) {
        do {
          ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_identifierString, previousChar ()) ;
          if (testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('z')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('Z')) || testForInputUTF32Char (TO_UNICODE ('_')) || testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9'))) {
          }else{
            mLoop = false ;
          }
        }while (mLoop) ;
        mLoop = true ;
        if (token.mTokenCode == -1) {
          token.mTokenCode = search_into_keyWordList (token.mLexicalAttribute_identifierString) ;
        }
        if (token.mTokenCode == -1) {
          token.mTokenCode = kToken_identifier ;
        }
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString_oa_5F_scanner__2E__2E_, 2, true)) {
        token.mTokenCode = kToken__2E__2E_ ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString_oa_5F_scanner__3B_, 1, true)) {
        token.mTokenCode = kToken__3B_ ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString_oa_5F_scanner__2C_, 1, true)) {
        token.mTokenCode = kToken__2C_ ;
        enterToken (token) ;
      }else if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9'))) {
        ::scanner_routine_enterDigitIntoUInt (*this, previousChar (), token.mLexicalAttribute_ulongValue, gLexicalMessage_oa_5F_scanner_decimalNumberTooLarge, gLexicalMessage_oa_5F_scanner_internalError) ;
        do {
          if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9'))) {
            ::scanner_routine_enterDigitIntoUInt (*this, previousChar (), token.mLexicalAttribute_ulongValue, gLexicalMessage_oa_5F_scanner_decimalNumberTooLarge, gLexicalMessage_oa_5F_scanner_internalError) ;
          }else if (testForInputUTF32Char (TO_UNICODE ('_'))) {
          }else{
            mLoop = false ;
          }
        }while (mLoop) ;
        mLoop = true ;
        token.mTokenCode = kToken_literal_5F_integer ;
        enterToken (token) ;
      }else if (testForInputUTF32CharRange (TO_UNICODE (1), TO_UNICODE (' '))) {
      }else if (testForInputUTF32Char (TO_UNICODE ('#'))) {
        do {
          if (testForInputUTF32CharRange (TO_UNICODE (1), TO_UNICODE ('\t')) || testForInputUTF32CharRange (TO_UNICODE ('\v'), TO_UNICODE ('~'))) {
          }else{
            mLoop = false ;
          }
        }while (mLoop) ;
        mLoop = true ;
        if (testForInputUTF32Char (TO_UNICODE ('\n'))) {
        }else{
          lexicalError (gLexicalMessage_oa_5F_scanner_incorrectEndOfComment COMMA_LINE_AND_SOURCE_FILE) ;
        }
      }else if (testForInputUTF32Char (TO_UNICODE ('\0'))) { // End of source text ? 
        token.mTokenCode = kToken_ ; // Empty string code
      }else{ // Unknown input character
        unknownCharacterLexicalError (LINE_AND_SOURCE_FILE) ;
        token.mTokenCode = -1 ; // No token
        advance () ; // ... go throught unknown character
      }
    }catch (const C_lexicalErrorException &) {
      token.mTokenCode = -1 ; // No token
      advance () ; // ... go throught unknown character
    }
  }
  if (UNICODE_VALUE (mCurrentChar) == '\0') {
    token.mTokenCode = 0 ;
    enterToken (token) ;
  }
  return token.mTokenCode > 0 ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                         E N T E R    T O K E N                                                                      *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void C_Lexique_oa_5F_scanner::enterToken (cTokenFor_oa_5F_scanner & ioToken) {
  cTokenFor_oa_5F_scanner * ptr = NULL ;
  macroMyNew (ptr, cTokenFor_oa_5F_scanner ()) ;
  ptr->mTokenCode = ioToken.mTokenCode ;
  // ptr->mIsOptional = ioToken.mIsOptional ;
  ptr->mStartLocation = mTokenStartLocation ;
  ptr->mEndLocation = mTokenEndLocation ;
  ptr->mTemplateStringBeforeToken = ioToken.mTemplateStringBeforeToken ;
  ioToken.mTemplateStringBeforeToken = "" ;
  ptr->mLexicalAttribute_identifierString = ioToken.mLexicalAttribute_identifierString ;
  ptr->mLexicalAttribute_ulongValue = ioToken.mLexicalAttribute_ulongValue ;
  enterTokenFromPointer (ptr) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//               A T T R I B U T E   A C C E S S                                                                       *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_String C_Lexique_oa_5F_scanner::attributeValue_identifierString (void) const {
  cTokenFor_oa_5F_scanner * ptr = (cTokenFor_oa_5F_scanner *) currentTokenPtr (HERE) ;
  return ptr->mLexicalAttribute_identifierString ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

uint32_t C_Lexique_oa_5F_scanner::attributeValue_ulongValue (void) const {
  cTokenFor_oa_5F_scanner * ptr = (cTokenFor_oa_5F_scanner *) currentTokenPtr (HERE) ;
  return ptr->mLexicalAttribute_ulongValue ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//         A S S I G N    F R O M    A T T R I B U T E                                                                 *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_lstring C_Lexique_oa_5F_scanner::synthetizedAttribute_identifierString (void) const {
  cTokenFor_oa_5F_scanner * ptr = (cTokenFor_oa_5F_scanner *) currentTokenPtr (HERE) ;
  macroValidSharedObject (ptr, cTokenFor_oa_5F_scanner) ;
  GALGAS_location currentLocation (ptr->mStartLocation, ptr->mEndLocation, sourceText ()) ;
  GALGAS_string value (ptr->mLexicalAttribute_identifierString) ;
  GALGAS_lstring result (value, currentLocation) ;
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_luint C_Lexique_oa_5F_scanner::synthetizedAttribute_ulongValue (void) const {
  cTokenFor_oa_5F_scanner * ptr = (cTokenFor_oa_5F_scanner *) currentTokenPtr (HERE) ;
  macroValidSharedObject (ptr, cTokenFor_oa_5F_scanner) ;
  GALGAS_location currentLocation (ptr->mStartLocation, ptr->mEndLocation, sourceText ()) ;
  GALGAS_uint value (ptr->mLexicalAttribute_ulongValue) ;
  GALGAS_luint result (value, currentLocation) ;
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                         I N T R O S P E C T I O N                                                                   *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_stringlist C_Lexique_oa_5F_scanner::symbols (LOCATION_ARGS) {
  GALGAS_stringlist result = GALGAS_stringlist::constructor_emptyList (THERE) ;
  result.addAssign_operation (GALGAS_string ("identifier") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("literal_integer") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("system") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("end") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("task") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("standard") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("extended") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("message") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("length") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("priority") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("period") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("offset") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("on") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("deadline") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("duration") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("processor") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("can") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("van") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("network") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("scalingfactor") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("every") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string (",") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string (";") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("..") COMMA_THERE) ;
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void getKeywordLists_oa_5F_scanner (TC_UniqueArray <C_String> & ioList) {
  ioList.appendObject ("oa_scanner:delimitorsList") ;
  ioList.appendObject ("oa_scanner:keyWordList") ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void getKeywordsForIdentifier_oa_5F_scanner (const C_String & inIdentifier,
                                                    bool & ioFound,
                                                    TC_UniqueArray <C_String> & ioList) {
  if (inIdentifier == "oa_scanner:delimitorsList") {
    ioFound = true ;
    ioList.appendObject (",") ;
    ioList.appendObject (";") ;
    ioList.appendObject ("..") ;
    ioList.sortArrayUsingCompareMethod() ;
  }
  if (inIdentifier == "oa_scanner:keyWordList") {
    ioFound = true ;
    ioList.appendObject ("on") ;
    ioList.appendObject ("can") ;
    ioList.appendObject ("end") ;
    ioList.appendObject ("van") ;
    ioList.appendObject ("task") ;
    ioList.appendObject ("every") ;
    ioList.appendObject ("length") ;
    ioList.appendObject ("offset") ;
    ioList.appendObject ("period") ;
    ioList.appendObject ("system") ;
    ioList.appendObject ("message") ;
    ioList.appendObject ("network") ;
    ioList.appendObject ("deadline") ;
    ioList.appendObject ("duration") ;
    ioList.appendObject ("extended") ;
    ioList.appendObject ("priority") ;
    ioList.appendObject ("standard") ;
    ioList.appendObject ("processor") ;
    ioList.appendObject ("scalingfactor") ;
    ioList.sortArrayUsingCompareMethod() ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static cLexiqueIntrospection lexiqueIntrospection_oa_5F_scanner
__attribute__ ((used))
__attribute__ ((unused)) (getKeywordLists_oa_5F_scanner, getKeywordsForIdentifier_oa_5F_scanner) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//   S T Y L E   I N D E X    F O R    T E R M I N A L                                                                 *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

uint32_t C_Lexique_oa_5F_scanner::styleIndexForTerminal (const int32_t inTerminalIndex) const {
  static const uint32_t kTerminalSymbolStyles [25] = {0,
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
  return (inTerminalIndex >= 0) ? kTerminalSymbolStyles [inTerminalIndex] : 0 ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//   S T Y L E   N A M E    F O R    S T Y L E    I N D E X                                                            *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_String C_Lexique_oa_5F_scanner::styleNameForIndex (const uint32_t inStyleIndex) const {
  C_String result ;
  if (inStyleIndex < 5) {
    static const char * kStyleArray [5] = {
      "",
      "identifier",
      "keyWords",
      "delimitors",
      "integerStyle"
    } ;
    result = kStyleArray [inStyleIndex] ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

cMapElement_M_5F_processor::cMapElement_M_5F_processor (const GALGAS_lstring & inKey,
                                                        const GALGAS_uint & in_mIndex,
                                                        const GALGAS_luint & in_mStep
                                                        COMMA_LOCATION_ARGS) :
cMapElement (inKey COMMA_THERE),
mProperty_mIndex (in_mIndex),
mProperty_mStep (in_mStep) {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

bool cMapElement_M_5F_processor::isValid (void) const {
  return mProperty_lkey.isValid () && mProperty_mIndex.isValid () && mProperty_mStep.isValid () ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

cMapElement * cMapElement_M_5F_processor::copy (void) {
  cMapElement * result = NULL ;
  macroMyNew (result, cMapElement_M_5F_processor (mProperty_lkey, mProperty_mIndex, mProperty_mStep COMMA_HERE)) ;
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void cMapElement_M_5F_processor::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mIndex" ":" ;
  mProperty_mIndex.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mStep" ":" ;
  mProperty_mStep.description (ioString, inIndentation) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

typeComparisonResult cMapElement_M_5F_processor::compare (const cCollectionElement * inOperand) const {
  cMapElement_M_5F_processor * operand = (cMapElement_M_5F_processor *) inOperand ;
  typeComparisonResult result = mProperty_lkey.objectCompare (operand->mProperty_lkey) ;
  if (kOperandEqual == result) {
    result = mProperty_mIndex.objectCompare (operand->mProperty_mIndex) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_mStep.objectCompare (operand->mProperty_mStep) ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_M_5F_processor::GALGAS_M_5F_processor (void) :
AC_GALGAS_map () {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_M_5F_processor::GALGAS_M_5F_processor (const GALGAS_M_5F_processor & inSource) :
AC_GALGAS_map (inSource) {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_M_5F_processor & GALGAS_M_5F_processor::operator = (const GALGAS_M_5F_processor & inSource) {
  * ((AC_GALGAS_map *) this) = inSource ;
  return * this ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_M_5F_processor GALGAS_M_5F_processor::constructor_emptyMap (LOCATION_ARGS) {
  GALGAS_M_5F_processor result ;
  result.makeNewEmptyMap (THERE) ;
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_M_5F_processor GALGAS_M_5F_processor::constructor_mapWithMapToOverride (const GALGAS_M_5F_processor & inMapToOverride
                                                                               COMMA_LOCATION_ARGS) {
  GALGAS_M_5F_processor result ;
  result.makeNewEmptyMapWithMapToOverride (inMapToOverride COMMA_THERE) ;
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_M_5F_processor GALGAS_M_5F_processor::getter_overriddenMap (C_Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) const {
  GALGAS_M_5F_processor result ;
  getOverridenMap (result, inCompiler COMMA_THERE) ;
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void GALGAS_M_5F_processor::addAssign_operation (const GALGAS_lstring & inKey,
                                                 const GALGAS_uint & inArgument0,
                                                 const GALGAS_luint & inArgument1,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) {
  cMapElement_M_5F_processor * p = NULL ;
  macroMyNew (p, cMapElement_M_5F_processor (inKey, inArgument0, inArgument1 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "@M_5F_processor insert error: '%K' already in map" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void GALGAS_M_5F_processor::setter_insertKey (GALGAS_lstring inKey,
                                              GALGAS_uint inArgument0,
                                              GALGAS_luint inArgument1,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  cMapElement_M_5F_processor * p = NULL ;
  macroMyNew (p, cMapElement_M_5F_processor (inKey, inArgument0, inArgument1 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "the processor '%K' has been already declared in %L" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

const char * kSearchErrorMessage_M_5F_processor_searchKey = "the processor '%K' is not declared" ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void GALGAS_M_5F_processor::method_searchKey (GALGAS_lstring inKey,
                                              GALGAS_uint & outArgument0,
                                              GALGAS_luint & outArgument1,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const {
  const cMapElement_M_5F_processor * p = (const cMapElement_M_5F_processor *) performSearch (inKey,
                                                                                             inCompiler,
                                                                                             kSearchErrorMessage_M_5F_processor_searchKey
                                                                                             COMMA_THERE) ;
  if (NULL == p) {
    outArgument0.drop () ;
    outArgument1.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_M_5F_processor) ;
    outArgument0 = p->mProperty_mIndex ;
    outArgument1 = p->mProperty_mStep ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_uint GALGAS_M_5F_processor::getter_mIndexForKey (const GALGAS_string & inKey,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_M_5F_processor * p = (const cMapElement_M_5F_processor *) attributes ;
  GALGAS_uint result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_M_5F_processor) ;
    result = p->mProperty_mIndex ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_luint GALGAS_M_5F_processor::getter_mStepForKey (const GALGAS_string & inKey,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_M_5F_processor * p = (const cMapElement_M_5F_processor *) attributes ;
  GALGAS_luint result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_M_5F_processor) ;
    result = p->mProperty_mStep ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void GALGAS_M_5F_processor::setter_setMIndexForKey (GALGAS_uint inAttributeValue,
                                                    GALGAS_string inKey,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, true, inCompiler COMMA_THERE) ;
  cMapElement_M_5F_processor * p = (cMapElement_M_5F_processor *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_M_5F_processor) ;
    p->mProperty_mIndex = inAttributeValue ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void GALGAS_M_5F_processor::setter_setMStepForKey (GALGAS_luint inAttributeValue,
                                                   GALGAS_string inKey,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, true, inCompiler COMMA_THERE) ;
  cMapElement_M_5F_processor * p = (cMapElement_M_5F_processor *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_M_5F_processor) ;
    p->mProperty_mStep = inAttributeValue ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

cMapElement_M_5F_processor * GALGAS_M_5F_processor::readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                       const GALGAS_string & inKey
                                                                                       COMMA_LOCATION_ARGS) {
  cMapElement_M_5F_processor * result = (cMapElement_M_5F_processor *) searchForReadWriteAttribute (inKey, false, inCompiler COMMA_THERE) ;
  macroNullOrValidSharedObject (result, cMapElement_M_5F_processor) ;
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

cEnumerator_M_5F_processor::cEnumerator_M_5F_processor (const GALGAS_M_5F_processor & inEnumeratedObject,
                                                        const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_M_5F_processor_2D_element cEnumerator_M_5F_processor::current (LOCATION_ARGS) const {
  const cMapElement_M_5F_processor * p = (const cMapElement_M_5F_processor *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_M_5F_processor) ;
  return GALGAS_M_5F_processor_2D_element (p->mProperty_lkey, p->mProperty_mIndex, p->mProperty_mStep) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_lstring cEnumerator_M_5F_processor::current_lkey (LOCATION_ARGS) const {
  const cMapElement * p = (const cMapElement *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement) ;
  return p->mProperty_lkey ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_uint cEnumerator_M_5F_processor::current_mIndex (LOCATION_ARGS) const {
  const cMapElement_M_5F_processor * p = (const cMapElement_M_5F_processor *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_M_5F_processor) ;
  return p->mProperty_mIndex ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_luint cEnumerator_M_5F_processor::current_mStep (LOCATION_ARGS) const {
  const cMapElement_M_5F_processor * p = (const cMapElement_M_5F_processor *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_M_5F_processor) ;
  return p->mProperty_mStep ;
}



//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                                  @M_processor type                                                  *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_M_5F_processor ("M_processor",
                                       NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

const C_galgas_type_descriptor * GALGAS_M_5F_processor::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_M_5F_processor ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

AC_GALGAS_root * GALGAS_M_5F_processor::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_M_5F_processor (*this)) ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_M_5F_processor GALGAS_M_5F_processor::extractObject (const GALGAS_object & inObject,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) {
  GALGAS_M_5F_processor result ;
  const GALGAS_M_5F_processor * p = (const GALGAS_M_5F_processor *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_M_5F_processor *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("M_processor", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

cMapElement_M_5F_network::cMapElement_M_5F_network (const GALGAS_lstring & inKey,
                                                    const GALGAS_uint & in_mIndex,
                                                    const GALGAS_bool & in_mCANnetwork,
                                                    const GALGAS_luint & in_mScalingFactor
                                                    COMMA_LOCATION_ARGS) :
cMapElement (inKey COMMA_THERE),
mProperty_mIndex (in_mIndex),
mProperty_mCANnetwork (in_mCANnetwork),
mProperty_mScalingFactor (in_mScalingFactor) {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

bool cMapElement_M_5F_network::isValid (void) const {
  return mProperty_lkey.isValid () && mProperty_mIndex.isValid () && mProperty_mCANnetwork.isValid () && mProperty_mScalingFactor.isValid () ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

cMapElement * cMapElement_M_5F_network::copy (void) {
  cMapElement * result = NULL ;
  macroMyNew (result, cMapElement_M_5F_network (mProperty_lkey, mProperty_mIndex, mProperty_mCANnetwork, mProperty_mScalingFactor COMMA_HERE)) ;
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void cMapElement_M_5F_network::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mIndex" ":" ;
  mProperty_mIndex.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mCANnetwork" ":" ;
  mProperty_mCANnetwork.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mScalingFactor" ":" ;
  mProperty_mScalingFactor.description (ioString, inIndentation) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

typeComparisonResult cMapElement_M_5F_network::compare (const cCollectionElement * inOperand) const {
  cMapElement_M_5F_network * operand = (cMapElement_M_5F_network *) inOperand ;
  typeComparisonResult result = mProperty_lkey.objectCompare (operand->mProperty_lkey) ;
  if (kOperandEqual == result) {
    result = mProperty_mIndex.objectCompare (operand->mProperty_mIndex) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_mCANnetwork.objectCompare (operand->mProperty_mCANnetwork) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_mScalingFactor.objectCompare (operand->mProperty_mScalingFactor) ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_M_5F_network::GALGAS_M_5F_network (void) :
AC_GALGAS_map () {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_M_5F_network::GALGAS_M_5F_network (const GALGAS_M_5F_network & inSource) :
AC_GALGAS_map (inSource) {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_M_5F_network & GALGAS_M_5F_network::operator = (const GALGAS_M_5F_network & inSource) {
  * ((AC_GALGAS_map *) this) = inSource ;
  return * this ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_M_5F_network GALGAS_M_5F_network::constructor_emptyMap (LOCATION_ARGS) {
  GALGAS_M_5F_network result ;
  result.makeNewEmptyMap (THERE) ;
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_M_5F_network GALGAS_M_5F_network::constructor_mapWithMapToOverride (const GALGAS_M_5F_network & inMapToOverride
                                                                           COMMA_LOCATION_ARGS) {
  GALGAS_M_5F_network result ;
  result.makeNewEmptyMapWithMapToOverride (inMapToOverride COMMA_THERE) ;
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_M_5F_network GALGAS_M_5F_network::getter_overriddenMap (C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) const {
  GALGAS_M_5F_network result ;
  getOverridenMap (result, inCompiler COMMA_THERE) ;
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void GALGAS_M_5F_network::addAssign_operation (const GALGAS_lstring & inKey,
                                               const GALGAS_uint & inArgument0,
                                               const GALGAS_bool & inArgument1,
                                               const GALGAS_luint & inArgument2,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) {
  cMapElement_M_5F_network * p = NULL ;
  macroMyNew (p, cMapElement_M_5F_network (inKey, inArgument0, inArgument1, inArgument2 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "@M_5F_network insert error: '%K' already in map" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void GALGAS_M_5F_network::setter_insertKey (GALGAS_lstring inKey,
                                            GALGAS_uint inArgument0,
                                            GALGAS_bool inArgument1,
                                            GALGAS_luint inArgument2,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) {
  cMapElement_M_5F_network * p = NULL ;
  macroMyNew (p, cMapElement_M_5F_network (inKey, inArgument0, inArgument1, inArgument2 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "the processor '%K' has been already declared in %L" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

const char * kSearchErrorMessage_M_5F_network_searchKey = "the processor '%K' is not declared" ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void GALGAS_M_5F_network::method_searchKey (GALGAS_lstring inKey,
                                            GALGAS_uint & outArgument0,
                                            GALGAS_bool & outArgument1,
                                            GALGAS_luint & outArgument2,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) const {
  const cMapElement_M_5F_network * p = (const cMapElement_M_5F_network *) performSearch (inKey,
                                                                                         inCompiler,
                                                                                         kSearchErrorMessage_M_5F_network_searchKey
                                                                                         COMMA_THERE) ;
  if (NULL == p) {
    outArgument0.drop () ;
    outArgument1.drop () ;
    outArgument2.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_M_5F_network) ;
    outArgument0 = p->mProperty_mIndex ;
    outArgument1 = p->mProperty_mCANnetwork ;
    outArgument2 = p->mProperty_mScalingFactor ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_uint GALGAS_M_5F_network::getter_mIndexForKey (const GALGAS_string & inKey,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_M_5F_network * p = (const cMapElement_M_5F_network *) attributes ;
  GALGAS_uint result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_M_5F_network) ;
    result = p->mProperty_mIndex ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_bool GALGAS_M_5F_network::getter_mCANnetworkForKey (const GALGAS_string & inKey,
                                                           C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_M_5F_network * p = (const cMapElement_M_5F_network *) attributes ;
  GALGAS_bool result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_M_5F_network) ;
    result = p->mProperty_mCANnetwork ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_luint GALGAS_M_5F_network::getter_mScalingFactorForKey (const GALGAS_string & inKey,
                                                               C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_M_5F_network * p = (const cMapElement_M_5F_network *) attributes ;
  GALGAS_luint result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_M_5F_network) ;
    result = p->mProperty_mScalingFactor ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void GALGAS_M_5F_network::setter_setMIndexForKey (GALGAS_uint inAttributeValue,
                                                  GALGAS_string inKey,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, true, inCompiler COMMA_THERE) ;
  cMapElement_M_5F_network * p = (cMapElement_M_5F_network *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_M_5F_network) ;
    p->mProperty_mIndex = inAttributeValue ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void GALGAS_M_5F_network::setter_setMCANnetworkForKey (GALGAS_bool inAttributeValue,
                                                       GALGAS_string inKey,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, true, inCompiler COMMA_THERE) ;
  cMapElement_M_5F_network * p = (cMapElement_M_5F_network *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_M_5F_network) ;
    p->mProperty_mCANnetwork = inAttributeValue ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void GALGAS_M_5F_network::setter_setMScalingFactorForKey (GALGAS_luint inAttributeValue,
                                                          GALGAS_string inKey,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, true, inCompiler COMMA_THERE) ;
  cMapElement_M_5F_network * p = (cMapElement_M_5F_network *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_M_5F_network) ;
    p->mProperty_mScalingFactor = inAttributeValue ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

cMapElement_M_5F_network * GALGAS_M_5F_network::readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                   const GALGAS_string & inKey
                                                                                   COMMA_LOCATION_ARGS) {
  cMapElement_M_5F_network * result = (cMapElement_M_5F_network *) searchForReadWriteAttribute (inKey, false, inCompiler COMMA_THERE) ;
  macroNullOrValidSharedObject (result, cMapElement_M_5F_network) ;
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

cEnumerator_M_5F_network::cEnumerator_M_5F_network (const GALGAS_M_5F_network & inEnumeratedObject,
                                                    const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_M_5F_network_2D_element cEnumerator_M_5F_network::current (LOCATION_ARGS) const {
  const cMapElement_M_5F_network * p = (const cMapElement_M_5F_network *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_M_5F_network) ;
  return GALGAS_M_5F_network_2D_element (p->mProperty_lkey, p->mProperty_mIndex, p->mProperty_mCANnetwork, p->mProperty_mScalingFactor) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_lstring cEnumerator_M_5F_network::current_lkey (LOCATION_ARGS) const {
  const cMapElement * p = (const cMapElement *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement) ;
  return p->mProperty_lkey ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_uint cEnumerator_M_5F_network::current_mIndex (LOCATION_ARGS) const {
  const cMapElement_M_5F_network * p = (const cMapElement_M_5F_network *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_M_5F_network) ;
  return p->mProperty_mIndex ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_bool cEnumerator_M_5F_network::current_mCANnetwork (LOCATION_ARGS) const {
  const cMapElement_M_5F_network * p = (const cMapElement_M_5F_network *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_M_5F_network) ;
  return p->mProperty_mCANnetwork ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_luint cEnumerator_M_5F_network::current_mScalingFactor (LOCATION_ARGS) const {
  const cMapElement_M_5F_network * p = (const cMapElement_M_5F_network *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_M_5F_network) ;
  return p->mProperty_mScalingFactor ;
}



//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                                   @M_network type                                                   *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_M_5F_network ("M_network",
                                     NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

const C_galgas_type_descriptor * GALGAS_M_5F_network::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_M_5F_network ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

AC_GALGAS_root * GALGAS_M_5F_network::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_M_5F_network (*this)) ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_M_5F_network GALGAS_M_5F_network::extractObject (const GALGAS_object & inObject,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) {
  GALGAS_M_5F_network result ;
  const GALGAS_M_5F_network * p = (const GALGAS_M_5F_network *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_M_5F_network *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("M_network", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//   Object comparison                                                                                                 *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*



typeComparisonResult GALGAS_AC_5F_canMessage::objectCompare (const GALGAS_AC_5F_canMessage & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_AC_5F_canMessage::GALGAS_AC_5F_canMessage (void) :
AC_GALGAS_class (false) {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_AC_5F_canMessage::GALGAS_AC_5F_canMessage (const cPtr_AC_5F_canMessage * inSourcePtr) :
AC_GALGAS_class (inSourcePtr, false) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_AC_5F_canMessage) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                       Pointer class for @AC_canMessage class                                        *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

cPtr_AC_5F_canMessage::cPtr_AC_5F_canMessage (LOCATION_ARGS) :
acPtr_class (THERE) {
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                                 @AC_canMessage type                                                 *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_AC_5F_canMessage ("AC_canMessage",
                                         NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

const C_galgas_type_descriptor * GALGAS_AC_5F_canMessage::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_AC_5F_canMessage ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

AC_GALGAS_root * GALGAS_AC_5F_canMessage::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_AC_5F_canMessage (*this)) ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_AC_5F_canMessage GALGAS_AC_5F_canMessage::extractObject (const GALGAS_object & inObject,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) {
  GALGAS_AC_5F_canMessage result ;
  const GALGAS_AC_5F_canMessage * p = (const GALGAS_AC_5F_canMessage *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_AC_5F_canMessage *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("AC_canMessage", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//   Object comparison                                                                                                 *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

typeComparisonResult cPtr_C_5F_canIndependantMessage::dynamicObjectCompare (const acPtr_class * /* inOperandPtr */) const {
  return kOperandEqual ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*


typeComparisonResult GALGAS_C_5F_canIndependantMessage::objectCompare (const GALGAS_C_5F_canIndependantMessage & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_C_5F_canIndependantMessage::GALGAS_C_5F_canIndependantMessage (void) :
GALGAS_AC_5F_canMessage () {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_C_5F_canIndependantMessage GALGAS_C_5F_canIndependantMessage::constructor_default (LOCATION_ARGS) {
  return GALGAS_C_5F_canIndependantMessage::constructor_new (THERE) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_C_5F_canIndependantMessage::GALGAS_C_5F_canIndependantMessage (const cPtr_C_5F_canIndependantMessage * inSourcePtr) :
GALGAS_AC_5F_canMessage (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_C_5F_canIndependantMessage) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_C_5F_canIndependantMessage GALGAS_C_5F_canIndependantMessage::constructor_new (LOCATION_ARGS) {
  GALGAS_C_5F_canIndependantMessage result ;
  macroMyNew (result.mObjectPtr, cPtr_C_5F_canIndependantMessage (THERE)) ;
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                  Pointer class for @C_canIndependantMessage class                                   *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

cPtr_C_5F_canIndependantMessage::cPtr_C_5F_canIndependantMessage (LOCATION_ARGS) :
cPtr_AC_5F_canMessage (THERE) {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

const C_galgas_type_descriptor * cPtr_C_5F_canIndependantMessage::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_C_5F_canIndependantMessage ;
}

void cPtr_C_5F_canIndependantMessage::description (C_String & ioString,
                                                   const int32_t /* inIndentation */) const {
  ioString << "[@C_canIndependantMessage]" ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

acPtr_class * cPtr_C_5F_canIndependantMessage::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_C_5F_canIndependantMessage (THERE)) ;
  return ptr ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                            @C_canIndependantMessage type                                            *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_C_5F_canIndependantMessage ("C_canIndependantMessage",
                                                   & kTypeDescriptor_GALGAS_AC_5F_canMessage) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

const C_galgas_type_descriptor * GALGAS_C_5F_canIndependantMessage::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_C_5F_canIndependantMessage ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

AC_GALGAS_root * GALGAS_C_5F_canIndependantMessage::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_C_5F_canIndependantMessage (*this)) ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_C_5F_canIndependantMessage GALGAS_C_5F_canIndependantMessage::extractObject (const GALGAS_object & inObject,
                                                                                    C_Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_C_5F_canIndependantMessage result ;
  const GALGAS_C_5F_canIndependantMessage * p = (const GALGAS_C_5F_canIndependantMessage *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_C_5F_canIndependantMessage *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("C_canIndependantMessage", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//   Object comparison                                                                                                 *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

typeComparisonResult cPtr_C_5F_canMessageFromMessage::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_C_5F_canMessageFromMessage * p = (const cPtr_C_5F_canMessageFromMessage *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_C_5F_canMessageFromMessage) ;
  if (kOperandEqual == result) {
    result = mProperty_mMessageIndex.objectCompare (p->mProperty_mMessageIndex) ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*


typeComparisonResult GALGAS_C_5F_canMessageFromMessage::objectCompare (const GALGAS_C_5F_canMessageFromMessage & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_C_5F_canMessageFromMessage::GALGAS_C_5F_canMessageFromMessage (void) :
GALGAS_AC_5F_canMessage () {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_C_5F_canMessageFromMessage GALGAS_C_5F_canMessageFromMessage::constructor_default (LOCATION_ARGS) {
  return GALGAS_C_5F_canMessageFromMessage::constructor_new (GALGAS_uint::constructor_default (HERE)
                                                             COMMA_THERE) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_C_5F_canMessageFromMessage::GALGAS_C_5F_canMessageFromMessage (const cPtr_C_5F_canMessageFromMessage * inSourcePtr) :
GALGAS_AC_5F_canMessage (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_C_5F_canMessageFromMessage) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_C_5F_canMessageFromMessage GALGAS_C_5F_canMessageFromMessage::constructor_new (const GALGAS_uint & inAttribute_mMessageIndex
                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_C_5F_canMessageFromMessage result ;
  if (inAttribute_mMessageIndex.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_C_5F_canMessageFromMessage (inAttribute_mMessageIndex COMMA_THERE)) ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_uint GALGAS_C_5F_canMessageFromMessage::getter_mMessageIndex (UNUSED_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (NULL != mObjectPtr) {
    const cPtr_C_5F_canMessageFromMessage * p = (const cPtr_C_5F_canMessageFromMessage *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_C_5F_canMessageFromMessage) ;
    result = p->mProperty_mMessageIndex ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_uint cPtr_C_5F_canMessageFromMessage::getter_mMessageIndex (UNUSED_LOCATION_ARGS) const {
  return mProperty_mMessageIndex ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                  Pointer class for @C_canMessageFromMessage class                                   *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

cPtr_C_5F_canMessageFromMessage::cPtr_C_5F_canMessageFromMessage (const GALGAS_uint & in_mMessageIndex
                                                                  COMMA_LOCATION_ARGS) :
cPtr_AC_5F_canMessage (THERE),
mProperty_mMessageIndex (in_mMessageIndex) {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

const C_galgas_type_descriptor * cPtr_C_5F_canMessageFromMessage::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_C_5F_canMessageFromMessage ;
}

void cPtr_C_5F_canMessageFromMessage::description (C_String & ioString,
                                                   const int32_t inIndentation) const {
  ioString << "[@C_canMessageFromMessage:" ;
  mProperty_mMessageIndex.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

acPtr_class * cPtr_C_5F_canMessageFromMessage::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_C_5F_canMessageFromMessage (mProperty_mMessageIndex COMMA_THERE)) ;
  return ptr ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                            @C_canMessageFromMessage type                                            *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_C_5F_canMessageFromMessage ("C_canMessageFromMessage",
                                                   & kTypeDescriptor_GALGAS_AC_5F_canMessage) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

const C_galgas_type_descriptor * GALGAS_C_5F_canMessageFromMessage::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_C_5F_canMessageFromMessage ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

AC_GALGAS_root * GALGAS_C_5F_canMessageFromMessage::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_C_5F_canMessageFromMessage (*this)) ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_C_5F_canMessageFromMessage GALGAS_C_5F_canMessageFromMessage::extractObject (const GALGAS_object & inObject,
                                                                                    C_Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_C_5F_canMessageFromMessage result ;
  const GALGAS_C_5F_canMessageFromMessage * p = (const GALGAS_C_5F_canMessageFromMessage *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_C_5F_canMessageFromMessage *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("C_canMessageFromMessage", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//   Object comparison                                                                                                 *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

typeComparisonResult cPtr_C_5F_canMessageFromTask::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_C_5F_canMessageFromTask * p = (const cPtr_C_5F_canMessageFromTask *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_C_5F_canMessageFromTask) ;
  if (kOperandEqual == result) {
    result = mProperty_mTaskIndex.objectCompare (p->mProperty_mTaskIndex) ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*


typeComparisonResult GALGAS_C_5F_canMessageFromTask::objectCompare (const GALGAS_C_5F_canMessageFromTask & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_C_5F_canMessageFromTask::GALGAS_C_5F_canMessageFromTask (void) :
GALGAS_AC_5F_canMessage () {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_C_5F_canMessageFromTask GALGAS_C_5F_canMessageFromTask::constructor_default (LOCATION_ARGS) {
  return GALGAS_C_5F_canMessageFromTask::constructor_new (GALGAS_uint::constructor_default (HERE)
                                                          COMMA_THERE) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_C_5F_canMessageFromTask::GALGAS_C_5F_canMessageFromTask (const cPtr_C_5F_canMessageFromTask * inSourcePtr) :
GALGAS_AC_5F_canMessage (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_C_5F_canMessageFromTask) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_C_5F_canMessageFromTask GALGAS_C_5F_canMessageFromTask::constructor_new (const GALGAS_uint & inAttribute_mTaskIndex
                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_C_5F_canMessageFromTask result ;
  if (inAttribute_mTaskIndex.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_C_5F_canMessageFromTask (inAttribute_mTaskIndex COMMA_THERE)) ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_uint GALGAS_C_5F_canMessageFromTask::getter_mTaskIndex (UNUSED_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (NULL != mObjectPtr) {
    const cPtr_C_5F_canMessageFromTask * p = (const cPtr_C_5F_canMessageFromTask *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_C_5F_canMessageFromTask) ;
    result = p->mProperty_mTaskIndex ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_uint cPtr_C_5F_canMessageFromTask::getter_mTaskIndex (UNUSED_LOCATION_ARGS) const {
  return mProperty_mTaskIndex ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                    Pointer class for @C_canMessageFromTask class                                    *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

cPtr_C_5F_canMessageFromTask::cPtr_C_5F_canMessageFromTask (const GALGAS_uint & in_mTaskIndex
                                                            COMMA_LOCATION_ARGS) :
cPtr_AC_5F_canMessage (THERE),
mProperty_mTaskIndex (in_mTaskIndex) {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

const C_galgas_type_descriptor * cPtr_C_5F_canMessageFromTask::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_C_5F_canMessageFromTask ;
}

void cPtr_C_5F_canMessageFromTask::description (C_String & ioString,
                                                const int32_t inIndentation) const {
  ioString << "[@C_canMessageFromTask:" ;
  mProperty_mTaskIndex.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

acPtr_class * cPtr_C_5F_canMessageFromTask::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_C_5F_canMessageFromTask (mProperty_mTaskIndex COMMA_THERE)) ;
  return ptr ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                             @C_canMessageFromTask type                                              *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_C_5F_canMessageFromTask ("C_canMessageFromTask",
                                                & kTypeDescriptor_GALGAS_AC_5F_canMessage) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

const C_galgas_type_descriptor * GALGAS_C_5F_canMessageFromTask::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_C_5F_canMessageFromTask ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

AC_GALGAS_root * GALGAS_C_5F_canMessageFromTask::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_C_5F_canMessageFromTask (*this)) ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_C_5F_canMessageFromTask GALGAS_C_5F_canMessageFromTask::extractObject (const GALGAS_object & inObject,
                                                                              C_Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_C_5F_canMessageFromTask result ;
  const GALGAS_C_5F_canMessageFromTask * p = (const GALGAS_C_5F_canMessageFromTask *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_C_5F_canMessageFromTask *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("C_canMessageFromTask", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

cMapElement_M_5F_messages::cMapElement_M_5F_messages (const GALGAS_lstring & inKey,
                                                      const GALGAS_uint & in_mIndex,
                                                      const GALGAS_luint & in_mClass,
                                                      const GALGAS_uint & in_mNetworkIndex,
                                                      const GALGAS_luint & in_mBytesCount,
                                                      const GALGAS_luint & in_mPriority,
                                                      const GALGAS_luint & in_mOffset,
                                                      const GALGAS_luint & in_mDeadline,
                                                      const GALGAS_luint & in_mPeriod,
                                                      const GALGAS_AC_5F_canMessage & in_mMessageKind
                                                      COMMA_LOCATION_ARGS) :
cMapElement (inKey COMMA_THERE),
mProperty_mIndex (in_mIndex),
mProperty_mClass (in_mClass),
mProperty_mNetworkIndex (in_mNetworkIndex),
mProperty_mBytesCount (in_mBytesCount),
mProperty_mPriority (in_mPriority),
mProperty_mOffset (in_mOffset),
mProperty_mDeadline (in_mDeadline),
mProperty_mPeriod (in_mPeriod),
mProperty_mMessageKind (in_mMessageKind) {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

bool cMapElement_M_5F_messages::isValid (void) const {
  return mProperty_lkey.isValid () && mProperty_mIndex.isValid () && mProperty_mClass.isValid () && mProperty_mNetworkIndex.isValid () && mProperty_mBytesCount.isValid () && mProperty_mPriority.isValid () && mProperty_mOffset.isValid () && mProperty_mDeadline.isValid () && mProperty_mPeriod.isValid () && mProperty_mMessageKind.isValid () ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

cMapElement * cMapElement_M_5F_messages::copy (void) {
  cMapElement * result = NULL ;
  macroMyNew (result, cMapElement_M_5F_messages (mProperty_lkey, mProperty_mIndex, mProperty_mClass, mProperty_mNetworkIndex, mProperty_mBytesCount, mProperty_mPriority, mProperty_mOffset, mProperty_mDeadline, mProperty_mPeriod, mProperty_mMessageKind COMMA_HERE)) ;
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void cMapElement_M_5F_messages::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mIndex" ":" ;
  mProperty_mIndex.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mClass" ":" ;
  mProperty_mClass.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mNetworkIndex" ":" ;
  mProperty_mNetworkIndex.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mBytesCount" ":" ;
  mProperty_mBytesCount.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mPriority" ":" ;
  mProperty_mPriority.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mOffset" ":" ;
  mProperty_mOffset.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mDeadline" ":" ;
  mProperty_mDeadline.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mPeriod" ":" ;
  mProperty_mPeriod.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mMessageKind" ":" ;
  mProperty_mMessageKind.description (ioString, inIndentation) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

typeComparisonResult cMapElement_M_5F_messages::compare (const cCollectionElement * inOperand) const {
  cMapElement_M_5F_messages * operand = (cMapElement_M_5F_messages *) inOperand ;
  typeComparisonResult result = mProperty_lkey.objectCompare (operand->mProperty_lkey) ;
  if (kOperandEqual == result) {
    result = mProperty_mIndex.objectCompare (operand->mProperty_mIndex) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_mClass.objectCompare (operand->mProperty_mClass) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_mNetworkIndex.objectCompare (operand->mProperty_mNetworkIndex) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_mBytesCount.objectCompare (operand->mProperty_mBytesCount) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_mPriority.objectCompare (operand->mProperty_mPriority) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_mOffset.objectCompare (operand->mProperty_mOffset) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_mDeadline.objectCompare (operand->mProperty_mDeadline) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_mPeriod.objectCompare (operand->mProperty_mPeriod) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_mMessageKind.objectCompare (operand->mProperty_mMessageKind) ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_M_5F_messages::GALGAS_M_5F_messages (void) :
AC_GALGAS_map () {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_M_5F_messages::GALGAS_M_5F_messages (const GALGAS_M_5F_messages & inSource) :
AC_GALGAS_map (inSource) {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_M_5F_messages & GALGAS_M_5F_messages::operator = (const GALGAS_M_5F_messages & inSource) {
  * ((AC_GALGAS_map *) this) = inSource ;
  return * this ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_M_5F_messages GALGAS_M_5F_messages::constructor_emptyMap (LOCATION_ARGS) {
  GALGAS_M_5F_messages result ;
  result.makeNewEmptyMap (THERE) ;
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_M_5F_messages GALGAS_M_5F_messages::constructor_mapWithMapToOverride (const GALGAS_M_5F_messages & inMapToOverride
                                                                             COMMA_LOCATION_ARGS) {
  GALGAS_M_5F_messages result ;
  result.makeNewEmptyMapWithMapToOverride (inMapToOverride COMMA_THERE) ;
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_M_5F_messages GALGAS_M_5F_messages::getter_overriddenMap (C_Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) const {
  GALGAS_M_5F_messages result ;
  getOverridenMap (result, inCompiler COMMA_THERE) ;
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void GALGAS_M_5F_messages::addAssign_operation (const GALGAS_lstring & inKey,
                                                const GALGAS_uint & inArgument0,
                                                const GALGAS_luint & inArgument1,
                                                const GALGAS_uint & inArgument2,
                                                const GALGAS_luint & inArgument3,
                                                const GALGAS_luint & inArgument4,
                                                const GALGAS_luint & inArgument5,
                                                const GALGAS_luint & inArgument6,
                                                const GALGAS_luint & inArgument7,
                                                const GALGAS_AC_5F_canMessage & inArgument8,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  cMapElement_M_5F_messages * p = NULL ;
  macroMyNew (p, cMapElement_M_5F_messages (inKey, inArgument0, inArgument1, inArgument2, inArgument3, inArgument4, inArgument5, inArgument6, inArgument7, inArgument8 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "@M_5F_messages insert error: '%K' already in map" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void GALGAS_M_5F_messages::setter_insertKey (GALGAS_lstring inKey,
                                             GALGAS_uint inArgument0,
                                             GALGAS_luint inArgument1,
                                             GALGAS_uint inArgument2,
                                             GALGAS_luint inArgument3,
                                             GALGAS_luint inArgument4,
                                             GALGAS_luint inArgument5,
                                             GALGAS_luint inArgument6,
                                             GALGAS_luint inArgument7,
                                             GALGAS_AC_5F_canMessage inArgument8,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) {
  cMapElement_M_5F_messages * p = NULL ;
  macroMyNew (p, cMapElement_M_5F_messages (inKey, inArgument0, inArgument1, inArgument2, inArgument3, inArgument4, inArgument5, inArgument6, inArgument7, inArgument8 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "the CAN message '%K' has been already declared in %L" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

const char * kSearchErrorMessage_M_5F_messages_searchKey = "the CAN message '%K' is not declared" ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void GALGAS_M_5F_messages::method_searchKey (GALGAS_lstring inKey,
                                             GALGAS_uint & outArgument0,
                                             GALGAS_luint & outArgument1,
                                             GALGAS_uint & outArgument2,
                                             GALGAS_luint & outArgument3,
                                             GALGAS_luint & outArgument4,
                                             GALGAS_luint & outArgument5,
                                             GALGAS_luint & outArgument6,
                                             GALGAS_luint & outArgument7,
                                             GALGAS_AC_5F_canMessage & outArgument8,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) const {
  const cMapElement_M_5F_messages * p = (const cMapElement_M_5F_messages *) performSearch (inKey,
                                                                                           inCompiler,
                                                                                           kSearchErrorMessage_M_5F_messages_searchKey
                                                                                           COMMA_THERE) ;
  if (NULL == p) {
    outArgument0.drop () ;
    outArgument1.drop () ;
    outArgument2.drop () ;
    outArgument3.drop () ;
    outArgument4.drop () ;
    outArgument5.drop () ;
    outArgument6.drop () ;
    outArgument7.drop () ;
    outArgument8.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_M_5F_messages) ;
    outArgument0 = p->mProperty_mIndex ;
    outArgument1 = p->mProperty_mClass ;
    outArgument2 = p->mProperty_mNetworkIndex ;
    outArgument3 = p->mProperty_mBytesCount ;
    outArgument4 = p->mProperty_mPriority ;
    outArgument5 = p->mProperty_mOffset ;
    outArgument6 = p->mProperty_mDeadline ;
    outArgument7 = p->mProperty_mPeriod ;
    outArgument8 = p->mProperty_mMessageKind ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_uint GALGAS_M_5F_messages::getter_mIndexForKey (const GALGAS_string & inKey,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_M_5F_messages * p = (const cMapElement_M_5F_messages *) attributes ;
  GALGAS_uint result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_M_5F_messages) ;
    result = p->mProperty_mIndex ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_luint GALGAS_M_5F_messages::getter_mClassForKey (const GALGAS_string & inKey,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_M_5F_messages * p = (const cMapElement_M_5F_messages *) attributes ;
  GALGAS_luint result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_M_5F_messages) ;
    result = p->mProperty_mClass ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_uint GALGAS_M_5F_messages::getter_mNetworkIndexForKey (const GALGAS_string & inKey,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_M_5F_messages * p = (const cMapElement_M_5F_messages *) attributes ;
  GALGAS_uint result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_M_5F_messages) ;
    result = p->mProperty_mNetworkIndex ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_luint GALGAS_M_5F_messages::getter_mBytesCountForKey (const GALGAS_string & inKey,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_M_5F_messages * p = (const cMapElement_M_5F_messages *) attributes ;
  GALGAS_luint result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_M_5F_messages) ;
    result = p->mProperty_mBytesCount ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_luint GALGAS_M_5F_messages::getter_mPriorityForKey (const GALGAS_string & inKey,
                                                           C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_M_5F_messages * p = (const cMapElement_M_5F_messages *) attributes ;
  GALGAS_luint result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_M_5F_messages) ;
    result = p->mProperty_mPriority ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_luint GALGAS_M_5F_messages::getter_mOffsetForKey (const GALGAS_string & inKey,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_M_5F_messages * p = (const cMapElement_M_5F_messages *) attributes ;
  GALGAS_luint result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_M_5F_messages) ;
    result = p->mProperty_mOffset ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_luint GALGAS_M_5F_messages::getter_mDeadlineForKey (const GALGAS_string & inKey,
                                                           C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_M_5F_messages * p = (const cMapElement_M_5F_messages *) attributes ;
  GALGAS_luint result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_M_5F_messages) ;
    result = p->mProperty_mDeadline ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_luint GALGAS_M_5F_messages::getter_mPeriodForKey (const GALGAS_string & inKey,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_M_5F_messages * p = (const cMapElement_M_5F_messages *) attributes ;
  GALGAS_luint result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_M_5F_messages) ;
    result = p->mProperty_mPeriod ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_AC_5F_canMessage GALGAS_M_5F_messages::getter_mMessageKindForKey (const GALGAS_string & inKey,
                                                                         C_Compiler * inCompiler
                                                                         COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_M_5F_messages * p = (const cMapElement_M_5F_messages *) attributes ;
  GALGAS_AC_5F_canMessage result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_M_5F_messages) ;
    result = p->mProperty_mMessageKind ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void GALGAS_M_5F_messages::setter_setMIndexForKey (GALGAS_uint inAttributeValue,
                                                   GALGAS_string inKey,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, true, inCompiler COMMA_THERE) ;
  cMapElement_M_5F_messages * p = (cMapElement_M_5F_messages *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_M_5F_messages) ;
    p->mProperty_mIndex = inAttributeValue ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void GALGAS_M_5F_messages::setter_setMClassForKey (GALGAS_luint inAttributeValue,
                                                   GALGAS_string inKey,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, true, inCompiler COMMA_THERE) ;
  cMapElement_M_5F_messages * p = (cMapElement_M_5F_messages *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_M_5F_messages) ;
    p->mProperty_mClass = inAttributeValue ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void GALGAS_M_5F_messages::setter_setMNetworkIndexForKey (GALGAS_uint inAttributeValue,
                                                          GALGAS_string inKey,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, true, inCompiler COMMA_THERE) ;
  cMapElement_M_5F_messages * p = (cMapElement_M_5F_messages *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_M_5F_messages) ;
    p->mProperty_mNetworkIndex = inAttributeValue ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void GALGAS_M_5F_messages::setter_setMBytesCountForKey (GALGAS_luint inAttributeValue,
                                                        GALGAS_string inKey,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, true, inCompiler COMMA_THERE) ;
  cMapElement_M_5F_messages * p = (cMapElement_M_5F_messages *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_M_5F_messages) ;
    p->mProperty_mBytesCount = inAttributeValue ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void GALGAS_M_5F_messages::setter_setMPriorityForKey (GALGAS_luint inAttributeValue,
                                                      GALGAS_string inKey,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, true, inCompiler COMMA_THERE) ;
  cMapElement_M_5F_messages * p = (cMapElement_M_5F_messages *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_M_5F_messages) ;
    p->mProperty_mPriority = inAttributeValue ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void GALGAS_M_5F_messages::setter_setMOffsetForKey (GALGAS_luint inAttributeValue,
                                                    GALGAS_string inKey,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, true, inCompiler COMMA_THERE) ;
  cMapElement_M_5F_messages * p = (cMapElement_M_5F_messages *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_M_5F_messages) ;
    p->mProperty_mOffset = inAttributeValue ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void GALGAS_M_5F_messages::setter_setMDeadlineForKey (GALGAS_luint inAttributeValue,
                                                      GALGAS_string inKey,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, true, inCompiler COMMA_THERE) ;
  cMapElement_M_5F_messages * p = (cMapElement_M_5F_messages *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_M_5F_messages) ;
    p->mProperty_mDeadline = inAttributeValue ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void GALGAS_M_5F_messages::setter_setMPeriodForKey (GALGAS_luint inAttributeValue,
                                                    GALGAS_string inKey,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, true, inCompiler COMMA_THERE) ;
  cMapElement_M_5F_messages * p = (cMapElement_M_5F_messages *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_M_5F_messages) ;
    p->mProperty_mPeriod = inAttributeValue ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void GALGAS_M_5F_messages::setter_setMMessageKindForKey (GALGAS_AC_5F_canMessage inAttributeValue,
                                                         GALGAS_string inKey,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, true, inCompiler COMMA_THERE) ;
  cMapElement_M_5F_messages * p = (cMapElement_M_5F_messages *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_M_5F_messages) ;
    p->mProperty_mMessageKind = inAttributeValue ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

cMapElement_M_5F_messages * GALGAS_M_5F_messages::readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                     const GALGAS_string & inKey
                                                                                     COMMA_LOCATION_ARGS) {
  cMapElement_M_5F_messages * result = (cMapElement_M_5F_messages *) searchForReadWriteAttribute (inKey, false, inCompiler COMMA_THERE) ;
  macroNullOrValidSharedObject (result, cMapElement_M_5F_messages) ;
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

cEnumerator_M_5F_messages::cEnumerator_M_5F_messages (const GALGAS_M_5F_messages & inEnumeratedObject,
                                                      const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_M_5F_messages_2D_element cEnumerator_M_5F_messages::current (LOCATION_ARGS) const {
  const cMapElement_M_5F_messages * p = (const cMapElement_M_5F_messages *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_M_5F_messages) ;
  return GALGAS_M_5F_messages_2D_element (p->mProperty_lkey, p->mProperty_mIndex, p->mProperty_mClass, p->mProperty_mNetworkIndex, p->mProperty_mBytesCount, p->mProperty_mPriority, p->mProperty_mOffset, p->mProperty_mDeadline, p->mProperty_mPeriod, p->mProperty_mMessageKind) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_lstring cEnumerator_M_5F_messages::current_lkey (LOCATION_ARGS) const {
  const cMapElement * p = (const cMapElement *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement) ;
  return p->mProperty_lkey ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_uint cEnumerator_M_5F_messages::current_mIndex (LOCATION_ARGS) const {
  const cMapElement_M_5F_messages * p = (const cMapElement_M_5F_messages *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_M_5F_messages) ;
  return p->mProperty_mIndex ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_luint cEnumerator_M_5F_messages::current_mClass (LOCATION_ARGS) const {
  const cMapElement_M_5F_messages * p = (const cMapElement_M_5F_messages *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_M_5F_messages) ;
  return p->mProperty_mClass ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_uint cEnumerator_M_5F_messages::current_mNetworkIndex (LOCATION_ARGS) const {
  const cMapElement_M_5F_messages * p = (const cMapElement_M_5F_messages *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_M_5F_messages) ;
  return p->mProperty_mNetworkIndex ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_luint cEnumerator_M_5F_messages::current_mBytesCount (LOCATION_ARGS) const {
  const cMapElement_M_5F_messages * p = (const cMapElement_M_5F_messages *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_M_5F_messages) ;
  return p->mProperty_mBytesCount ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_luint cEnumerator_M_5F_messages::current_mPriority (LOCATION_ARGS) const {
  const cMapElement_M_5F_messages * p = (const cMapElement_M_5F_messages *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_M_5F_messages) ;
  return p->mProperty_mPriority ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_luint cEnumerator_M_5F_messages::current_mOffset (LOCATION_ARGS) const {
  const cMapElement_M_5F_messages * p = (const cMapElement_M_5F_messages *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_M_5F_messages) ;
  return p->mProperty_mOffset ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_luint cEnumerator_M_5F_messages::current_mDeadline (LOCATION_ARGS) const {
  const cMapElement_M_5F_messages * p = (const cMapElement_M_5F_messages *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_M_5F_messages) ;
  return p->mProperty_mDeadline ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_luint cEnumerator_M_5F_messages::current_mPeriod (LOCATION_ARGS) const {
  const cMapElement_M_5F_messages * p = (const cMapElement_M_5F_messages *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_M_5F_messages) ;
  return p->mProperty_mPeriod ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_AC_5F_canMessage cEnumerator_M_5F_messages::current_mMessageKind (LOCATION_ARGS) const {
  const cMapElement_M_5F_messages * p = (const cMapElement_M_5F_messages *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_M_5F_messages) ;
  return p->mProperty_mMessageKind ;
}



//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                                  @M_messages type                                                   *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_M_5F_messages ("M_messages",
                                      NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

const C_galgas_type_descriptor * GALGAS_M_5F_messages::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_M_5F_messages ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

AC_GALGAS_root * GALGAS_M_5F_messages::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_M_5F_messages (*this)) ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_M_5F_messages GALGAS_M_5F_messages::extractObject (const GALGAS_object & inObject,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) {
  GALGAS_M_5F_messages result ;
  const GALGAS_M_5F_messages * p = (const GALGAS_M_5F_messages *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_M_5F_messages *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("M_messages", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//   Object comparison                                                                                                 *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*



typeComparisonResult GALGAS_AC_5F_task::objectCompare (const GALGAS_AC_5F_task & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_AC_5F_task::GALGAS_AC_5F_task (void) :
AC_GALGAS_class (false) {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_AC_5F_task::GALGAS_AC_5F_task (const cPtr_AC_5F_task * inSourcePtr) :
AC_GALGAS_class (inSourcePtr, false) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_AC_5F_task) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                          Pointer class for @AC_task class                                           *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

cPtr_AC_5F_task::cPtr_AC_5F_task (LOCATION_ARGS) :
acPtr_class (THERE) {
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                                    @AC_task type                                                    *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_AC_5F_task ("AC_task",
                                   NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

const C_galgas_type_descriptor * GALGAS_AC_5F_task::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_AC_5F_task ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

AC_GALGAS_root * GALGAS_AC_5F_task::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_AC_5F_task (*this)) ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_AC_5F_task GALGAS_AC_5F_task::extractObject (const GALGAS_object & inObject,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  GALGAS_AC_5F_task result ;
  const GALGAS_AC_5F_task * p = (const GALGAS_AC_5F_task *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_AC_5F_task *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("AC_task", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//   Object comparison                                                                                                 *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

typeComparisonResult cPtr_C_5F_independantTask::dynamicObjectCompare (const acPtr_class * /* inOperandPtr */) const {
  return kOperandEqual ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*


typeComparisonResult GALGAS_C_5F_independantTask::objectCompare (const GALGAS_C_5F_independantTask & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_C_5F_independantTask::GALGAS_C_5F_independantTask (void) :
GALGAS_AC_5F_task () {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_C_5F_independantTask GALGAS_C_5F_independantTask::constructor_default (LOCATION_ARGS) {
  return GALGAS_C_5F_independantTask::constructor_new (THERE) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_C_5F_independantTask::GALGAS_C_5F_independantTask (const cPtr_C_5F_independantTask * inSourcePtr) :
GALGAS_AC_5F_task (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_C_5F_independantTask) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_C_5F_independantTask GALGAS_C_5F_independantTask::constructor_new (LOCATION_ARGS) {
  GALGAS_C_5F_independantTask result ;
  macroMyNew (result.mObjectPtr, cPtr_C_5F_independantTask (THERE)) ;
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                     Pointer class for @C_independantTask class                                      *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

cPtr_C_5F_independantTask::cPtr_C_5F_independantTask (LOCATION_ARGS) :
cPtr_AC_5F_task (THERE) {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

const C_galgas_type_descriptor * cPtr_C_5F_independantTask::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_C_5F_independantTask ;
}

void cPtr_C_5F_independantTask::description (C_String & ioString,
                                             const int32_t /* inIndentation */) const {
  ioString << "[@C_independantTask]" ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

acPtr_class * cPtr_C_5F_independantTask::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_C_5F_independantTask (THERE)) ;
  return ptr ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                               @C_independantTask type                                               *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_C_5F_independantTask ("C_independantTask",
                                             & kTypeDescriptor_GALGAS_AC_5F_task) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

const C_galgas_type_descriptor * GALGAS_C_5F_independantTask::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_C_5F_independantTask ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

AC_GALGAS_root * GALGAS_C_5F_independantTask::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_C_5F_independantTask (*this)) ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_C_5F_independantTask GALGAS_C_5F_independantTask::extractObject (const GALGAS_object & inObject,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_C_5F_independantTask result ;
  const GALGAS_C_5F_independantTask * p = (const GALGAS_C_5F_independantTask *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_C_5F_independantTask *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("C_independantTask", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

cMapElement_M_5F_tasks::cMapElement_M_5F_tasks (const GALGAS_lstring & inKey,
                                                const GALGAS_uint & in_mIndex,
                                                const GALGAS_luint & in_mPriority,
                                                const GALGAS_luint & in_mOffset,
                                                const GALGAS_luint & in_mDeadline,
                                                const GALGAS_luint & in_mDurationMin,
                                                const GALGAS_luint & in_mDurationMax,
                                                const GALGAS_uint & in_mProcessor,
                                                const GALGAS_luint & in_mPeriod,
                                                const GALGAS_AC_5F_task & in_mTaskKind
                                                COMMA_LOCATION_ARGS) :
cMapElement (inKey COMMA_THERE),
mProperty_mIndex (in_mIndex),
mProperty_mPriority (in_mPriority),
mProperty_mOffset (in_mOffset),
mProperty_mDeadline (in_mDeadline),
mProperty_mDurationMin (in_mDurationMin),
mProperty_mDurationMax (in_mDurationMax),
mProperty_mProcessor (in_mProcessor),
mProperty_mPeriod (in_mPeriod),
mProperty_mTaskKind (in_mTaskKind) {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

bool cMapElement_M_5F_tasks::isValid (void) const {
  return mProperty_lkey.isValid () && mProperty_mIndex.isValid () && mProperty_mPriority.isValid () && mProperty_mOffset.isValid () && mProperty_mDeadline.isValid () && mProperty_mDurationMin.isValid () && mProperty_mDurationMax.isValid () && mProperty_mProcessor.isValid () && mProperty_mPeriod.isValid () && mProperty_mTaskKind.isValid () ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

cMapElement * cMapElement_M_5F_tasks::copy (void) {
  cMapElement * result = NULL ;
  macroMyNew (result, cMapElement_M_5F_tasks (mProperty_lkey, mProperty_mIndex, mProperty_mPriority, mProperty_mOffset, mProperty_mDeadline, mProperty_mDurationMin, mProperty_mDurationMax, mProperty_mProcessor, mProperty_mPeriod, mProperty_mTaskKind COMMA_HERE)) ;
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void cMapElement_M_5F_tasks::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mIndex" ":" ;
  mProperty_mIndex.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mPriority" ":" ;
  mProperty_mPriority.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mOffset" ":" ;
  mProperty_mOffset.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mDeadline" ":" ;
  mProperty_mDeadline.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mDurationMin" ":" ;
  mProperty_mDurationMin.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mDurationMax" ":" ;
  mProperty_mDurationMax.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mProcessor" ":" ;
  mProperty_mProcessor.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mPeriod" ":" ;
  mProperty_mPeriod.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mTaskKind" ":" ;
  mProperty_mTaskKind.description (ioString, inIndentation) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

typeComparisonResult cMapElement_M_5F_tasks::compare (const cCollectionElement * inOperand) const {
  cMapElement_M_5F_tasks * operand = (cMapElement_M_5F_tasks *) inOperand ;
  typeComparisonResult result = mProperty_lkey.objectCompare (operand->mProperty_lkey) ;
  if (kOperandEqual == result) {
    result = mProperty_mIndex.objectCompare (operand->mProperty_mIndex) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_mPriority.objectCompare (operand->mProperty_mPriority) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_mOffset.objectCompare (operand->mProperty_mOffset) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_mDeadline.objectCompare (operand->mProperty_mDeadline) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_mDurationMin.objectCompare (operand->mProperty_mDurationMin) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_mDurationMax.objectCompare (operand->mProperty_mDurationMax) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_mProcessor.objectCompare (operand->mProperty_mProcessor) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_mPeriod.objectCompare (operand->mProperty_mPeriod) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_mTaskKind.objectCompare (operand->mProperty_mTaskKind) ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_M_5F_tasks::GALGAS_M_5F_tasks (void) :
AC_GALGAS_map () {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_M_5F_tasks::GALGAS_M_5F_tasks (const GALGAS_M_5F_tasks & inSource) :
AC_GALGAS_map (inSource) {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_M_5F_tasks & GALGAS_M_5F_tasks::operator = (const GALGAS_M_5F_tasks & inSource) {
  * ((AC_GALGAS_map *) this) = inSource ;
  return * this ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_M_5F_tasks GALGAS_M_5F_tasks::constructor_emptyMap (LOCATION_ARGS) {
  GALGAS_M_5F_tasks result ;
  result.makeNewEmptyMap (THERE) ;
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_M_5F_tasks GALGAS_M_5F_tasks::constructor_mapWithMapToOverride (const GALGAS_M_5F_tasks & inMapToOverride
                                                                       COMMA_LOCATION_ARGS) {
  GALGAS_M_5F_tasks result ;
  result.makeNewEmptyMapWithMapToOverride (inMapToOverride COMMA_THERE) ;
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_M_5F_tasks GALGAS_M_5F_tasks::getter_overriddenMap (C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) const {
  GALGAS_M_5F_tasks result ;
  getOverridenMap (result, inCompiler COMMA_THERE) ;
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void GALGAS_M_5F_tasks::addAssign_operation (const GALGAS_lstring & inKey,
                                             const GALGAS_uint & inArgument0,
                                             const GALGAS_luint & inArgument1,
                                             const GALGAS_luint & inArgument2,
                                             const GALGAS_luint & inArgument3,
                                             const GALGAS_luint & inArgument4,
                                             const GALGAS_luint & inArgument5,
                                             const GALGAS_uint & inArgument6,
                                             const GALGAS_luint & inArgument7,
                                             const GALGAS_AC_5F_task & inArgument8,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) {
  cMapElement_M_5F_tasks * p = NULL ;
  macroMyNew (p, cMapElement_M_5F_tasks (inKey, inArgument0, inArgument1, inArgument2, inArgument3, inArgument4, inArgument5, inArgument6, inArgument7, inArgument8 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "@M_5F_tasks insert error: '%K' already in map" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void GALGAS_M_5F_tasks::setter_insertKey (GALGAS_lstring inKey,
                                          GALGAS_uint inArgument0,
                                          GALGAS_luint inArgument1,
                                          GALGAS_luint inArgument2,
                                          GALGAS_luint inArgument3,
                                          GALGAS_luint inArgument4,
                                          GALGAS_luint inArgument5,
                                          GALGAS_uint inArgument6,
                                          GALGAS_luint inArgument7,
                                          GALGAS_AC_5F_task inArgument8,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
  cMapElement_M_5F_tasks * p = NULL ;
  macroMyNew (p, cMapElement_M_5F_tasks (inKey, inArgument0, inArgument1, inArgument2, inArgument3, inArgument4, inArgument5, inArgument6, inArgument7, inArgument8 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "the task '%K' has been already declared in %L" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

const char * kSearchErrorMessage_M_5F_tasks_searchKey = "the task '%K' is not declared" ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void GALGAS_M_5F_tasks::method_searchKey (GALGAS_lstring inKey,
                                          GALGAS_uint & outArgument0,
                                          GALGAS_luint & outArgument1,
                                          GALGAS_luint & outArgument2,
                                          GALGAS_luint & outArgument3,
                                          GALGAS_luint & outArgument4,
                                          GALGAS_luint & outArgument5,
                                          GALGAS_uint & outArgument6,
                                          GALGAS_luint & outArgument7,
                                          GALGAS_AC_5F_task & outArgument8,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) const {
  const cMapElement_M_5F_tasks * p = (const cMapElement_M_5F_tasks *) performSearch (inKey,
                                                                                     inCompiler,
                                                                                     kSearchErrorMessage_M_5F_tasks_searchKey
                                                                                     COMMA_THERE) ;
  if (NULL == p) {
    outArgument0.drop () ;
    outArgument1.drop () ;
    outArgument2.drop () ;
    outArgument3.drop () ;
    outArgument4.drop () ;
    outArgument5.drop () ;
    outArgument6.drop () ;
    outArgument7.drop () ;
    outArgument8.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_M_5F_tasks) ;
    outArgument0 = p->mProperty_mIndex ;
    outArgument1 = p->mProperty_mPriority ;
    outArgument2 = p->mProperty_mOffset ;
    outArgument3 = p->mProperty_mDeadline ;
    outArgument4 = p->mProperty_mDurationMin ;
    outArgument5 = p->mProperty_mDurationMax ;
    outArgument6 = p->mProperty_mProcessor ;
    outArgument7 = p->mProperty_mPeriod ;
    outArgument8 = p->mProperty_mTaskKind ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_uint GALGAS_M_5F_tasks::getter_mIndexForKey (const GALGAS_string & inKey,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_M_5F_tasks * p = (const cMapElement_M_5F_tasks *) attributes ;
  GALGAS_uint result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_M_5F_tasks) ;
    result = p->mProperty_mIndex ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_luint GALGAS_M_5F_tasks::getter_mPriorityForKey (const GALGAS_string & inKey,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_M_5F_tasks * p = (const cMapElement_M_5F_tasks *) attributes ;
  GALGAS_luint result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_M_5F_tasks) ;
    result = p->mProperty_mPriority ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_luint GALGAS_M_5F_tasks::getter_mOffsetForKey (const GALGAS_string & inKey,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_M_5F_tasks * p = (const cMapElement_M_5F_tasks *) attributes ;
  GALGAS_luint result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_M_5F_tasks) ;
    result = p->mProperty_mOffset ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_luint GALGAS_M_5F_tasks::getter_mDeadlineForKey (const GALGAS_string & inKey,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_M_5F_tasks * p = (const cMapElement_M_5F_tasks *) attributes ;
  GALGAS_luint result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_M_5F_tasks) ;
    result = p->mProperty_mDeadline ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_luint GALGAS_M_5F_tasks::getter_mDurationMinForKey (const GALGAS_string & inKey,
                                                           C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_M_5F_tasks * p = (const cMapElement_M_5F_tasks *) attributes ;
  GALGAS_luint result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_M_5F_tasks) ;
    result = p->mProperty_mDurationMin ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_luint GALGAS_M_5F_tasks::getter_mDurationMaxForKey (const GALGAS_string & inKey,
                                                           C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_M_5F_tasks * p = (const cMapElement_M_5F_tasks *) attributes ;
  GALGAS_luint result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_M_5F_tasks) ;
    result = p->mProperty_mDurationMax ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_uint GALGAS_M_5F_tasks::getter_mProcessorForKey (const GALGAS_string & inKey,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_M_5F_tasks * p = (const cMapElement_M_5F_tasks *) attributes ;
  GALGAS_uint result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_M_5F_tasks) ;
    result = p->mProperty_mProcessor ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_luint GALGAS_M_5F_tasks::getter_mPeriodForKey (const GALGAS_string & inKey,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_M_5F_tasks * p = (const cMapElement_M_5F_tasks *) attributes ;
  GALGAS_luint result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_M_5F_tasks) ;
    result = p->mProperty_mPeriod ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_AC_5F_task GALGAS_M_5F_tasks::getter_mTaskKindForKey (const GALGAS_string & inKey,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_M_5F_tasks * p = (const cMapElement_M_5F_tasks *) attributes ;
  GALGAS_AC_5F_task result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_M_5F_tasks) ;
    result = p->mProperty_mTaskKind ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void GALGAS_M_5F_tasks::setter_setMIndexForKey (GALGAS_uint inAttributeValue,
                                                GALGAS_string inKey,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, true, inCompiler COMMA_THERE) ;
  cMapElement_M_5F_tasks * p = (cMapElement_M_5F_tasks *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_M_5F_tasks) ;
    p->mProperty_mIndex = inAttributeValue ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void GALGAS_M_5F_tasks::setter_setMPriorityForKey (GALGAS_luint inAttributeValue,
                                                   GALGAS_string inKey,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, true, inCompiler COMMA_THERE) ;
  cMapElement_M_5F_tasks * p = (cMapElement_M_5F_tasks *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_M_5F_tasks) ;
    p->mProperty_mPriority = inAttributeValue ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void GALGAS_M_5F_tasks::setter_setMOffsetForKey (GALGAS_luint inAttributeValue,
                                                 GALGAS_string inKey,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, true, inCompiler COMMA_THERE) ;
  cMapElement_M_5F_tasks * p = (cMapElement_M_5F_tasks *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_M_5F_tasks) ;
    p->mProperty_mOffset = inAttributeValue ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void GALGAS_M_5F_tasks::setter_setMDeadlineForKey (GALGAS_luint inAttributeValue,
                                                   GALGAS_string inKey,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, true, inCompiler COMMA_THERE) ;
  cMapElement_M_5F_tasks * p = (cMapElement_M_5F_tasks *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_M_5F_tasks) ;
    p->mProperty_mDeadline = inAttributeValue ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void GALGAS_M_5F_tasks::setter_setMDurationMinForKey (GALGAS_luint inAttributeValue,
                                                      GALGAS_string inKey,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, true, inCompiler COMMA_THERE) ;
  cMapElement_M_5F_tasks * p = (cMapElement_M_5F_tasks *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_M_5F_tasks) ;
    p->mProperty_mDurationMin = inAttributeValue ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void GALGAS_M_5F_tasks::setter_setMDurationMaxForKey (GALGAS_luint inAttributeValue,
                                                      GALGAS_string inKey,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, true, inCompiler COMMA_THERE) ;
  cMapElement_M_5F_tasks * p = (cMapElement_M_5F_tasks *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_M_5F_tasks) ;
    p->mProperty_mDurationMax = inAttributeValue ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void GALGAS_M_5F_tasks::setter_setMProcessorForKey (GALGAS_uint inAttributeValue,
                                                    GALGAS_string inKey,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, true, inCompiler COMMA_THERE) ;
  cMapElement_M_5F_tasks * p = (cMapElement_M_5F_tasks *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_M_5F_tasks) ;
    p->mProperty_mProcessor = inAttributeValue ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void GALGAS_M_5F_tasks::setter_setMPeriodForKey (GALGAS_luint inAttributeValue,
                                                 GALGAS_string inKey,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, true, inCompiler COMMA_THERE) ;
  cMapElement_M_5F_tasks * p = (cMapElement_M_5F_tasks *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_M_5F_tasks) ;
    p->mProperty_mPeriod = inAttributeValue ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void GALGAS_M_5F_tasks::setter_setMTaskKindForKey (GALGAS_AC_5F_task inAttributeValue,
                                                   GALGAS_string inKey,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, true, inCompiler COMMA_THERE) ;
  cMapElement_M_5F_tasks * p = (cMapElement_M_5F_tasks *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_M_5F_tasks) ;
    p->mProperty_mTaskKind = inAttributeValue ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

cMapElement_M_5F_tasks * GALGAS_M_5F_tasks::readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                               const GALGAS_string & inKey
                                                                               COMMA_LOCATION_ARGS) {
  cMapElement_M_5F_tasks * result = (cMapElement_M_5F_tasks *) searchForReadWriteAttribute (inKey, false, inCompiler COMMA_THERE) ;
  macroNullOrValidSharedObject (result, cMapElement_M_5F_tasks) ;
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

cEnumerator_M_5F_tasks::cEnumerator_M_5F_tasks (const GALGAS_M_5F_tasks & inEnumeratedObject,
                                                const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_M_5F_tasks_2D_element cEnumerator_M_5F_tasks::current (LOCATION_ARGS) const {
  const cMapElement_M_5F_tasks * p = (const cMapElement_M_5F_tasks *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_M_5F_tasks) ;
  return GALGAS_M_5F_tasks_2D_element (p->mProperty_lkey, p->mProperty_mIndex, p->mProperty_mPriority, p->mProperty_mOffset, p->mProperty_mDeadline, p->mProperty_mDurationMin, p->mProperty_mDurationMax, p->mProperty_mProcessor, p->mProperty_mPeriod, p->mProperty_mTaskKind) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_lstring cEnumerator_M_5F_tasks::current_lkey (LOCATION_ARGS) const {
  const cMapElement * p = (const cMapElement *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement) ;
  return p->mProperty_lkey ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_uint cEnumerator_M_5F_tasks::current_mIndex (LOCATION_ARGS) const {
  const cMapElement_M_5F_tasks * p = (const cMapElement_M_5F_tasks *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_M_5F_tasks) ;
  return p->mProperty_mIndex ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_luint cEnumerator_M_5F_tasks::current_mPriority (LOCATION_ARGS) const {
  const cMapElement_M_5F_tasks * p = (const cMapElement_M_5F_tasks *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_M_5F_tasks) ;
  return p->mProperty_mPriority ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_luint cEnumerator_M_5F_tasks::current_mOffset (LOCATION_ARGS) const {
  const cMapElement_M_5F_tasks * p = (const cMapElement_M_5F_tasks *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_M_5F_tasks) ;
  return p->mProperty_mOffset ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_luint cEnumerator_M_5F_tasks::current_mDeadline (LOCATION_ARGS) const {
  const cMapElement_M_5F_tasks * p = (const cMapElement_M_5F_tasks *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_M_5F_tasks) ;
  return p->mProperty_mDeadline ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_luint cEnumerator_M_5F_tasks::current_mDurationMin (LOCATION_ARGS) const {
  const cMapElement_M_5F_tasks * p = (const cMapElement_M_5F_tasks *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_M_5F_tasks) ;
  return p->mProperty_mDurationMin ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_luint cEnumerator_M_5F_tasks::current_mDurationMax (LOCATION_ARGS) const {
  const cMapElement_M_5F_tasks * p = (const cMapElement_M_5F_tasks *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_M_5F_tasks) ;
  return p->mProperty_mDurationMax ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_uint cEnumerator_M_5F_tasks::current_mProcessor (LOCATION_ARGS) const {
  const cMapElement_M_5F_tasks * p = (const cMapElement_M_5F_tasks *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_M_5F_tasks) ;
  return p->mProperty_mProcessor ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_luint cEnumerator_M_5F_tasks::current_mPeriod (LOCATION_ARGS) const {
  const cMapElement_M_5F_tasks * p = (const cMapElement_M_5F_tasks *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_M_5F_tasks) ;
  return p->mProperty_mPeriod ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_AC_5F_task cEnumerator_M_5F_tasks::current_mTaskKind (LOCATION_ARGS) const {
  const cMapElement_M_5F_tasks * p = (const cMapElement_M_5F_tasks *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_M_5F_tasks) ;
  return p->mProperty_mTaskKind ;
}



//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                                    @M_tasks type                                                    *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_M_5F_tasks ("M_tasks",
                                   NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

const C_galgas_type_descriptor * GALGAS_M_5F_tasks::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_M_5F_tasks ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

AC_GALGAS_root * GALGAS_M_5F_tasks::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_M_5F_tasks (*this)) ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_M_5F_tasks GALGAS_M_5F_tasks::extractObject (const GALGAS_object & inObject,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  GALGAS_M_5F_tasks result ;
  const GALGAS_M_5F_tasks * p = (const GALGAS_M_5F_tasks *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_M_5F_tasks *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("M_tasks", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}



//---------------------------------------------------------------------------------------------------------------------*

void cParser_oa_5F_parser::rule_oa_5F_parser_axiome_i0_ (C_Lexique_oa_5F_scanner * inCompiler) {
  GALGAS_M_5F_processor var_outProcessorMap_484 = GALGAS_M_5F_processor::constructor_emptyMap (SOURCE_FILE ("oa_parser.galgas", 12)) ;
  GALGAS_M_5F_network var_outNetworkMap_536 = GALGAS_M_5F_network::constructor_emptyMap (SOURCE_FILE ("oa_parser.galgas", 13)) ;
  GALGAS_M_5F_messages var_outMessagesMap_588 = GALGAS_M_5F_messages::constructor_emptyMap (SOURCE_FILE ("oa_parser.galgas", 14)) ;
  GALGAS_M_5F_tasks var_outTaskMap_634 = GALGAS_M_5F_tasks::constructor_emptyMap (SOURCE_FILE ("oa_parser.galgas", 15)) ;
  inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_system COMMA_SOURCE_FILE ("oa_parser.galgas", 16)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_oa_5F_parser_0 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_processor COMMA_SOURCE_FILE ("oa_parser.galgas", 19)) ;
      GALGAS_lstring var_processorName_726 ;
      var_processorName_726 = inCompiler->synthetizedAttribute_identifierString () ;
      inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("oa_parser.galgas", 21)) ;
      GALGAS_luint var_step_775 ;
      switch (select_oa_5F_parser_1 (inCompiler)) {
      case 1: {
        var_step_775 = GALGAS_luint::constructor_new (GALGAS_uint ((uint32_t) 1U), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("oa_parser.galgas", 24))  COMMA_SOURCE_FILE ("oa_parser.galgas", 24)) ;
      } break ;
      case 2: {
        inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_scalingfactor COMMA_SOURCE_FILE ("oa_parser.galgas", 26)) ;
        var_step_775 = inCompiler->synthetizedAttribute_ulongValue () ;
        inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("oa_parser.galgas", 27)) ;
        const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, var_step_775.getter_uint (SOURCE_FILE ("oa_parser.galgas", 28)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
        if (kBoolTrue == test_1) {
          TC_Array <C_FixItDescription> fixItArray2 ;
          inCompiler->emitSemanticError (var_step_775.getter_location (SOURCE_FILE ("oa_parser.galgas", 29)), GALGAS_string ("the step value must be > 0"), fixItArray2  COMMA_SOURCE_FILE ("oa_parser.galgas", 29)) ;
        }
      } break ;
      default:
        break ;
      }
      {
      var_outProcessorMap_484.setter_insertKey (var_processorName_726, var_outProcessorMap_484.getter_count (SOURCE_FILE ("oa_parser.galgas", 32)), var_step_775, inCompiler COMMA_SOURCE_FILE ("oa_parser.galgas", 32)) ;
      }
      inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken__3B_ COMMA_SOURCE_FILE ("oa_parser.galgas", 33)) ;
    } break ;
    case 3: {
      GALGAS_bool var_network_1105 ;
      switch (select_oa_5F_parser_2 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_can COMMA_SOURCE_FILE ("oa_parser.galgas", 37)) ;
        var_network_1105 = GALGAS_bool (true) ;
      } break ;
      case 2: {
        inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_van COMMA_SOURCE_FILE ("oa_parser.galgas", 40)) ;
        var_network_1105 = GALGAS_bool (false) ;
      } break ;
      default:
        break ;
      }
      inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_network COMMA_SOURCE_FILE ("oa_parser.galgas", 43)) ;
      GALGAS_lstring var_networkName_1237 ;
      var_networkName_1237 = inCompiler->synthetizedAttribute_identifierString () ;
      inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("oa_parser.galgas", 45)) ;
      GALGAS_luint var_factor_1286 ;
      switch (select_oa_5F_parser_3 (inCompiler)) {
      case 1: {
        var_factor_1286 = GALGAS_luint::constructor_new (GALGAS_uint ((uint32_t) 1U), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("oa_parser.galgas", 48))  COMMA_SOURCE_FILE ("oa_parser.galgas", 48)) ;
      } break ;
      case 2: {
        inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_scalingfactor COMMA_SOURCE_FILE ("oa_parser.galgas", 50)) ;
        var_factor_1286 = inCompiler->synthetizedAttribute_ulongValue () ;
        inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("oa_parser.galgas", 51)) ;
        const enumGalgasBool test_3 = GALGAS_bool (kIsEqual, var_factor_1286.getter_uint (SOURCE_FILE ("oa_parser.galgas", 52)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
        if (kBoolTrue == test_3) {
          TC_Array <C_FixItDescription> fixItArray4 ;
          inCompiler->emitSemanticError (var_factor_1286.getter_location (SOURCE_FILE ("oa_parser.galgas", 53)), GALGAS_string ("the factor value must be > 0"), fixItArray4  COMMA_SOURCE_FILE ("oa_parser.galgas", 53)) ;
        }
      } break ;
      default:
        break ;
      }
      {
      var_outNetworkMap_536.setter_insertKey (var_networkName_1237, var_outNetworkMap_536.getter_count (SOURCE_FILE ("oa_parser.galgas", 56)), var_network_1105, var_factor_1286, inCompiler COMMA_SOURCE_FILE ("oa_parser.galgas", 56)) ;
      }
      inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken__3B_ COMMA_SOURCE_FILE ("oa_parser.galgas", 57)) ;
    } break ;
    case 4: {
      inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_task COMMA_SOURCE_FILE ("oa_parser.galgas", 59)) ;
      GALGAS_lstring var_taskName_1646 ;
      var_taskName_1646 = inCompiler->synthetizedAttribute_identifierString () ;
      inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("oa_parser.galgas", 61)) ;
      inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_priority COMMA_SOURCE_FILE ("oa_parser.galgas", 62)) ;
      GALGAS_luint var_taskPriority_1713 ;
      var_taskPriority_1713 = inCompiler->synthetizedAttribute_ulongValue () ;
      inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("oa_parser.galgas", 64)) ;
      inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_duration COMMA_SOURCE_FILE ("oa_parser.galgas", 65)) ;
      GALGAS_luint var_taskDurationMin_1792 ;
      var_taskDurationMin_1792 = inCompiler->synthetizedAttribute_ulongValue () ;
      inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("oa_parser.galgas", 67)) ;
      inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken__2E__2E_ COMMA_SOURCE_FILE ("oa_parser.galgas", 68)) ;
      GALGAS_luint var_taskDurationMax_1868 ;
      var_taskDurationMax_1868 = inCompiler->synthetizedAttribute_ulongValue () ;
      inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("oa_parser.galgas", 70)) ;
      GALGAS_luint var_taskOffset_1930 ;
      GALGAS_bool var_explicitOffset_1955 ;
      switch (select_oa_5F_parser_4 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_offset COMMA_SOURCE_FILE ("oa_parser.galgas", 74)) ;
        var_taskOffset_1930 = inCompiler->synthetizedAttribute_ulongValue () ;
        inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("oa_parser.galgas", 75)) ;
        var_explicitOffset_1955 = GALGAS_bool (true) ;
      } break ;
      case 2: {
        var_taskOffset_1930 = GALGAS_luint::constructor_new (GALGAS_uint ((uint32_t) 0U), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("oa_parser.galgas", 78))  COMMA_SOURCE_FILE ("oa_parser.galgas", 78)) ;
        var_explicitOffset_1955 = GALGAS_bool (false) ;
      } break ;
      default:
        break ;
      }
      GALGAS_luint var_taskDeadline_2168 ;
      switch (select_oa_5F_parser_5 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_deadline COMMA_SOURCE_FILE ("oa_parser.galgas", 83)) ;
        var_taskDeadline_2168 = inCompiler->synthetizedAttribute_ulongValue () ;
        inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("oa_parser.galgas", 84)) ;
      } break ;
      case 2: {
        var_taskDeadline_2168 = GALGAS_luint::constructor_new (GALGAS_uint ((uint32_t) 4294967295U), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("oa_parser.galgas", 86))  COMMA_SOURCE_FILE ("oa_parser.galgas", 86)) ;
      } break ;
      default:
        break ;
      }
      GALGAS_AC_5F_task var_taskKind_2336 ;
      GALGAS_uint var_taskProcessorIndex_2365 ;
      GALGAS_luint var_taskPeriod_2387 ;
      switch (select_oa_5F_parser_6 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_period COMMA_SOURCE_FILE ("oa_parser.galgas", 92)) ;
        var_taskPeriod_2387 = inCompiler->synthetizedAttribute_ulongValue () ;
        inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("oa_parser.galgas", 93)) ;
        inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_processor COMMA_SOURCE_FILE ("oa_parser.galgas", 94)) ;
        GALGAS_lstring var_taskProcessorName_2501 ;
        var_taskProcessorName_2501 = inCompiler->synthetizedAttribute_identifierString () ;
        inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("oa_parser.galgas", 96)) ;
        GALGAS_luint joker_2614 ; // Joker input parameter
        var_outProcessorMap_484.method_searchKey (var_taskProcessorName_2501, var_taskProcessorIndex_2365, joker_2614, inCompiler COMMA_SOURCE_FILE ("oa_parser.galgas", 97)) ;
        var_taskKind_2336 = GALGAS_C_5F_independantTask::constructor_new (SOURCE_FILE ("oa_parser.galgas", 98)) ;
      } break ;
      case 2: {
        inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_on COMMA_SOURCE_FILE ("oa_parser.galgas", 100)) ;
        const enumGalgasBool test_5 = var_explicitOffset_1955.boolEnum () ;
        if (kBoolTrue == test_5) {
          TC_Array <C_FixItDescription> fixItArray6 ;
          inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("oa_parser.galgas", 102)), GALGAS_string ("A dependant task cannot have an offset"), fixItArray6  COMMA_SOURCE_FILE ("oa_parser.galgas", 102)) ;
        }
        switch (select_oa_5F_parser_7 (inCompiler)) {
        case 1: {
          inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_task COMMA_SOURCE_FILE ("oa_parser.galgas", 105)) ;
          GALGAS_lstring var_masterTaskName_2846 ;
          var_masterTaskName_2846 = inCompiler->synthetizedAttribute_identifierString () ;
          inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("oa_parser.galgas", 107)) ;
          GALGAS_luint var_every_2905 ;
          switch (select_oa_5F_parser_8 (inCompiler)) {
          case 1: {
            var_every_2905 = GALGAS_luint::constructor_new (GALGAS_uint ((uint32_t) 1U), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("oa_parser.galgas", 110))  COMMA_SOURCE_FILE ("oa_parser.galgas", 110)) ;
          } break ;
          case 2: {
            inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_every COMMA_SOURCE_FILE ("oa_parser.galgas", 112)) ;
            var_every_2905 = inCompiler->synthetizedAttribute_ulongValue () ;
            inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("oa_parser.galgas", 113)) ;
          } break ;
          default:
            break ;
          }
          GALGAS_uint var_masterTaskIndex_3079 ;
          GALGAS_luint joker_3144 ; // Joker input parameter
          GALGAS_luint joker_3147 ; // Joker input parameter
          GALGAS_luint joker_3150 ; // Joker input parameter
          GALGAS_luint joker_3153 ; // Joker input parameter
          GALGAS_luint joker_3156 ; // Joker input parameter
          GALGAS_AC_5F_task joker_3191 ; // Joker input parameter
          var_outTaskMap_634.method_searchKey (var_masterTaskName_2846, var_masterTaskIndex_3079, joker_3144, joker_3147, joker_3150, joker_3153, joker_3156, var_taskProcessorIndex_2365, var_taskPeriod_2387, joker_3191, inCompiler COMMA_SOURCE_FILE ("oa_parser.galgas", 116)) ;
          var_taskKind_2336 = GALGAS_C_5F_taskDependsFromTask::constructor_new (var_masterTaskIndex_3079, var_every_2905  COMMA_SOURCE_FILE ("oa_parser.galgas", 117)) ;
        } break ;
        case 2: {
          inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_message COMMA_SOURCE_FILE ("oa_parser.galgas", 119)) ;
          GALGAS_lstring var_masterMessageName_3329 ;
          var_masterMessageName_3329 = inCompiler->synthetizedAttribute_identifierString () ;
          inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("oa_parser.galgas", 121)) ;
          GALGAS_uint var_masterMessageIndex_3403 ;
          GALGAS_luint joker_3478 ; // Joker input parameter
          GALGAS_uint joker_3481 ; // Joker input parameter
          GALGAS_luint joker_3484 ; // Joker input parameter
          GALGAS_luint joker_3487 ; // Joker input parameter
          GALGAS_luint joker_3490 ; // Joker input parameter
          GALGAS_luint joker_3493 ; // Joker input parameter
          GALGAS_AC_5F_canMessage joker_3508 ; // Joker input parameter
          var_outMessagesMap_588.method_searchKey (var_masterMessageName_3329, var_masterMessageIndex_3403, joker_3478, joker_3481, joker_3484, joker_3487, joker_3490, joker_3493, var_taskPeriod_2387, joker_3508, inCompiler COMMA_SOURCE_FILE ("oa_parser.galgas", 123)) ;
          inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_processor COMMA_SOURCE_FILE ("oa_parser.galgas", 124)) ;
          GALGAS_lstring var_taskProcessorName_3565 ;
          var_taskProcessorName_3565 = inCompiler->synthetizedAttribute_identifierString () ;
          inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("oa_parser.galgas", 126)) ;
          GALGAS_luint var_every_3627 ;
          switch (select_oa_5F_parser_9 (inCompiler)) {
          case 1: {
            var_every_3627 = GALGAS_luint::constructor_new (GALGAS_uint ((uint32_t) 1U), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("oa_parser.galgas", 129))  COMMA_SOURCE_FILE ("oa_parser.galgas", 129)) ;
          } break ;
          case 2: {
            inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_every COMMA_SOURCE_FILE ("oa_parser.galgas", 131)) ;
            var_every_3627 = inCompiler->synthetizedAttribute_ulongValue () ;
            inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("oa_parser.galgas", 132)) ;
          } break ;
          default:
            break ;
          }
          GALGAS_luint joker_3847 ; // Joker input parameter
          var_outProcessorMap_484.method_searchKey (var_taskProcessorName_3565, var_taskProcessorIndex_2365, joker_3847, inCompiler COMMA_SOURCE_FILE ("oa_parser.galgas", 134)) ;
          var_taskKind_2336 = GALGAS_C_5F_taskDependsFromMessage::constructor_new (var_masterMessageIndex_3403, var_every_3627  COMMA_SOURCE_FILE ("oa_parser.galgas", 135)) ;
        } break ;
        default:
          break ;
        }
      } break ;
      default:
        break ;
      }
      {
      var_outTaskMap_634.setter_insertKey (var_taskName_1646, var_outTaskMap_634.getter_count (SOURCE_FILE ("oa_parser.galgas", 138)), var_taskPriority_1713, var_taskOffset_1930, var_taskDeadline_2168, var_taskDurationMin_1792, var_taskDurationMax_1868, var_taskProcessorIndex_2365, var_taskPeriod_2387, var_taskKind_2336, inCompiler COMMA_SOURCE_FILE ("oa_parser.galgas", 138)) ;
      }
      inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken__3B_ COMMA_SOURCE_FILE ("oa_parser.galgas", 147)) ;
    } break ;
    case 5: {
      GALGAS_luint var_messageClass_4480 ;
      switch (select_oa_5F_parser_10 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_standard COMMA_SOURCE_FILE ("oa_parser.galgas", 151)) ;
        var_messageClass_4480 = GALGAS_luint::constructor_new (GALGAS_uint ((uint32_t) 0U), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("oa_parser.galgas", 152))  COMMA_SOURCE_FILE ("oa_parser.galgas", 152)) ;
        inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_message COMMA_SOURCE_FILE ("oa_parser.galgas", 153)) ;
      } break ;
      case 2: {
        inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_extended COMMA_SOURCE_FILE ("oa_parser.galgas", 155)) ;
        var_messageClass_4480 = GALGAS_luint::constructor_new (GALGAS_uint ((uint32_t) 1U), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("oa_parser.galgas", 156))  COMMA_SOURCE_FILE ("oa_parser.galgas", 156)) ;
        inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_message COMMA_SOURCE_FILE ("oa_parser.galgas", 157)) ;
      } break ;
      case 3: {
        inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_message COMMA_SOURCE_FILE ("oa_parser.galgas", 159)) ;
        var_messageClass_4480 = GALGAS_luint::constructor_new (GALGAS_uint ((uint32_t) 2U), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("oa_parser.galgas", 160))  COMMA_SOURCE_FILE ("oa_parser.galgas", 160)) ;
      } break ;
      default:
        break ;
      }
      GALGAS_lstring var_messageName_4785 ;
      var_messageName_4785 = inCompiler->synthetizedAttribute_identifierString () ;
      inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("oa_parser.galgas", 163)) ;
      inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_network COMMA_SOURCE_FILE ("oa_parser.galgas", 164)) ;
      GALGAS_lstring var_networkName_4855 ;
      var_networkName_4855 = inCompiler->synthetizedAttribute_identifierString () ;
      inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("oa_parser.galgas", 166)) ;
      GALGAS_uint var_networkIndex_4909 ;
      GALGAS_bool var_CANnetwork_4930 ;
      GALGAS_luint joker_5000 ; // Joker input parameter
      var_outNetworkMap_536.method_searchKey (var_networkName_4855, var_networkIndex_4909, var_CANnetwork_4930, joker_5000, inCompiler COMMA_SOURCE_FILE ("oa_parser.galgas", 169)) ;
      const enumGalgasBool test_7 = var_CANnetwork_4930.operator_and (GALGAS_bool (kIsEqual, var_messageClass_4480.getter_uint (SOURCE_FILE ("oa_parser.galgas", 170)).objectCompare (GALGAS_uint ((uint32_t) 2U))) COMMA_SOURCE_FILE ("oa_parser.galgas", 170)).boolEnum () ;
      if (kBoolTrue == test_7) {
        TC_Array <C_FixItDescription> fixItArray8 ;
        inCompiler->emitSemanticError (var_messageClass_4480.getter_location (SOURCE_FILE ("oa_parser.galgas", 171)), GALGAS_string ("a CAN message must be either standard either extended"), fixItArray8  COMMA_SOURCE_FILE ("oa_parser.galgas", 171)) ;
      }else if (kBoolFalse == test_7) {
        const enumGalgasBool test_9 = var_CANnetwork_4930.operator_not (SOURCE_FILE ("oa_parser.galgas", 172)).operator_and (GALGAS_bool (kIsNotEqual, var_messageClass_4480.getter_uint (SOURCE_FILE ("oa_parser.galgas", 172)).objectCompare (GALGAS_uint ((uint32_t) 2U))) COMMA_SOURCE_FILE ("oa_parser.galgas", 172)).boolEnum () ;
        if (kBoolTrue == test_9) {
          TC_Array <C_FixItDescription> fixItArray10 ;
          inCompiler->emitSemanticError (var_messageClass_4480.getter_location (SOURCE_FILE ("oa_parser.galgas", 173)), GALGAS_string ("a VAN message cannot be standard or extended"), fixItArray10  COMMA_SOURCE_FILE ("oa_parser.galgas", 173)) ;
        }
      }
      inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_length COMMA_SOURCE_FILE ("oa_parser.galgas", 175)) ;
      GALGAS_luint var_bytesCount_5315 ;
      var_bytesCount_5315 = inCompiler->synthetizedAttribute_ulongValue () ;
      inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("oa_parser.galgas", 177)) ;
      const enumGalgasBool test_11 = var_CANnetwork_4930.operator_and (GALGAS_bool (kIsStrictSup, var_bytesCount_5315.getter_uint (SOURCE_FILE ("oa_parser.galgas", 178)).objectCompare (GALGAS_uint ((uint32_t) 8U))) COMMA_SOURCE_FILE ("oa_parser.galgas", 178)).boolEnum () ;
      if (kBoolTrue == test_11) {
        TC_Array <C_FixItDescription> fixItArray12 ;
        inCompiler->emitSemanticError (var_bytesCount_5315.getter_location (SOURCE_FILE ("oa_parser.galgas", 179)), GALGAS_string ("CAN message length must be <= 8 bytes"), fixItArray12  COMMA_SOURCE_FILE ("oa_parser.galgas", 179)) ;
      }else if (kBoolFalse == test_11) {
        const enumGalgasBool test_13 = var_CANnetwork_4930.operator_not (SOURCE_FILE ("oa_parser.galgas", 180)).operator_and (GALGAS_bool (kIsStrictSup, var_bytesCount_5315.getter_uint (SOURCE_FILE ("oa_parser.galgas", 180)).objectCompare (GALGAS_uint ((uint32_t) 28U))) COMMA_SOURCE_FILE ("oa_parser.galgas", 180)).boolEnum () ;
        if (kBoolTrue == test_13) {
          TC_Array <C_FixItDescription> fixItArray14 ;
          inCompiler->emitSemanticError (var_bytesCount_5315.getter_location (SOURCE_FILE ("oa_parser.galgas", 181)), GALGAS_string ("VAN message must be <= 28 bytes"), fixItArray14  COMMA_SOURCE_FILE ("oa_parser.galgas", 181)) ;
        }
      }
      inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_priority COMMA_SOURCE_FILE ("oa_parser.galgas", 183)) ;
      GALGAS_luint var_priority_5625 ;
      var_priority_5625 = inCompiler->synthetizedAttribute_ulongValue () ;
      inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("oa_parser.galgas", 185)) ;
      GALGAS_luint var_offset_5676 ;
      GALGAS_bool var_explicitOffset_5701 ;
      switch (select_oa_5F_parser_11 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_offset COMMA_SOURCE_FILE ("oa_parser.galgas", 189)) ;
        var_offset_5676 = inCompiler->synthetizedAttribute_ulongValue () ;
        inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("oa_parser.galgas", 190)) ;
        var_explicitOffset_5701 = GALGAS_bool (true) ;
      } break ;
      case 2: {
        var_offset_5676 = GALGAS_luint::constructor_new (GALGAS_uint ((uint32_t) 0U), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("oa_parser.galgas", 193))  COMMA_SOURCE_FILE ("oa_parser.galgas", 193)) ;
        var_explicitOffset_5701 = GALGAS_bool (false) ;
      } break ;
      default:
        break ;
      }
      GALGAS_luint var_deadline_5901 ;
      switch (select_oa_5F_parser_12 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_deadline COMMA_SOURCE_FILE ("oa_parser.galgas", 198)) ;
        var_deadline_5901 = inCompiler->synthetizedAttribute_ulongValue () ;
        inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("oa_parser.galgas", 199)) ;
      } break ;
      case 2: {
        var_deadline_5901 = GALGAS_luint::constructor_new (GALGAS_uint ((uint32_t) 4294967295U), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("oa_parser.galgas", 201))  COMMA_SOURCE_FILE ("oa_parser.galgas", 201)) ;
      } break ;
      default:
        break ;
      }
      GALGAS_AC_5F_canMessage var_messageKind_6070 ;
      GALGAS_luint var_period_6088 ;
      switch (select_oa_5F_parser_13 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_period COMMA_SOURCE_FILE ("oa_parser.galgas", 206)) ;
        var_period_6088 = inCompiler->synthetizedAttribute_ulongValue () ;
        inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("oa_parser.galgas", 207)) ;
        var_messageKind_6070 = GALGAS_C_5F_canIndependantMessage::constructor_new (SOURCE_FILE ("oa_parser.galgas", 208)) ;
      } break ;
      case 2: {
        inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_on COMMA_SOURCE_FILE ("oa_parser.galgas", 210)) ;
        const enumGalgasBool test_15 = var_explicitOffset_5701.boolEnum () ;
        if (kBoolTrue == test_15) {
          TC_Array <C_FixItDescription> fixItArray16 ;
          inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("oa_parser.galgas", 212)), GALGAS_string ("A dependant task cannot have an offset"), fixItArray16  COMMA_SOURCE_FILE ("oa_parser.galgas", 212)) ;
        }
        switch (select_oa_5F_parser_14 (inCompiler)) {
        case 1: {
          inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_message COMMA_SOURCE_FILE ("oa_parser.galgas", 215)) ;
          GALGAS_lstring var_name_6379 ;
          var_name_6379 = inCompiler->synthetizedAttribute_identifierString () ;
          inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("oa_parser.galgas", 217)) ;
          GALGAS_uint var_messageIndex_6434 ;
          GALGAS_luint joker_6490 ; // Joker input parameter
          GALGAS_uint joker_6493 ; // Joker input parameter
          GALGAS_luint joker_6496 ; // Joker input parameter
          GALGAS_luint joker_6499 ; // Joker input parameter
          GALGAS_luint joker_6502 ; // Joker input parameter
          GALGAS_luint joker_6505 ; // Joker input parameter
          GALGAS_AC_5F_canMessage joker_6516 ; // Joker input parameter
          var_outMessagesMap_588.method_searchKey (var_name_6379, var_messageIndex_6434, joker_6490, joker_6493, joker_6496, joker_6499, joker_6502, joker_6505, var_period_6088, joker_6516, inCompiler COMMA_SOURCE_FILE ("oa_parser.galgas", 219)) ;
          var_messageKind_6070 = GALGAS_C_5F_canMessageFromMessage::constructor_new (var_messageIndex_6434  COMMA_SOURCE_FILE ("oa_parser.galgas", 220)) ;
        } break ;
        case 2: {
          inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_task COMMA_SOURCE_FILE ("oa_parser.galgas", 222)) ;
          GALGAS_lstring var_taskName_6637 ;
          var_taskName_6637 = inCompiler->synthetizedAttribute_identifierString () ;
          inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("oa_parser.galgas", 224)) ;
          GALGAS_uint var_taskIndex_6693 ;
          GALGAS_luint joker_6746 ; // Joker input parameter
          GALGAS_luint joker_6749 ; // Joker input parameter
          GALGAS_luint joker_6752 ; // Joker input parameter
          GALGAS_luint joker_6755 ; // Joker input parameter
          GALGAS_luint joker_6758 ; // Joker input parameter
          GALGAS_uint joker_6761 ; // Joker input parameter
          GALGAS_AC_5F_task joker_6772 ; // Joker input parameter
          var_outTaskMap_634.method_searchKey (var_taskName_6637, var_taskIndex_6693, joker_6746, joker_6749, joker_6752, joker_6755, joker_6758, joker_6761, var_period_6088, joker_6772, inCompiler COMMA_SOURCE_FILE ("oa_parser.galgas", 226)) ;
          var_messageKind_6070 = GALGAS_C_5F_canMessageFromTask::constructor_new (var_taskIndex_6693  COMMA_SOURCE_FILE ("oa_parser.galgas", 227)) ;
        } break ;
        default:
          break ;
        }
      } break ;
      default:
        break ;
      }
      {
      var_outMessagesMap_588.setter_insertKey (var_messageName_4785, var_outMessagesMap_588.getter_count (SOURCE_FILE ("oa_parser.galgas", 230)), var_messageClass_4480, var_networkIndex_4909, var_bytesCount_5315, var_priority_5625, var_offset_5676, var_deadline_5901, var_period_6088, var_messageKind_6070, inCompiler COMMA_SOURCE_FILE ("oa_parser.galgas", 230)) ;
      }
      inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken__3B_ COMMA_SOURCE_FILE ("oa_parser.galgas", 232)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_end COMMA_SOURCE_FILE ("oa_parser.galgas", 234)) ;
  {
  routine_performComputations (var_outProcessorMap_484, var_outNetworkMap_536, var_outMessagesMap_588, var_outTaskMap_634, inCompiler  COMMA_SOURCE_FILE ("oa_parser.galgas", 235)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_oa_5F_parser::rule_oa_5F_parser_axiome_i0_parse (C_Lexique_oa_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_system COMMA_SOURCE_FILE ("oa_parser.galgas", 16)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_oa_5F_parser_0 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_processor COMMA_SOURCE_FILE ("oa_parser.galgas", 19)) ;
      inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("oa_parser.galgas", 21)) ;
      switch (select_oa_5F_parser_1 (inCompiler)) {
      case 1: {
      } break ;
      case 2: {
        inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_scalingfactor COMMA_SOURCE_FILE ("oa_parser.galgas", 26)) ;
        inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("oa_parser.galgas", 27)) ;
      } break ;
      default:
        break ;
      }
      inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken__3B_ COMMA_SOURCE_FILE ("oa_parser.galgas", 33)) ;
    } break ;
    case 3: {
      switch (select_oa_5F_parser_2 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_can COMMA_SOURCE_FILE ("oa_parser.galgas", 37)) ;
      } break ;
      case 2: {
        inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_van COMMA_SOURCE_FILE ("oa_parser.galgas", 40)) ;
      } break ;
      default:
        break ;
      }
      inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_network COMMA_SOURCE_FILE ("oa_parser.galgas", 43)) ;
      inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("oa_parser.galgas", 45)) ;
      switch (select_oa_5F_parser_3 (inCompiler)) {
      case 1: {
      } break ;
      case 2: {
        inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_scalingfactor COMMA_SOURCE_FILE ("oa_parser.galgas", 50)) ;
        inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("oa_parser.galgas", 51)) ;
      } break ;
      default:
        break ;
      }
      inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken__3B_ COMMA_SOURCE_FILE ("oa_parser.galgas", 57)) ;
    } break ;
    case 4: {
      inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_task COMMA_SOURCE_FILE ("oa_parser.galgas", 59)) ;
      inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("oa_parser.galgas", 61)) ;
      inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_priority COMMA_SOURCE_FILE ("oa_parser.galgas", 62)) ;
      inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("oa_parser.galgas", 64)) ;
      inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_duration COMMA_SOURCE_FILE ("oa_parser.galgas", 65)) ;
      inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("oa_parser.galgas", 67)) ;
      inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken__2E__2E_ COMMA_SOURCE_FILE ("oa_parser.galgas", 68)) ;
      inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("oa_parser.galgas", 70)) ;
      switch (select_oa_5F_parser_4 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_offset COMMA_SOURCE_FILE ("oa_parser.galgas", 74)) ;
        inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("oa_parser.galgas", 75)) ;
      } break ;
      case 2: {
      } break ;
      default:
        break ;
      }
      switch (select_oa_5F_parser_5 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_deadline COMMA_SOURCE_FILE ("oa_parser.galgas", 83)) ;
        inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("oa_parser.galgas", 84)) ;
      } break ;
      case 2: {
      } break ;
      default:
        break ;
      }
      switch (select_oa_5F_parser_6 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_period COMMA_SOURCE_FILE ("oa_parser.galgas", 92)) ;
        inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("oa_parser.galgas", 93)) ;
        inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_processor COMMA_SOURCE_FILE ("oa_parser.galgas", 94)) ;
        inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("oa_parser.galgas", 96)) ;
      } break ;
      case 2: {
        inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_on COMMA_SOURCE_FILE ("oa_parser.galgas", 100)) ;
        switch (select_oa_5F_parser_7 (inCompiler)) {
        case 1: {
          inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_task COMMA_SOURCE_FILE ("oa_parser.galgas", 105)) ;
          inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("oa_parser.galgas", 107)) ;
          switch (select_oa_5F_parser_8 (inCompiler)) {
          case 1: {
          } break ;
          case 2: {
            inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_every COMMA_SOURCE_FILE ("oa_parser.galgas", 112)) ;
            inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("oa_parser.galgas", 113)) ;
          } break ;
          default:
            break ;
          }
        } break ;
        case 2: {
          inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_message COMMA_SOURCE_FILE ("oa_parser.galgas", 119)) ;
          inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("oa_parser.galgas", 121)) ;
          inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_processor COMMA_SOURCE_FILE ("oa_parser.galgas", 124)) ;
          inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("oa_parser.galgas", 126)) ;
          switch (select_oa_5F_parser_9 (inCompiler)) {
          case 1: {
          } break ;
          case 2: {
            inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_every COMMA_SOURCE_FILE ("oa_parser.galgas", 131)) ;
            inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("oa_parser.galgas", 132)) ;
          } break ;
          default:
            break ;
          }
        } break ;
        default:
          break ;
        }
      } break ;
      default:
        break ;
      }
      inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken__3B_ COMMA_SOURCE_FILE ("oa_parser.galgas", 147)) ;
    } break ;
    case 5: {
      switch (select_oa_5F_parser_10 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_standard COMMA_SOURCE_FILE ("oa_parser.galgas", 151)) ;
        inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_message COMMA_SOURCE_FILE ("oa_parser.galgas", 153)) ;
      } break ;
      case 2: {
        inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_extended COMMA_SOURCE_FILE ("oa_parser.galgas", 155)) ;
        inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_message COMMA_SOURCE_FILE ("oa_parser.galgas", 157)) ;
      } break ;
      case 3: {
        inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_message COMMA_SOURCE_FILE ("oa_parser.galgas", 159)) ;
      } break ;
      default:
        break ;
      }
      inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("oa_parser.galgas", 163)) ;
      inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_network COMMA_SOURCE_FILE ("oa_parser.galgas", 164)) ;
      inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("oa_parser.galgas", 166)) ;
      inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_length COMMA_SOURCE_FILE ("oa_parser.galgas", 175)) ;
      inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("oa_parser.galgas", 177)) ;
      inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_priority COMMA_SOURCE_FILE ("oa_parser.galgas", 183)) ;
      inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("oa_parser.galgas", 185)) ;
      switch (select_oa_5F_parser_11 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_offset COMMA_SOURCE_FILE ("oa_parser.galgas", 189)) ;
        inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("oa_parser.galgas", 190)) ;
      } break ;
      case 2: {
      } break ;
      default:
        break ;
      }
      switch (select_oa_5F_parser_12 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_deadline COMMA_SOURCE_FILE ("oa_parser.galgas", 198)) ;
        inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("oa_parser.galgas", 199)) ;
      } break ;
      case 2: {
      } break ;
      default:
        break ;
      }
      switch (select_oa_5F_parser_13 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_period COMMA_SOURCE_FILE ("oa_parser.galgas", 206)) ;
        inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("oa_parser.galgas", 207)) ;
      } break ;
      case 2: {
        inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_on COMMA_SOURCE_FILE ("oa_parser.galgas", 210)) ;
        switch (select_oa_5F_parser_14 (inCompiler)) {
        case 1: {
          inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_message COMMA_SOURCE_FILE ("oa_parser.galgas", 215)) ;
          inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("oa_parser.galgas", 217)) ;
        } break ;
        case 2: {
          inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_task COMMA_SOURCE_FILE ("oa_parser.galgas", 222)) ;
          inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("oa_parser.galgas", 224)) ;
        } break ;
        default:
          break ;
        }
      } break ;
      default:
        break ;
      }
      inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken__3B_ COMMA_SOURCE_FILE ("oa_parser.galgas", 232)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->acceptTerminal (C_Lexique_oa_5F_scanner::kToken_end COMMA_SOURCE_FILE ("oa_parser.galgas", 234)) ;
  inCompiler->resetTemplateString () ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//   Object comparison                                                                                                 *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

typeComparisonResult cPtr_C_5F_taskDependsFromTask::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_C_5F_taskDependsFromTask * p = (const cPtr_C_5F_taskDependsFromTask *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_C_5F_taskDependsFromTask) ;
  if (kOperandEqual == result) {
    result = mProperty_mTask.objectCompare (p->mProperty_mTask) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_mEvery.objectCompare (p->mProperty_mEvery) ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*


typeComparisonResult GALGAS_C_5F_taskDependsFromTask::objectCompare (const GALGAS_C_5F_taskDependsFromTask & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_C_5F_taskDependsFromTask::GALGAS_C_5F_taskDependsFromTask (void) :
GALGAS_AC_5F_task () {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_C_5F_taskDependsFromTask GALGAS_C_5F_taskDependsFromTask::constructor_default (LOCATION_ARGS) {
  return GALGAS_C_5F_taskDependsFromTask::constructor_new (GALGAS_uint::constructor_default (HERE),
                                                           GALGAS_luint::constructor_default (HERE)
                                                           COMMA_THERE) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_C_5F_taskDependsFromTask::GALGAS_C_5F_taskDependsFromTask (const cPtr_C_5F_taskDependsFromTask * inSourcePtr) :
GALGAS_AC_5F_task (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_C_5F_taskDependsFromTask) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_C_5F_taskDependsFromTask GALGAS_C_5F_taskDependsFromTask::constructor_new (const GALGAS_uint & inAttribute_mTask,
                                                                                  const GALGAS_luint & inAttribute_mEvery
                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_C_5F_taskDependsFromTask result ;
  if (inAttribute_mTask.isValid () && inAttribute_mEvery.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_C_5F_taskDependsFromTask (inAttribute_mTask, inAttribute_mEvery COMMA_THERE)) ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_uint GALGAS_C_5F_taskDependsFromTask::getter_mTask (UNUSED_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (NULL != mObjectPtr) {
    const cPtr_C_5F_taskDependsFromTask * p = (const cPtr_C_5F_taskDependsFromTask *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_C_5F_taskDependsFromTask) ;
    result = p->mProperty_mTask ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_uint cPtr_C_5F_taskDependsFromTask::getter_mTask (UNUSED_LOCATION_ARGS) const {
  return mProperty_mTask ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_luint GALGAS_C_5F_taskDependsFromTask::getter_mEvery (UNUSED_LOCATION_ARGS) const {
  GALGAS_luint result ;
  if (NULL != mObjectPtr) {
    const cPtr_C_5F_taskDependsFromTask * p = (const cPtr_C_5F_taskDependsFromTask *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_C_5F_taskDependsFromTask) ;
    result = p->mProperty_mEvery ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_luint cPtr_C_5F_taskDependsFromTask::getter_mEvery (UNUSED_LOCATION_ARGS) const {
  return mProperty_mEvery ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                   Pointer class for @C_taskDependsFromTask class                                    *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

cPtr_C_5F_taskDependsFromTask::cPtr_C_5F_taskDependsFromTask (const GALGAS_uint & in_mTask,
                                                              const GALGAS_luint & in_mEvery
                                                              COMMA_LOCATION_ARGS) :
cPtr_AC_5F_task (THERE),
mProperty_mTask (in_mTask),
mProperty_mEvery (in_mEvery) {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

const C_galgas_type_descriptor * cPtr_C_5F_taskDependsFromTask::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_C_5F_taskDependsFromTask ;
}

void cPtr_C_5F_taskDependsFromTask::description (C_String & ioString,
                                                 const int32_t inIndentation) const {
  ioString << "[@C_taskDependsFromTask:" ;
  mProperty_mTask.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_mEvery.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

acPtr_class * cPtr_C_5F_taskDependsFromTask::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_C_5F_taskDependsFromTask (mProperty_mTask, mProperty_mEvery COMMA_THERE)) ;
  return ptr ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                             @C_taskDependsFromTask type                                             *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_C_5F_taskDependsFromTask ("C_taskDependsFromTask",
                                                 & kTypeDescriptor_GALGAS_AC_5F_task) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

const C_galgas_type_descriptor * GALGAS_C_5F_taskDependsFromTask::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_C_5F_taskDependsFromTask ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

AC_GALGAS_root * GALGAS_C_5F_taskDependsFromTask::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_C_5F_taskDependsFromTask (*this)) ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_C_5F_taskDependsFromTask GALGAS_C_5F_taskDependsFromTask::extractObject (const GALGAS_object & inObject,
                                                                                C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_C_5F_taskDependsFromTask result ;
  const GALGAS_C_5F_taskDependsFromTask * p = (const GALGAS_C_5F_taskDependsFromTask *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_C_5F_taskDependsFromTask *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("C_taskDependsFromTask", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//   Object comparison                                                                                                 *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

typeComparisonResult cPtr_C_5F_taskDependsFromMessage::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_C_5F_taskDependsFromMessage * p = (const cPtr_C_5F_taskDependsFromMessage *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_C_5F_taskDependsFromMessage) ;
  if (kOperandEqual == result) {
    result = mProperty_mMessage.objectCompare (p->mProperty_mMessage) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_mEvery.objectCompare (p->mProperty_mEvery) ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*


typeComparisonResult GALGAS_C_5F_taskDependsFromMessage::objectCompare (const GALGAS_C_5F_taskDependsFromMessage & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_C_5F_taskDependsFromMessage::GALGAS_C_5F_taskDependsFromMessage (void) :
GALGAS_AC_5F_task () {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_C_5F_taskDependsFromMessage GALGAS_C_5F_taskDependsFromMessage::constructor_default (LOCATION_ARGS) {
  return GALGAS_C_5F_taskDependsFromMessage::constructor_new (GALGAS_uint::constructor_default (HERE),
                                                              GALGAS_luint::constructor_default (HERE)
                                                              COMMA_THERE) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_C_5F_taskDependsFromMessage::GALGAS_C_5F_taskDependsFromMessage (const cPtr_C_5F_taskDependsFromMessage * inSourcePtr) :
GALGAS_AC_5F_task (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_C_5F_taskDependsFromMessage) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_C_5F_taskDependsFromMessage GALGAS_C_5F_taskDependsFromMessage::constructor_new (const GALGAS_uint & inAttribute_mMessage,
                                                                                        const GALGAS_luint & inAttribute_mEvery
                                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_C_5F_taskDependsFromMessage result ;
  if (inAttribute_mMessage.isValid () && inAttribute_mEvery.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_C_5F_taskDependsFromMessage (inAttribute_mMessage, inAttribute_mEvery COMMA_THERE)) ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_uint GALGAS_C_5F_taskDependsFromMessage::getter_mMessage (UNUSED_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (NULL != mObjectPtr) {
    const cPtr_C_5F_taskDependsFromMessage * p = (const cPtr_C_5F_taskDependsFromMessage *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_C_5F_taskDependsFromMessage) ;
    result = p->mProperty_mMessage ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_uint cPtr_C_5F_taskDependsFromMessage::getter_mMessage (UNUSED_LOCATION_ARGS) const {
  return mProperty_mMessage ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_luint GALGAS_C_5F_taskDependsFromMessage::getter_mEvery (UNUSED_LOCATION_ARGS) const {
  GALGAS_luint result ;
  if (NULL != mObjectPtr) {
    const cPtr_C_5F_taskDependsFromMessage * p = (const cPtr_C_5F_taskDependsFromMessage *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_C_5F_taskDependsFromMessage) ;
    result = p->mProperty_mEvery ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_luint cPtr_C_5F_taskDependsFromMessage::getter_mEvery (UNUSED_LOCATION_ARGS) const {
  return mProperty_mEvery ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                  Pointer class for @C_taskDependsFromMessage class                                  *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

cPtr_C_5F_taskDependsFromMessage::cPtr_C_5F_taskDependsFromMessage (const GALGAS_uint & in_mMessage,
                                                                    const GALGAS_luint & in_mEvery
                                                                    COMMA_LOCATION_ARGS) :
cPtr_AC_5F_task (THERE),
mProperty_mMessage (in_mMessage),
mProperty_mEvery (in_mEvery) {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

const C_galgas_type_descriptor * cPtr_C_5F_taskDependsFromMessage::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_C_5F_taskDependsFromMessage ;
}

void cPtr_C_5F_taskDependsFromMessage::description (C_String & ioString,
                                                    const int32_t inIndentation) const {
  ioString << "[@C_taskDependsFromMessage:" ;
  mProperty_mMessage.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_mEvery.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

acPtr_class * cPtr_C_5F_taskDependsFromMessage::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_C_5F_taskDependsFromMessage (mProperty_mMessage, mProperty_mEvery COMMA_THERE)) ;
  return ptr ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                           @C_taskDependsFromMessage type                                            *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_C_5F_taskDependsFromMessage ("C_taskDependsFromMessage",
                                                    & kTypeDescriptor_GALGAS_AC_5F_task) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

const C_galgas_type_descriptor * GALGAS_C_5F_taskDependsFromMessage::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_C_5F_taskDependsFromMessage ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

AC_GALGAS_root * GALGAS_C_5F_taskDependsFromMessage::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_C_5F_taskDependsFromMessage (*this)) ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_C_5F_taskDependsFromMessage GALGAS_C_5F_taskDependsFromMessage::extractObject (const GALGAS_object & inObject,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_C_5F_taskDependsFromMessage result ;
  const GALGAS_C_5F_taskDependsFromMessage * p = (const GALGAS_C_5F_taskDependsFromMessage *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_C_5F_taskDependsFromMessage *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("C_taskDependsFromMessage", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

#include "utilities/MF_MemoryControl.h"
#include "galgas2/C_galgas_CLI_Options.h"

#include "files/C_FileManager.h"

//---------------------------------------------------------------------------------------------------------------------*


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                   L L ( 1 )    P R O D U C T I O N    R U L E S                                      
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

#define TERMINAL(t)     ((t)+1)
#define NONTERMINAL(nt) ((-nt)-1)
#define END_PRODUCTION  (0)

static const int16_t gProductions_oa_grammar [] = {
// At index 0 : <axiome>, in file 'oa_parser.ggs', line 11
  TERMINAL (C_Lexique_oa_5F_scanner::kToken_system) // $system$
, NONTERMINAL (1) // <select_oa_5F_parser_0>
, TERMINAL (C_Lexique_oa_5F_scanner::kToken_end) // $end$
, END_PRODUCTION
//---- Added productions from 'select' and 'repeat' instructions
// At index 4 : <select_oa_5F_parser_0>, in file 'oa_parser.ggs', line 17
, END_PRODUCTION
// At index 5 : <select_oa_5F_parser_0>, in file 'oa_parser.ggs', line 17
, TERMINAL (C_Lexique_oa_5F_scanner::kToken_processor) // $processor$
, TERMINAL (C_Lexique_oa_5F_scanner::kToken_identifier) // $identifier$
, NONTERMINAL (2) // <select_oa_5F_parser_1>
, TERMINAL (C_Lexique_oa_5F_scanner::kToken__3B_) // $;$
, NONTERMINAL (1) // <select_oa_5F_parser_0>
, END_PRODUCTION
// At index 11 : <select_oa_5F_parser_0>, in file 'oa_parser.ggs', line 17
, NONTERMINAL (3) // <select_oa_5F_parser_2>
, TERMINAL (C_Lexique_oa_5F_scanner::kToken_network) // $network$
, TERMINAL (C_Lexique_oa_5F_scanner::kToken_identifier) // $identifier$
, NONTERMINAL (4) // <select_oa_5F_parser_3>
, TERMINAL (C_Lexique_oa_5F_scanner::kToken__3B_) // $;$
, NONTERMINAL (1) // <select_oa_5F_parser_0>
, END_PRODUCTION
// At index 18 : <select_oa_5F_parser_0>, in file 'oa_parser.ggs', line 17
, TERMINAL (C_Lexique_oa_5F_scanner::kToken_task) // $task$
, TERMINAL (C_Lexique_oa_5F_scanner::kToken_identifier) // $identifier$
, TERMINAL (C_Lexique_oa_5F_scanner::kToken_priority) // $priority$
, TERMINAL (C_Lexique_oa_5F_scanner::kToken_literal_5F_integer) // $literal_integer$
, TERMINAL (C_Lexique_oa_5F_scanner::kToken_duration) // $duration$
, TERMINAL (C_Lexique_oa_5F_scanner::kToken_literal_5F_integer) // $literal_integer$
, TERMINAL (C_Lexique_oa_5F_scanner::kToken__2E__2E_) // $..$
, TERMINAL (C_Lexique_oa_5F_scanner::kToken_literal_5F_integer) // $literal_integer$
, NONTERMINAL (5) // <select_oa_5F_parser_4>
, NONTERMINAL (6) // <select_oa_5F_parser_5>
, NONTERMINAL (7) // <select_oa_5F_parser_6>
, TERMINAL (C_Lexique_oa_5F_scanner::kToken__3B_) // $;$
, NONTERMINAL (1) // <select_oa_5F_parser_0>
, END_PRODUCTION
// At index 32 : <select_oa_5F_parser_0>, in file 'oa_parser.ggs', line 17
, NONTERMINAL (11) // <select_oa_5F_parser_10>
, TERMINAL (C_Lexique_oa_5F_scanner::kToken_identifier) // $identifier$
, TERMINAL (C_Lexique_oa_5F_scanner::kToken_network) // $network$
, TERMINAL (C_Lexique_oa_5F_scanner::kToken_identifier) // $identifier$
, TERMINAL (C_Lexique_oa_5F_scanner::kToken_length) // $length$
, TERMINAL (C_Lexique_oa_5F_scanner::kToken_literal_5F_integer) // $literal_integer$
, TERMINAL (C_Lexique_oa_5F_scanner::kToken_priority) // $priority$
, TERMINAL (C_Lexique_oa_5F_scanner::kToken_literal_5F_integer) // $literal_integer$
, NONTERMINAL (12) // <select_oa_5F_parser_11>
, NONTERMINAL (13) // <select_oa_5F_parser_12>
, NONTERMINAL (14) // <select_oa_5F_parser_13>
, TERMINAL (C_Lexique_oa_5F_scanner::kToken__3B_) // $;$
, NONTERMINAL (1) // <select_oa_5F_parser_0>
, END_PRODUCTION
// At index 46 : <select_oa_5F_parser_1>, in file 'oa_parser.ggs', line 23
, END_PRODUCTION
// At index 47 : <select_oa_5F_parser_1>, in file 'oa_parser.ggs', line 23
, TERMINAL (C_Lexique_oa_5F_scanner::kToken_scalingfactor) // $scalingfactor$
, TERMINAL (C_Lexique_oa_5F_scanner::kToken_literal_5F_integer) // $literal_integer$
, END_PRODUCTION
// At index 50 : <select_oa_5F_parser_2>, in file 'oa_parser.ggs', line 36
, TERMINAL (C_Lexique_oa_5F_scanner::kToken_can) // $can$
, END_PRODUCTION
// At index 52 : <select_oa_5F_parser_2>, in file 'oa_parser.ggs', line 36
, TERMINAL (C_Lexique_oa_5F_scanner::kToken_van) // $van$
, END_PRODUCTION
// At index 54 : <select_oa_5F_parser_3>, in file 'oa_parser.ggs', line 47
, END_PRODUCTION
// At index 55 : <select_oa_5F_parser_3>, in file 'oa_parser.ggs', line 47
, TERMINAL (C_Lexique_oa_5F_scanner::kToken_scalingfactor) // $scalingfactor$
, TERMINAL (C_Lexique_oa_5F_scanner::kToken_literal_5F_integer) // $literal_integer$
, END_PRODUCTION
// At index 58 : <select_oa_5F_parser_4>, in file 'oa_parser.ggs', line 73
, TERMINAL (C_Lexique_oa_5F_scanner::kToken_offset) // $offset$
, TERMINAL (C_Lexique_oa_5F_scanner::kToken_literal_5F_integer) // $literal_integer$
, END_PRODUCTION
// At index 61 : <select_oa_5F_parser_4>, in file 'oa_parser.ggs', line 73
, END_PRODUCTION
// At index 62 : <select_oa_5F_parser_5>, in file 'oa_parser.ggs', line 82
, TERMINAL (C_Lexique_oa_5F_scanner::kToken_deadline) // $deadline$
, TERMINAL (C_Lexique_oa_5F_scanner::kToken_literal_5F_integer) // $literal_integer$
, END_PRODUCTION
// At index 65 : <select_oa_5F_parser_5>, in file 'oa_parser.ggs', line 82
, END_PRODUCTION
// At index 66 : <select_oa_5F_parser_6>, in file 'oa_parser.ggs', line 91
, TERMINAL (C_Lexique_oa_5F_scanner::kToken_period) // $period$
, TERMINAL (C_Lexique_oa_5F_scanner::kToken_literal_5F_integer) // $literal_integer$
, TERMINAL (C_Lexique_oa_5F_scanner::kToken_processor) // $processor$
, TERMINAL (C_Lexique_oa_5F_scanner::kToken_identifier) // $identifier$
, END_PRODUCTION
// At index 71 : <select_oa_5F_parser_6>, in file 'oa_parser.ggs', line 91
, TERMINAL (C_Lexique_oa_5F_scanner::kToken_on) // $on$
, NONTERMINAL (8) // <select_oa_5F_parser_7>
, END_PRODUCTION
// At index 74 : <select_oa_5F_parser_7>, in file 'oa_parser.ggs', line 104
, TERMINAL (C_Lexique_oa_5F_scanner::kToken_task) // $task$
, TERMINAL (C_Lexique_oa_5F_scanner::kToken_identifier) // $identifier$
, NONTERMINAL (9) // <select_oa_5F_parser_8>
, END_PRODUCTION
// At index 78 : <select_oa_5F_parser_7>, in file 'oa_parser.ggs', line 104
, TERMINAL (C_Lexique_oa_5F_scanner::kToken_message) // $message$
, TERMINAL (C_Lexique_oa_5F_scanner::kToken_identifier) // $identifier$
, TERMINAL (C_Lexique_oa_5F_scanner::kToken_processor) // $processor$
, TERMINAL (C_Lexique_oa_5F_scanner::kToken_identifier) // $identifier$
, NONTERMINAL (10) // <select_oa_5F_parser_9>
, END_PRODUCTION
// At index 84 : <select_oa_5F_parser_8>, in file 'oa_parser.ggs', line 109
, END_PRODUCTION
// At index 85 : <select_oa_5F_parser_8>, in file 'oa_parser.ggs', line 109
, TERMINAL (C_Lexique_oa_5F_scanner::kToken_every) // $every$
, TERMINAL (C_Lexique_oa_5F_scanner::kToken_literal_5F_integer) // $literal_integer$
, END_PRODUCTION
// At index 88 : <select_oa_5F_parser_9>, in file 'oa_parser.ggs', line 128
, END_PRODUCTION
// At index 89 : <select_oa_5F_parser_9>, in file 'oa_parser.ggs', line 128
, TERMINAL (C_Lexique_oa_5F_scanner::kToken_every) // $every$
, TERMINAL (C_Lexique_oa_5F_scanner::kToken_literal_5F_integer) // $literal_integer$
, END_PRODUCTION
// At index 92 : <select_oa_5F_parser_10>, in file 'oa_parser.ggs', line 150
, TERMINAL (C_Lexique_oa_5F_scanner::kToken_standard) // $standard$
, TERMINAL (C_Lexique_oa_5F_scanner::kToken_message) // $message$
, END_PRODUCTION
// At index 95 : <select_oa_5F_parser_10>, in file 'oa_parser.ggs', line 150
, TERMINAL (C_Lexique_oa_5F_scanner::kToken_extended) // $extended$
, TERMINAL (C_Lexique_oa_5F_scanner::kToken_message) // $message$
, END_PRODUCTION
// At index 98 : <select_oa_5F_parser_10>, in file 'oa_parser.ggs', line 150
, TERMINAL (C_Lexique_oa_5F_scanner::kToken_message) // $message$
, END_PRODUCTION
// At index 100 : <select_oa_5F_parser_11>, in file 'oa_parser.ggs', line 188
, TERMINAL (C_Lexique_oa_5F_scanner::kToken_offset) // $offset$
, TERMINAL (C_Lexique_oa_5F_scanner::kToken_literal_5F_integer) // $literal_integer$
, END_PRODUCTION
// At index 103 : <select_oa_5F_parser_11>, in file 'oa_parser.ggs', line 188
, END_PRODUCTION
// At index 104 : <select_oa_5F_parser_12>, in file 'oa_parser.ggs', line 197
, TERMINAL (C_Lexique_oa_5F_scanner::kToken_deadline) // $deadline$
, TERMINAL (C_Lexique_oa_5F_scanner::kToken_literal_5F_integer) // $literal_integer$
, END_PRODUCTION
// At index 107 : <select_oa_5F_parser_12>, in file 'oa_parser.ggs', line 197
, END_PRODUCTION
// At index 108 : <select_oa_5F_parser_13>, in file 'oa_parser.ggs', line 205
, TERMINAL (C_Lexique_oa_5F_scanner::kToken_period) // $period$
, TERMINAL (C_Lexique_oa_5F_scanner::kToken_literal_5F_integer) // $literal_integer$
, END_PRODUCTION
// At index 111 : <select_oa_5F_parser_13>, in file 'oa_parser.ggs', line 205
, TERMINAL (C_Lexique_oa_5F_scanner::kToken_on) // $on$
, NONTERMINAL (15) // <select_oa_5F_parser_14>
, END_PRODUCTION
// At index 114 : <select_oa_5F_parser_14>, in file 'oa_parser.ggs', line 214
, TERMINAL (C_Lexique_oa_5F_scanner::kToken_message) // $message$
, TERMINAL (C_Lexique_oa_5F_scanner::kToken_identifier) // $identifier$
, END_PRODUCTION
// At index 117 : <select_oa_5F_parser_14>, in file 'oa_parser.ggs', line 214
, TERMINAL (C_Lexique_oa_5F_scanner::kToken_task) // $task$
, TERMINAL (C_Lexique_oa_5F_scanner::kToken_identifier) // $identifier$
, END_PRODUCTION
// At index 120 : <>, in file '.ggs', line 0
, NONTERMINAL (0) // <axiome>
, END_PRODUCTION
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                          P R O D U C T I O N    N A M E S                                            
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const cProductionNameDescriptor gProductionNames_oa_grammar [36] = {
 {"<axiome>", "oa_parser", 0}, // at index 0
 {"<select_oa_5F_parser_0>", "oa_parser", 4}, // at index 1
 {"<select_oa_5F_parser_0>", "oa_parser", 5}, // at index 2
 {"<select_oa_5F_parser_0>", "oa_parser", 11}, // at index 3
 {"<select_oa_5F_parser_0>", "oa_parser", 18}, // at index 4
 {"<select_oa_5F_parser_0>", "oa_parser", 32}, // at index 5
 {"<select_oa_5F_parser_1>", "oa_parser", 46}, // at index 6
 {"<select_oa_5F_parser_1>", "oa_parser", 47}, // at index 7
 {"<select_oa_5F_parser_2>", "oa_parser", 50}, // at index 8
 {"<select_oa_5F_parser_2>", "oa_parser", 52}, // at index 9
 {"<select_oa_5F_parser_3>", "oa_parser", 54}, // at index 10
 {"<select_oa_5F_parser_3>", "oa_parser", 55}, // at index 11
 {"<select_oa_5F_parser_4>", "oa_parser", 58}, // at index 12
 {"<select_oa_5F_parser_4>", "oa_parser", 61}, // at index 13
 {"<select_oa_5F_parser_5>", "oa_parser", 62}, // at index 14
 {"<select_oa_5F_parser_5>", "oa_parser", 65}, // at index 15
 {"<select_oa_5F_parser_6>", "oa_parser", 66}, // at index 16
 {"<select_oa_5F_parser_6>", "oa_parser", 71}, // at index 17
 {"<select_oa_5F_parser_7>", "oa_parser", 74}, // at index 18
 {"<select_oa_5F_parser_7>", "oa_parser", 78}, // at index 19
 {"<select_oa_5F_parser_8>", "oa_parser", 84}, // at index 20
 {"<select_oa_5F_parser_8>", "oa_parser", 85}, // at index 21
 {"<select_oa_5F_parser_9>", "oa_parser", 88}, // at index 22
 {"<select_oa_5F_parser_9>", "oa_parser", 89}, // at index 23
 {"<select_oa_5F_parser_10>", "oa_parser", 92}, // at index 24
 {"<select_oa_5F_parser_10>", "oa_parser", 95}, // at index 25
 {"<select_oa_5F_parser_10>", "oa_parser", 98}, // at index 26
 {"<select_oa_5F_parser_11>", "oa_parser", 100}, // at index 27
 {"<select_oa_5F_parser_11>", "oa_parser", 103}, // at index 28
 {"<select_oa_5F_parser_12>", "oa_parser", 104}, // at index 29
 {"<select_oa_5F_parser_12>", "oa_parser", 107}, // at index 30
 {"<select_oa_5F_parser_13>", "oa_parser", 108}, // at index 31
 {"<select_oa_5F_parser_13>", "oa_parser", 111}, // at index 32
 {"<select_oa_5F_parser_14>", "oa_parser", 114}, // at index 33
 {"<select_oa_5F_parser_14>", "oa_parser", 117}, // at index 34
 {"<>", "", 120} // at index 35
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                 L L ( 1 )    P R O D U C T I O N    I N D E X E S                                    
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gProductionIndexes_oa_grammar [36] = {
0, // index 0 : <axiome>, in file 'oa_parser.ggs', line 11
4, // index 1 : <select_oa_5F_parser_0>, in file 'oa_parser.ggs', line 17
5, // index 2 : <select_oa_5F_parser_0>, in file 'oa_parser.ggs', line 17
11, // index 3 : <select_oa_5F_parser_0>, in file 'oa_parser.ggs', line 17
18, // index 4 : <select_oa_5F_parser_0>, in file 'oa_parser.ggs', line 17
32, // index 5 : <select_oa_5F_parser_0>, in file 'oa_parser.ggs', line 17
46, // index 6 : <select_oa_5F_parser_1>, in file 'oa_parser.ggs', line 23
47, // index 7 : <select_oa_5F_parser_1>, in file 'oa_parser.ggs', line 23
50, // index 8 : <select_oa_5F_parser_2>, in file 'oa_parser.ggs', line 36
52, // index 9 : <select_oa_5F_parser_2>, in file 'oa_parser.ggs', line 36
54, // index 10 : <select_oa_5F_parser_3>, in file 'oa_parser.ggs', line 47
55, // index 11 : <select_oa_5F_parser_3>, in file 'oa_parser.ggs', line 47
58, // index 12 : <select_oa_5F_parser_4>, in file 'oa_parser.ggs', line 73
61, // index 13 : <select_oa_5F_parser_4>, in file 'oa_parser.ggs', line 73
62, // index 14 : <select_oa_5F_parser_5>, in file 'oa_parser.ggs', line 82
65, // index 15 : <select_oa_5F_parser_5>, in file 'oa_parser.ggs', line 82
66, // index 16 : <select_oa_5F_parser_6>, in file 'oa_parser.ggs', line 91
71, // index 17 : <select_oa_5F_parser_6>, in file 'oa_parser.ggs', line 91
74, // index 18 : <select_oa_5F_parser_7>, in file 'oa_parser.ggs', line 104
78, // index 19 : <select_oa_5F_parser_7>, in file 'oa_parser.ggs', line 104
84, // index 20 : <select_oa_5F_parser_8>, in file 'oa_parser.ggs', line 109
85, // index 21 : <select_oa_5F_parser_8>, in file 'oa_parser.ggs', line 109
88, // index 22 : <select_oa_5F_parser_9>, in file 'oa_parser.ggs', line 128
89, // index 23 : <select_oa_5F_parser_9>, in file 'oa_parser.ggs', line 128
92, // index 24 : <select_oa_5F_parser_10>, in file 'oa_parser.ggs', line 150
95, // index 25 : <select_oa_5F_parser_10>, in file 'oa_parser.ggs', line 150
98, // index 26 : <select_oa_5F_parser_10>, in file 'oa_parser.ggs', line 150
100, // index 27 : <select_oa_5F_parser_11>, in file 'oa_parser.ggs', line 188
103, // index 28 : <select_oa_5F_parser_11>, in file 'oa_parser.ggs', line 188
104, // index 29 : <select_oa_5F_parser_12>, in file 'oa_parser.ggs', line 197
107, // index 30 : <select_oa_5F_parser_12>, in file 'oa_parser.ggs', line 197
108, // index 31 : <select_oa_5F_parser_13>, in file 'oa_parser.ggs', line 205
111, // index 32 : <select_oa_5F_parser_13>, in file 'oa_parser.ggs', line 205
114, // index 33 : <select_oa_5F_parser_14>, in file 'oa_parser.ggs', line 214
117, // index 34 : <select_oa_5F_parser_14>, in file 'oa_parser.ggs', line 214
120 // index 35 : <>, in file '.ggs', line 0
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                           L L ( 1 )    F I R S T    P R O D U C T I O N    I N D E X E S                             
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gFirstProductionIndexes_oa_grammar [18] = {
0, // at 0 : <axiome>
1, // at 1 : <select_oa_5F_parser_0>
6, // at 2 : <select_oa_5F_parser_1>
8, // at 3 : <select_oa_5F_parser_2>
10, // at 4 : <select_oa_5F_parser_3>
12, // at 5 : <select_oa_5F_parser_4>
14, // at 6 : <select_oa_5F_parser_5>
16, // at 7 : <select_oa_5F_parser_6>
18, // at 8 : <select_oa_5F_parser_7>
20, // at 9 : <select_oa_5F_parser_8>
22, // at 10 : <select_oa_5F_parser_9>
24, // at 11 : <select_oa_5F_parser_10>
27, // at 12 : <select_oa_5F_parser_11>
29, // at 13 : <select_oa_5F_parser_12>
31, // at 14 : <select_oa_5F_parser_13>
33, // at 15 : <select_oa_5F_parser_14>
35, // at 16 : <>
0} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                    L L ( 1 )    D E C I S I O N    T A B L E S                                       
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gDecision_oa_grammar [] = {
// At index 0 : <axiome> only one production, no choice
  -1,
//---- Added non terminal symbols from 'select' and 'repeat' instructions
// At index 1 : <select_oa_5F_parser_0>
C_Lexique_oa_5F_scanner::kToken_end, -1, // Choice 1
C_Lexique_oa_5F_scanner::kToken_processor, -1, // Choice 2
C_Lexique_oa_5F_scanner::kToken_can, C_Lexique_oa_5F_scanner::kToken_van, -1, // Choice 3
C_Lexique_oa_5F_scanner::kToken_task, -1, // Choice 4
C_Lexique_oa_5F_scanner::kToken_message, C_Lexique_oa_5F_scanner::kToken_standard, C_Lexique_oa_5F_scanner::kToken_extended, -1, // Choice 5
  -1,
// At index 15 : <select_oa_5F_parser_1>
C_Lexique_oa_5F_scanner::kToken__3B_, -1, // Choice 1
C_Lexique_oa_5F_scanner::kToken_scalingfactor, -1, // Choice 2
  -1,
// At index 20 : <select_oa_5F_parser_2>
C_Lexique_oa_5F_scanner::kToken_can, -1, // Choice 1
C_Lexique_oa_5F_scanner::kToken_van, -1, // Choice 2
  -1,
// At index 25 : <select_oa_5F_parser_3>
C_Lexique_oa_5F_scanner::kToken__3B_, -1, // Choice 1
C_Lexique_oa_5F_scanner::kToken_scalingfactor, -1, // Choice 2
  -1,
// At index 30 : <select_oa_5F_parser_4>
C_Lexique_oa_5F_scanner::kToken_offset, -1, // Choice 1
C_Lexique_oa_5F_scanner::kToken_deadline, C_Lexique_oa_5F_scanner::kToken_period, C_Lexique_oa_5F_scanner::kToken_on, -1, // Choice 2
  -1,
// At index 37 : <select_oa_5F_parser_5>
C_Lexique_oa_5F_scanner::kToken_deadline, -1, // Choice 1
C_Lexique_oa_5F_scanner::kToken_period, C_Lexique_oa_5F_scanner::kToken_on, -1, // Choice 2
  -1,
// At index 43 : <select_oa_5F_parser_6>
C_Lexique_oa_5F_scanner::kToken_period, -1, // Choice 1
C_Lexique_oa_5F_scanner::kToken_on, -1, // Choice 2
  -1,
// At index 48 : <select_oa_5F_parser_7>
C_Lexique_oa_5F_scanner::kToken_task, -1, // Choice 1
C_Lexique_oa_5F_scanner::kToken_message, -1, // Choice 2
  -1,
// At index 53 : <select_oa_5F_parser_8>
C_Lexique_oa_5F_scanner::kToken__3B_, -1, // Choice 1
C_Lexique_oa_5F_scanner::kToken_every, -1, // Choice 2
  -1,
// At index 58 : <select_oa_5F_parser_9>
C_Lexique_oa_5F_scanner::kToken__3B_, -1, // Choice 1
C_Lexique_oa_5F_scanner::kToken_every, -1, // Choice 2
  -1,
// At index 63 : <select_oa_5F_parser_10>
C_Lexique_oa_5F_scanner::kToken_standard, -1, // Choice 1
C_Lexique_oa_5F_scanner::kToken_extended, -1, // Choice 2
C_Lexique_oa_5F_scanner::kToken_message, -1, // Choice 3
  -1,
// At index 70 : <select_oa_5F_parser_11>
C_Lexique_oa_5F_scanner::kToken_offset, -1, // Choice 1
C_Lexique_oa_5F_scanner::kToken_deadline, C_Lexique_oa_5F_scanner::kToken_period, C_Lexique_oa_5F_scanner::kToken_on, -1, // Choice 2
  -1,
// At index 77 : <select_oa_5F_parser_12>
C_Lexique_oa_5F_scanner::kToken_deadline, -1, // Choice 1
C_Lexique_oa_5F_scanner::kToken_period, C_Lexique_oa_5F_scanner::kToken_on, -1, // Choice 2
  -1,
// At index 83 : <select_oa_5F_parser_13>
C_Lexique_oa_5F_scanner::kToken_period, -1, // Choice 1
C_Lexique_oa_5F_scanner::kToken_on, -1, // Choice 2
  -1,
// At index 88 : <select_oa_5F_parser_14>
C_Lexique_oa_5F_scanner::kToken_message, -1, // Choice 1
C_Lexique_oa_5F_scanner::kToken_task, -1, // Choice 2
  -1,
// At index 93 : <> only one production, no choice
  -1,
0} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            L L ( 1 )    D E C I S I O N    T A B L E S    I N D E X E S                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gDecisionIndexes_oa_grammar [18] = {
0, // at 0 : <axiome>
1, // at 1 : <select_oa_5F_parser_0>
15, // at 2 : <select_oa_5F_parser_1>
20, // at 3 : <select_oa_5F_parser_2>
25, // at 4 : <select_oa_5F_parser_3>
30, // at 5 : <select_oa_5F_parser_4>
37, // at 6 : <select_oa_5F_parser_5>
43, // at 7 : <select_oa_5F_parser_6>
48, // at 8 : <select_oa_5F_parser_7>
53, // at 9 : <select_oa_5F_parser_8>
58, // at 10 : <select_oa_5F_parser_9>
63, // at 11 : <select_oa_5F_parser_10>
70, // at 12 : <select_oa_5F_parser_11>
77, // at 13 : <select_oa_5F_parser_12>
83, // at 14 : <select_oa_5F_parser_13>
88, // at 15 : <select_oa_5F_parser_14>
93, // at 16 : <>
0} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                        'axiome' non terminal implementation                                          
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_oa_5F_grammar::nt_axiome_parse (C_Lexique_oa_5F_scanner * inLexique) {
  rule_oa_5F_parser_axiome_i0_parse(inLexique) ;
}

void cGrammar_oa_5F_grammar::nt_axiome_ (C_Lexique_oa_5F_scanner * inLexique) {
  rule_oa_5F_parser_axiome_i0_(inLexique) ;
}

void cGrammar_oa_5F_grammar::performIndexing (C_Compiler * /* inCompiler */,
             const C_String & /* inSourceFilePath */) {
}

void cGrammar_oa_5F_grammar::performOnlyLexicalAnalysis (C_Compiler * inCompiler,
             const C_String & inSourceFilePath) {
  C_Lexique_oa_5F_scanner * scanner = NULL ;
  macroMyNew (scanner, C_Lexique_oa_5F_scanner (inCompiler, inSourceFilePath COMMA_HERE)) ;
  if (scanner->sourceText ().isValid ()) {
    scanner->performLexicalAnalysis () ;
  }
  macroDetachSharedObject (scanner) ;
}

void cGrammar_oa_5F_grammar::performOnlySyntaxAnalysis (C_Compiler * inCompiler,
             const C_String & inSourceFilePath) {
  C_Lexique_oa_5F_scanner * scanner = NULL ;
  macroMyNew (scanner, C_Lexique_oa_5F_scanner (inCompiler, inSourceFilePath COMMA_HERE)) ;
  if (scanner->sourceText ().isValid ()) {
    scanner->performTopDownParsing (gProductions_oa_grammar, gProductionNames_oa_grammar, gProductionIndexes_oa_grammar,
                                    gFirstProductionIndexes_oa_grammar, gDecision_oa_grammar, gDecisionIndexes_oa_grammar, 120) ;
  }
  macroDetachSharedObject (scanner) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                        Grammar start symbol implementation                                           
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_oa_5F_grammar::_performSourceFileParsing_ (C_Compiler * inCompiler,
                                GALGAS_lstring inFilePath
                                COMMA_LOCATION_ARGS) {
  if (inFilePath.isValid ()) {
    const GALGAS_string filePathAsString = inFilePath.getter_string (HERE) ;
    C_String filePath = filePathAsString.stringValue () ;
    if (! C_FileManager::isAbsolutePath (filePath)) {
      filePath = inCompiler->sourceFilePath ().stringByDeletingLastPathComponent ().stringByAppendingPathComponent (filePath) ;
    }
    if (C_FileManager::fileExistsAtPath (filePath)) {
    C_Lexique_oa_5F_scanner * scanner = NULL ;
    macroMyNew (scanner, C_Lexique_oa_5F_scanner (inCompiler, filePath COMMA_HERE)) ;
    if (scanner->sourceText ().isValid ()) {
      const bool ok = scanner->performTopDownParsing (gProductions_oa_grammar, gProductionNames_oa_grammar, gProductionIndexes_oa_grammar,
                                                      gFirstProductionIndexes_oa_grammar, gDecision_oa_grammar, gDecisionIndexes_oa_grammar, 120) ;
      if (ok && ! executionModeIsSyntaxAnalysisOnly ()) {
        cGrammar_oa_5F_grammar grammar ;
        grammar.nt_axiome_ (scanner) ;
        }
      }else{
        C_String message ;
        message << "the '" << filePath << "' file exists, but cannot be read" ;
        const GALGAS_location errorLocation (inFilePath.getter_location (THERE)) ;
        inCompiler->semanticErrorAtLocation (errorLocation, message, TC_Array <C_FixItDescription> () COMMA_THERE) ;
      }
      macroDetachSharedObject (scanner) ;
    }else{
      C_String message ;
      message << "the '" << filePath << "' file does not exist" ;
      const GALGAS_location errorLocation (inFilePath.getter_location (THERE)) ;
      inCompiler->semanticErrorAtLocation (errorLocation, message, TC_Array <C_FixItDescription> () COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_oa_5F_grammar::_performSourceStringParsing_ (C_Compiler * inCompiler,
                                GALGAS_string inSourceString,
                                GALGAS_string inNameString
                                COMMA_UNUSED_LOCATION_ARGS) {
  if (inSourceString.isValid () && inNameString.isValid ()) {
    const C_String sourceString = inSourceString.stringValue () ;
    const C_String nameString = inNameString.stringValue () ;
    C_Lexique_oa_5F_scanner * scanner = NULL ;
    macroMyNew (scanner, C_Lexique_oa_5F_scanner (inCompiler, sourceString, nameString COMMA_HERE)) ;
    const bool ok = scanner->performTopDownParsing (gProductions_oa_grammar, gProductionNames_oa_grammar, gProductionIndexes_oa_grammar,
                                                    gFirstProductionIndexes_oa_grammar, gDecision_oa_grammar, gDecisionIndexes_oa_grammar, 120) ;
    if (ok && ! executionModeIsSyntaxAnalysisOnly ()) {
      cGrammar_oa_5F_grammar grammar ;
      grammar.nt_axiome_ (scanner) ;
    }
    macroDetachSharedObject (scanner) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                             'select_oa_5F_parser_0' added non terminal implementation                                
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_oa_5F_grammar::select_oa_5F_parser_0 (C_Lexique_oa_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                             'select_oa_5F_parser_1' added non terminal implementation                                
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_oa_5F_grammar::select_oa_5F_parser_1 (C_Lexique_oa_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                             'select_oa_5F_parser_2' added non terminal implementation                                
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_oa_5F_grammar::select_oa_5F_parser_2 (C_Lexique_oa_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                             'select_oa_5F_parser_3' added non terminal implementation                                
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_oa_5F_grammar::select_oa_5F_parser_3 (C_Lexique_oa_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                             'select_oa_5F_parser_4' added non terminal implementation                                
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_oa_5F_grammar::select_oa_5F_parser_4 (C_Lexique_oa_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                             'select_oa_5F_parser_5' added non terminal implementation                                
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_oa_5F_grammar::select_oa_5F_parser_5 (C_Lexique_oa_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                             'select_oa_5F_parser_6' added non terminal implementation                                
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_oa_5F_grammar::select_oa_5F_parser_6 (C_Lexique_oa_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                             'select_oa_5F_parser_7' added non terminal implementation                                
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_oa_5F_grammar::select_oa_5F_parser_7 (C_Lexique_oa_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                             'select_oa_5F_parser_8' added non terminal implementation                                
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_oa_5F_grammar::select_oa_5F_parser_8 (C_Lexique_oa_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                             'select_oa_5F_parser_9' added non terminal implementation                                
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_oa_5F_grammar::select_oa_5F_parser_9 (C_Lexique_oa_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                             'select_oa_5F_parser_10' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_oa_5F_grammar::select_oa_5F_parser_10 (C_Lexique_oa_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                             'select_oa_5F_parser_11' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_oa_5F_grammar::select_oa_5F_parser_11 (C_Lexique_oa_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                             'select_oa_5F_parser_12' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_oa_5F_grammar::select_oa_5F_parser_12 (C_Lexique_oa_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                             'select_oa_5F_parser_13' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_oa_5F_grammar::select_oa_5F_parser_13 (C_Lexique_oa_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                             'select_oa_5F_parser_14' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_oa_5F_grammar::select_oa_5F_parser_14 (C_Lexique_oa_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_M_5F_processor_2D_element::GALGAS_M_5F_processor_2D_element (void) :
mProperty_lkey (),
mProperty_mIndex (),
mProperty_mStep () {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_M_5F_processor_2D_element::~ GALGAS_M_5F_processor_2D_element (void) {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_M_5F_processor_2D_element::GALGAS_M_5F_processor_2D_element (const GALGAS_lstring & inOperand0,
                                                                    const GALGAS_uint & inOperand1,
                                                                    const GALGAS_luint & inOperand2) :
mProperty_lkey (inOperand0),
mProperty_mIndex (inOperand1),
mProperty_mStep (inOperand2) {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_M_5F_processor_2D_element GALGAS_M_5F_processor_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_M_5F_processor_2D_element (GALGAS_lstring::constructor_default (HERE),
                                           GALGAS_uint::constructor_default (HERE),
                                           GALGAS_luint::constructor_default (HERE)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_M_5F_processor_2D_element GALGAS_M_5F_processor_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                                    const GALGAS_uint & inOperand1,
                                                                                    const GALGAS_luint & inOperand2 
                                                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_M_5F_processor_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid ()) {
    result = GALGAS_M_5F_processor_2D_element (inOperand0, inOperand1, inOperand2) ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

typeComparisonResult GALGAS_M_5F_processor_2D_element::objectCompare (const GALGAS_M_5F_processor_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_lkey.objectCompare (inOperand.mProperty_lkey) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_mIndex.objectCompare (inOperand.mProperty_mIndex) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_mStep.objectCompare (inOperand.mProperty_mStep) ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

bool GALGAS_M_5F_processor_2D_element::isValid (void) const {
  return mProperty_lkey.isValid () && mProperty_mIndex.isValid () && mProperty_mStep.isValid () ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void GALGAS_M_5F_processor_2D_element::drop (void) {
  mProperty_lkey.drop () ;
  mProperty_mIndex.drop () ;
  mProperty_mStep.drop () ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void GALGAS_M_5F_processor_2D_element::description (C_String & ioString,
                                                    const int32_t inIndentation) const {
  ioString << "<struct @M_processor-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_lkey.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_mIndex.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_mStep.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_lstring GALGAS_M_5F_processor_2D_element::getter_lkey (UNUSED_LOCATION_ARGS) const {
  return mProperty_lkey ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_uint GALGAS_M_5F_processor_2D_element::getter_mIndex (UNUSED_LOCATION_ARGS) const {
  return mProperty_mIndex ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_luint GALGAS_M_5F_processor_2D_element::getter_mStep (UNUSED_LOCATION_ARGS) const {
  return mProperty_mStep ;
}



//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                              @M_processor-element type                                              *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_M_5F_processor_2D_element ("M_processor-element",
                                                  NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

const C_galgas_type_descriptor * GALGAS_M_5F_processor_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_M_5F_processor_2D_element ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

AC_GALGAS_root * GALGAS_M_5F_processor_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_M_5F_processor_2D_element (*this)) ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_M_5F_processor_2D_element GALGAS_M_5F_processor_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                  C_Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_M_5F_processor_2D_element result ;
  const GALGAS_M_5F_processor_2D_element * p = (const GALGAS_M_5F_processor_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_M_5F_processor_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("M_processor-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_M_5F_network_2D_element::GALGAS_M_5F_network_2D_element (void) :
mProperty_lkey (),
mProperty_mIndex (),
mProperty_mCANnetwork (),
mProperty_mScalingFactor () {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_M_5F_network_2D_element::~ GALGAS_M_5F_network_2D_element (void) {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_M_5F_network_2D_element::GALGAS_M_5F_network_2D_element (const GALGAS_lstring & inOperand0,
                                                                const GALGAS_uint & inOperand1,
                                                                const GALGAS_bool & inOperand2,
                                                                const GALGAS_luint & inOperand3) :
mProperty_lkey (inOperand0),
mProperty_mIndex (inOperand1),
mProperty_mCANnetwork (inOperand2),
mProperty_mScalingFactor (inOperand3) {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_M_5F_network_2D_element GALGAS_M_5F_network_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_M_5F_network_2D_element (GALGAS_lstring::constructor_default (HERE),
                                         GALGAS_uint::constructor_default (HERE),
                                         GALGAS_bool::constructor_default (HERE),
                                         GALGAS_luint::constructor_default (HERE)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_M_5F_network_2D_element GALGAS_M_5F_network_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                                const GALGAS_uint & inOperand1,
                                                                                const GALGAS_bool & inOperand2,
                                                                                const GALGAS_luint & inOperand3 
                                                                                COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_M_5F_network_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid () && inOperand3.isValid ()) {
    result = GALGAS_M_5F_network_2D_element (inOperand0, inOperand1, inOperand2, inOperand3) ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

typeComparisonResult GALGAS_M_5F_network_2D_element::objectCompare (const GALGAS_M_5F_network_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_lkey.objectCompare (inOperand.mProperty_lkey) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_mIndex.objectCompare (inOperand.mProperty_mIndex) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_mCANnetwork.objectCompare (inOperand.mProperty_mCANnetwork) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_mScalingFactor.objectCompare (inOperand.mProperty_mScalingFactor) ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

bool GALGAS_M_5F_network_2D_element::isValid (void) const {
  return mProperty_lkey.isValid () && mProperty_mIndex.isValid () && mProperty_mCANnetwork.isValid () && mProperty_mScalingFactor.isValid () ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void GALGAS_M_5F_network_2D_element::drop (void) {
  mProperty_lkey.drop () ;
  mProperty_mIndex.drop () ;
  mProperty_mCANnetwork.drop () ;
  mProperty_mScalingFactor.drop () ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void GALGAS_M_5F_network_2D_element::description (C_String & ioString,
                                                  const int32_t inIndentation) const {
  ioString << "<struct @M_network-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_lkey.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_mIndex.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_mCANnetwork.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_mScalingFactor.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_lstring GALGAS_M_5F_network_2D_element::getter_lkey (UNUSED_LOCATION_ARGS) const {
  return mProperty_lkey ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_uint GALGAS_M_5F_network_2D_element::getter_mIndex (UNUSED_LOCATION_ARGS) const {
  return mProperty_mIndex ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_bool GALGAS_M_5F_network_2D_element::getter_mCANnetwork (UNUSED_LOCATION_ARGS) const {
  return mProperty_mCANnetwork ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_luint GALGAS_M_5F_network_2D_element::getter_mScalingFactor (UNUSED_LOCATION_ARGS) const {
  return mProperty_mScalingFactor ;
}



//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                               @M_network-element type                                               *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_M_5F_network_2D_element ("M_network-element",
                                                NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

const C_galgas_type_descriptor * GALGAS_M_5F_network_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_M_5F_network_2D_element ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

AC_GALGAS_root * GALGAS_M_5F_network_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_M_5F_network_2D_element (*this)) ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_M_5F_network_2D_element GALGAS_M_5F_network_2D_element::extractObject (const GALGAS_object & inObject,
                                                                              C_Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_M_5F_network_2D_element result ;
  const GALGAS_M_5F_network_2D_element * p = (const GALGAS_M_5F_network_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_M_5F_network_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("M_network-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_M_5F_messages_2D_element::GALGAS_M_5F_messages_2D_element (void) :
mProperty_lkey (),
mProperty_mIndex (),
mProperty_mClass (),
mProperty_mNetworkIndex (),
mProperty_mBytesCount (),
mProperty_mPriority (),
mProperty_mOffset (),
mProperty_mDeadline (),
mProperty_mPeriod (),
mProperty_mMessageKind () {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_M_5F_messages_2D_element::~ GALGAS_M_5F_messages_2D_element (void) {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_M_5F_messages_2D_element::GALGAS_M_5F_messages_2D_element (const GALGAS_lstring & inOperand0,
                                                                  const GALGAS_uint & inOperand1,
                                                                  const GALGAS_luint & inOperand2,
                                                                  const GALGAS_uint & inOperand3,
                                                                  const GALGAS_luint & inOperand4,
                                                                  const GALGAS_luint & inOperand5,
                                                                  const GALGAS_luint & inOperand6,
                                                                  const GALGAS_luint & inOperand7,
                                                                  const GALGAS_luint & inOperand8,
                                                                  const GALGAS_AC_5F_canMessage & inOperand9) :
mProperty_lkey (inOperand0),
mProperty_mIndex (inOperand1),
mProperty_mClass (inOperand2),
mProperty_mNetworkIndex (inOperand3),
mProperty_mBytesCount (inOperand4),
mProperty_mPriority (inOperand5),
mProperty_mOffset (inOperand6),
mProperty_mDeadline (inOperand7),
mProperty_mPeriod (inOperand8),
mProperty_mMessageKind (inOperand9) {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_M_5F_messages_2D_element GALGAS_M_5F_messages_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                                  const GALGAS_uint & inOperand1,
                                                                                  const GALGAS_luint & inOperand2,
                                                                                  const GALGAS_uint & inOperand3,
                                                                                  const GALGAS_luint & inOperand4,
                                                                                  const GALGAS_luint & inOperand5,
                                                                                  const GALGAS_luint & inOperand6,
                                                                                  const GALGAS_luint & inOperand7,
                                                                                  const GALGAS_luint & inOperand8,
                                                                                  const GALGAS_AC_5F_canMessage & inOperand9 
                                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_M_5F_messages_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid () && inOperand3.isValid () && inOperand4.isValid () && inOperand5.isValid () && inOperand6.isValid () && inOperand7.isValid () && inOperand8.isValid () && inOperand9.isValid ()) {
    result = GALGAS_M_5F_messages_2D_element (inOperand0, inOperand1, inOperand2, inOperand3, inOperand4, inOperand5, inOperand6, inOperand7, inOperand8, inOperand9) ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

typeComparisonResult GALGAS_M_5F_messages_2D_element::objectCompare (const GALGAS_M_5F_messages_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_lkey.objectCompare (inOperand.mProperty_lkey) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_mIndex.objectCompare (inOperand.mProperty_mIndex) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_mClass.objectCompare (inOperand.mProperty_mClass) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_mNetworkIndex.objectCompare (inOperand.mProperty_mNetworkIndex) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_mBytesCount.objectCompare (inOperand.mProperty_mBytesCount) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_mPriority.objectCompare (inOperand.mProperty_mPriority) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_mOffset.objectCompare (inOperand.mProperty_mOffset) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_mDeadline.objectCompare (inOperand.mProperty_mDeadline) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_mPeriod.objectCompare (inOperand.mProperty_mPeriod) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_mMessageKind.objectCompare (inOperand.mProperty_mMessageKind) ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

bool GALGAS_M_5F_messages_2D_element::isValid (void) const {
  return mProperty_lkey.isValid () && mProperty_mIndex.isValid () && mProperty_mClass.isValid () && mProperty_mNetworkIndex.isValid () && mProperty_mBytesCount.isValid () && mProperty_mPriority.isValid () && mProperty_mOffset.isValid () && mProperty_mDeadline.isValid () && mProperty_mPeriod.isValid () && mProperty_mMessageKind.isValid () ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void GALGAS_M_5F_messages_2D_element::drop (void) {
  mProperty_lkey.drop () ;
  mProperty_mIndex.drop () ;
  mProperty_mClass.drop () ;
  mProperty_mNetworkIndex.drop () ;
  mProperty_mBytesCount.drop () ;
  mProperty_mPriority.drop () ;
  mProperty_mOffset.drop () ;
  mProperty_mDeadline.drop () ;
  mProperty_mPeriod.drop () ;
  mProperty_mMessageKind.drop () ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void GALGAS_M_5F_messages_2D_element::description (C_String & ioString,
                                                   const int32_t inIndentation) const {
  ioString << "<struct @M_messages-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_lkey.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_mIndex.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_mClass.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_mNetworkIndex.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_mBytesCount.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_mPriority.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_mOffset.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_mDeadline.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_mPeriod.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_mMessageKind.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_lstring GALGAS_M_5F_messages_2D_element::getter_lkey (UNUSED_LOCATION_ARGS) const {
  return mProperty_lkey ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_uint GALGAS_M_5F_messages_2D_element::getter_mIndex (UNUSED_LOCATION_ARGS) const {
  return mProperty_mIndex ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_luint GALGAS_M_5F_messages_2D_element::getter_mClass (UNUSED_LOCATION_ARGS) const {
  return mProperty_mClass ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_uint GALGAS_M_5F_messages_2D_element::getter_mNetworkIndex (UNUSED_LOCATION_ARGS) const {
  return mProperty_mNetworkIndex ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_luint GALGAS_M_5F_messages_2D_element::getter_mBytesCount (UNUSED_LOCATION_ARGS) const {
  return mProperty_mBytesCount ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_luint GALGAS_M_5F_messages_2D_element::getter_mPriority (UNUSED_LOCATION_ARGS) const {
  return mProperty_mPriority ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_luint GALGAS_M_5F_messages_2D_element::getter_mOffset (UNUSED_LOCATION_ARGS) const {
  return mProperty_mOffset ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_luint GALGAS_M_5F_messages_2D_element::getter_mDeadline (UNUSED_LOCATION_ARGS) const {
  return mProperty_mDeadline ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_luint GALGAS_M_5F_messages_2D_element::getter_mPeriod (UNUSED_LOCATION_ARGS) const {
  return mProperty_mPeriod ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_AC_5F_canMessage GALGAS_M_5F_messages_2D_element::getter_mMessageKind (UNUSED_LOCATION_ARGS) const {
  return mProperty_mMessageKind ;
}



//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                              @M_messages-element type                                               *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_M_5F_messages_2D_element ("M_messages-element",
                                                 NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

const C_galgas_type_descriptor * GALGAS_M_5F_messages_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_M_5F_messages_2D_element ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

AC_GALGAS_root * GALGAS_M_5F_messages_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_M_5F_messages_2D_element (*this)) ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_M_5F_messages_2D_element GALGAS_M_5F_messages_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_M_5F_messages_2D_element result ;
  const GALGAS_M_5F_messages_2D_element * p = (const GALGAS_M_5F_messages_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_M_5F_messages_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("M_messages-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_M_5F_tasks_2D_element::GALGAS_M_5F_tasks_2D_element (void) :
mProperty_lkey (),
mProperty_mIndex (),
mProperty_mPriority (),
mProperty_mOffset (),
mProperty_mDeadline (),
mProperty_mDurationMin (),
mProperty_mDurationMax (),
mProperty_mProcessor (),
mProperty_mPeriod (),
mProperty_mTaskKind () {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_M_5F_tasks_2D_element::~ GALGAS_M_5F_tasks_2D_element (void) {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_M_5F_tasks_2D_element::GALGAS_M_5F_tasks_2D_element (const GALGAS_lstring & inOperand0,
                                                            const GALGAS_uint & inOperand1,
                                                            const GALGAS_luint & inOperand2,
                                                            const GALGAS_luint & inOperand3,
                                                            const GALGAS_luint & inOperand4,
                                                            const GALGAS_luint & inOperand5,
                                                            const GALGAS_luint & inOperand6,
                                                            const GALGAS_uint & inOperand7,
                                                            const GALGAS_luint & inOperand8,
                                                            const GALGAS_AC_5F_task & inOperand9) :
mProperty_lkey (inOperand0),
mProperty_mIndex (inOperand1),
mProperty_mPriority (inOperand2),
mProperty_mOffset (inOperand3),
mProperty_mDeadline (inOperand4),
mProperty_mDurationMin (inOperand5),
mProperty_mDurationMax (inOperand6),
mProperty_mProcessor (inOperand7),
mProperty_mPeriod (inOperand8),
mProperty_mTaskKind (inOperand9) {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_M_5F_tasks_2D_element GALGAS_M_5F_tasks_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                            const GALGAS_uint & inOperand1,
                                                                            const GALGAS_luint & inOperand2,
                                                                            const GALGAS_luint & inOperand3,
                                                                            const GALGAS_luint & inOperand4,
                                                                            const GALGAS_luint & inOperand5,
                                                                            const GALGAS_luint & inOperand6,
                                                                            const GALGAS_uint & inOperand7,
                                                                            const GALGAS_luint & inOperand8,
                                                                            const GALGAS_AC_5F_task & inOperand9 
                                                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_M_5F_tasks_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid () && inOperand3.isValid () && inOperand4.isValid () && inOperand5.isValid () && inOperand6.isValid () && inOperand7.isValid () && inOperand8.isValid () && inOperand9.isValid ()) {
    result = GALGAS_M_5F_tasks_2D_element (inOperand0, inOperand1, inOperand2, inOperand3, inOperand4, inOperand5, inOperand6, inOperand7, inOperand8, inOperand9) ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

typeComparisonResult GALGAS_M_5F_tasks_2D_element::objectCompare (const GALGAS_M_5F_tasks_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_lkey.objectCompare (inOperand.mProperty_lkey) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_mIndex.objectCompare (inOperand.mProperty_mIndex) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_mPriority.objectCompare (inOperand.mProperty_mPriority) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_mOffset.objectCompare (inOperand.mProperty_mOffset) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_mDeadline.objectCompare (inOperand.mProperty_mDeadline) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_mDurationMin.objectCompare (inOperand.mProperty_mDurationMin) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_mDurationMax.objectCompare (inOperand.mProperty_mDurationMax) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_mProcessor.objectCompare (inOperand.mProperty_mProcessor) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_mPeriod.objectCompare (inOperand.mProperty_mPeriod) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_mTaskKind.objectCompare (inOperand.mProperty_mTaskKind) ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

bool GALGAS_M_5F_tasks_2D_element::isValid (void) const {
  return mProperty_lkey.isValid () && mProperty_mIndex.isValid () && mProperty_mPriority.isValid () && mProperty_mOffset.isValid () && mProperty_mDeadline.isValid () && mProperty_mDurationMin.isValid () && mProperty_mDurationMax.isValid () && mProperty_mProcessor.isValid () && mProperty_mPeriod.isValid () && mProperty_mTaskKind.isValid () ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void GALGAS_M_5F_tasks_2D_element::drop (void) {
  mProperty_lkey.drop () ;
  mProperty_mIndex.drop () ;
  mProperty_mPriority.drop () ;
  mProperty_mOffset.drop () ;
  mProperty_mDeadline.drop () ;
  mProperty_mDurationMin.drop () ;
  mProperty_mDurationMax.drop () ;
  mProperty_mProcessor.drop () ;
  mProperty_mPeriod.drop () ;
  mProperty_mTaskKind.drop () ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void GALGAS_M_5F_tasks_2D_element::description (C_String & ioString,
                                                const int32_t inIndentation) const {
  ioString << "<struct @M_tasks-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_lkey.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_mIndex.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_mPriority.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_mOffset.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_mDeadline.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_mDurationMin.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_mDurationMax.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_mProcessor.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_mPeriod.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_mTaskKind.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_lstring GALGAS_M_5F_tasks_2D_element::getter_lkey (UNUSED_LOCATION_ARGS) const {
  return mProperty_lkey ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_uint GALGAS_M_5F_tasks_2D_element::getter_mIndex (UNUSED_LOCATION_ARGS) const {
  return mProperty_mIndex ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_luint GALGAS_M_5F_tasks_2D_element::getter_mPriority (UNUSED_LOCATION_ARGS) const {
  return mProperty_mPriority ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_luint GALGAS_M_5F_tasks_2D_element::getter_mOffset (UNUSED_LOCATION_ARGS) const {
  return mProperty_mOffset ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_luint GALGAS_M_5F_tasks_2D_element::getter_mDeadline (UNUSED_LOCATION_ARGS) const {
  return mProperty_mDeadline ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_luint GALGAS_M_5F_tasks_2D_element::getter_mDurationMin (UNUSED_LOCATION_ARGS) const {
  return mProperty_mDurationMin ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_luint GALGAS_M_5F_tasks_2D_element::getter_mDurationMax (UNUSED_LOCATION_ARGS) const {
  return mProperty_mDurationMax ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_uint GALGAS_M_5F_tasks_2D_element::getter_mProcessor (UNUSED_LOCATION_ARGS) const {
  return mProperty_mProcessor ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_luint GALGAS_M_5F_tasks_2D_element::getter_mPeriod (UNUSED_LOCATION_ARGS) const {
  return mProperty_mPeriod ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_AC_5F_task GALGAS_M_5F_tasks_2D_element::getter_mTaskKind (UNUSED_LOCATION_ARGS) const {
  return mProperty_mTaskKind ;
}



//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                                @M_tasks-element type                                                *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_M_5F_tasks_2D_element ("M_tasks-element",
                                              NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

const C_galgas_type_descriptor * GALGAS_M_5F_tasks_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_M_5F_tasks_2D_element ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

AC_GALGAS_root * GALGAS_M_5F_tasks_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_M_5F_tasks_2D_element (*this)) ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_M_5F_tasks_2D_element GALGAS_M_5F_tasks_2D_element::extractObject (const GALGAS_object & inObject,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_M_5F_tasks_2D_element result ;
  const GALGAS_M_5F_tasks_2D_element * p = (const GALGAS_M_5F_tasks_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_M_5F_tasks_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("M_tasks-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                               Bool options                                                                          *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_BoolCommandLineOption gOption_oa_5F_cli_5F_options_createIntermediateFiles ("oa_cli_options",
                                         "createIntermediateFiles",
                                         67,
                                         "create-intermediate-files",
                                         "Create the intermediate files") ;

C_BoolCommandLineOption gOption_oa_5F_cli_5F_options_useCANmaxLegth ("oa_cli_options",
                                         "useCANmaxLegth",
                                         77,
                                         "use-can-max-length",
                                         "Use only CAN messages max length") ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                               UInt options                                                                          *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                              String options                                                                         *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                              String List options                                                                    *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*


#include "project_header.h"
#include "command_line_interface/F_mainForLIBPM.h"
#include "command_line_interface/F_Analyze_CLI_Options.h"
#include "utilities/F_DisplayException.h"
#include "galgas2/C_galgas_CLI_Options.h"
#include "galgas2/F_verbose_output.h"
#include "galgas2/cLexiqueIntrospection.h"
#include "command_line_interface/C_builtin_CLI_Options.h"

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                      print_tool_help_message                                                                        *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void print_tool_help_message (void) {
  co << "Compiled with GALGAS revision NUMERO_REVISION_GALGAS\n" ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static const char * kSourceFileExtensions [] = {
  "nprt",
  NULL
} ;    

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static const char * kSourceFileHelpMessages [] = {
  "an '.nprt' source file",
  NULL
} ;    

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

const char * projectVersionString (void) {
  return "1.2.0" ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                                  Routine 'before'                                                   *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void routine_before (C_Compiler * /* inCompiler */
                            COMMA_UNUSED_LOCATION_ARGS) {
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                                   Routine 'after'                                                   *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void routine_after (C_Compiler * /* inCompiler */
                           COMMA_UNUSED_LOCATION_ARGS) {
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                               Routine 'programRule_0'                                               *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void routine_programRule_5F__30_ (const GALGAS_lstring constinArgument_inSourceFile,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) {
  cGrammar_oa_5F_grammar::_performSourceFileParsing_ (inCompiler, constinArgument_inSourceFile  COMMA_SOURCE_FILE ("oa_main.galgas", 11)) ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                      M A I N    F O R    L I B P M                                                                  *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

int mainForLIBPM (int inArgc, const char * inArgv []) {
//--- Analyze Command Line Options
  TC_UniqueArray <C_String> sourceFilesArray ;
  F_Analyze_CLI_Options (inArgc, inArgv,
                         sourceFilesArray,
                         kSourceFileExtensions,
                         kSourceFileHelpMessages,
                         print_tool_help_message) ;
//---
  int returnCode = 0 ; // No error
//--- Set Execution mode
  C_String executionModeOptionErrorMessage ;
  setExecutionMode (executionModeOptionErrorMessage) ;
  if (executionModeOptionErrorMessage.length () > 0) {
    co << executionModeOptionErrorMessage ;
    returnCode = 1 ;
  }else{
  //--- Common lexique object
    C_Compiler * commonCompiler = NULL ;
    macroMyNew (commonCompiler, C_Compiler (NULL COMMA_HERE)) ;
    try{
      routine_before (commonCompiler COMMA_HERE) ;
      cLexiqueIntrospection::handleGetKeywordListOption (commonCompiler) ;
      const bool verboseOptionOn = verboseOutput () ;
      for (int32_t i=0 ; i<sourceFilesArray.count () ; i++) {
        const C_String fileExtension = sourceFilesArray (i COMMA_HERE).pathExtension () ;
        const GALGAS_string sfp = GALGAS_string (sourceFilesArray (i COMMA_HERE)) ;
        const GALGAS_location location = commonCompiler->here () ;
        const GALGAS_lstring sourceFilePath (sfp, location) ;
        int r = 0 ;
        if (fileExtension == "nprt") {
          switch (executionMode ()) {
          case kExecutionModeNormal :
            routine_programRule_5F__30_ (sourceFilePath, commonCompiler COMMA_HERE) ;
            break ;
          case kExecutionModeLexicalAnalysisOnly :
            cGrammar_oa_5F_grammar::performOnlyLexicalAnalysis (commonCompiler, sourceFilesArray (i COMMA_HERE)) ;
            break ;
          case kExecutionModeSyntaxAnalysisOnly :
            cGrammar_oa_5F_grammar::performOnlySyntaxAnalysis (commonCompiler, sourceFilesArray (i COMMA_HERE)) ;
            break ;
          case kExecutionModeIndexing :
            cGrammar_oa_5F_grammar::performIndexing (commonCompiler, sourceFilesArray (i COMMA_HERE)) ;
            break ;
          case kExecutionModeLatex :
            cGrammar_oa_5F_grammar::performOnlyLexicalAnalysis (commonCompiler, sourceFilesArray (i COMMA_HERE)) ;
            break ;
          }
        }else{
          printf ("*** Error: unhandled extension for file '%s' ***\n", sourceFilesArray (i COMMA_HERE).cString (HERE)) ;
          r = 1 ;
        }
        if (r != 0) {
          returnCode = r ;
        }
      }
    //--- Error or warnings ?
      if (totalErrorCount () > 0) {
        returnCode = 1 ; // Error code
      }else if (totalWarningCount () > 0) {
        if (gOption_galgas_5F_builtin_5F_options_treat_5F_warnings_5F_as_5F_error.mValue) {
          returnCode = 1 ; // Error code
          if (verboseOptionOn) {
            printf ("** Note: warnings are treated as errors. **\n") ;
          }
        }
      }
    //--- Epilogue
      routine_after (commonCompiler COMMA_HERE) ;
    //--- Emit JSON issue file ?
      if (gOption_generic_5F_cli_5F_options_emit_5F_issue_5F_json_5F_file.mValue != "") {
        commonCompiler->writeIssueJSONFile (gOption_generic_5F_cli_5F_options_emit_5F_issue_5F_json_5F_file.mValue) ;
      }
    //--- Display error and warnings count
      if (verboseOptionOn || (totalWarningCount () > 0) || (totalErrorCount () > 0)) {
        C_String message ;
        if (totalWarningCount () == 0) {
          message << "No warning" ;
        }else if (totalWarningCount () == 1) {
          message << "1 warning" ;
        }else{
          message << cStringWithSigned (totalWarningCount ()) << " warnings" ;
        }
        message << ", " ;
        if (totalErrorCount () == 0) {
          message << "no error" ;
        }else if (totalErrorCount () == 1) {
          message << "1 error" ;
        }else{
          message << cStringWithSigned (totalErrorCount ()) << " errors" ;
        }
        message << ".\n" ;
        ggs_printMessage (message COMMA_HERE) ;
      }
    }catch (const ::std:: exception & e) {
      F_default_display_exception (e) ;
      returnCode = 1 ; // Error code
    }catch (...) {
      printf ("**** Unknow exception ****\n") ;
      throw ;
    }
    macroDetachSharedObject (commonCompiler) ;
  }
  return returnCode ;
}

