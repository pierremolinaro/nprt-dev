#pragma once

//--------------------------------------------------------------------------------------------------

#include "all-predefined-types.h"

//--------------------------------------------------------------------------------------------------


//--------------------------------------------------------------------------------------------------
//
// Phase 1: @2lstringlist list
//
//--------------------------------------------------------------------------------------------------

class GGS__32_lstringlist : public AC_GALGAS_list {
//--------------------------------- Default constructor
  public: GGS__32_lstringlist (void) ;

//--------------------------------- List constructor used by listmap
  public: GGS__32_lstringlist (const capCollectionElementArray & inSharedArray) ;

//--------------------------------- Element constructor
  public: static void makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                 const class GGS_lstring & in_mValue_30_,
                                                 const class GGS_lstring & in_mValue_31_
                                                 COMMA_LOCATION_ARGS) ;

//-- Start of type generic part

//--------------------------------- Initializers
  public: static GGS__32_lstringlist init (Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) ;

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GGS__32_lstringlist extractObject (const GGS_object & inObject,
                                                    Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GGS__32_lstringlist class_func_emptyList (LOCATION_ARGS) ;

  public: static class GGS__32_lstringlist class_func_listWithValue (const class GGS_lstring & inOperand0,
                                                                     const class GGS_lstring & inOperand1
                                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public: VIRTUAL_IN_DEBUG void plusAssign_operation (const GGS__32_lstringlist inOperand,
                                                       class Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public: VIRTUAL_IN_DEBUG void addAssign_operation (const class GGS_lstring & inOperand0,
                                                     const class GGS_lstring & inOperand1
                                                     COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public: VIRTUAL_IN_DEBUG GGS__32_lstringlist add_operation (const GGS__32_lstringlist & inOperand,
                                                              Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_append (class GGS_lstring constinArgument0,
                                               class GGS_lstring constinArgument1,
                                               Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_insertAtIndex (class GGS_lstring constinArgument0,
                                                      class GGS_lstring constinArgument1,
                                                      class GGS_uint constinArgument2,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popFirst (class GGS_lstring & outArgument0,
                                                 class GGS_lstring & outArgument1,
                                                 Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popLast (class GGS_lstring & outArgument0,
                                                class GGS_lstring & outArgument1,
                                                Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_removeAtIndex (class GGS_lstring & outArgument0,
                                                      class GGS_lstring & outArgument1,
                                                      class GGS_uint constinArgument2,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMValue_30_AtIndex (class GGS_lstring constinArgument0,
                                                             class GGS_uint constinArgument1,
                                                             Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMValue_31_AtIndex (class GGS_lstring constinArgument0,
                                                             class GGS_uint constinArgument1,
                                                             Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_first (class GGS_lstring & outArgument0,
                                              class GGS_lstring & outArgument1,
                                              Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG void method_last (class GGS_lstring & outArgument0,
                                             class GGS_lstring & outArgument1,
                                             Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GGS_lstring getter_mValue_30_AtIndex (const class GGS_uint & constinOperand0,
                                                                       Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GGS_lstring getter_mValue_31_AtIndex (const class GGS_uint & constinOperand0,
                                                                       Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GGS__32_lstringlist getter_subListFromIndex (const class GGS_uint & constinOperand0,
                                                                              Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GGS__32_lstringlist getter_subListToIndex (const class GGS_uint & constinOperand0,
                                                                            Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GGS__32_lstringlist getter_subListWithRange (const class GGS_range & constinOperand0,
                                                                              Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) const ;


//--------------------------------- Read subscripts

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;

//--- Append element
  public: VIRTUAL_IN_DEBUG void enterElement (const class GGS__32_lstringlist_2E_element & inValue,
                                              Compiler * /* inCompiler */
                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- Friend
  friend class cEnumerator__32_lstringlist ;
 
} ; // End of GGS__32_lstringlist class

//--------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//--------------------------------------------------------------------------------------------------

class cEnumerator__32_lstringlist : public cGenericAbstractEnumerator {
  public: cEnumerator__32_lstringlist (const GGS__32_lstringlist & inEnumeratedObject,
                                       const EnumerationOrder inOrder) ;

//--- Current element access
  public: class GGS_lstring current_mValue_30_ (LOCATION_ARGS) const ;
  public: class GGS_lstring current_mValue_31_ (LOCATION_ARGS) const ;
//--- Current element access
  public: class GGS__32_lstringlist_2E_element current (LOCATION_ARGS) const ;
} ;

//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS__32_lstringlist ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @_32_lstringlist_2E_element struct
//
//--------------------------------------------------------------------------------------------------

class GGS__32_lstringlist_2E_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GGS_lstring mProperty_mValue_30_ ;
  public: inline GGS_lstring readProperty_mValue_30_ (void) const {
    return mProperty_mValue_30_ ;
  }

  public: GGS_lstring mProperty_mValue_31_ ;
  public: inline GGS_lstring readProperty_mValue_31_ (void) const {
    return mProperty_mValue_31_ ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default constructor
  public: GGS__32_lstringlist_2E_element (void) ;

//--------------------------------- Property setters
  public: inline void setter_setMValue_30_ (const GGS_lstring & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mValue_30_ = inValue ;
  }

  public: inline void setter_setMValue_31_ (const GGS_lstring & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mValue_31_ = inValue ;
  }

//--------------------------------- Virtual destructor
  public: virtual ~ GGS__32_lstringlist_2E_element (void) ;

//--------------------------------- Set initialized properties
  private: void setInitializedProperties (Compiler * inCompiler) ;

//--------------------------------- Native constructor
  public: GGS__32_lstringlist_2E_element (const GGS_lstring & in_mValue_30_,
                                          const GGS_lstring & in_mValue_31_) ;

//-- Start of type generic part

//--------------------------------- Initializers
  public: static GGS__32_lstringlist_2E_element init_21__21_ (const class GGS_lstring & inOperand0,
                                                              const class GGS_lstring & inOperand1,
                                                              Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GGS__32_lstringlist_2E_element extractObject (const GGS_object & inObject,
                                                               Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GGS__32_lstringlist_2E_element class_func_new (const class GGS_lstring & inOperand0,
                                                                      const class GGS_lstring & inOperand1,
                                                                      class Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (String & ioString,
                                             const int32_t inIndentation) const override ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GGS__32_lstringlist_2E_element class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS__32_lstringlist_2E_element ;

//--------------------------------------------------------------------------------------------------
//
//LEXIQUE oa_5F_scanner
//
//--------------------------------------------------------------------------------------------------

#include "Lexique.h"

//--------------------------------------------------------------------------------------------------
//                    E X T E R N    R O U T I N E S
//--------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------
//                    E X T E R N    F U N C T I O N S
//--------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------
//                       T O K E N    C L A S S
//--------------------------------------------------------------------------------------------------

class cTokenFor_oa_5F_scanner : public cToken {
  public: String mLexicalAttribute_identifierString ;
  public: uint32_t mLexicalAttribute_ulongValue ;

  public: cTokenFor_oa_5F_scanner (void) ;
} ;

//--------------------------------------------------------------------------------------------------
//                     S C A N N E R    C L A S S
//--------------------------------------------------------------------------------------------------

class Lexique_oa_5F_scanner : public Lexique {
//--- Constructors
  public: Lexique_oa_5F_scanner (Compiler * inCallerCompiler,
                       const String & inSourceFileName
                       COMMA_LOCATION_ARGS) ;

  public: Lexique_oa_5F_scanner (Compiler * inCallerCompiler,
                       const String & inSourceString,
                       const String & inStringForError
                       COMMA_LOCATION_ARGS) ;

//--- Instrospection
  public: static GGS_stringlist symbols (LOCATION_ARGS) ;

//--- Declaring a protected virtual destructor enables the compiler to raise
//    an error if a direct delete is performed; only the static method
//    SharedObject::detachPointer may invoke delete.
  #ifndef DO_NOT_GENERATE_CHECKINGS
    protected: virtual ~ Lexique_oa_5F_scanner (void) { }
  #endif



//--- Terminal symbols enumeration
  public: enum {kToken_,
   kToken_identifier /* 1 */ ,
   kToken_literal_5F_integer /* 2 */ ,
   kToken_system /* 3 */ ,
   kToken_end /* 4 */ ,
   kToken_task /* 5 */ ,
   kToken_standard /* 6 */ ,
   kToken_extended /* 7 */ ,
   kToken_message /* 8 */ ,
   kToken_length /* 9 */ ,
   kToken_priority /* 10 */ ,
   kToken_period /* 11 */ ,
   kToken_offset /* 12 */ ,
   kToken_on /* 13 */ ,
   kToken_deadline /* 14 */ ,
   kToken_duration /* 15 */ ,
   kToken_processor /* 16 */ ,
   kToken_can /* 17 */ ,
   kToken_van /* 18 */ ,
   kToken_network /* 19 */ ,
   kToken_scalingfactor /* 20 */ ,
   kToken_every /* 21 */ ,
   kToken__2C_ /* 22 */ ,
   kToken__3B_ /* 23 */ ,
   kToken__2E__2E_ /* 24 */ } ;

//--- Key words table 'keyWordList'
  public: static int32_t search_into_keyWordList (const String & inSearchedString) ;

//--- Key words table 'delimitorsList'
  public: static int32_t search_into_delimitorsList (const String & inSearchedString) ;
  

//--- Assign from attribute
  public: GGS_lstring synthetizedAttribute_identifierString (void) const ;
  public: GGS_luint synthetizedAttribute_ulongValue (void) const ;


//--- Attribute access
  public: String attributeValue_identifierString (void) const ;
  public: uint32_t attributeValue_ulongValue (void) const ;


//--- indexing keys

//--- Parse lexical token
  protected: void internalParseLexicalToken (cTokenFor_oa_5F_scanner & token) ;
  protected: virtual bool parseLexicalToken (void) override ;

//--- Get terminal message
  protected: virtual String getMessageForTerminal (const int32_t inTerminalSymbol) const override ;

//--- Get terminal count
  public: virtual int32_t terminalVocabularyCount (void) const override { return 24 ; }

//--- Get Token String
  public: virtual String getCurrentTokenString (const cToken * inTokenPtr) const override ;

//--- Enter Token
  protected: void enterToken (cTokenFor_oa_5F_scanner & ioToken) ;

//--- Style name for Latex
  protected: virtual String styleNameForIndex (const uint32_t inStyleIndex) const override ;
  protected: virtual uint32_t styleIndexForTerminal (const int32_t inTerminalIndex) const override ;
} ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @M_processor map
//
//--------------------------------------------------------------------------------------------------

class cMapElement_M_5F_processor ;

//--------------------------------------------------------------------------------------------------

extern const char * kSearchErrorMessage_M_5F_processor_searchKey ;

//--------------------------------------------------------------------------------------------------

class GGS_M_5F_processor : public AC_GALGAS_map {
//--------------------------------- Default constructor
  public: GGS_M_5F_processor (void) ;

//--------------------------------- Handle copy
  public: GGS_M_5F_processor (const GGS_M_5F_processor & inSource) ;
  public: GGS_M_5F_processor & operator = (const GGS_M_5F_processor & inSource) ;
  
//-- Start of type generic part

//--------------------------------- Initializers
  public: static GGS_M_5F_processor init (Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GGS_M_5F_processor extractObject (const GGS_object & inObject,
                                                   Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GGS_M_5F_processor class_func_emptyMap (LOCATION_ARGS) ;

  public: static class GGS_M_5F_processor class_func_mapWithMapToOverride (const class GGS_M_5F_processor & inOperand0
                                                                           COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public: VIRTUAL_IN_DEBUG void addAssign_operation (const class GGS_lstring & inOperand0,
                                                     const class GGS_uint & inOperand1,
                                                     const class GGS_luint & inOperand2,
                                                     Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public: VIRTUAL_IN_DEBUG GGS_M_5F_processor add_operation (const GGS_M_5F_processor & inOperand,
                                                             Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_insertKey (class GGS_lstring constinArgument0,
                                                  class GGS_uint constinArgument1,
                                                  class GGS_luint constinArgument2,
                                                  Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMIndexForKey (class GGS_uint constinArgument0,
                                                        class GGS_string constinArgument1,
                                                        Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMStepForKey (class GGS_luint constinArgument0,
                                                       class GGS_string constinArgument1,
                                                       Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_searchKey (class GGS_lstring constinArgument0,
                                                  class GGS_uint & outArgument1,
                                                  class GGS_luint & outArgument2,
                                                  Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GGS_uint getter_mIndexForKey (const class GGS_string & constinOperand0,
                                                               Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GGS_luint getter_mStepForKey (const class GGS_string & constinOperand0,
                                                               Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GGS_M_5F_processor getter_overriddenMap (Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const ;


//--------------------------------- Read subscripts
  public: VIRTUAL_IN_DEBUG class GGS_M_5F_processor_2E_element_3F_ readSubscript__3F_ (const class GGS_string & in0,
                                                                                       Compiler * inCompiler
                                                                                       COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
  public: VIRTUAL_IN_DEBUG cMapElement_M_5F_processor * readWriteAccessForWithInstruction (Compiler * inCompiler,
                                                                                           const GGS_string & inKey
                                                                                           COMMA_LOCATION_ARGS) ;


//--- Append element
  public: VIRTUAL_IN_DEBUG void enterElement (const class GGS_M_5F_processor_2E_element & inValue,
                                              Compiler * /* inCompiler */
                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- Friend
  friend class cEnumerator_M_5F_processor ;
 
} ; // End of GGS_M_5F_processor class

//--------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//--------------------------------------------------------------------------------------------------

class cEnumerator_M_5F_processor : public cGenericAbstractEnumerator {
  public: cEnumerator_M_5F_processor (const GGS_M_5F_processor & inEnumeratedObject,
                                      const EnumerationOrder inOrder) ;

//--- Current element access
  public: class GGS_lstring current_lkey (LOCATION_ARGS) const ;
  public: class GGS_uint current_mIndex (LOCATION_ARGS) const ;
  public: class GGS_luint current_mStep (LOCATION_ARGS) const ;
//--- Current element access
  public: class GGS_M_5F_processor_2E_element current (LOCATION_ARGS) const ;
} ;

//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_M_5F_processor ;

//--------------------------------------------------------------------------------------------------
//
// Phase 2: class for element of '@M_processor' map
//
//--------------------------------------------------------------------------------------------------

class cMapElement_M_5F_processor : public cMapElement {
//--- Map attributes
  public: GGS_uint mProperty_mIndex ;
  public: GGS_luint mProperty_mStep ;

//--- Constructors
  public: cMapElement_M_5F_processor (const GGS_M_5F_processor_2E_element & inValue
                                      COMMA_LOCATION_ARGS) ;
 
  public: cMapElement_M_5F_processor (const GGS_lstring & inKey,
                                      const GGS_uint & in_mIndex,
                                      const GGS_luint & in_mStep
                                      COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements

//--- Virtual method that checks that all attributes are valid
  public: virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public: virtual cMapElement * copy (void) ;

//--- Description
 public: virtual void description (String & ioString, const int32_t inIndentation) const ;
} ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @M_5F_processor_2E_element struct
//
//--------------------------------------------------------------------------------------------------

class GGS_M_5F_processor_2E_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GGS_lstring mProperty_lkey ;
  public: inline GGS_lstring readProperty_lkey (void) const {
    return mProperty_lkey ;
  }

  public: GGS_uint mProperty_mIndex ;
  public: inline GGS_uint readProperty_mIndex (void) const {
    return mProperty_mIndex ;
  }

  public: GGS_luint mProperty_mStep ;
  public: inline GGS_luint readProperty_mStep (void) const {
    return mProperty_mStep ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default constructor
  public: GGS_M_5F_processor_2E_element (void) ;

//--------------------------------- Property setters
  public: inline void setter_setLkey (const GGS_lstring & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_lkey = inValue ;
  }

  public: inline void setter_setMIndex (const GGS_uint & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mIndex = inValue ;
  }

  public: inline void setter_setMStep (const GGS_luint & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mStep = inValue ;
  }

//--------------------------------- Virtual destructor
  public: virtual ~ GGS_M_5F_processor_2E_element (void) ;

//--------------------------------- Set initialized properties
  private: void setInitializedProperties (Compiler * inCompiler) ;

//--------------------------------- Native constructor
  public: GGS_M_5F_processor_2E_element (const GGS_lstring & in_lkey,
                                         const GGS_uint & in_mIndex,
                                         const GGS_luint & in_mStep) ;

//-- Start of type generic part

//--------------------------------- Initializers
  public: static GGS_M_5F_processor_2E_element init_21__21__21_ (const class GGS_lstring & inOperand0,
                                                                 const class GGS_uint & inOperand1,
                                                                 const class GGS_luint & inOperand2,
                                                                 Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GGS_M_5F_processor_2E_element extractObject (const GGS_object & inObject,
                                                              Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GGS_M_5F_processor_2E_element class_func_new (const class GGS_lstring & inOperand0,
                                                                     const class GGS_uint & inOperand1,
                                                                     const class GGS_luint & inOperand2,
                                                                     class Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (String & ioString,
                                             const int32_t inIndentation) const override ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GGS_M_5F_processor_2E_element class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_M_5F_processor_2E_element ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: M_processor.element? optional
//
//--------------------------------------------------------------------------------------------------

class GGS_M_5F_processor_2E_element_3F_ : public AC_GALGAS_root {
//--------------------------------- Private property
  private: GGS_M_5F_processor_2E_element mValue ;
  private: OptionalState mState ;

//--------------------------------- Default constructor
  public: GGS_M_5F_processor_2E_element_3F_ (void) ;

//--------------------------------- Constructor from unwrapped type
  public: GGS_M_5F_processor_2E_element_3F_ (const GGS_M_5F_processor_2E_element & inSource) ;

//--------------------------------- Constructor from weak type

//--------------------------------- nil initializer
  public: static GGS_M_5F_processor_2E_element_3F_ init_nil (void) ;

  public: inline bool isNil (void) const { return mState == OptionalState::isNil ; }

  public: bool isValuated (void) const ;
  public: inline GGS_M_5F_processor_2E_element unwrappedValue (void) const {
    return mValue ;
  }

//--------------------------------- GALGAS read only properties
  public: inline GGS_bool readProperty_isNil (void) const {
    return GGS_bool (mState != OptionalState::invalid, mState == OptionalState::isNil) ;
  }

  public: inline GGS_bool readProperty_isSome (void) const {
    return GGS_bool (mState != OptionalState::invalid, mState == OptionalState::valuated) ;
  }

  
//--- Methods that every type should implement
  public: virtual bool isValid (void) const override ;
  
  public: virtual void drop (void) override ;

  public: virtual void description (String & ioString,
                                    const int32_t inIndentation) const override ;

//-- Start of type generic part

//--------------------------------- Initializers

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GGS_M_5F_processor_2E_element_3F_ extractObject (const GGS_object & inObject,
                                                                  Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) ;


//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GGS_M_5F_processor_2E_element_3F_ class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_M_5F_processor_2E_element_3F_ ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @M_network map
//
//--------------------------------------------------------------------------------------------------

class cMapElement_M_5F_network ;

//--------------------------------------------------------------------------------------------------

extern const char * kSearchErrorMessage_M_5F_network_searchKey ;

//--------------------------------------------------------------------------------------------------

class GGS_M_5F_network : public AC_GALGAS_map {
//--------------------------------- Default constructor
  public: GGS_M_5F_network (void) ;

//--------------------------------- Handle copy
  public: GGS_M_5F_network (const GGS_M_5F_network & inSource) ;
  public: GGS_M_5F_network & operator = (const GGS_M_5F_network & inSource) ;
  
//-- Start of type generic part

//--------------------------------- Initializers
  public: static GGS_M_5F_network init (Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GGS_M_5F_network extractObject (const GGS_object & inObject,
                                                 Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GGS_M_5F_network class_func_emptyMap (LOCATION_ARGS) ;

  public: static class GGS_M_5F_network class_func_mapWithMapToOverride (const class GGS_M_5F_network & inOperand0
                                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public: VIRTUAL_IN_DEBUG void addAssign_operation (const class GGS_lstring & inOperand0,
                                                     const class GGS_uint & inOperand1,
                                                     const class GGS_bool & inOperand2,
                                                     const class GGS_luint & inOperand3,
                                                     Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public: VIRTUAL_IN_DEBUG GGS_M_5F_network add_operation (const GGS_M_5F_network & inOperand,
                                                           Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_insertKey (class GGS_lstring constinArgument0,
                                                  class GGS_uint constinArgument1,
                                                  class GGS_bool constinArgument2,
                                                  class GGS_luint constinArgument3,
                                                  Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMCANnetworkForKey (class GGS_bool constinArgument0,
                                                             class GGS_string constinArgument1,
                                                             Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMIndexForKey (class GGS_uint constinArgument0,
                                                        class GGS_string constinArgument1,
                                                        Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMScalingFactorForKey (class GGS_luint constinArgument0,
                                                                class GGS_string constinArgument1,
                                                                Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_searchKey (class GGS_lstring constinArgument0,
                                                  class GGS_uint & outArgument1,
                                                  class GGS_bool & outArgument2,
                                                  class GGS_luint & outArgument3,
                                                  Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GGS_bool getter_mCANnetworkForKey (const class GGS_string & constinOperand0,
                                                                    Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GGS_uint getter_mIndexForKey (const class GGS_string & constinOperand0,
                                                               Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GGS_luint getter_mScalingFactorForKey (const class GGS_string & constinOperand0,
                                                                        Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GGS_M_5F_network getter_overriddenMap (Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) const ;


//--------------------------------- Read subscripts
  public: VIRTUAL_IN_DEBUG class GGS_M_5F_network_2E_element_3F_ readSubscript__3F_ (const class GGS_string & in0,
                                                                                     Compiler * inCompiler
                                                                                     COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
  public: VIRTUAL_IN_DEBUG cMapElement_M_5F_network * readWriteAccessForWithInstruction (Compiler * inCompiler,
                                                                                         const GGS_string & inKey
                                                                                         COMMA_LOCATION_ARGS) ;


//--- Append element
  public: VIRTUAL_IN_DEBUG void enterElement (const class GGS_M_5F_network_2E_element & inValue,
                                              Compiler * /* inCompiler */
                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- Friend
  friend class cEnumerator_M_5F_network ;
 
} ; // End of GGS_M_5F_network class

//--------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//--------------------------------------------------------------------------------------------------

class cEnumerator_M_5F_network : public cGenericAbstractEnumerator {
  public: cEnumerator_M_5F_network (const GGS_M_5F_network & inEnumeratedObject,
                                    const EnumerationOrder inOrder) ;

//--- Current element access
  public: class GGS_lstring current_lkey (LOCATION_ARGS) const ;
  public: class GGS_uint current_mIndex (LOCATION_ARGS) const ;
  public: class GGS_bool current_mCANnetwork (LOCATION_ARGS) const ;
  public: class GGS_luint current_mScalingFactor (LOCATION_ARGS) const ;
//--- Current element access
  public: class GGS_M_5F_network_2E_element current (LOCATION_ARGS) const ;
} ;

//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_M_5F_network ;

//--------------------------------------------------------------------------------------------------
//
// Phase 2: class for element of '@M_network' map
//
//--------------------------------------------------------------------------------------------------

class cMapElement_M_5F_network : public cMapElement {
//--- Map attributes
  public: GGS_uint mProperty_mIndex ;
  public: GGS_bool mProperty_mCANnetwork ;
  public: GGS_luint mProperty_mScalingFactor ;

//--- Constructors
  public: cMapElement_M_5F_network (const GGS_M_5F_network_2E_element & inValue
                                    COMMA_LOCATION_ARGS) ;
 
  public: cMapElement_M_5F_network (const GGS_lstring & inKey,
                                    const GGS_uint & in_mIndex,
                                    const GGS_bool & in_mCANnetwork,
                                    const GGS_luint & in_mScalingFactor
                                    COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements

//--- Virtual method that checks that all attributes are valid
  public: virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public: virtual cMapElement * copy (void) ;

//--- Description
 public: virtual void description (String & ioString, const int32_t inIndentation) const ;
} ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @M_5F_network_2E_element struct
//
//--------------------------------------------------------------------------------------------------

class GGS_M_5F_network_2E_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GGS_lstring mProperty_lkey ;
  public: inline GGS_lstring readProperty_lkey (void) const {
    return mProperty_lkey ;
  }

  public: GGS_uint mProperty_mIndex ;
  public: inline GGS_uint readProperty_mIndex (void) const {
    return mProperty_mIndex ;
  }

  public: GGS_bool mProperty_mCANnetwork ;
  public: inline GGS_bool readProperty_mCANnetwork (void) const {
    return mProperty_mCANnetwork ;
  }

  public: GGS_luint mProperty_mScalingFactor ;
  public: inline GGS_luint readProperty_mScalingFactor (void) const {
    return mProperty_mScalingFactor ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default constructor
  public: GGS_M_5F_network_2E_element (void) ;

//--------------------------------- Property setters
  public: inline void setter_setLkey (const GGS_lstring & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_lkey = inValue ;
  }

  public: inline void setter_setMIndex (const GGS_uint & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mIndex = inValue ;
  }

  public: inline void setter_setMCANnetwork (const GGS_bool & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mCANnetwork = inValue ;
  }

  public: inline void setter_setMScalingFactor (const GGS_luint & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mScalingFactor = inValue ;
  }

//--------------------------------- Virtual destructor
  public: virtual ~ GGS_M_5F_network_2E_element (void) ;

//--------------------------------- Set initialized properties
  private: void setInitializedProperties (Compiler * inCompiler) ;

//--------------------------------- Native constructor
  public: GGS_M_5F_network_2E_element (const GGS_lstring & in_lkey,
                                       const GGS_uint & in_mIndex,
                                       const GGS_bool & in_mCANnetwork,
                                       const GGS_luint & in_mScalingFactor) ;

//-- Start of type generic part

//--------------------------------- Initializers
  public: static GGS_M_5F_network_2E_element init_21__21__21__21_ (const class GGS_lstring & inOperand0,
                                                                   const class GGS_uint & inOperand1,
                                                                   const class GGS_bool & inOperand2,
                                                                   const class GGS_luint & inOperand3,
                                                                   Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GGS_M_5F_network_2E_element extractObject (const GGS_object & inObject,
                                                            Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GGS_M_5F_network_2E_element class_func_new (const class GGS_lstring & inOperand0,
                                                                   const class GGS_uint & inOperand1,
                                                                   const class GGS_bool & inOperand2,
                                                                   const class GGS_luint & inOperand3,
                                                                   class Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (String & ioString,
                                             const int32_t inIndentation) const override ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GGS_M_5F_network_2E_element class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_M_5F_network_2E_element ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: M_network.element? optional
//
//--------------------------------------------------------------------------------------------------

class GGS_M_5F_network_2E_element_3F_ : public AC_GALGAS_root {
//--------------------------------- Private property
  private: GGS_M_5F_network_2E_element mValue ;
  private: OptionalState mState ;

//--------------------------------- Default constructor
  public: GGS_M_5F_network_2E_element_3F_ (void) ;

//--------------------------------- Constructor from unwrapped type
  public: GGS_M_5F_network_2E_element_3F_ (const GGS_M_5F_network_2E_element & inSource) ;

//--------------------------------- Constructor from weak type

//--------------------------------- nil initializer
  public: static GGS_M_5F_network_2E_element_3F_ init_nil (void) ;

  public: inline bool isNil (void) const { return mState == OptionalState::isNil ; }

  public: bool isValuated (void) const ;
  public: inline GGS_M_5F_network_2E_element unwrappedValue (void) const {
    return mValue ;
  }

//--------------------------------- GALGAS read only properties
  public: inline GGS_bool readProperty_isNil (void) const {
    return GGS_bool (mState != OptionalState::invalid, mState == OptionalState::isNil) ;
  }

  public: inline GGS_bool readProperty_isSome (void) const {
    return GGS_bool (mState != OptionalState::invalid, mState == OptionalState::valuated) ;
  }

  
//--- Methods that every type should implement
  public: virtual bool isValid (void) const override ;
  
  public: virtual void drop (void) override ;

  public: virtual void description (String & ioString,
                                    const int32_t inIndentation) const override ;

//-- Start of type generic part

//--------------------------------- Initializers

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GGS_M_5F_network_2E_element_3F_ extractObject (const GGS_object & inObject,
                                                                Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) ;


//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GGS_M_5F_network_2E_element_3F_ class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_M_5F_network_2E_element_3F_ ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @AC_5F_canMessage reference class
//
//--------------------------------------------------------------------------------------------------

class GGS_AC_5F_canMessage : public AC_GALGAS_reference_class {
//--------------------------------- Default constructor
  public: GGS_AC_5F_canMessage (void) ;

//--------------------------------- Constructor from pointer
  public: GGS_AC_5F_canMessage (const class cPtr_AC_5F_canMessage * inSourcePtr) ;

//--------------------------------- Property access
//-- Start of type generic part

//--------------------------------- Initializers
  public: static GGS_AC_5F_canMessage init (Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GGS_AC_5F_canMessage extractObject (const GGS_object & inObject,
                                                     Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GGS_AC_5F_canMessage & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GGS_AC_5F_canMessage class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_AC_5F_canMessage ;

#include "separateHeaderFor_AC_5F_canMessage.h"

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @AC_5F_canMessage_2E_weak weak reference class
//
//--------------------------------------------------------------------------------------------------

class GGS_AC_5F_canMessage_2E_weak : public AC_GALGAS_weak_reference {
//--------------------------------- Default constructor
  public: GGS_AC_5F_canMessage_2E_weak (void) ;

//--------------------------------- Constructor and assignment from strong reference
  public: GGS_AC_5F_canMessage_2E_weak (const class GGS_AC_5F_canMessage & inSource) ;

  public: GGS_AC_5F_canMessage_2E_weak & operator = (const class GGS_AC_5F_canMessage & inSource) ;

//--------------------------------- Constructor and assignment from optional reference

//--------------------------------- nil initializer
  public: inline static GGS_AC_5F_canMessage_2E_weak init_nil (void) {
    GGS_AC_5F_canMessage_2E_weak result ;
    macroMyNew (result.mProxyPtr, cPtr_weakReference_proxy (HERE)) ;
    return result ;
  }

//--------------------------------- Bang operator
  public: GGS_AC_5F_canMessage bang_AC_5F_canMessage_2E_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const ;

//--------------------------------- isValuated
  public: inline bool isValuated (void) const {
    return isValid () && (ptr () != nullptr) ;
  }

//--------------------------------- Unwrapped value
  public: inline GGS_AC_5F_canMessage unwrappedValue (void) const {
    GGS_AC_5F_canMessage result ;
    if (isValid ()) {
      const cPtr_AC_5F_canMessage * p = (cPtr_AC_5F_canMessage *) ptr () ;
      if (nullptr != p) {
        result = GGS_AC_5F_canMessage (p) ;
      }
    }
    return result ;
  }

//--------------------------------- GALGAS read only properties
  public: inline GGS_bool readProperty_isNil (void) const {
    return GGS_bool (isValid (), ptr () == nullptr) ;
  }

  public: inline GGS_bool readProperty_isSome (void) const {
    return GGS_bool (isValid (), ptr () != nullptr) ;
  }

//-- Start of type generic part

//--------------------------------- Initializers

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GGS_AC_5F_canMessage_2E_weak extractObject (const GGS_object & inObject,
                                                             Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GGS_AC_5F_canMessage_2E_weak class_func_nil (LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GGS_AC_5F_canMessage_2E_weak & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GGS_AC_5F_canMessage_2E_weak class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_AC_5F_canMessage_2E_weak ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @C_5F_canIndependantMessage reference class
//
//--------------------------------------------------------------------------------------------------

class GGS_C_5F_canIndependantMessage : public GGS_AC_5F_canMessage {
//--------------------------------- Default constructor
  public: GGS_C_5F_canIndependantMessage (void) ;

//--------------------------------- Constructor from pointer
  public: GGS_C_5F_canIndependantMessage (const class cPtr_C_5F_canIndependantMessage * inSourcePtr) ;

//--------------------------------- Property access
//-- Start of type generic part

//--------------------------------- Initializers
  public: static GGS_C_5F_canIndependantMessage init (Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GGS_C_5F_canIndependantMessage extractObject (const GGS_object & inObject,
                                                               Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GGS_C_5F_canIndependantMessage class_func_new (LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GGS_C_5F_canIndependantMessage & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GGS_C_5F_canIndependantMessage class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_C_5F_canIndependantMessage ;

#include "separateHeaderFor_C_5F_canIndependantMessage.h"

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @C_5F_canIndependantMessage_2E_weak weak reference class
//
//--------------------------------------------------------------------------------------------------

class GGS_C_5F_canIndependantMessage_2E_weak : public GGS_AC_5F_canMessage_2E_weak {
//--------------------------------- Default constructor
  public: GGS_C_5F_canIndependantMessage_2E_weak (void) ;

//--------------------------------- Constructor and assignment from strong reference
  public: GGS_C_5F_canIndependantMessage_2E_weak (const class GGS_C_5F_canIndependantMessage & inSource) ;

  public: GGS_C_5F_canIndependantMessage_2E_weak & operator = (const class GGS_C_5F_canIndependantMessage & inSource) ;

//--------------------------------- Constructor and assignment from optional reference

//--------------------------------- nil initializer
  public: inline static GGS_C_5F_canIndependantMessage_2E_weak init_nil (void) {
    GGS_C_5F_canIndependantMessage_2E_weak result ;
    macroMyNew (result.mProxyPtr, cPtr_weakReference_proxy (HERE)) ;
    return result ;
  }

//--------------------------------- Bang operator
  public: GGS_C_5F_canIndependantMessage bang_C_5F_canIndependantMessage_2E_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const ;

//--------------------------------- isValuated
  public: inline bool isValuated (void) const {
    return isValid () && (ptr () != nullptr) ;
  }

//--------------------------------- Unwrapped value
  public: inline GGS_C_5F_canIndependantMessage unwrappedValue (void) const {
    GGS_C_5F_canIndependantMessage result ;
    if (isValid ()) {
      const cPtr_C_5F_canIndependantMessage * p = (cPtr_C_5F_canIndependantMessage *) ptr () ;
      if (nullptr != p) {
        result = GGS_C_5F_canIndependantMessage (p) ;
      }
    }
    return result ;
  }

//--------------------------------- GALGAS read only properties
  public: inline GGS_bool readProperty_isNil (void) const {
    return GGS_bool (isValid (), ptr () == nullptr) ;
  }

  public: inline GGS_bool readProperty_isSome (void) const {
    return GGS_bool (isValid (), ptr () != nullptr) ;
  }

//-- Start of type generic part

//--------------------------------- Initializers

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GGS_C_5F_canIndependantMessage_2E_weak extractObject (const GGS_object & inObject,
                                                                       Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GGS_C_5F_canIndependantMessage_2E_weak class_func_nil (LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GGS_C_5F_canIndependantMessage_2E_weak & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GGS_C_5F_canIndependantMessage_2E_weak class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_C_5F_canIndependantMessage_2E_weak ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @C_5F_canMessageFromMessage reference class
//
//--------------------------------------------------------------------------------------------------

class GGS_C_5F_canMessageFromMessage : public GGS_AC_5F_canMessage {
//--------------------------------- Default constructor
  public: GGS_C_5F_canMessageFromMessage (void) ;

//--------------------------------- Constructor from pointer
  public: GGS_C_5F_canMessageFromMessage (const class cPtr_C_5F_canMessageFromMessage * inSourcePtr) ;

//--------------------------------- Property access
  public: class GGS_uint readProperty_mMessageIndex (void) const ;
  public: void setProperty_mMessageIndex (const GGS_uint & inValue) ;

//-- Start of type generic part

//--------------------------------- Initializers
  public: static GGS_C_5F_canMessageFromMessage init_21_ (const class GGS_uint & inOperand0,
                                                          Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GGS_C_5F_canMessageFromMessage extractObject (const GGS_object & inObject,
                                                               Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GGS_C_5F_canMessageFromMessage class_func_new (const class GGS_uint & inOperand0
                                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GGS_C_5F_canMessageFromMessage & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GGS_C_5F_canMessageFromMessage class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_C_5F_canMessageFromMessage ;

#include "separateHeaderFor_C_5F_canMessageFromMessage.h"

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @C_5F_canMessageFromMessage_2E_weak weak reference class
//
//--------------------------------------------------------------------------------------------------

class GGS_C_5F_canMessageFromMessage_2E_weak : public GGS_AC_5F_canMessage_2E_weak {
//--------------------------------- Default constructor
  public: GGS_C_5F_canMessageFromMessage_2E_weak (void) ;

//--------------------------------- Constructor and assignment from strong reference
  public: GGS_C_5F_canMessageFromMessage_2E_weak (const class GGS_C_5F_canMessageFromMessage & inSource) ;

  public: GGS_C_5F_canMessageFromMessage_2E_weak & operator = (const class GGS_C_5F_canMessageFromMessage & inSource) ;

//--------------------------------- Constructor and assignment from optional reference

//--------------------------------- nil initializer
  public: inline static GGS_C_5F_canMessageFromMessage_2E_weak init_nil (void) {
    GGS_C_5F_canMessageFromMessage_2E_weak result ;
    macroMyNew (result.mProxyPtr, cPtr_weakReference_proxy (HERE)) ;
    return result ;
  }

//--------------------------------- Bang operator
  public: GGS_C_5F_canMessageFromMessage bang_C_5F_canMessageFromMessage_2E_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const ;

//--------------------------------- isValuated
  public: inline bool isValuated (void) const {
    return isValid () && (ptr () != nullptr) ;
  }

//--------------------------------- Unwrapped value
  public: inline GGS_C_5F_canMessageFromMessage unwrappedValue (void) const {
    GGS_C_5F_canMessageFromMessage result ;
    if (isValid ()) {
      const cPtr_C_5F_canMessageFromMessage * p = (cPtr_C_5F_canMessageFromMessage *) ptr () ;
      if (nullptr != p) {
        result = GGS_C_5F_canMessageFromMessage (p) ;
      }
    }
    return result ;
  }

//--------------------------------- GALGAS read only properties
  public: inline GGS_bool readProperty_isNil (void) const {
    return GGS_bool (isValid (), ptr () == nullptr) ;
  }

  public: inline GGS_bool readProperty_isSome (void) const {
    return GGS_bool (isValid (), ptr () != nullptr) ;
  }

//-- Start of type generic part

//--------------------------------- Initializers

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GGS_C_5F_canMessageFromMessage_2E_weak extractObject (const GGS_object & inObject,
                                                                       Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GGS_C_5F_canMessageFromMessage_2E_weak class_func_nil (LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GGS_C_5F_canMessageFromMessage_2E_weak & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GGS_C_5F_canMessageFromMessage_2E_weak class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_C_5F_canMessageFromMessage_2E_weak ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @C_5F_canMessageFromTask reference class
//
//--------------------------------------------------------------------------------------------------

class GGS_C_5F_canMessageFromTask : public GGS_AC_5F_canMessage {
//--------------------------------- Default constructor
  public: GGS_C_5F_canMessageFromTask (void) ;

//--------------------------------- Constructor from pointer
  public: GGS_C_5F_canMessageFromTask (const class cPtr_C_5F_canMessageFromTask * inSourcePtr) ;

//--------------------------------- Property access
  public: class GGS_uint readProperty_mTaskIndex (void) const ;
  public: void setProperty_mTaskIndex (const GGS_uint & inValue) ;

//-- Start of type generic part

//--------------------------------- Initializers
  public: static GGS_C_5F_canMessageFromTask init_21_ (const class GGS_uint & inOperand0,
                                                       Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GGS_C_5F_canMessageFromTask extractObject (const GGS_object & inObject,
                                                            Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GGS_C_5F_canMessageFromTask class_func_new (const class GGS_uint & inOperand0
                                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GGS_C_5F_canMessageFromTask & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GGS_C_5F_canMessageFromTask class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_C_5F_canMessageFromTask ;

#include "separateHeaderFor_C_5F_canMessageFromTask.h"

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @C_5F_canMessageFromTask_2E_weak weak reference class
//
//--------------------------------------------------------------------------------------------------

class GGS_C_5F_canMessageFromTask_2E_weak : public GGS_AC_5F_canMessage_2E_weak {
//--------------------------------- Default constructor
  public: GGS_C_5F_canMessageFromTask_2E_weak (void) ;

//--------------------------------- Constructor and assignment from strong reference
  public: GGS_C_5F_canMessageFromTask_2E_weak (const class GGS_C_5F_canMessageFromTask & inSource) ;

  public: GGS_C_5F_canMessageFromTask_2E_weak & operator = (const class GGS_C_5F_canMessageFromTask & inSource) ;

//--------------------------------- Constructor and assignment from optional reference

//--------------------------------- nil initializer
  public: inline static GGS_C_5F_canMessageFromTask_2E_weak init_nil (void) {
    GGS_C_5F_canMessageFromTask_2E_weak result ;
    macroMyNew (result.mProxyPtr, cPtr_weakReference_proxy (HERE)) ;
    return result ;
  }

//--------------------------------- Bang operator
  public: GGS_C_5F_canMessageFromTask bang_C_5F_canMessageFromTask_2E_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const ;

//--------------------------------- isValuated
  public: inline bool isValuated (void) const {
    return isValid () && (ptr () != nullptr) ;
  }

//--------------------------------- Unwrapped value
  public: inline GGS_C_5F_canMessageFromTask unwrappedValue (void) const {
    GGS_C_5F_canMessageFromTask result ;
    if (isValid ()) {
      const cPtr_C_5F_canMessageFromTask * p = (cPtr_C_5F_canMessageFromTask *) ptr () ;
      if (nullptr != p) {
        result = GGS_C_5F_canMessageFromTask (p) ;
      }
    }
    return result ;
  }

//--------------------------------- GALGAS read only properties
  public: inline GGS_bool readProperty_isNil (void) const {
    return GGS_bool (isValid (), ptr () == nullptr) ;
  }

  public: inline GGS_bool readProperty_isSome (void) const {
    return GGS_bool (isValid (), ptr () != nullptr) ;
  }

//-- Start of type generic part

//--------------------------------- Initializers

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GGS_C_5F_canMessageFromTask_2E_weak extractObject (const GGS_object & inObject,
                                                                    Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GGS_C_5F_canMessageFromTask_2E_weak class_func_nil (LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GGS_C_5F_canMessageFromTask_2E_weak & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GGS_C_5F_canMessageFromTask_2E_weak class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_C_5F_canMessageFromTask_2E_weak ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @M_messages map
//
//--------------------------------------------------------------------------------------------------

class cMapElement_M_5F_messages ;

//--------------------------------------------------------------------------------------------------

extern const char * kSearchErrorMessage_M_5F_messages_searchKey ;

//--------------------------------------------------------------------------------------------------

class GGS_M_5F_messages : public AC_GALGAS_map {
//--------------------------------- Default constructor
  public: GGS_M_5F_messages (void) ;

//--------------------------------- Handle copy
  public: GGS_M_5F_messages (const GGS_M_5F_messages & inSource) ;
  public: GGS_M_5F_messages & operator = (const GGS_M_5F_messages & inSource) ;
  
//-- Start of type generic part

//--------------------------------- Initializers
  public: static GGS_M_5F_messages init (Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GGS_M_5F_messages extractObject (const GGS_object & inObject,
                                                  Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GGS_M_5F_messages class_func_emptyMap (LOCATION_ARGS) ;

  public: static class GGS_M_5F_messages class_func_mapWithMapToOverride (const class GGS_M_5F_messages & inOperand0
                                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public: VIRTUAL_IN_DEBUG void addAssign_operation (const class GGS_lstring & inOperand0,
                                                     const class GGS_uint & inOperand1,
                                                     const class GGS_luint & inOperand2,
                                                     const class GGS_uint & inOperand3,
                                                     const class GGS_luint & inOperand4,
                                                     const class GGS_luint & inOperand5,
                                                     const class GGS_luint & inOperand6,
                                                     const class GGS_luint & inOperand7,
                                                     const class GGS_luint & inOperand8,
                                                     const class GGS_AC_5F_canMessage & inOperand9,
                                                     Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public: VIRTUAL_IN_DEBUG GGS_M_5F_messages add_operation (const GGS_M_5F_messages & inOperand,
                                                            Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_insertKey (class GGS_lstring constinArgument0,
                                                  class GGS_uint constinArgument1,
                                                  class GGS_luint constinArgument2,
                                                  class GGS_uint constinArgument3,
                                                  class GGS_luint constinArgument4,
                                                  class GGS_luint constinArgument5,
                                                  class GGS_luint constinArgument6,
                                                  class GGS_luint constinArgument7,
                                                  class GGS_luint constinArgument8,
                                                  class GGS_AC_5F_canMessage constinArgument9,
                                                  Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMBytesCountForKey (class GGS_luint constinArgument0,
                                                             class GGS_string constinArgument1,
                                                             Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMClassForKey (class GGS_luint constinArgument0,
                                                        class GGS_string constinArgument1,
                                                        Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMDeadlineForKey (class GGS_luint constinArgument0,
                                                           class GGS_string constinArgument1,
                                                           Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMIndexForKey (class GGS_uint constinArgument0,
                                                        class GGS_string constinArgument1,
                                                        Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMMessageKindForKey (class GGS_AC_5F_canMessage constinArgument0,
                                                              class GGS_string constinArgument1,
                                                              Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMNetworkIndexForKey (class GGS_uint constinArgument0,
                                                               class GGS_string constinArgument1,
                                                               Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMOffsetForKey (class GGS_luint constinArgument0,
                                                         class GGS_string constinArgument1,
                                                         Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMPeriodForKey (class GGS_luint constinArgument0,
                                                         class GGS_string constinArgument1,
                                                         Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMPriorityForKey (class GGS_luint constinArgument0,
                                                           class GGS_string constinArgument1,
                                                           Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_searchKey (class GGS_lstring constinArgument0,
                                                  class GGS_uint & outArgument1,
                                                  class GGS_luint & outArgument2,
                                                  class GGS_uint & outArgument3,
                                                  class GGS_luint & outArgument4,
                                                  class GGS_luint & outArgument5,
                                                  class GGS_luint & outArgument6,
                                                  class GGS_luint & outArgument7,
                                                  class GGS_luint & outArgument8,
                                                  class GGS_AC_5F_canMessage & outArgument9,
                                                  Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GGS_luint getter_mBytesCountForKey (const class GGS_string & constinOperand0,
                                                                     Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GGS_luint getter_mClassForKey (const class GGS_string & constinOperand0,
                                                                Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GGS_luint getter_mDeadlineForKey (const class GGS_string & constinOperand0,
                                                                   Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GGS_uint getter_mIndexForKey (const class GGS_string & constinOperand0,
                                                               Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GGS_AC_5F_canMessage getter_mMessageKindForKey (const class GGS_string & constinOperand0,
                                                                                 Compiler * inCompiler
                                                                                 COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GGS_uint getter_mNetworkIndexForKey (const class GGS_string & constinOperand0,
                                                                      Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GGS_luint getter_mOffsetForKey (const class GGS_string & constinOperand0,
                                                                 Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GGS_luint getter_mPeriodForKey (const class GGS_string & constinOperand0,
                                                                 Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GGS_luint getter_mPriorityForKey (const class GGS_string & constinOperand0,
                                                                   Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GGS_M_5F_messages getter_overriddenMap (Compiler * inCompiler
                                                                         COMMA_LOCATION_ARGS) const ;


//--------------------------------- Read subscripts
  public: VIRTUAL_IN_DEBUG class GGS_M_5F_messages_2E_element_3F_ readSubscript__3F_ (const class GGS_string & in0,
                                                                                      Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
  public: VIRTUAL_IN_DEBUG cMapElement_M_5F_messages * readWriteAccessForWithInstruction (Compiler * inCompiler,
                                                                                          const GGS_string & inKey
                                                                                          COMMA_LOCATION_ARGS) ;


//--- Append element
  public: VIRTUAL_IN_DEBUG void enterElement (const class GGS_M_5F_messages_2E_element & inValue,
                                              Compiler * /* inCompiler */
                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- Friend
  friend class cEnumerator_M_5F_messages ;
 
} ; // End of GGS_M_5F_messages class

//--------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//--------------------------------------------------------------------------------------------------

class cEnumerator_M_5F_messages : public cGenericAbstractEnumerator {
  public: cEnumerator_M_5F_messages (const GGS_M_5F_messages & inEnumeratedObject,
                                     const EnumerationOrder inOrder) ;

//--- Current element access
  public: class GGS_lstring current_lkey (LOCATION_ARGS) const ;
  public: class GGS_uint current_mIndex (LOCATION_ARGS) const ;
  public: class GGS_luint current_mClass (LOCATION_ARGS) const ;
  public: class GGS_uint current_mNetworkIndex (LOCATION_ARGS) const ;
  public: class GGS_luint current_mBytesCount (LOCATION_ARGS) const ;
  public: class GGS_luint current_mPriority (LOCATION_ARGS) const ;
  public: class GGS_luint current_mOffset (LOCATION_ARGS) const ;
  public: class GGS_luint current_mDeadline (LOCATION_ARGS) const ;
  public: class GGS_luint current_mPeriod (LOCATION_ARGS) const ;
  public: class GGS_AC_5F_canMessage current_mMessageKind (LOCATION_ARGS) const ;
//--- Current element access
  public: class GGS_M_5F_messages_2E_element current (LOCATION_ARGS) const ;
} ;

//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_M_5F_messages ;

//--------------------------------------------------------------------------------------------------
//
// Phase 2: class for element of '@M_messages' map
//
//--------------------------------------------------------------------------------------------------

class cMapElement_M_5F_messages : public cMapElement {
//--- Map attributes
  public: GGS_uint mProperty_mIndex ;
  public: GGS_luint mProperty_mClass ;
  public: GGS_uint mProperty_mNetworkIndex ;
  public: GGS_luint mProperty_mBytesCount ;
  public: GGS_luint mProperty_mPriority ;
  public: GGS_luint mProperty_mOffset ;
  public: GGS_luint mProperty_mDeadline ;
  public: GGS_luint mProperty_mPeriod ;
  public: GGS_AC_5F_canMessage mProperty_mMessageKind ;

//--- Constructors
  public: cMapElement_M_5F_messages (const GGS_M_5F_messages_2E_element & inValue
                                     COMMA_LOCATION_ARGS) ;
 
  public: cMapElement_M_5F_messages (const GGS_lstring & inKey,
                                     const GGS_uint & in_mIndex,
                                     const GGS_luint & in_mClass,
                                     const GGS_uint & in_mNetworkIndex,
                                     const GGS_luint & in_mBytesCount,
                                     const GGS_luint & in_mPriority,
                                     const GGS_luint & in_mOffset,
                                     const GGS_luint & in_mDeadline,
                                     const GGS_luint & in_mPeriod,
                                     const GGS_AC_5F_canMessage & in_mMessageKind
                                     COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements

//--- Virtual method that checks that all attributes are valid
  public: virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public: virtual cMapElement * copy (void) ;

//--- Description
 public: virtual void description (String & ioString, const int32_t inIndentation) const ;
} ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @M_5F_messages_2E_element struct
//
//--------------------------------------------------------------------------------------------------

class GGS_M_5F_messages_2E_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GGS_lstring mProperty_lkey ;
  public: inline GGS_lstring readProperty_lkey (void) const {
    return mProperty_lkey ;
  }

  public: GGS_uint mProperty_mIndex ;
  public: inline GGS_uint readProperty_mIndex (void) const {
    return mProperty_mIndex ;
  }

  public: GGS_luint mProperty_mClass ;
  public: inline GGS_luint readProperty_mClass (void) const {
    return mProperty_mClass ;
  }

  public: GGS_uint mProperty_mNetworkIndex ;
  public: inline GGS_uint readProperty_mNetworkIndex (void) const {
    return mProperty_mNetworkIndex ;
  }

  public: GGS_luint mProperty_mBytesCount ;
  public: inline GGS_luint readProperty_mBytesCount (void) const {
    return mProperty_mBytesCount ;
  }

  public: GGS_luint mProperty_mPriority ;
  public: inline GGS_luint readProperty_mPriority (void) const {
    return mProperty_mPriority ;
  }

  public: GGS_luint mProperty_mOffset ;
  public: inline GGS_luint readProperty_mOffset (void) const {
    return mProperty_mOffset ;
  }

  public: GGS_luint mProperty_mDeadline ;
  public: inline GGS_luint readProperty_mDeadline (void) const {
    return mProperty_mDeadline ;
  }

  public: GGS_luint mProperty_mPeriod ;
  public: inline GGS_luint readProperty_mPeriod (void) const {
    return mProperty_mPeriod ;
  }

  public: GGS_AC_5F_canMessage mProperty_mMessageKind ;
  public: inline GGS_AC_5F_canMessage readProperty_mMessageKind (void) const {
    return mProperty_mMessageKind ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default constructor
  public: GGS_M_5F_messages_2E_element (void) ;

//--------------------------------- Property setters
  public: inline void setter_setLkey (const GGS_lstring & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_lkey = inValue ;
  }

  public: inline void setter_setMIndex (const GGS_uint & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mIndex = inValue ;
  }

  public: inline void setter_setMClass (const GGS_luint & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mClass = inValue ;
  }

  public: inline void setter_setMNetworkIndex (const GGS_uint & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mNetworkIndex = inValue ;
  }

  public: inline void setter_setMBytesCount (const GGS_luint & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mBytesCount = inValue ;
  }

  public: inline void setter_setMPriority (const GGS_luint & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mPriority = inValue ;
  }

  public: inline void setter_setMOffset (const GGS_luint & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mOffset = inValue ;
  }

  public: inline void setter_setMDeadline (const GGS_luint & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mDeadline = inValue ;
  }

  public: inline void setter_setMPeriod (const GGS_luint & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mPeriod = inValue ;
  }

  public: inline void setter_setMMessageKind (const GGS_AC_5F_canMessage & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mMessageKind = inValue ;
  }

//--------------------------------- Virtual destructor
  public: virtual ~ GGS_M_5F_messages_2E_element (void) ;

//--------------------------------- Set initialized properties
  private: void setInitializedProperties (Compiler * inCompiler) ;

//--------------------------------- Native constructor
  public: GGS_M_5F_messages_2E_element (const GGS_lstring & in_lkey,
                                        const GGS_uint & in_mIndex,
                                        const GGS_luint & in_mClass,
                                        const GGS_uint & in_mNetworkIndex,
                                        const GGS_luint & in_mBytesCount,
                                        const GGS_luint & in_mPriority,
                                        const GGS_luint & in_mOffset,
                                        const GGS_luint & in_mDeadline,
                                        const GGS_luint & in_mPeriod,
                                        const GGS_AC_5F_canMessage & in_mMessageKind) ;

//-- Start of type generic part

//--------------------------------- Initializers
  public: static GGS_M_5F_messages_2E_element init_21__21__21__21__21__21__21__21__21__21_ (const class GGS_lstring & inOperand0,
                                                                                            const class GGS_uint & inOperand1,
                                                                                            const class GGS_luint & inOperand2,
                                                                                            const class GGS_uint & inOperand3,
                                                                                            const class GGS_luint & inOperand4,
                                                                                            const class GGS_luint & inOperand5,
                                                                                            const class GGS_luint & inOperand6,
                                                                                            const class GGS_luint & inOperand7,
                                                                                            const class GGS_luint & inOperand8,
                                                                                            const class GGS_AC_5F_canMessage & inOperand9,
                                                                                            Compiler * inCompiler
                                                                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GGS_M_5F_messages_2E_element extractObject (const GGS_object & inObject,
                                                             Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GGS_M_5F_messages_2E_element class_func_new (const class GGS_lstring & inOperand0,
                                                                    const class GGS_uint & inOperand1,
                                                                    const class GGS_luint & inOperand2,
                                                                    const class GGS_uint & inOperand3,
                                                                    const class GGS_luint & inOperand4,
                                                                    const class GGS_luint & inOperand5,
                                                                    const class GGS_luint & inOperand6,
                                                                    const class GGS_luint & inOperand7,
                                                                    const class GGS_luint & inOperand8,
                                                                    const class GGS_AC_5F_canMessage & inOperand9,
                                                                    class Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (String & ioString,
                                             const int32_t inIndentation) const override ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GGS_M_5F_messages_2E_element class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_M_5F_messages_2E_element ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: M_messages.element? optional
//
//--------------------------------------------------------------------------------------------------

class GGS_M_5F_messages_2E_element_3F_ : public AC_GALGAS_root {
//--------------------------------- Private property
  private: GGS_M_5F_messages_2E_element mValue ;
  private: OptionalState mState ;

//--------------------------------- Default constructor
  public: GGS_M_5F_messages_2E_element_3F_ (void) ;

//--------------------------------- Constructor from unwrapped type
  public: GGS_M_5F_messages_2E_element_3F_ (const GGS_M_5F_messages_2E_element & inSource) ;

//--------------------------------- Constructor from weak type

//--------------------------------- nil initializer
  public: static GGS_M_5F_messages_2E_element_3F_ init_nil (void) ;

  public: inline bool isNil (void) const { return mState == OptionalState::isNil ; }

  public: bool isValuated (void) const ;
  public: inline GGS_M_5F_messages_2E_element unwrappedValue (void) const {
    return mValue ;
  }

//--------------------------------- GALGAS read only properties
  public: inline GGS_bool readProperty_isNil (void) const {
    return GGS_bool (mState != OptionalState::invalid, mState == OptionalState::isNil) ;
  }

  public: inline GGS_bool readProperty_isSome (void) const {
    return GGS_bool (mState != OptionalState::invalid, mState == OptionalState::valuated) ;
  }

  
//--- Methods that every type should implement
  public: virtual bool isValid (void) const override ;
  
  public: virtual void drop (void) override ;

  public: virtual void description (String & ioString,
                                    const int32_t inIndentation) const override ;

//-- Start of type generic part

//--------------------------------- Initializers

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GGS_M_5F_messages_2E_element_3F_ extractObject (const GGS_object & inObject,
                                                                 Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) ;


//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GGS_M_5F_messages_2E_element_3F_ class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_M_5F_messages_2E_element_3F_ ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @AC_5F_task reference class
//
//--------------------------------------------------------------------------------------------------

class GGS_AC_5F_task : public AC_GALGAS_reference_class {
//--------------------------------- Default constructor
  public: GGS_AC_5F_task (void) ;

//--------------------------------- Constructor from pointer
  public: GGS_AC_5F_task (const class cPtr_AC_5F_task * inSourcePtr) ;

//--------------------------------- Property access
//-- Start of type generic part

//--------------------------------- Initializers
  public: static GGS_AC_5F_task init (Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GGS_AC_5F_task extractObject (const GGS_object & inObject,
                                               Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GGS_AC_5F_task & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GGS_AC_5F_task class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_AC_5F_task ;

#include "separateHeaderFor_AC_5F_task.h"

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @AC_5F_task_2E_weak weak reference class
//
//--------------------------------------------------------------------------------------------------

class GGS_AC_5F_task_2E_weak : public AC_GALGAS_weak_reference {
//--------------------------------- Default constructor
  public: GGS_AC_5F_task_2E_weak (void) ;

//--------------------------------- Constructor and assignment from strong reference
  public: GGS_AC_5F_task_2E_weak (const class GGS_AC_5F_task & inSource) ;

  public: GGS_AC_5F_task_2E_weak & operator = (const class GGS_AC_5F_task & inSource) ;

//--------------------------------- Constructor and assignment from optional reference

//--------------------------------- nil initializer
  public: inline static GGS_AC_5F_task_2E_weak init_nil (void) {
    GGS_AC_5F_task_2E_weak result ;
    macroMyNew (result.mProxyPtr, cPtr_weakReference_proxy (HERE)) ;
    return result ;
  }

//--------------------------------- Bang operator
  public: GGS_AC_5F_task bang_AC_5F_task_2E_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const ;

//--------------------------------- isValuated
  public: inline bool isValuated (void) const {
    return isValid () && (ptr () != nullptr) ;
  }

//--------------------------------- Unwrapped value
  public: inline GGS_AC_5F_task unwrappedValue (void) const {
    GGS_AC_5F_task result ;
    if (isValid ()) {
      const cPtr_AC_5F_task * p = (cPtr_AC_5F_task *) ptr () ;
      if (nullptr != p) {
        result = GGS_AC_5F_task (p) ;
      }
    }
    return result ;
  }

//--------------------------------- GALGAS read only properties
  public: inline GGS_bool readProperty_isNil (void) const {
    return GGS_bool (isValid (), ptr () == nullptr) ;
  }

  public: inline GGS_bool readProperty_isSome (void) const {
    return GGS_bool (isValid (), ptr () != nullptr) ;
  }

//-- Start of type generic part

//--------------------------------- Initializers

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GGS_AC_5F_task_2E_weak extractObject (const GGS_object & inObject,
                                                       Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GGS_AC_5F_task_2E_weak class_func_nil (LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GGS_AC_5F_task_2E_weak & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GGS_AC_5F_task_2E_weak class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_AC_5F_task_2E_weak ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @C_5F_independantTask reference class
//
//--------------------------------------------------------------------------------------------------

class GGS_C_5F_independantTask : public GGS_AC_5F_task {
//--------------------------------- Default constructor
  public: GGS_C_5F_independantTask (void) ;

//--------------------------------- Constructor from pointer
  public: GGS_C_5F_independantTask (const class cPtr_C_5F_independantTask * inSourcePtr) ;

//--------------------------------- Property access
//-- Start of type generic part

//--------------------------------- Initializers
  public: static GGS_C_5F_independantTask init (Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GGS_C_5F_independantTask extractObject (const GGS_object & inObject,
                                                         Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GGS_C_5F_independantTask class_func_new (LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GGS_C_5F_independantTask & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GGS_C_5F_independantTask class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_C_5F_independantTask ;

#include "separateHeaderFor_C_5F_independantTask.h"

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @C_5F_independantTask_2E_weak weak reference class
//
//--------------------------------------------------------------------------------------------------

class GGS_C_5F_independantTask_2E_weak : public GGS_AC_5F_task_2E_weak {
//--------------------------------- Default constructor
  public: GGS_C_5F_independantTask_2E_weak (void) ;

//--------------------------------- Constructor and assignment from strong reference
  public: GGS_C_5F_independantTask_2E_weak (const class GGS_C_5F_independantTask & inSource) ;

  public: GGS_C_5F_independantTask_2E_weak & operator = (const class GGS_C_5F_independantTask & inSource) ;

//--------------------------------- Constructor and assignment from optional reference

//--------------------------------- nil initializer
  public: inline static GGS_C_5F_independantTask_2E_weak init_nil (void) {
    GGS_C_5F_independantTask_2E_weak result ;
    macroMyNew (result.mProxyPtr, cPtr_weakReference_proxy (HERE)) ;
    return result ;
  }

//--------------------------------- Bang operator
  public: GGS_C_5F_independantTask bang_C_5F_independantTask_2E_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const ;

//--------------------------------- isValuated
  public: inline bool isValuated (void) const {
    return isValid () && (ptr () != nullptr) ;
  }

//--------------------------------- Unwrapped value
  public: inline GGS_C_5F_independantTask unwrappedValue (void) const {
    GGS_C_5F_independantTask result ;
    if (isValid ()) {
      const cPtr_C_5F_independantTask * p = (cPtr_C_5F_independantTask *) ptr () ;
      if (nullptr != p) {
        result = GGS_C_5F_independantTask (p) ;
      }
    }
    return result ;
  }

//--------------------------------- GALGAS read only properties
  public: inline GGS_bool readProperty_isNil (void) const {
    return GGS_bool (isValid (), ptr () == nullptr) ;
  }

  public: inline GGS_bool readProperty_isSome (void) const {
    return GGS_bool (isValid (), ptr () != nullptr) ;
  }

//-- Start of type generic part

//--------------------------------- Initializers

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GGS_C_5F_independantTask_2E_weak extractObject (const GGS_object & inObject,
                                                                 Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GGS_C_5F_independantTask_2E_weak class_func_nil (LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GGS_C_5F_independantTask_2E_weak & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GGS_C_5F_independantTask_2E_weak class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_C_5F_independantTask_2E_weak ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @C_5F_taskDependsFromTask reference class
//
//--------------------------------------------------------------------------------------------------

class GGS_C_5F_taskDependsFromTask : public GGS_AC_5F_task {
//--------------------------------- Default constructor
  public: GGS_C_5F_taskDependsFromTask (void) ;

//--------------------------------- Constructor from pointer
  public: GGS_C_5F_taskDependsFromTask (const class cPtr_C_5F_taskDependsFromTask * inSourcePtr) ;

//--------------------------------- Property access
  public: class GGS_uint readProperty_mTask (void) const ;
  public: void setProperty_mTask (const GGS_uint & inValue) ;

  public: class GGS_luint readProperty_mEvery (void) const ;
  public: void setProperty_mEvery (const GGS_luint & inValue) ;

//-- Start of type generic part

//--------------------------------- Initializers
  public: static GGS_C_5F_taskDependsFromTask init_21__21_ (const class GGS_uint & inOperand0,
                                                            const class GGS_luint & inOperand1,
                                                            Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GGS_C_5F_taskDependsFromTask extractObject (const GGS_object & inObject,
                                                             Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GGS_C_5F_taskDependsFromTask class_func_new (const class GGS_uint & inOperand0,
                                                                    const class GGS_luint & inOperand1
                                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GGS_C_5F_taskDependsFromTask & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GGS_C_5F_taskDependsFromTask class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_C_5F_taskDependsFromTask ;

#include "separateHeaderFor_C_5F_taskDependsFromTask.h"

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @C_5F_taskDependsFromTask_2E_weak weak reference class
//
//--------------------------------------------------------------------------------------------------

class GGS_C_5F_taskDependsFromTask_2E_weak : public GGS_AC_5F_task_2E_weak {
//--------------------------------- Default constructor
  public: GGS_C_5F_taskDependsFromTask_2E_weak (void) ;

//--------------------------------- Constructor and assignment from strong reference
  public: GGS_C_5F_taskDependsFromTask_2E_weak (const class GGS_C_5F_taskDependsFromTask & inSource) ;

  public: GGS_C_5F_taskDependsFromTask_2E_weak & operator = (const class GGS_C_5F_taskDependsFromTask & inSource) ;

//--------------------------------- Constructor and assignment from optional reference

//--------------------------------- nil initializer
  public: inline static GGS_C_5F_taskDependsFromTask_2E_weak init_nil (void) {
    GGS_C_5F_taskDependsFromTask_2E_weak result ;
    macroMyNew (result.mProxyPtr, cPtr_weakReference_proxy (HERE)) ;
    return result ;
  }

//--------------------------------- Bang operator
  public: GGS_C_5F_taskDependsFromTask bang_C_5F_taskDependsFromTask_2E_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const ;

//--------------------------------- isValuated
  public: inline bool isValuated (void) const {
    return isValid () && (ptr () != nullptr) ;
  }

//--------------------------------- Unwrapped value
  public: inline GGS_C_5F_taskDependsFromTask unwrappedValue (void) const {
    GGS_C_5F_taskDependsFromTask result ;
    if (isValid ()) {
      const cPtr_C_5F_taskDependsFromTask * p = (cPtr_C_5F_taskDependsFromTask *) ptr () ;
      if (nullptr != p) {
        result = GGS_C_5F_taskDependsFromTask (p) ;
      }
    }
    return result ;
  }

//--------------------------------- GALGAS read only properties
  public: inline GGS_bool readProperty_isNil (void) const {
    return GGS_bool (isValid (), ptr () == nullptr) ;
  }

  public: inline GGS_bool readProperty_isSome (void) const {
    return GGS_bool (isValid (), ptr () != nullptr) ;
  }

//-- Start of type generic part

//--------------------------------- Initializers

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GGS_C_5F_taskDependsFromTask_2E_weak extractObject (const GGS_object & inObject,
                                                                     Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GGS_C_5F_taskDependsFromTask_2E_weak class_func_nil (LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GGS_C_5F_taskDependsFromTask_2E_weak & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GGS_C_5F_taskDependsFromTask_2E_weak class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_C_5F_taskDependsFromTask_2E_weak ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @C_5F_taskDependsFromMessage reference class
//
//--------------------------------------------------------------------------------------------------

class GGS_C_5F_taskDependsFromMessage : public GGS_AC_5F_task {
//--------------------------------- Default constructor
  public: GGS_C_5F_taskDependsFromMessage (void) ;

//--------------------------------- Constructor from pointer
  public: GGS_C_5F_taskDependsFromMessage (const class cPtr_C_5F_taskDependsFromMessage * inSourcePtr) ;

//--------------------------------- Property access
  public: class GGS_uint readProperty_mMessage (void) const ;
  public: void setProperty_mMessage (const GGS_uint & inValue) ;

  public: class GGS_luint readProperty_mEvery (void) const ;
  public: void setProperty_mEvery (const GGS_luint & inValue) ;

//-- Start of type generic part

//--------------------------------- Initializers
  public: static GGS_C_5F_taskDependsFromMessage init_21__21_ (const class GGS_uint & inOperand0,
                                                               const class GGS_luint & inOperand1,
                                                               Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GGS_C_5F_taskDependsFromMessage extractObject (const GGS_object & inObject,
                                                                Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GGS_C_5F_taskDependsFromMessage class_func_new (const class GGS_uint & inOperand0,
                                                                       const class GGS_luint & inOperand1
                                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GGS_C_5F_taskDependsFromMessage & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GGS_C_5F_taskDependsFromMessage class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_C_5F_taskDependsFromMessage ;

#include "separateHeaderFor_C_5F_taskDependsFromMessage.h"

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @C_5F_taskDependsFromMessage_2E_weak weak reference class
//
//--------------------------------------------------------------------------------------------------

class GGS_C_5F_taskDependsFromMessage_2E_weak : public GGS_AC_5F_task_2E_weak {
//--------------------------------- Default constructor
  public: GGS_C_5F_taskDependsFromMessage_2E_weak (void) ;

//--------------------------------- Constructor and assignment from strong reference
  public: GGS_C_5F_taskDependsFromMessage_2E_weak (const class GGS_C_5F_taskDependsFromMessage & inSource) ;

  public: GGS_C_5F_taskDependsFromMessage_2E_weak & operator = (const class GGS_C_5F_taskDependsFromMessage & inSource) ;

//--------------------------------- Constructor and assignment from optional reference

//--------------------------------- nil initializer
  public: inline static GGS_C_5F_taskDependsFromMessage_2E_weak init_nil (void) {
    GGS_C_5F_taskDependsFromMessage_2E_weak result ;
    macroMyNew (result.mProxyPtr, cPtr_weakReference_proxy (HERE)) ;
    return result ;
  }

//--------------------------------- Bang operator
  public: GGS_C_5F_taskDependsFromMessage bang_C_5F_taskDependsFromMessage_2E_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const ;

//--------------------------------- isValuated
  public: inline bool isValuated (void) const {
    return isValid () && (ptr () != nullptr) ;
  }

//--------------------------------- Unwrapped value
  public: inline GGS_C_5F_taskDependsFromMessage unwrappedValue (void) const {
    GGS_C_5F_taskDependsFromMessage result ;
    if (isValid ()) {
      const cPtr_C_5F_taskDependsFromMessage * p = (cPtr_C_5F_taskDependsFromMessage *) ptr () ;
      if (nullptr != p) {
        result = GGS_C_5F_taskDependsFromMessage (p) ;
      }
    }
    return result ;
  }

//--------------------------------- GALGAS read only properties
  public: inline GGS_bool readProperty_isNil (void) const {
    return GGS_bool (isValid (), ptr () == nullptr) ;
  }

  public: inline GGS_bool readProperty_isSome (void) const {
    return GGS_bool (isValid (), ptr () != nullptr) ;
  }

//-- Start of type generic part

//--------------------------------- Initializers

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GGS_C_5F_taskDependsFromMessage_2E_weak extractObject (const GGS_object & inObject,
                                                                        Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GGS_C_5F_taskDependsFromMessage_2E_weak class_func_nil (LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GGS_C_5F_taskDependsFromMessage_2E_weak & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GGS_C_5F_taskDependsFromMessage_2E_weak class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_C_5F_taskDependsFromMessage_2E_weak ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @M_tasks map
//
//--------------------------------------------------------------------------------------------------

class cMapElement_M_5F_tasks ;

//--------------------------------------------------------------------------------------------------

extern const char * kSearchErrorMessage_M_5F_tasks_searchKey ;

//--------------------------------------------------------------------------------------------------

class GGS_M_5F_tasks : public AC_GALGAS_map {
//--------------------------------- Default constructor
  public: GGS_M_5F_tasks (void) ;

//--------------------------------- Handle copy
  public: GGS_M_5F_tasks (const GGS_M_5F_tasks & inSource) ;
  public: GGS_M_5F_tasks & operator = (const GGS_M_5F_tasks & inSource) ;
  
//-- Start of type generic part

//--------------------------------- Initializers
  public: static GGS_M_5F_tasks init (Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GGS_M_5F_tasks extractObject (const GGS_object & inObject,
                                               Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GGS_M_5F_tasks class_func_emptyMap (LOCATION_ARGS) ;

  public: static class GGS_M_5F_tasks class_func_mapWithMapToOverride (const class GGS_M_5F_tasks & inOperand0
                                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public: VIRTUAL_IN_DEBUG void addAssign_operation (const class GGS_lstring & inOperand0,
                                                     const class GGS_uint & inOperand1,
                                                     const class GGS_luint & inOperand2,
                                                     const class GGS_luint & inOperand3,
                                                     const class GGS_luint & inOperand4,
                                                     const class GGS_luint & inOperand5,
                                                     const class GGS_luint & inOperand6,
                                                     const class GGS_uint & inOperand7,
                                                     const class GGS_luint & inOperand8,
                                                     const class GGS_AC_5F_task & inOperand9,
                                                     Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public: VIRTUAL_IN_DEBUG GGS_M_5F_tasks add_operation (const GGS_M_5F_tasks & inOperand,
                                                         Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_insertKey (class GGS_lstring constinArgument0,
                                                  class GGS_uint constinArgument1,
                                                  class GGS_luint constinArgument2,
                                                  class GGS_luint constinArgument3,
                                                  class GGS_luint constinArgument4,
                                                  class GGS_luint constinArgument5,
                                                  class GGS_luint constinArgument6,
                                                  class GGS_uint constinArgument7,
                                                  class GGS_luint constinArgument8,
                                                  class GGS_AC_5F_task constinArgument9,
                                                  Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMDeadlineForKey (class GGS_luint constinArgument0,
                                                           class GGS_string constinArgument1,
                                                           Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMDurationMaxForKey (class GGS_luint constinArgument0,
                                                              class GGS_string constinArgument1,
                                                              Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMDurationMinForKey (class GGS_luint constinArgument0,
                                                              class GGS_string constinArgument1,
                                                              Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMIndexForKey (class GGS_uint constinArgument0,
                                                        class GGS_string constinArgument1,
                                                        Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMOffsetForKey (class GGS_luint constinArgument0,
                                                         class GGS_string constinArgument1,
                                                         Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMPeriodForKey (class GGS_luint constinArgument0,
                                                         class GGS_string constinArgument1,
                                                         Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMPriorityForKey (class GGS_luint constinArgument0,
                                                           class GGS_string constinArgument1,
                                                           Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMProcessorForKey (class GGS_uint constinArgument0,
                                                            class GGS_string constinArgument1,
                                                            Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMTaskKindForKey (class GGS_AC_5F_task constinArgument0,
                                                           class GGS_string constinArgument1,
                                                           Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_searchKey (class GGS_lstring constinArgument0,
                                                  class GGS_uint & outArgument1,
                                                  class GGS_luint & outArgument2,
                                                  class GGS_luint & outArgument3,
                                                  class GGS_luint & outArgument4,
                                                  class GGS_luint & outArgument5,
                                                  class GGS_luint & outArgument6,
                                                  class GGS_uint & outArgument7,
                                                  class GGS_luint & outArgument8,
                                                  class GGS_AC_5F_task & outArgument9,
                                                  Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GGS_luint getter_mDeadlineForKey (const class GGS_string & constinOperand0,
                                                                   Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GGS_luint getter_mDurationMaxForKey (const class GGS_string & constinOperand0,
                                                                      Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GGS_luint getter_mDurationMinForKey (const class GGS_string & constinOperand0,
                                                                      Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GGS_uint getter_mIndexForKey (const class GGS_string & constinOperand0,
                                                               Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GGS_luint getter_mOffsetForKey (const class GGS_string & constinOperand0,
                                                                 Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GGS_luint getter_mPeriodForKey (const class GGS_string & constinOperand0,
                                                                 Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GGS_luint getter_mPriorityForKey (const class GGS_string & constinOperand0,
                                                                   Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GGS_uint getter_mProcessorForKey (const class GGS_string & constinOperand0,
                                                                   Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GGS_AC_5F_task getter_mTaskKindForKey (const class GGS_string & constinOperand0,
                                                                        Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GGS_M_5F_tasks getter_overriddenMap (Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) const ;


//--------------------------------- Read subscripts
  public: VIRTUAL_IN_DEBUG class GGS_M_5F_tasks_2E_element_3F_ readSubscript__3F_ (const class GGS_string & in0,
                                                                                   Compiler * inCompiler
                                                                                   COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
  public: VIRTUAL_IN_DEBUG cMapElement_M_5F_tasks * readWriteAccessForWithInstruction (Compiler * inCompiler,
                                                                                       const GGS_string & inKey
                                                                                       COMMA_LOCATION_ARGS) ;


//--- Append element
  public: VIRTUAL_IN_DEBUG void enterElement (const class GGS_M_5F_tasks_2E_element & inValue,
                                              Compiler * /* inCompiler */
                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- Friend
  friend class cEnumerator_M_5F_tasks ;
 
} ; // End of GGS_M_5F_tasks class

//--------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//--------------------------------------------------------------------------------------------------

class cEnumerator_M_5F_tasks : public cGenericAbstractEnumerator {
  public: cEnumerator_M_5F_tasks (const GGS_M_5F_tasks & inEnumeratedObject,
                                  const EnumerationOrder inOrder) ;

//--- Current element access
  public: class GGS_lstring current_lkey (LOCATION_ARGS) const ;
  public: class GGS_uint current_mIndex (LOCATION_ARGS) const ;
  public: class GGS_luint current_mPriority (LOCATION_ARGS) const ;
  public: class GGS_luint current_mOffset (LOCATION_ARGS) const ;
  public: class GGS_luint current_mDeadline (LOCATION_ARGS) const ;
  public: class GGS_luint current_mDurationMin (LOCATION_ARGS) const ;
  public: class GGS_luint current_mDurationMax (LOCATION_ARGS) const ;
  public: class GGS_uint current_mProcessor (LOCATION_ARGS) const ;
  public: class GGS_luint current_mPeriod (LOCATION_ARGS) const ;
  public: class GGS_AC_5F_task current_mTaskKind (LOCATION_ARGS) const ;
//--- Current element access
  public: class GGS_M_5F_tasks_2E_element current (LOCATION_ARGS) const ;
} ;

//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_M_5F_tasks ;

//--------------------------------------------------------------------------------------------------
//
// Phase 2: class for element of '@M_tasks' map
//
//--------------------------------------------------------------------------------------------------

class cMapElement_M_5F_tasks : public cMapElement {
//--- Map attributes
  public: GGS_uint mProperty_mIndex ;
  public: GGS_luint mProperty_mPriority ;
  public: GGS_luint mProperty_mOffset ;
  public: GGS_luint mProperty_mDeadline ;
  public: GGS_luint mProperty_mDurationMin ;
  public: GGS_luint mProperty_mDurationMax ;
  public: GGS_uint mProperty_mProcessor ;
  public: GGS_luint mProperty_mPeriod ;
  public: GGS_AC_5F_task mProperty_mTaskKind ;

//--- Constructors
  public: cMapElement_M_5F_tasks (const GGS_M_5F_tasks_2E_element & inValue
                                  COMMA_LOCATION_ARGS) ;
 
  public: cMapElement_M_5F_tasks (const GGS_lstring & inKey,
                                  const GGS_uint & in_mIndex,
                                  const GGS_luint & in_mPriority,
                                  const GGS_luint & in_mOffset,
                                  const GGS_luint & in_mDeadline,
                                  const GGS_luint & in_mDurationMin,
                                  const GGS_luint & in_mDurationMax,
                                  const GGS_uint & in_mProcessor,
                                  const GGS_luint & in_mPeriod,
                                  const GGS_AC_5F_task & in_mTaskKind
                                  COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements

//--- Virtual method that checks that all attributes are valid
  public: virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public: virtual cMapElement * copy (void) ;

//--- Description
 public: virtual void description (String & ioString, const int32_t inIndentation) const ;
} ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @M_5F_tasks_2E_element struct
//
//--------------------------------------------------------------------------------------------------

class GGS_M_5F_tasks_2E_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GGS_lstring mProperty_lkey ;
  public: inline GGS_lstring readProperty_lkey (void) const {
    return mProperty_lkey ;
  }

  public: GGS_uint mProperty_mIndex ;
  public: inline GGS_uint readProperty_mIndex (void) const {
    return mProperty_mIndex ;
  }

  public: GGS_luint mProperty_mPriority ;
  public: inline GGS_luint readProperty_mPriority (void) const {
    return mProperty_mPriority ;
  }

  public: GGS_luint mProperty_mOffset ;
  public: inline GGS_luint readProperty_mOffset (void) const {
    return mProperty_mOffset ;
  }

  public: GGS_luint mProperty_mDeadline ;
  public: inline GGS_luint readProperty_mDeadline (void) const {
    return mProperty_mDeadline ;
  }

  public: GGS_luint mProperty_mDurationMin ;
  public: inline GGS_luint readProperty_mDurationMin (void) const {
    return mProperty_mDurationMin ;
  }

  public: GGS_luint mProperty_mDurationMax ;
  public: inline GGS_luint readProperty_mDurationMax (void) const {
    return mProperty_mDurationMax ;
  }

  public: GGS_uint mProperty_mProcessor ;
  public: inline GGS_uint readProperty_mProcessor (void) const {
    return mProperty_mProcessor ;
  }

  public: GGS_luint mProperty_mPeriod ;
  public: inline GGS_luint readProperty_mPeriod (void) const {
    return mProperty_mPeriod ;
  }

  public: GGS_AC_5F_task mProperty_mTaskKind ;
  public: inline GGS_AC_5F_task readProperty_mTaskKind (void) const {
    return mProperty_mTaskKind ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default constructor
  public: GGS_M_5F_tasks_2E_element (void) ;

//--------------------------------- Property setters
  public: inline void setter_setLkey (const GGS_lstring & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_lkey = inValue ;
  }

  public: inline void setter_setMIndex (const GGS_uint & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mIndex = inValue ;
  }

  public: inline void setter_setMPriority (const GGS_luint & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mPriority = inValue ;
  }

  public: inline void setter_setMOffset (const GGS_luint & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mOffset = inValue ;
  }

  public: inline void setter_setMDeadline (const GGS_luint & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mDeadline = inValue ;
  }

  public: inline void setter_setMDurationMin (const GGS_luint & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mDurationMin = inValue ;
  }

  public: inline void setter_setMDurationMax (const GGS_luint & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mDurationMax = inValue ;
  }

  public: inline void setter_setMProcessor (const GGS_uint & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mProcessor = inValue ;
  }

  public: inline void setter_setMPeriod (const GGS_luint & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mPeriod = inValue ;
  }

  public: inline void setter_setMTaskKind (const GGS_AC_5F_task & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mTaskKind = inValue ;
  }

//--------------------------------- Virtual destructor
  public: virtual ~ GGS_M_5F_tasks_2E_element (void) ;

//--------------------------------- Set initialized properties
  private: void setInitializedProperties (Compiler * inCompiler) ;

//--------------------------------- Native constructor
  public: GGS_M_5F_tasks_2E_element (const GGS_lstring & in_lkey,
                                     const GGS_uint & in_mIndex,
                                     const GGS_luint & in_mPriority,
                                     const GGS_luint & in_mOffset,
                                     const GGS_luint & in_mDeadline,
                                     const GGS_luint & in_mDurationMin,
                                     const GGS_luint & in_mDurationMax,
                                     const GGS_uint & in_mProcessor,
                                     const GGS_luint & in_mPeriod,
                                     const GGS_AC_5F_task & in_mTaskKind) ;

//-- Start of type generic part

//--------------------------------- Initializers
  public: static GGS_M_5F_tasks_2E_element init_21__21__21__21__21__21__21__21__21__21_ (const class GGS_lstring & inOperand0,
                                                                                         const class GGS_uint & inOperand1,
                                                                                         const class GGS_luint & inOperand2,
                                                                                         const class GGS_luint & inOperand3,
                                                                                         const class GGS_luint & inOperand4,
                                                                                         const class GGS_luint & inOperand5,
                                                                                         const class GGS_luint & inOperand6,
                                                                                         const class GGS_uint & inOperand7,
                                                                                         const class GGS_luint & inOperand8,
                                                                                         const class GGS_AC_5F_task & inOperand9,
                                                                                         Compiler * inCompiler
                                                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GGS_M_5F_tasks_2E_element extractObject (const GGS_object & inObject,
                                                          Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GGS_M_5F_tasks_2E_element class_func_new (const class GGS_lstring & inOperand0,
                                                                 const class GGS_uint & inOperand1,
                                                                 const class GGS_luint & inOperand2,
                                                                 const class GGS_luint & inOperand3,
                                                                 const class GGS_luint & inOperand4,
                                                                 const class GGS_luint & inOperand5,
                                                                 const class GGS_luint & inOperand6,
                                                                 const class GGS_uint & inOperand7,
                                                                 const class GGS_luint & inOperand8,
                                                                 const class GGS_AC_5F_task & inOperand9,
                                                                 class Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (String & ioString,
                                             const int32_t inIndentation) const override ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GGS_M_5F_tasks_2E_element class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_M_5F_tasks_2E_element ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: M_tasks.element? optional
//
//--------------------------------------------------------------------------------------------------

class GGS_M_5F_tasks_2E_element_3F_ : public AC_GALGAS_root {
//--------------------------------- Private property
  private: GGS_M_5F_tasks_2E_element mValue ;
  private: OptionalState mState ;

//--------------------------------- Default constructor
  public: GGS_M_5F_tasks_2E_element_3F_ (void) ;

//--------------------------------- Constructor from unwrapped type
  public: GGS_M_5F_tasks_2E_element_3F_ (const GGS_M_5F_tasks_2E_element & inSource) ;

//--------------------------------- Constructor from weak type

//--------------------------------- nil initializer
  public: static GGS_M_5F_tasks_2E_element_3F_ init_nil (void) ;

  public: inline bool isNil (void) const { return mState == OptionalState::isNil ; }

  public: bool isValuated (void) const ;
  public: inline GGS_M_5F_tasks_2E_element unwrappedValue (void) const {
    return mValue ;
  }

//--------------------------------- GALGAS read only properties
  public: inline GGS_bool readProperty_isNil (void) const {
    return GGS_bool (mState != OptionalState::invalid, mState == OptionalState::isNil) ;
  }

  public: inline GGS_bool readProperty_isSome (void) const {
    return GGS_bool (mState != OptionalState::invalid, mState == OptionalState::valuated) ;
  }

  
//--- Methods that every type should implement
  public: virtual bool isValid (void) const override ;
  
  public: virtual void drop (void) override ;

  public: virtual void description (String & ioString,
                                    const int32_t inIndentation) const override ;

//-- Start of type generic part

//--------------------------------- Initializers

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GGS_M_5F_tasks_2E_element_3F_ extractObject (const GGS_object & inObject,
                                                              Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;


//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GGS_M_5F_tasks_2E_element_3F_ class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_M_5F_tasks_2E_element_3F_ ;

//--------------------------------------------------------------------------------------------------
//
//Parser class 'oa_parser' declaration
//
//--------------------------------------------------------------------------------------------------

class cParser_oa_5F_parser {
//--- Virtual destructor
  public: virtual ~ cParser_oa_5F_parser (void) { }

//--- Non terminal declarations
  protected: virtual void nt_axiome_ (class Lexique_oa_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_axiome_parse (class Lexique_oa_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_axiome_indexing (class Lexique_oa_5F_scanner * inLexique) = 0 ;


//--- Rule declarations
  protected: void rule_oa_5F_parser_axiome_i0_ (Lexique_oa_5F_scanner * inLexique) ;

  protected: void rule_oa_5F_parser_axiome_i0_parse (Lexique_oa_5F_scanner * inLexique) ;

  protected: void rule_oa_5F_parser_axiome_i0_indexing (Lexique_oa_5F_scanner * inLexique) ;



//--- Select methods
  protected: virtual int32_t select_oa_5F_parser_0 (Lexique_oa_5F_scanner *) = 0 ;

  protected: virtual int32_t select_oa_5F_parser_1 (Lexique_oa_5F_scanner *) = 0 ;

  protected: virtual int32_t select_oa_5F_parser_2 (Lexique_oa_5F_scanner *) = 0 ;

  protected: virtual int32_t select_oa_5F_parser_3 (Lexique_oa_5F_scanner *) = 0 ;

  protected: virtual int32_t select_oa_5F_parser_4 (Lexique_oa_5F_scanner *) = 0 ;

  protected: virtual int32_t select_oa_5F_parser_5 (Lexique_oa_5F_scanner *) = 0 ;

  protected: virtual int32_t select_oa_5F_parser_6 (Lexique_oa_5F_scanner *) = 0 ;

  protected: virtual int32_t select_oa_5F_parser_7 (Lexique_oa_5F_scanner *) = 0 ;

  protected: virtual int32_t select_oa_5F_parser_8 (Lexique_oa_5F_scanner *) = 0 ;

  protected: virtual int32_t select_oa_5F_parser_9 (Lexique_oa_5F_scanner *) = 0 ;

  protected: virtual int32_t select_oa_5F_parser_10 (Lexique_oa_5F_scanner *) = 0 ;

  protected: virtual int32_t select_oa_5F_parser_11 (Lexique_oa_5F_scanner *) = 0 ;

  protected: virtual int32_t select_oa_5F_parser_12 (Lexique_oa_5F_scanner *) = 0 ;

  protected: virtual int32_t select_oa_5F_parser_13 (Lexique_oa_5F_scanner *) = 0 ;

  protected: virtual int32_t select_oa_5F_parser_14 (Lexique_oa_5F_scanner *) = 0 ;


} ;

//--------------------------------------------------------------------------------------------------
//
//Routine 'performComputations&&&&'
//
//--------------------------------------------------------------------------------------------------

void routine_performComputations_26__26__26__26_ (class GGS_M_5F_processor & ioArgument0,
                                                  class GGS_M_5F_network & ioArgument1,
                                                  class GGS_M_5F_messages & ioArgument2,
                                                  class GGS_M_5F_tasks & ioArgument3,
                                                  class Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//  GRAMMAR oa_grammar
//--------------------------------------------------------------------------------------------------

class cGrammar_oa_5F_grammar : public cParser_oa_5F_parser {
//------------------------------------- 'axiome' non terminal
//--- 'parse' label
  public: virtual void nt_axiome_parse (Lexique_oa_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_axiome_indexing (Lexique_oa_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_axiome_ (Lexique_oa_5F_scanner * inCompiler) ;

//--- Start symbol
  public: static void _performSourceFileParsing_ (Compiler * inCompiler,
                                                  GGS_lstring inFileName
                                                  COMMA_LOCATION_ARGS) ;

  public: static void _performSourceStringParsing_ (Compiler * inCompiler,
                                                    GGS_string inSourceString,
                                                    GGS_string inNameString
                                                    COMMA_LOCATION_ARGS) ;

//--- Indexing
  public: static void performIndexing (Compiler * inCompiler,
                                       const String & inSourceFilePath) ;

//--- Only lexical analysis
  public: static void performOnlyLexicalAnalysis (Compiler * inCompiler,
                                                  const String & inSourceFilePath) ;

//--- Only syntax analysis
  public: static void performOnlySyntaxAnalysis (Compiler * inCompiler,
                                                 const String & inSourceFilePath) ;

  public: virtual int32_t select_oa_5F_parser_0 (Lexique_oa_5F_scanner *) ;

  public: virtual int32_t select_oa_5F_parser_1 (Lexique_oa_5F_scanner *) ;

  public: virtual int32_t select_oa_5F_parser_2 (Lexique_oa_5F_scanner *) ;

  public: virtual int32_t select_oa_5F_parser_3 (Lexique_oa_5F_scanner *) ;

  public: virtual int32_t select_oa_5F_parser_4 (Lexique_oa_5F_scanner *) ;

  public: virtual int32_t select_oa_5F_parser_5 (Lexique_oa_5F_scanner *) ;

  public: virtual int32_t select_oa_5F_parser_6 (Lexique_oa_5F_scanner *) ;

  public: virtual int32_t select_oa_5F_parser_7 (Lexique_oa_5F_scanner *) ;

  public: virtual int32_t select_oa_5F_parser_8 (Lexique_oa_5F_scanner *) ;

  public: virtual int32_t select_oa_5F_parser_9 (Lexique_oa_5F_scanner *) ;

  public: virtual int32_t select_oa_5F_parser_10 (Lexique_oa_5F_scanner *) ;

  public: virtual int32_t select_oa_5F_parser_11 (Lexique_oa_5F_scanner *) ;

  public: virtual int32_t select_oa_5F_parser_12 (Lexique_oa_5F_scanner *) ;

  public: virtual int32_t select_oa_5F_parser_13 (Lexique_oa_5F_scanner *) ;

  public: virtual int32_t select_oa_5F_parser_14 (Lexique_oa_5F_scanner *) ;
} ;

//--------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------
//
//Routine 'println?'
//
//--------------------------------------------------------------------------------------------------

void routine_println_3F_ (const class GGS_string constinArgument0,
                          class Compiler * inCompiler
                          COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Routine 'print?'
//
//--------------------------------------------------------------------------------------------------

void routine_print_3F_ (const class GGS_string constinArgument0,
                        class Compiler * inCompiler
                        COMMA_LOCATION_ARGS) ;


//--------------------------------------------------------------------------------------------------
//
//                               Bool options                                                    
//
//--------------------------------------------------------------------------------------------------

extern BoolCommandLineOption gOption_oa_5F_cli_5F_options_createIntermediateFiles ;

extern BoolCommandLineOption gOption_oa_5F_cli_5F_options_useCANmaxLegth ;

//--------------------------------------------------------------------------------------------------
//
//                               UInt options                                                    
//
//--------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------
//
//                              String options                                                   
//
//--------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------
//
//                              String List options                                              
//
//--------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------

