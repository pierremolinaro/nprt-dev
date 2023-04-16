#pragma once

//----------------------------------------------------------------------------------------------------------------------

#include "all-predefined-types.h"

//----------------------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------------------
//
//LEXIQUE oa_5F_scanner
//
//----------------------------------------------------------------------------------------------------------------------

#include "galgas2/C_Lexique.h"

//----------------------------------------------------------------------------------------------------------------------
//                    E X T E R N    R O U T I N E S
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
//                    E X T E R N    F U N C T I O N S
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
//                       T O K E N    C L A S S
//----------------------------------------------------------------------------------------------------------------------

class cTokenFor_oa_5F_scanner : public cToken {
  public: C_String mLexicalAttribute_identifierString ;
  public: uint32_t mLexicalAttribute_ulongValue ;

  public: cTokenFor_oa_5F_scanner (void) ;
} ;

//----------------------------------------------------------------------------------------------------------------------
//                     S C A N N E R    C L A S S
//----------------------------------------------------------------------------------------------------------------------

class C_Lexique_oa_5F_scanner : public C_Lexique {
//--- Constructors
  public: C_Lexique_oa_5F_scanner (C_Compiler * inCallerCompiler,
                       const C_String & inSourceFileName
                       COMMA_LOCATION_ARGS) ;

  public: C_Lexique_oa_5F_scanner (C_Compiler * inCallerCompiler,
                       const C_String & inSourceString,
                       const C_String & inStringForError
                       COMMA_LOCATION_ARGS) ;

//--- Instrospection
  public: static GALGAS_stringlist symbols (LOCATION_ARGS) ;

//--- Declaring a protected virtual destructor enables the compiler to raise
//    an error if a direct delete is performed; only the static method
//    C_SharedObject::detachPointer may invoke delete.
  #ifndef DO_NOT_GENERATE_CHECKINGS
    protected: virtual ~ C_Lexique_oa_5F_scanner (void) {}
  #endif



//--- Terminal symbols enumeration
  public: enum {kToken_,
   kToken_identifier,
   kToken_literal_5F_integer,
   kToken_system,
   kToken_end,
   kToken_task,
   kToken_standard,
   kToken_extended,
   kToken_message,
   kToken_length,
   kToken_priority,
   kToken_period,
   kToken_offset,
   kToken_on,
   kToken_deadline,
   kToken_duration,
   kToken_processor,
   kToken_can,
   kToken_van,
   kToken_network,
   kToken_scalingfactor,
   kToken_every,
   kToken__2C_,
   kToken__3B_,
   kToken__2E__2E_} ;

//--- Key words table 'keyWordList'
  public: static int16_t search_into_keyWordList (const C_String & inSearchedString) ;

//--- Key words table 'delimitorsList'
  public: static int16_t search_into_delimitorsList (const C_String & inSearchedString) ;
  

//--- Assign from attribute
  public: GALGAS_lstring synthetizedAttribute_identifierString (void) const ;
  public: GALGAS_luint synthetizedAttribute_ulongValue (void) const ;


//--- Attribute access
  public: C_String attributeValue_identifierString (void) const ;
  public: uint32_t attributeValue_ulongValue (void) const ;


//--- Indexing keys

//--- Parse lexical token
  protected: void internalParseLexicalToken (cTokenFor_oa_5F_scanner & token) ;
  protected: virtual bool parseLexicalToken (void) override ;

//--- Get terminal message
  protected: virtual C_String getMessageForTerminal (const int16_t inTerminalSymbol) const override ;

//--- Get terminal count
  public: virtual int16_t terminalVocabularyCount (void) const override { return 24 ; }

//--- Get Token String
  public: virtual C_String getCurrentTokenString (const cToken * inTokenPtr) const override ;

//--- Enter Token
  protected: void enterToken (cTokenFor_oa_5F_scanner & ioToken) ;

//--- Style name for Latex
  protected: virtual C_String styleNameForIndex (const uint32_t inStyleIndex) const override ;
  protected: virtual uint32_t styleIndexForTerminal (const int32_t inTerminalIndex) const override ;
} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @M_processor map
//
//----------------------------------------------------------------------------------------------------------------------

class cMapElement_M_5F_processor ;

//----------------------------------------------------------------------------------------------------------------------

extern const char * kSearchErrorMessage_M_5F_processor_searchKey ;

//----------------------------------------------------------------------------------------------------------------------

class GALGAS_M_5F_processor : public AC_GALGAS_map {
//--------------------------------- Default constructor
  public: GALGAS_M_5F_processor (void) ;

//--------------------------------- Handle copy
  public: GALGAS_M_5F_processor (const GALGAS_M_5F_processor & inSource) ;
  public: GALGAS_M_5F_processor & operator = (const GALGAS_M_5F_processor & inSource) ;
  
//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_M_5F_processor extractObject (const GALGAS_object & inObject,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_M_5F_processor constructor_emptyMap (LOCATION_ARGS) ;

  public: static class GALGAS_M_5F_processor constructor_mapWithMapToOverride (const class GALGAS_M_5F_processor & inOperand0
                                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public: VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_lstring & inOperand0,
                                                     const class GALGAS_uint & inOperand1,
                                                     const class GALGAS_luint & inOperand2,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_insertKey (class GALGAS_lstring constinArgument0,
                                                  class GALGAS_uint constinArgument1,
                                                  class GALGAS_luint constinArgument2,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMIndexForKey (class GALGAS_uint constinArgument0,
                                                        class GALGAS_string constinArgument1,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMStepForKey (class GALGAS_luint constinArgument0,
                                                       class GALGAS_string constinArgument1,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_searchKey (class GALGAS_lstring constinArgument0,
                                                  class GALGAS_uint & outArgument1,
                                                  class GALGAS_luint & outArgument2,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_uint getter_mIndexForKey (const class GALGAS_string & constinOperand0,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_luint getter_mStepForKey (const class GALGAS_string & constinOperand0,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_M_5F_processor getter_overriddenMap (C_Compiler * inCompiler
                                                                             COMMA_LOCATION_ARGS) const ;


//--------------------------------- Optional Methods
  public: VIRTUAL_IN_DEBUG bool optional_searchKey (const class GALGAS_string & constinOperand0,
                                                    class GALGAS_uint & outOperand1,
                                                    class GALGAS_luint & outOperand2) const ;


//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
  public: VIRTUAL_IN_DEBUG cMapElement_M_5F_processor * readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                           const GALGAS_string & inKey
                                                                                           COMMA_LOCATION_ARGS) ;

//--------------------------------- Friend

  friend class cEnumerator_M_5F_processor ;
 
} ; // End of GALGAS_M_5F_processor class

//----------------------------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//----------------------------------------------------------------------------------------------------------------------

class cEnumerator_M_5F_processor : public cGenericAbstractEnumerator {
  public: cEnumerator_M_5F_processor (const GALGAS_M_5F_processor & inEnumeratedObject,
                                      const typeEnumerationOrder inOrder) ;

//--- Current element access
  public: class GALGAS_lstring current_lkey (LOCATION_ARGS) const ;
  public: class GALGAS_uint current_mIndex (LOCATION_ARGS) const ;
  public: class GALGAS_luint current_mStep (LOCATION_ARGS) const ;
//--- Current element access
  public: class GALGAS_M_5F_processor_2D_element current (LOCATION_ARGS) const ;
} ;

//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_M_5F_processor ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: class for element of '@M_processor' map
//
//----------------------------------------------------------------------------------------------------------------------

class cMapElement_M_5F_processor : public cMapElement {
//--- Map attributes
  public: GALGAS_uint mProperty_mIndex ;
  public: GALGAS_luint mProperty_mStep ;

//--- Constructor
  public: cMapElement_M_5F_processor (const GALGAS_lstring & inKey,
                                      const GALGAS_uint & in_mIndex,
                                      const GALGAS_luint & in_mStep
                                      COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public: virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public: virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public: virtual cMapElement * copy (void) ;

//--- Description
 public: virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @M_5F_processor_2D_element struct
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_M_5F_processor_2D_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GALGAS_lstring mProperty_lkey ;
  public: inline GALGAS_lstring readProperty_lkey (void) const {
    return mProperty_lkey ;
  }

  public: GALGAS_uint mProperty_mIndex ;
  public: inline GALGAS_uint readProperty_mIndex (void) const {
    return mProperty_mIndex ;
  }

  public: GALGAS_luint mProperty_mStep ;
  public: inline GALGAS_luint readProperty_mStep (void) const {
    return mProperty_mStep ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default GALGAS constructor
  public: static GALGAS_M_5F_processor_2D_element constructor_default (LOCATION_ARGS) ;

//--------------------------------- Default constructor
  public: GALGAS_M_5F_processor_2D_element (void) ;

//--------------------------------- Property setters
  public: inline void setter_setLkey (const GALGAS_lstring & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_lkey = inValue ;
  }

  public: inline void setter_setMIndex (const GALGAS_uint & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mIndex = inValue ;
  }

  public: inline void setter_setMStep (const GALGAS_luint & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mStep = inValue ;
  }

//--------------------------------- Virtual destructor (in debug mode)
  public: virtual ~ GALGAS_M_5F_processor_2D_element (void) ;

//--------------------------------- Native constructor
  public: GALGAS_M_5F_processor_2D_element (const GALGAS_lstring & in_lkey,
                                            const GALGAS_uint & in_mIndex,
                                            const GALGAS_luint & in_mStep) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_M_5F_processor_2D_element extractObject (const GALGAS_object & inObject,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_M_5F_processor_2D_element constructor_new (const class GALGAS_lstring & inOperand0,
                                                                         const class GALGAS_uint & inOperand1,
                                                                         const class GALGAS_luint & inOperand2
                                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_M_5F_processor_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_M_5F_processor_2D_element class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_M_5F_processor_2D_element ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @M_network map
//
//----------------------------------------------------------------------------------------------------------------------

class cMapElement_M_5F_network ;

//----------------------------------------------------------------------------------------------------------------------

extern const char * kSearchErrorMessage_M_5F_network_searchKey ;

//----------------------------------------------------------------------------------------------------------------------

class GALGAS_M_5F_network : public AC_GALGAS_map {
//--------------------------------- Default constructor
  public: GALGAS_M_5F_network (void) ;

//--------------------------------- Handle copy
  public: GALGAS_M_5F_network (const GALGAS_M_5F_network & inSource) ;
  public: GALGAS_M_5F_network & operator = (const GALGAS_M_5F_network & inSource) ;
  
//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_M_5F_network extractObject (const GALGAS_object & inObject,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_M_5F_network constructor_emptyMap (LOCATION_ARGS) ;

  public: static class GALGAS_M_5F_network constructor_mapWithMapToOverride (const class GALGAS_M_5F_network & inOperand0
                                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public: VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_lstring & inOperand0,
                                                     const class GALGAS_uint & inOperand1,
                                                     const class GALGAS_bool & inOperand2,
                                                     const class GALGAS_luint & inOperand3,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_insertKey (class GALGAS_lstring constinArgument0,
                                                  class GALGAS_uint constinArgument1,
                                                  class GALGAS_bool constinArgument2,
                                                  class GALGAS_luint constinArgument3,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMCANnetworkForKey (class GALGAS_bool constinArgument0,
                                                             class GALGAS_string constinArgument1,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMIndexForKey (class GALGAS_uint constinArgument0,
                                                        class GALGAS_string constinArgument1,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMScalingFactorForKey (class GALGAS_luint constinArgument0,
                                                                class GALGAS_string constinArgument1,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_searchKey (class GALGAS_lstring constinArgument0,
                                                  class GALGAS_uint & outArgument1,
                                                  class GALGAS_bool & outArgument2,
                                                  class GALGAS_luint & outArgument3,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_bool getter_mCANnetworkForKey (const class GALGAS_string & constinOperand0,
                                                                       C_Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_uint getter_mIndexForKey (const class GALGAS_string & constinOperand0,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_luint getter_mScalingFactorForKey (const class GALGAS_string & constinOperand0,
                                                                           C_Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_M_5F_network getter_overriddenMap (C_Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) const ;


//--------------------------------- Optional Methods
  public: VIRTUAL_IN_DEBUG bool optional_searchKey (const class GALGAS_string & constinOperand0,
                                                    class GALGAS_uint & outOperand1,
                                                    class GALGAS_bool & outOperand2,
                                                    class GALGAS_luint & outOperand3) const ;


//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
  public: VIRTUAL_IN_DEBUG cMapElement_M_5F_network * readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                         const GALGAS_string & inKey
                                                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- Friend

  friend class cEnumerator_M_5F_network ;
 
} ; // End of GALGAS_M_5F_network class

//----------------------------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//----------------------------------------------------------------------------------------------------------------------

class cEnumerator_M_5F_network : public cGenericAbstractEnumerator {
  public: cEnumerator_M_5F_network (const GALGAS_M_5F_network & inEnumeratedObject,
                                    const typeEnumerationOrder inOrder) ;

//--- Current element access
  public: class GALGAS_lstring current_lkey (LOCATION_ARGS) const ;
  public: class GALGAS_uint current_mIndex (LOCATION_ARGS) const ;
  public: class GALGAS_bool current_mCANnetwork (LOCATION_ARGS) const ;
  public: class GALGAS_luint current_mScalingFactor (LOCATION_ARGS) const ;
//--- Current element access
  public: class GALGAS_M_5F_network_2D_element current (LOCATION_ARGS) const ;
} ;

//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_M_5F_network ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: class for element of '@M_network' map
//
//----------------------------------------------------------------------------------------------------------------------

class cMapElement_M_5F_network : public cMapElement {
//--- Map attributes
  public: GALGAS_uint mProperty_mIndex ;
  public: GALGAS_bool mProperty_mCANnetwork ;
  public: GALGAS_luint mProperty_mScalingFactor ;

//--- Constructor
  public: cMapElement_M_5F_network (const GALGAS_lstring & inKey,
                                    const GALGAS_uint & in_mIndex,
                                    const GALGAS_bool & in_mCANnetwork,
                                    const GALGAS_luint & in_mScalingFactor
                                    COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public: virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public: virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public: virtual cMapElement * copy (void) ;

//--- Description
 public: virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @M_5F_network_2D_element struct
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_M_5F_network_2D_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GALGAS_lstring mProperty_lkey ;
  public: inline GALGAS_lstring readProperty_lkey (void) const {
    return mProperty_lkey ;
  }

  public: GALGAS_uint mProperty_mIndex ;
  public: inline GALGAS_uint readProperty_mIndex (void) const {
    return mProperty_mIndex ;
  }

  public: GALGAS_bool mProperty_mCANnetwork ;
  public: inline GALGAS_bool readProperty_mCANnetwork (void) const {
    return mProperty_mCANnetwork ;
  }

  public: GALGAS_luint mProperty_mScalingFactor ;
  public: inline GALGAS_luint readProperty_mScalingFactor (void) const {
    return mProperty_mScalingFactor ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default GALGAS constructor
  public: static GALGAS_M_5F_network_2D_element constructor_default (LOCATION_ARGS) ;

//--------------------------------- Default constructor
  public: GALGAS_M_5F_network_2D_element (void) ;

//--------------------------------- Property setters
  public: inline void setter_setLkey (const GALGAS_lstring & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_lkey = inValue ;
  }

  public: inline void setter_setMIndex (const GALGAS_uint & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mIndex = inValue ;
  }

  public: inline void setter_setMCANnetwork (const GALGAS_bool & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mCANnetwork = inValue ;
  }

  public: inline void setter_setMScalingFactor (const GALGAS_luint & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mScalingFactor = inValue ;
  }

//--------------------------------- Virtual destructor (in debug mode)
  public: virtual ~ GALGAS_M_5F_network_2D_element (void) ;

//--------------------------------- Native constructor
  public: GALGAS_M_5F_network_2D_element (const GALGAS_lstring & in_lkey,
                                          const GALGAS_uint & in_mIndex,
                                          const GALGAS_bool & in_mCANnetwork,
                                          const GALGAS_luint & in_mScalingFactor) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_M_5F_network_2D_element extractObject (const GALGAS_object & inObject,
                                                               C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_M_5F_network_2D_element constructor_new (const class GALGAS_lstring & inOperand0,
                                                                       const class GALGAS_uint & inOperand1,
                                                                       const class GALGAS_bool & inOperand2,
                                                                       const class GALGAS_luint & inOperand3
                                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_M_5F_network_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_M_5F_network_2D_element class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_M_5F_network_2D_element ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @AC_5F_canMessage reference class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_AC_5F_canMessage : public AC_GALGAS_reference_class {
//--------------------------------- Default constructor
  public: GALGAS_AC_5F_canMessage (void) ;

//--------------------------------- Constructor from pointer
  public: GALGAS_AC_5F_canMessage (const class cPtr_AC_5F_canMessage * inSourcePtr) ;

//--------------------------------- Property read access
//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_AC_5F_canMessage extractObject (const GALGAS_object & inObject,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_AC_5F_canMessage & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_AC_5F_canMessage class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_AC_5F_canMessage ;

#include "separateHeaderFor_AC_5F_canMessage.h"

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @AC_5F_canMessage_2D_weak weak reference class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_AC_5F_canMessage_2D_weak : public AC_GALGAS_weak_reference {
//--------------------------------- Default constructor
  public: GALGAS_AC_5F_canMessage_2D_weak (void) ;

//--------------------------------- Default GALGAS constructor
  public: static GALGAS_AC_5F_canMessage_2D_weak constructor_default (LOCATION_ARGS) ;

//--------------------------------- Constructor and assignment from strong reference
  public: GALGAS_AC_5F_canMessage_2D_weak (const class GALGAS_AC_5F_canMessage & inSource) ;

  public: GALGAS_AC_5F_canMessage_2D_weak & operator = (const class GALGAS_AC_5F_canMessage & inSource) ;

//--------------------------------- Bang operator
  public: GALGAS_AC_5F_canMessage bang_AC_5F_canMessage_2D_weak (C_Compiler * inCompiler COMMA_LOCATION_ARGS) const ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_AC_5F_canMessage_2D_weak extractObject (const GALGAS_object & inObject,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_AC_5F_canMessage_2D_weak constructor_nil (LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_AC_5F_canMessage_2D_weak & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_AC_5F_canMessage_2D_weak class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_AC_5F_canMessage_2D_weak ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @C_5F_canIndependantMessage reference class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_C_5F_canIndependantMessage : public GALGAS_AC_5F_canMessage {
//--------------------------------- Default constructor
  public: GALGAS_C_5F_canIndependantMessage (void) ;

//--------------------------------- Default GALGAS constructor
  public: static GALGAS_C_5F_canIndependantMessage constructor_default (LOCATION_ARGS) ;

//--------------------------------- Constructor from pointer
  public: GALGAS_C_5F_canIndependantMessage (const class cPtr_C_5F_canIndependantMessage * inSourcePtr) ;

//--------------------------------- Property read access
//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_C_5F_canIndependantMessage extractObject (const GALGAS_object & inObject,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_C_5F_canIndependantMessage constructor_new (LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_C_5F_canIndependantMessage & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_C_5F_canIndependantMessage class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_C_5F_canIndependantMessage ;

#include "separateHeaderFor_C_5F_canIndependantMessage.h"

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @C_5F_canIndependantMessage_2D_weak weak reference class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_C_5F_canIndependantMessage_2D_weak : public GALGAS_AC_5F_canMessage_2D_weak {
//--------------------------------- Default constructor
  public: GALGAS_C_5F_canIndependantMessage_2D_weak (void) ;

//--------------------------------- Default GALGAS constructor
  public: static GALGAS_C_5F_canIndependantMessage_2D_weak constructor_default (LOCATION_ARGS) ;

//--------------------------------- Constructor and assignment from strong reference
  public: GALGAS_C_5F_canIndependantMessage_2D_weak (const class GALGAS_C_5F_canIndependantMessage & inSource) ;

  public: GALGAS_C_5F_canIndependantMessage_2D_weak & operator = (const class GALGAS_C_5F_canIndependantMessage & inSource) ;

//--------------------------------- Bang operator
  public: GALGAS_C_5F_canIndependantMessage bang_C_5F_canIndependantMessage_2D_weak (C_Compiler * inCompiler COMMA_LOCATION_ARGS) const ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_C_5F_canIndependantMessage_2D_weak extractObject (const GALGAS_object & inObject,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_C_5F_canIndependantMessage_2D_weak constructor_nil (LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_C_5F_canIndependantMessage_2D_weak & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_C_5F_canIndependantMessage_2D_weak class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_C_5F_canIndependantMessage_2D_weak ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @C_5F_canMessageFromMessage reference class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_C_5F_canMessageFromMessage : public GALGAS_AC_5F_canMessage {
//--------------------------------- Default constructor
  public: GALGAS_C_5F_canMessageFromMessage (void) ;

//--------------------------------- Default GALGAS constructor
  public: static GALGAS_C_5F_canMessageFromMessage constructor_default (LOCATION_ARGS) ;

//--------------------------------- Constructor from pointer
  public: GALGAS_C_5F_canMessageFromMessage (const class cPtr_C_5F_canMessageFromMessage * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_uint readProperty_mMessageIndex (void) const ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_C_5F_canMessageFromMessage extractObject (const GALGAS_object & inObject,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_C_5F_canMessageFromMessage constructor_new (const class GALGAS_uint & inOperand0
                                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_C_5F_canMessageFromMessage & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setMMessageIndex (class GALGAS_uint inArgument0
                                                         COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_C_5F_canMessageFromMessage class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_C_5F_canMessageFromMessage ;

#include "separateHeaderFor_C_5F_canMessageFromMessage.h"

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @C_5F_canMessageFromMessage_2D_weak weak reference class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_C_5F_canMessageFromMessage_2D_weak : public GALGAS_AC_5F_canMessage_2D_weak {
//--------------------------------- Default constructor
  public: GALGAS_C_5F_canMessageFromMessage_2D_weak (void) ;

//--------------------------------- Default GALGAS constructor
  public: static GALGAS_C_5F_canMessageFromMessage_2D_weak constructor_default (LOCATION_ARGS) ;

//--------------------------------- Constructor and assignment from strong reference
  public: GALGAS_C_5F_canMessageFromMessage_2D_weak (const class GALGAS_C_5F_canMessageFromMessage & inSource) ;

  public: GALGAS_C_5F_canMessageFromMessage_2D_weak & operator = (const class GALGAS_C_5F_canMessageFromMessage & inSource) ;

//--------------------------------- Bang operator
  public: GALGAS_C_5F_canMessageFromMessage bang_C_5F_canMessageFromMessage_2D_weak (C_Compiler * inCompiler COMMA_LOCATION_ARGS) const ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_C_5F_canMessageFromMessage_2D_weak extractObject (const GALGAS_object & inObject,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_C_5F_canMessageFromMessage_2D_weak constructor_nil (LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_C_5F_canMessageFromMessage_2D_weak & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_C_5F_canMessageFromMessage_2D_weak class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_C_5F_canMessageFromMessage_2D_weak ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @C_5F_canMessageFromTask reference class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_C_5F_canMessageFromTask : public GALGAS_AC_5F_canMessage {
//--------------------------------- Default constructor
  public: GALGAS_C_5F_canMessageFromTask (void) ;

//--------------------------------- Default GALGAS constructor
  public: static GALGAS_C_5F_canMessageFromTask constructor_default (LOCATION_ARGS) ;

//--------------------------------- Constructor from pointer
  public: GALGAS_C_5F_canMessageFromTask (const class cPtr_C_5F_canMessageFromTask * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_uint readProperty_mTaskIndex (void) const ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_C_5F_canMessageFromTask extractObject (const GALGAS_object & inObject,
                                                               C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_C_5F_canMessageFromTask constructor_new (const class GALGAS_uint & inOperand0
                                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_C_5F_canMessageFromTask & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setMTaskIndex (class GALGAS_uint inArgument0
                                                      COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_C_5F_canMessageFromTask class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_C_5F_canMessageFromTask ;

#include "separateHeaderFor_C_5F_canMessageFromTask.h"

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @C_5F_canMessageFromTask_2D_weak weak reference class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_C_5F_canMessageFromTask_2D_weak : public GALGAS_AC_5F_canMessage_2D_weak {
//--------------------------------- Default constructor
  public: GALGAS_C_5F_canMessageFromTask_2D_weak (void) ;

//--------------------------------- Default GALGAS constructor
  public: static GALGAS_C_5F_canMessageFromTask_2D_weak constructor_default (LOCATION_ARGS) ;

//--------------------------------- Constructor and assignment from strong reference
  public: GALGAS_C_5F_canMessageFromTask_2D_weak (const class GALGAS_C_5F_canMessageFromTask & inSource) ;

  public: GALGAS_C_5F_canMessageFromTask_2D_weak & operator = (const class GALGAS_C_5F_canMessageFromTask & inSource) ;

//--------------------------------- Bang operator
  public: GALGAS_C_5F_canMessageFromTask bang_C_5F_canMessageFromTask_2D_weak (C_Compiler * inCompiler COMMA_LOCATION_ARGS) const ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_C_5F_canMessageFromTask_2D_weak extractObject (const GALGAS_object & inObject,
                                                                       C_Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_C_5F_canMessageFromTask_2D_weak constructor_nil (LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_C_5F_canMessageFromTask_2D_weak & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_C_5F_canMessageFromTask_2D_weak class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_C_5F_canMessageFromTask_2D_weak ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @M_messages map
//
//----------------------------------------------------------------------------------------------------------------------

class cMapElement_M_5F_messages ;

//----------------------------------------------------------------------------------------------------------------------

extern const char * kSearchErrorMessage_M_5F_messages_searchKey ;

//----------------------------------------------------------------------------------------------------------------------

class GALGAS_M_5F_messages : public AC_GALGAS_map {
//--------------------------------- Default constructor
  public: GALGAS_M_5F_messages (void) ;

//--------------------------------- Handle copy
  public: GALGAS_M_5F_messages (const GALGAS_M_5F_messages & inSource) ;
  public: GALGAS_M_5F_messages & operator = (const GALGAS_M_5F_messages & inSource) ;
  
//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_M_5F_messages extractObject (const GALGAS_object & inObject,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_M_5F_messages constructor_emptyMap (LOCATION_ARGS) ;

  public: static class GALGAS_M_5F_messages constructor_mapWithMapToOverride (const class GALGAS_M_5F_messages & inOperand0
                                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public: VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_lstring & inOperand0,
                                                     const class GALGAS_uint & inOperand1,
                                                     const class GALGAS_luint & inOperand2,
                                                     const class GALGAS_uint & inOperand3,
                                                     const class GALGAS_luint & inOperand4,
                                                     const class GALGAS_luint & inOperand5,
                                                     const class GALGAS_luint & inOperand6,
                                                     const class GALGAS_luint & inOperand7,
                                                     const class GALGAS_luint & inOperand8,
                                                     const class GALGAS_AC_5F_canMessage & inOperand9,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_insertKey (class GALGAS_lstring constinArgument0,
                                                  class GALGAS_uint constinArgument1,
                                                  class GALGAS_luint constinArgument2,
                                                  class GALGAS_uint constinArgument3,
                                                  class GALGAS_luint constinArgument4,
                                                  class GALGAS_luint constinArgument5,
                                                  class GALGAS_luint constinArgument6,
                                                  class GALGAS_luint constinArgument7,
                                                  class GALGAS_luint constinArgument8,
                                                  class GALGAS_AC_5F_canMessage constinArgument9,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMBytesCountForKey (class GALGAS_luint constinArgument0,
                                                             class GALGAS_string constinArgument1,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMClassForKey (class GALGAS_luint constinArgument0,
                                                        class GALGAS_string constinArgument1,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMDeadlineForKey (class GALGAS_luint constinArgument0,
                                                           class GALGAS_string constinArgument1,
                                                           C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMIndexForKey (class GALGAS_uint constinArgument0,
                                                        class GALGAS_string constinArgument1,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMMessageKindForKey (class GALGAS_AC_5F_canMessage constinArgument0,
                                                              class GALGAS_string constinArgument1,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMNetworkIndexForKey (class GALGAS_uint constinArgument0,
                                                               class GALGAS_string constinArgument1,
                                                               C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMOffsetForKey (class GALGAS_luint constinArgument0,
                                                         class GALGAS_string constinArgument1,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMPeriodForKey (class GALGAS_luint constinArgument0,
                                                         class GALGAS_string constinArgument1,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMPriorityForKey (class GALGAS_luint constinArgument0,
                                                           class GALGAS_string constinArgument1,
                                                           C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_searchKey (class GALGAS_lstring constinArgument0,
                                                  class GALGAS_uint & outArgument1,
                                                  class GALGAS_luint & outArgument2,
                                                  class GALGAS_uint & outArgument3,
                                                  class GALGAS_luint & outArgument4,
                                                  class GALGAS_luint & outArgument5,
                                                  class GALGAS_luint & outArgument6,
                                                  class GALGAS_luint & outArgument7,
                                                  class GALGAS_luint & outArgument8,
                                                  class GALGAS_AC_5F_canMessage & outArgument9,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_luint getter_mBytesCountForKey (const class GALGAS_string & constinOperand0,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_luint getter_mClassForKey (const class GALGAS_string & constinOperand0,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_luint getter_mDeadlineForKey (const class GALGAS_string & constinOperand0,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_uint getter_mIndexForKey (const class GALGAS_string & constinOperand0,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_AC_5F_canMessage getter_mMessageKindForKey (const class GALGAS_string & constinOperand0,
                                                                                    C_Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_uint getter_mNetworkIndexForKey (const class GALGAS_string & constinOperand0,
                                                                         C_Compiler * inCompiler
                                                                         COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_luint getter_mOffsetForKey (const class GALGAS_string & constinOperand0,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_luint getter_mPeriodForKey (const class GALGAS_string & constinOperand0,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_luint getter_mPriorityForKey (const class GALGAS_string & constinOperand0,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_M_5F_messages getter_overriddenMap (C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) const ;


//--------------------------------- Optional Methods
  public: VIRTUAL_IN_DEBUG bool optional_searchKey (const class GALGAS_string & constinOperand0,
                                                    class GALGAS_uint & outOperand1,
                                                    class GALGAS_luint & outOperand2,
                                                    class GALGAS_uint & outOperand3,
                                                    class GALGAS_luint & outOperand4,
                                                    class GALGAS_luint & outOperand5,
                                                    class GALGAS_luint & outOperand6,
                                                    class GALGAS_luint & outOperand7,
                                                    class GALGAS_luint & outOperand8,
                                                    class GALGAS_AC_5F_canMessage & outOperand9) const ;


//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
  public: VIRTUAL_IN_DEBUG cMapElement_M_5F_messages * readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                          const GALGAS_string & inKey
                                                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- Friend

  friend class cEnumerator_M_5F_messages ;
 
} ; // End of GALGAS_M_5F_messages class

//----------------------------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//----------------------------------------------------------------------------------------------------------------------

class cEnumerator_M_5F_messages : public cGenericAbstractEnumerator {
  public: cEnumerator_M_5F_messages (const GALGAS_M_5F_messages & inEnumeratedObject,
                                     const typeEnumerationOrder inOrder) ;

//--- Current element access
  public: class GALGAS_lstring current_lkey (LOCATION_ARGS) const ;
  public: class GALGAS_uint current_mIndex (LOCATION_ARGS) const ;
  public: class GALGAS_luint current_mClass (LOCATION_ARGS) const ;
  public: class GALGAS_uint current_mNetworkIndex (LOCATION_ARGS) const ;
  public: class GALGAS_luint current_mBytesCount (LOCATION_ARGS) const ;
  public: class GALGAS_luint current_mPriority (LOCATION_ARGS) const ;
  public: class GALGAS_luint current_mOffset (LOCATION_ARGS) const ;
  public: class GALGAS_luint current_mDeadline (LOCATION_ARGS) const ;
  public: class GALGAS_luint current_mPeriod (LOCATION_ARGS) const ;
  public: class GALGAS_AC_5F_canMessage current_mMessageKind (LOCATION_ARGS) const ;
//--- Current element access
  public: class GALGAS_M_5F_messages_2D_element current (LOCATION_ARGS) const ;
} ;

//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_M_5F_messages ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: class for element of '@M_messages' map
//
//----------------------------------------------------------------------------------------------------------------------

class cMapElement_M_5F_messages : public cMapElement {
//--- Map attributes
  public: GALGAS_uint mProperty_mIndex ;
  public: GALGAS_luint mProperty_mClass ;
  public: GALGAS_uint mProperty_mNetworkIndex ;
  public: GALGAS_luint mProperty_mBytesCount ;
  public: GALGAS_luint mProperty_mPriority ;
  public: GALGAS_luint mProperty_mOffset ;
  public: GALGAS_luint mProperty_mDeadline ;
  public: GALGAS_luint mProperty_mPeriod ;
  public: GALGAS_AC_5F_canMessage mProperty_mMessageKind ;

//--- Constructor
  public: cMapElement_M_5F_messages (const GALGAS_lstring & inKey,
                                     const GALGAS_uint & in_mIndex,
                                     const GALGAS_luint & in_mClass,
                                     const GALGAS_uint & in_mNetworkIndex,
                                     const GALGAS_luint & in_mBytesCount,
                                     const GALGAS_luint & in_mPriority,
                                     const GALGAS_luint & in_mOffset,
                                     const GALGAS_luint & in_mDeadline,
                                     const GALGAS_luint & in_mPeriod,
                                     const GALGAS_AC_5F_canMessage & in_mMessageKind
                                     COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public: virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public: virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public: virtual cMapElement * copy (void) ;

//--- Description
 public: virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @M_5F_messages_2D_element struct
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_M_5F_messages_2D_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GALGAS_lstring mProperty_lkey ;
  public: inline GALGAS_lstring readProperty_lkey (void) const {
    return mProperty_lkey ;
  }

  public: GALGAS_uint mProperty_mIndex ;
  public: inline GALGAS_uint readProperty_mIndex (void) const {
    return mProperty_mIndex ;
  }

  public: GALGAS_luint mProperty_mClass ;
  public: inline GALGAS_luint readProperty_mClass (void) const {
    return mProperty_mClass ;
  }

  public: GALGAS_uint mProperty_mNetworkIndex ;
  public: inline GALGAS_uint readProperty_mNetworkIndex (void) const {
    return mProperty_mNetworkIndex ;
  }

  public: GALGAS_luint mProperty_mBytesCount ;
  public: inline GALGAS_luint readProperty_mBytesCount (void) const {
    return mProperty_mBytesCount ;
  }

  public: GALGAS_luint mProperty_mPriority ;
  public: inline GALGAS_luint readProperty_mPriority (void) const {
    return mProperty_mPriority ;
  }

  public: GALGAS_luint mProperty_mOffset ;
  public: inline GALGAS_luint readProperty_mOffset (void) const {
    return mProperty_mOffset ;
  }

  public: GALGAS_luint mProperty_mDeadline ;
  public: inline GALGAS_luint readProperty_mDeadline (void) const {
    return mProperty_mDeadline ;
  }

  public: GALGAS_luint mProperty_mPeriod ;
  public: inline GALGAS_luint readProperty_mPeriod (void) const {
    return mProperty_mPeriod ;
  }

  public: GALGAS_AC_5F_canMessage mProperty_mMessageKind ;
  public: inline GALGAS_AC_5F_canMessage readProperty_mMessageKind (void) const {
    return mProperty_mMessageKind ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default constructor
  public: GALGAS_M_5F_messages_2D_element (void) ;

//--------------------------------- Property setters
  public: inline void setter_setLkey (const GALGAS_lstring & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_lkey = inValue ;
  }

  public: inline void setter_setMIndex (const GALGAS_uint & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mIndex = inValue ;
  }

  public: inline void setter_setMClass (const GALGAS_luint & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mClass = inValue ;
  }

  public: inline void setter_setMNetworkIndex (const GALGAS_uint & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mNetworkIndex = inValue ;
  }

  public: inline void setter_setMBytesCount (const GALGAS_luint & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mBytesCount = inValue ;
  }

  public: inline void setter_setMPriority (const GALGAS_luint & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mPriority = inValue ;
  }

  public: inline void setter_setMOffset (const GALGAS_luint & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mOffset = inValue ;
  }

  public: inline void setter_setMDeadline (const GALGAS_luint & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mDeadline = inValue ;
  }

  public: inline void setter_setMPeriod (const GALGAS_luint & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mPeriod = inValue ;
  }

  public: inline void setter_setMMessageKind (const GALGAS_AC_5F_canMessage & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mMessageKind = inValue ;
  }

//--------------------------------- Virtual destructor (in debug mode)
  public: virtual ~ GALGAS_M_5F_messages_2D_element (void) ;

//--------------------------------- Native constructor
  public: GALGAS_M_5F_messages_2D_element (const GALGAS_lstring & in_lkey,
                                           const GALGAS_uint & in_mIndex,
                                           const GALGAS_luint & in_mClass,
                                           const GALGAS_uint & in_mNetworkIndex,
                                           const GALGAS_luint & in_mBytesCount,
                                           const GALGAS_luint & in_mPriority,
                                           const GALGAS_luint & in_mOffset,
                                           const GALGAS_luint & in_mDeadline,
                                           const GALGAS_luint & in_mPeriod,
                                           const GALGAS_AC_5F_canMessage & in_mMessageKind) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_M_5F_messages_2D_element extractObject (const GALGAS_object & inObject,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_M_5F_messages_2D_element constructor_new (const class GALGAS_lstring & inOperand0,
                                                                        const class GALGAS_uint & inOperand1,
                                                                        const class GALGAS_luint & inOperand2,
                                                                        const class GALGAS_uint & inOperand3,
                                                                        const class GALGAS_luint & inOperand4,
                                                                        const class GALGAS_luint & inOperand5,
                                                                        const class GALGAS_luint & inOperand6,
                                                                        const class GALGAS_luint & inOperand7,
                                                                        const class GALGAS_luint & inOperand8,
                                                                        const class GALGAS_AC_5F_canMessage & inOperand9
                                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_M_5F_messages_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_M_5F_messages_2D_element class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_M_5F_messages_2D_element ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @AC_5F_task reference class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_AC_5F_task : public AC_GALGAS_reference_class {
//--------------------------------- Default constructor
  public: GALGAS_AC_5F_task (void) ;

//--------------------------------- Constructor from pointer
  public: GALGAS_AC_5F_task (const class cPtr_AC_5F_task * inSourcePtr) ;

//--------------------------------- Property read access
//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_AC_5F_task extractObject (const GALGAS_object & inObject,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_AC_5F_task & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_AC_5F_task class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_AC_5F_task ;

#include "separateHeaderFor_AC_5F_task.h"

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @AC_5F_task_2D_weak weak reference class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_AC_5F_task_2D_weak : public AC_GALGAS_weak_reference {
//--------------------------------- Default constructor
  public: GALGAS_AC_5F_task_2D_weak (void) ;

//--------------------------------- Default GALGAS constructor
  public: static GALGAS_AC_5F_task_2D_weak constructor_default (LOCATION_ARGS) ;

//--------------------------------- Constructor and assignment from strong reference
  public: GALGAS_AC_5F_task_2D_weak (const class GALGAS_AC_5F_task & inSource) ;

  public: GALGAS_AC_5F_task_2D_weak & operator = (const class GALGAS_AC_5F_task & inSource) ;

//--------------------------------- Bang operator
  public: GALGAS_AC_5F_task bang_AC_5F_task_2D_weak (C_Compiler * inCompiler COMMA_LOCATION_ARGS) const ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_AC_5F_task_2D_weak extractObject (const GALGAS_object & inObject,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_AC_5F_task_2D_weak constructor_nil (LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_AC_5F_task_2D_weak & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_AC_5F_task_2D_weak class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_AC_5F_task_2D_weak ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @C_5F_independantTask reference class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_C_5F_independantTask : public GALGAS_AC_5F_task {
//--------------------------------- Default constructor
  public: GALGAS_C_5F_independantTask (void) ;

//--------------------------------- Default GALGAS constructor
  public: static GALGAS_C_5F_independantTask constructor_default (LOCATION_ARGS) ;

//--------------------------------- Constructor from pointer
  public: GALGAS_C_5F_independantTask (const class cPtr_C_5F_independantTask * inSourcePtr) ;

//--------------------------------- Property read access
//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_C_5F_independantTask extractObject (const GALGAS_object & inObject,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_C_5F_independantTask constructor_new (LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_C_5F_independantTask & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_C_5F_independantTask class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_C_5F_independantTask ;

#include "separateHeaderFor_C_5F_independantTask.h"

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @C_5F_independantTask_2D_weak weak reference class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_C_5F_independantTask_2D_weak : public GALGAS_AC_5F_task_2D_weak {
//--------------------------------- Default constructor
  public: GALGAS_C_5F_independantTask_2D_weak (void) ;

//--------------------------------- Default GALGAS constructor
  public: static GALGAS_C_5F_independantTask_2D_weak constructor_default (LOCATION_ARGS) ;

//--------------------------------- Constructor and assignment from strong reference
  public: GALGAS_C_5F_independantTask_2D_weak (const class GALGAS_C_5F_independantTask & inSource) ;

  public: GALGAS_C_5F_independantTask_2D_weak & operator = (const class GALGAS_C_5F_independantTask & inSource) ;

//--------------------------------- Bang operator
  public: GALGAS_C_5F_independantTask bang_C_5F_independantTask_2D_weak (C_Compiler * inCompiler COMMA_LOCATION_ARGS) const ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_C_5F_independantTask_2D_weak extractObject (const GALGAS_object & inObject,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_C_5F_independantTask_2D_weak constructor_nil (LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_C_5F_independantTask_2D_weak & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_C_5F_independantTask_2D_weak class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_C_5F_independantTask_2D_weak ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @C_5F_taskDependsFromTask reference class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_C_5F_taskDependsFromTask : public GALGAS_AC_5F_task {
//--------------------------------- Default constructor
  public: GALGAS_C_5F_taskDependsFromTask (void) ;

//--------------------------------- Default GALGAS constructor
  public: static GALGAS_C_5F_taskDependsFromTask constructor_default (LOCATION_ARGS) ;

//--------------------------------- Constructor from pointer
  public: GALGAS_C_5F_taskDependsFromTask (const class cPtr_C_5F_taskDependsFromTask * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_uint readProperty_mTask (void) const ;

  public: class GALGAS_luint readProperty_mEvery (void) const ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_C_5F_taskDependsFromTask extractObject (const GALGAS_object & inObject,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_C_5F_taskDependsFromTask constructor_new (const class GALGAS_uint & inOperand0,
                                                                        const class GALGAS_luint & inOperand1
                                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_C_5F_taskDependsFromTask & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setMEvery (class GALGAS_luint inArgument0
                                                  COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMTask (class GALGAS_uint inArgument0
                                                 COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_C_5F_taskDependsFromTask class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_C_5F_taskDependsFromTask ;

#include "separateHeaderFor_C_5F_taskDependsFromTask.h"

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @C_5F_taskDependsFromTask_2D_weak weak reference class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_C_5F_taskDependsFromTask_2D_weak : public GALGAS_AC_5F_task_2D_weak {
//--------------------------------- Default constructor
  public: GALGAS_C_5F_taskDependsFromTask_2D_weak (void) ;

//--------------------------------- Default GALGAS constructor
  public: static GALGAS_C_5F_taskDependsFromTask_2D_weak constructor_default (LOCATION_ARGS) ;

//--------------------------------- Constructor and assignment from strong reference
  public: GALGAS_C_5F_taskDependsFromTask_2D_weak (const class GALGAS_C_5F_taskDependsFromTask & inSource) ;

  public: GALGAS_C_5F_taskDependsFromTask_2D_weak & operator = (const class GALGAS_C_5F_taskDependsFromTask & inSource) ;

//--------------------------------- Bang operator
  public: GALGAS_C_5F_taskDependsFromTask bang_C_5F_taskDependsFromTask_2D_weak (C_Compiler * inCompiler COMMA_LOCATION_ARGS) const ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_C_5F_taskDependsFromTask_2D_weak extractObject (const GALGAS_object & inObject,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_C_5F_taskDependsFromTask_2D_weak constructor_nil (LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_C_5F_taskDependsFromTask_2D_weak & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_C_5F_taskDependsFromTask_2D_weak class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_C_5F_taskDependsFromTask_2D_weak ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @C_5F_taskDependsFromMessage reference class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_C_5F_taskDependsFromMessage : public GALGAS_AC_5F_task {
//--------------------------------- Default constructor
  public: GALGAS_C_5F_taskDependsFromMessage (void) ;

//--------------------------------- Default GALGAS constructor
  public: static GALGAS_C_5F_taskDependsFromMessage constructor_default (LOCATION_ARGS) ;

//--------------------------------- Constructor from pointer
  public: GALGAS_C_5F_taskDependsFromMessage (const class cPtr_C_5F_taskDependsFromMessage * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_uint readProperty_mMessage (void) const ;

  public: class GALGAS_luint readProperty_mEvery (void) const ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_C_5F_taskDependsFromMessage extractObject (const GALGAS_object & inObject,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_C_5F_taskDependsFromMessage constructor_new (const class GALGAS_uint & inOperand0,
                                                                           const class GALGAS_luint & inOperand1
                                                                           COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_C_5F_taskDependsFromMessage & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setMEvery (class GALGAS_luint inArgument0
                                                  COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMMessage (class GALGAS_uint inArgument0
                                                    COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_C_5F_taskDependsFromMessage class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_C_5F_taskDependsFromMessage ;

#include "separateHeaderFor_C_5F_taskDependsFromMessage.h"

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @C_5F_taskDependsFromMessage_2D_weak weak reference class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_C_5F_taskDependsFromMessage_2D_weak : public GALGAS_AC_5F_task_2D_weak {
//--------------------------------- Default constructor
  public: GALGAS_C_5F_taskDependsFromMessage_2D_weak (void) ;

//--------------------------------- Default GALGAS constructor
  public: static GALGAS_C_5F_taskDependsFromMessage_2D_weak constructor_default (LOCATION_ARGS) ;

//--------------------------------- Constructor and assignment from strong reference
  public: GALGAS_C_5F_taskDependsFromMessage_2D_weak (const class GALGAS_C_5F_taskDependsFromMessage & inSource) ;

  public: GALGAS_C_5F_taskDependsFromMessage_2D_weak & operator = (const class GALGAS_C_5F_taskDependsFromMessage & inSource) ;

//--------------------------------- Bang operator
  public: GALGAS_C_5F_taskDependsFromMessage bang_C_5F_taskDependsFromMessage_2D_weak (C_Compiler * inCompiler COMMA_LOCATION_ARGS) const ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_C_5F_taskDependsFromMessage_2D_weak extractObject (const GALGAS_object & inObject,
                                                                           C_Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_C_5F_taskDependsFromMessage_2D_weak constructor_nil (LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_C_5F_taskDependsFromMessage_2D_weak & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_C_5F_taskDependsFromMessage_2D_weak class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_C_5F_taskDependsFromMessage_2D_weak ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @M_tasks map
//
//----------------------------------------------------------------------------------------------------------------------

class cMapElement_M_5F_tasks ;

//----------------------------------------------------------------------------------------------------------------------

extern const char * kSearchErrorMessage_M_5F_tasks_searchKey ;

//----------------------------------------------------------------------------------------------------------------------

class GALGAS_M_5F_tasks : public AC_GALGAS_map {
//--------------------------------- Default constructor
  public: GALGAS_M_5F_tasks (void) ;

//--------------------------------- Handle copy
  public: GALGAS_M_5F_tasks (const GALGAS_M_5F_tasks & inSource) ;
  public: GALGAS_M_5F_tasks & operator = (const GALGAS_M_5F_tasks & inSource) ;
  
//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_M_5F_tasks extractObject (const GALGAS_object & inObject,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_M_5F_tasks constructor_emptyMap (LOCATION_ARGS) ;

  public: static class GALGAS_M_5F_tasks constructor_mapWithMapToOverride (const class GALGAS_M_5F_tasks & inOperand0
                                                                           COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public: VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_lstring & inOperand0,
                                                     const class GALGAS_uint & inOperand1,
                                                     const class GALGAS_luint & inOperand2,
                                                     const class GALGAS_luint & inOperand3,
                                                     const class GALGAS_luint & inOperand4,
                                                     const class GALGAS_luint & inOperand5,
                                                     const class GALGAS_luint & inOperand6,
                                                     const class GALGAS_uint & inOperand7,
                                                     const class GALGAS_luint & inOperand8,
                                                     const class GALGAS_AC_5F_task & inOperand9,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_insertKey (class GALGAS_lstring constinArgument0,
                                                  class GALGAS_uint constinArgument1,
                                                  class GALGAS_luint constinArgument2,
                                                  class GALGAS_luint constinArgument3,
                                                  class GALGAS_luint constinArgument4,
                                                  class GALGAS_luint constinArgument5,
                                                  class GALGAS_luint constinArgument6,
                                                  class GALGAS_uint constinArgument7,
                                                  class GALGAS_luint constinArgument8,
                                                  class GALGAS_AC_5F_task constinArgument9,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMDeadlineForKey (class GALGAS_luint constinArgument0,
                                                           class GALGAS_string constinArgument1,
                                                           C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMDurationMaxForKey (class GALGAS_luint constinArgument0,
                                                              class GALGAS_string constinArgument1,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMDurationMinForKey (class GALGAS_luint constinArgument0,
                                                              class GALGAS_string constinArgument1,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMIndexForKey (class GALGAS_uint constinArgument0,
                                                        class GALGAS_string constinArgument1,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMOffsetForKey (class GALGAS_luint constinArgument0,
                                                         class GALGAS_string constinArgument1,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMPeriodForKey (class GALGAS_luint constinArgument0,
                                                         class GALGAS_string constinArgument1,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMPriorityForKey (class GALGAS_luint constinArgument0,
                                                           class GALGAS_string constinArgument1,
                                                           C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMProcessorForKey (class GALGAS_uint constinArgument0,
                                                            class GALGAS_string constinArgument1,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMTaskKindForKey (class GALGAS_AC_5F_task constinArgument0,
                                                           class GALGAS_string constinArgument1,
                                                           C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_searchKey (class GALGAS_lstring constinArgument0,
                                                  class GALGAS_uint & outArgument1,
                                                  class GALGAS_luint & outArgument2,
                                                  class GALGAS_luint & outArgument3,
                                                  class GALGAS_luint & outArgument4,
                                                  class GALGAS_luint & outArgument5,
                                                  class GALGAS_luint & outArgument6,
                                                  class GALGAS_uint & outArgument7,
                                                  class GALGAS_luint & outArgument8,
                                                  class GALGAS_AC_5F_task & outArgument9,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_luint getter_mDeadlineForKey (const class GALGAS_string & constinOperand0,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_luint getter_mDurationMaxForKey (const class GALGAS_string & constinOperand0,
                                                                         C_Compiler * inCompiler
                                                                         COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_luint getter_mDurationMinForKey (const class GALGAS_string & constinOperand0,
                                                                         C_Compiler * inCompiler
                                                                         COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_uint getter_mIndexForKey (const class GALGAS_string & constinOperand0,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_luint getter_mOffsetForKey (const class GALGAS_string & constinOperand0,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_luint getter_mPeriodForKey (const class GALGAS_string & constinOperand0,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_luint getter_mPriorityForKey (const class GALGAS_string & constinOperand0,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_uint getter_mProcessorForKey (const class GALGAS_string & constinOperand0,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_AC_5F_task getter_mTaskKindForKey (const class GALGAS_string & constinOperand0,
                                                                           C_Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_M_5F_tasks getter_overriddenMap (C_Compiler * inCompiler
                                                                         COMMA_LOCATION_ARGS) const ;


//--------------------------------- Optional Methods
  public: VIRTUAL_IN_DEBUG bool optional_searchKey (const class GALGAS_string & constinOperand0,
                                                    class GALGAS_uint & outOperand1,
                                                    class GALGAS_luint & outOperand2,
                                                    class GALGAS_luint & outOperand3,
                                                    class GALGAS_luint & outOperand4,
                                                    class GALGAS_luint & outOperand5,
                                                    class GALGAS_luint & outOperand6,
                                                    class GALGAS_uint & outOperand7,
                                                    class GALGAS_luint & outOperand8,
                                                    class GALGAS_AC_5F_task & outOperand9) const ;


//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
  public: VIRTUAL_IN_DEBUG cMapElement_M_5F_tasks * readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                       const GALGAS_string & inKey
                                                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- Friend

  friend class cEnumerator_M_5F_tasks ;
 
} ; // End of GALGAS_M_5F_tasks class

//----------------------------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//----------------------------------------------------------------------------------------------------------------------

class cEnumerator_M_5F_tasks : public cGenericAbstractEnumerator {
  public: cEnumerator_M_5F_tasks (const GALGAS_M_5F_tasks & inEnumeratedObject,
                                  const typeEnumerationOrder inOrder) ;

//--- Current element access
  public: class GALGAS_lstring current_lkey (LOCATION_ARGS) const ;
  public: class GALGAS_uint current_mIndex (LOCATION_ARGS) const ;
  public: class GALGAS_luint current_mPriority (LOCATION_ARGS) const ;
  public: class GALGAS_luint current_mOffset (LOCATION_ARGS) const ;
  public: class GALGAS_luint current_mDeadline (LOCATION_ARGS) const ;
  public: class GALGAS_luint current_mDurationMin (LOCATION_ARGS) const ;
  public: class GALGAS_luint current_mDurationMax (LOCATION_ARGS) const ;
  public: class GALGAS_uint current_mProcessor (LOCATION_ARGS) const ;
  public: class GALGAS_luint current_mPeriod (LOCATION_ARGS) const ;
  public: class GALGAS_AC_5F_task current_mTaskKind (LOCATION_ARGS) const ;
//--- Current element access
  public: class GALGAS_M_5F_tasks_2D_element current (LOCATION_ARGS) const ;
} ;

//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_M_5F_tasks ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: class for element of '@M_tasks' map
//
//----------------------------------------------------------------------------------------------------------------------

class cMapElement_M_5F_tasks : public cMapElement {
//--- Map attributes
  public: GALGAS_uint mProperty_mIndex ;
  public: GALGAS_luint mProperty_mPriority ;
  public: GALGAS_luint mProperty_mOffset ;
  public: GALGAS_luint mProperty_mDeadline ;
  public: GALGAS_luint mProperty_mDurationMin ;
  public: GALGAS_luint mProperty_mDurationMax ;
  public: GALGAS_uint mProperty_mProcessor ;
  public: GALGAS_luint mProperty_mPeriod ;
  public: GALGAS_AC_5F_task mProperty_mTaskKind ;

//--- Constructor
  public: cMapElement_M_5F_tasks (const GALGAS_lstring & inKey,
                                  const GALGAS_uint & in_mIndex,
                                  const GALGAS_luint & in_mPriority,
                                  const GALGAS_luint & in_mOffset,
                                  const GALGAS_luint & in_mDeadline,
                                  const GALGAS_luint & in_mDurationMin,
                                  const GALGAS_luint & in_mDurationMax,
                                  const GALGAS_uint & in_mProcessor,
                                  const GALGAS_luint & in_mPeriod,
                                  const GALGAS_AC_5F_task & in_mTaskKind
                                  COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public: virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public: virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public: virtual cMapElement * copy (void) ;

//--- Description
 public: virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @M_5F_tasks_2D_element struct
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_M_5F_tasks_2D_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GALGAS_lstring mProperty_lkey ;
  public: inline GALGAS_lstring readProperty_lkey (void) const {
    return mProperty_lkey ;
  }

  public: GALGAS_uint mProperty_mIndex ;
  public: inline GALGAS_uint readProperty_mIndex (void) const {
    return mProperty_mIndex ;
  }

  public: GALGAS_luint mProperty_mPriority ;
  public: inline GALGAS_luint readProperty_mPriority (void) const {
    return mProperty_mPriority ;
  }

  public: GALGAS_luint mProperty_mOffset ;
  public: inline GALGAS_luint readProperty_mOffset (void) const {
    return mProperty_mOffset ;
  }

  public: GALGAS_luint mProperty_mDeadline ;
  public: inline GALGAS_luint readProperty_mDeadline (void) const {
    return mProperty_mDeadline ;
  }

  public: GALGAS_luint mProperty_mDurationMin ;
  public: inline GALGAS_luint readProperty_mDurationMin (void) const {
    return mProperty_mDurationMin ;
  }

  public: GALGAS_luint mProperty_mDurationMax ;
  public: inline GALGAS_luint readProperty_mDurationMax (void) const {
    return mProperty_mDurationMax ;
  }

  public: GALGAS_uint mProperty_mProcessor ;
  public: inline GALGAS_uint readProperty_mProcessor (void) const {
    return mProperty_mProcessor ;
  }

  public: GALGAS_luint mProperty_mPeriod ;
  public: inline GALGAS_luint readProperty_mPeriod (void) const {
    return mProperty_mPeriod ;
  }

  public: GALGAS_AC_5F_task mProperty_mTaskKind ;
  public: inline GALGAS_AC_5F_task readProperty_mTaskKind (void) const {
    return mProperty_mTaskKind ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default constructor
  public: GALGAS_M_5F_tasks_2D_element (void) ;

//--------------------------------- Property setters
  public: inline void setter_setLkey (const GALGAS_lstring & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_lkey = inValue ;
  }

  public: inline void setter_setMIndex (const GALGAS_uint & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mIndex = inValue ;
  }

  public: inline void setter_setMPriority (const GALGAS_luint & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mPriority = inValue ;
  }

  public: inline void setter_setMOffset (const GALGAS_luint & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mOffset = inValue ;
  }

  public: inline void setter_setMDeadline (const GALGAS_luint & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mDeadline = inValue ;
  }

  public: inline void setter_setMDurationMin (const GALGAS_luint & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mDurationMin = inValue ;
  }

  public: inline void setter_setMDurationMax (const GALGAS_luint & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mDurationMax = inValue ;
  }

  public: inline void setter_setMProcessor (const GALGAS_uint & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mProcessor = inValue ;
  }

  public: inline void setter_setMPeriod (const GALGAS_luint & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mPeriod = inValue ;
  }

  public: inline void setter_setMTaskKind (const GALGAS_AC_5F_task & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mTaskKind = inValue ;
  }

//--------------------------------- Virtual destructor (in debug mode)
  public: virtual ~ GALGAS_M_5F_tasks_2D_element (void) ;

//--------------------------------- Native constructor
  public: GALGAS_M_5F_tasks_2D_element (const GALGAS_lstring & in_lkey,
                                        const GALGAS_uint & in_mIndex,
                                        const GALGAS_luint & in_mPriority,
                                        const GALGAS_luint & in_mOffset,
                                        const GALGAS_luint & in_mDeadline,
                                        const GALGAS_luint & in_mDurationMin,
                                        const GALGAS_luint & in_mDurationMax,
                                        const GALGAS_uint & in_mProcessor,
                                        const GALGAS_luint & in_mPeriod,
                                        const GALGAS_AC_5F_task & in_mTaskKind) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_M_5F_tasks_2D_element extractObject (const GALGAS_object & inObject,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_M_5F_tasks_2D_element constructor_new (const class GALGAS_lstring & inOperand0,
                                                                     const class GALGAS_uint & inOperand1,
                                                                     const class GALGAS_luint & inOperand2,
                                                                     const class GALGAS_luint & inOperand3,
                                                                     const class GALGAS_luint & inOperand4,
                                                                     const class GALGAS_luint & inOperand5,
                                                                     const class GALGAS_luint & inOperand6,
                                                                     const class GALGAS_uint & inOperand7,
                                                                     const class GALGAS_luint & inOperand8,
                                                                     const class GALGAS_AC_5F_task & inOperand9
                                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_M_5F_tasks_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_M_5F_tasks_2D_element class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_M_5F_tasks_2D_element ;

//----------------------------------------------------------------------------------------------------------------------
//
//Parser class 'oa_parser' declaration
//
//----------------------------------------------------------------------------------------------------------------------

class cParser_oa_5F_parser {
//--- Virtual destructor
  public: virtual ~ cParser_oa_5F_parser (void) {}

//--- Non terminal declarations
  protected: virtual void nt_axiome_ (class C_Lexique_oa_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_axiome_parse (class C_Lexique_oa_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_axiome_indexing (class C_Lexique_oa_5F_scanner * inLexique) = 0 ;


//--- Rule declarations
  protected: void rule_oa_5F_parser_axiome_i0_ (C_Lexique_oa_5F_scanner * inLexique) ;

  protected: void rule_oa_5F_parser_axiome_i0_parse (C_Lexique_oa_5F_scanner * inLexique) ;

  protected: void rule_oa_5F_parser_axiome_i0_indexing (C_Lexique_oa_5F_scanner * inLexique) ;



//--- Select methods
  protected: virtual int32_t select_oa_5F_parser_0 (C_Lexique_oa_5F_scanner *) = 0 ;

  protected: virtual int32_t select_oa_5F_parser_1 (C_Lexique_oa_5F_scanner *) = 0 ;

  protected: virtual int32_t select_oa_5F_parser_2 (C_Lexique_oa_5F_scanner *) = 0 ;

  protected: virtual int32_t select_oa_5F_parser_3 (C_Lexique_oa_5F_scanner *) = 0 ;

  protected: virtual int32_t select_oa_5F_parser_4 (C_Lexique_oa_5F_scanner *) = 0 ;

  protected: virtual int32_t select_oa_5F_parser_5 (C_Lexique_oa_5F_scanner *) = 0 ;

  protected: virtual int32_t select_oa_5F_parser_6 (C_Lexique_oa_5F_scanner *) = 0 ;

  protected: virtual int32_t select_oa_5F_parser_7 (C_Lexique_oa_5F_scanner *) = 0 ;

  protected: virtual int32_t select_oa_5F_parser_8 (C_Lexique_oa_5F_scanner *) = 0 ;

  protected: virtual int32_t select_oa_5F_parser_9 (C_Lexique_oa_5F_scanner *) = 0 ;

  protected: virtual int32_t select_oa_5F_parser_10 (C_Lexique_oa_5F_scanner *) = 0 ;

  protected: virtual int32_t select_oa_5F_parser_11 (C_Lexique_oa_5F_scanner *) = 0 ;

  protected: virtual int32_t select_oa_5F_parser_12 (C_Lexique_oa_5F_scanner *) = 0 ;

  protected: virtual int32_t select_oa_5F_parser_13 (C_Lexique_oa_5F_scanner *) = 0 ;

  protected: virtual int32_t select_oa_5F_parser_14 (C_Lexique_oa_5F_scanner *) = 0 ;


} ;

//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'performComputations'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_performComputations (class GALGAS_M_5F_processor & ioArgument0,
                                  class GALGAS_M_5F_network & ioArgument1,
                                  class GALGAS_M_5F_messages & ioArgument2,
                                  class GALGAS_M_5F_tasks & ioArgument3,
                                  class C_Compiler * inCompiler
                                  COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//  GRAMMAR oa_grammar
//----------------------------------------------------------------------------------------------------------------------

class cGrammar_oa_5F_grammar : public cParser_oa_5F_parser {
//------------------------------------- 'axiome' non terminal
//--- 'parse' label
  public: virtual void nt_axiome_parse (C_Lexique_oa_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_axiome_indexing (C_Lexique_oa_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_axiome_ (C_Lexique_oa_5F_scanner * inCompiler) ;

//--- Start symbol
  public: static void _performSourceFileParsing_ (C_Compiler * inCompiler,
                                                  GALGAS_lstring inFileName
                                                  COMMA_LOCATION_ARGS) ;

  public: static void _performSourceStringParsing_ (C_Compiler * inCompiler,
                                                    GALGAS_string inSourceString,
                                                    GALGAS_string inNameString
                                                    COMMA_LOCATION_ARGS) ;

//--- Indexing
  public: static void performIndexing (C_Compiler * inCompiler,
                                       const C_String & inSourceFilePath) ;

//--- Only lexical analysis
  public: static void performOnlyLexicalAnalysis (C_Compiler * inCompiler,
                                                  const C_String & inSourceFilePath) ;

//--- Only syntax analysis
  public: static void performOnlySyntaxAnalysis (C_Compiler * inCompiler,
                                                 const C_String & inSourceFilePath) ;

  public: virtual int32_t select_oa_5F_parser_0 (C_Lexique_oa_5F_scanner *) ;

  public: virtual int32_t select_oa_5F_parser_1 (C_Lexique_oa_5F_scanner *) ;

  public: virtual int32_t select_oa_5F_parser_2 (C_Lexique_oa_5F_scanner *) ;

  public: virtual int32_t select_oa_5F_parser_3 (C_Lexique_oa_5F_scanner *) ;

  public: virtual int32_t select_oa_5F_parser_4 (C_Lexique_oa_5F_scanner *) ;

  public: virtual int32_t select_oa_5F_parser_5 (C_Lexique_oa_5F_scanner *) ;

  public: virtual int32_t select_oa_5F_parser_6 (C_Lexique_oa_5F_scanner *) ;

  public: virtual int32_t select_oa_5F_parser_7 (C_Lexique_oa_5F_scanner *) ;

  public: virtual int32_t select_oa_5F_parser_8 (C_Lexique_oa_5F_scanner *) ;

  public: virtual int32_t select_oa_5F_parser_9 (C_Lexique_oa_5F_scanner *) ;

  public: virtual int32_t select_oa_5F_parser_10 (C_Lexique_oa_5F_scanner *) ;

  public: virtual int32_t select_oa_5F_parser_11 (C_Lexique_oa_5F_scanner *) ;

  public: virtual int32_t select_oa_5F_parser_12 (C_Lexique_oa_5F_scanner *) ;

  public: virtual int32_t select_oa_5F_parser_13 (C_Lexique_oa_5F_scanner *) ;

  public: virtual int32_t select_oa_5F_parser_14 (C_Lexique_oa_5F_scanner *) ;
} ;

//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
//
//                               Bool options                                                    
//
//----------------------------------------------------------------------------------------------------------------------

extern C_BoolCommandLineOption gOption_oa_5F_cli_5F_options_createIntermediateFiles ;

extern C_BoolCommandLineOption gOption_oa_5F_cli_5F_options_useCANmaxLegth ;

//----------------------------------------------------------------------------------------------------------------------
//
//                               UInt options                                                    
//
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
//
//                              String options                                                   
//
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
//
//                              String List options                                              
//
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------

