//--- START OF USER ZONE 1


//--- END OF USER ZONE 1
//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @C_canIndependantMessage class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_C_5F_canIndependantMessage : public cPtr_AC_5F_canMessage {

//--- START OF USER ZONE 2

  public : virtual bool messageDependsOnTask (void) const override ;
  public : virtual bool messageDependsOnMessage (void) const override ;
  public : virtual uint32_t getMessageDependanceValue (void) const override ;

//--- END OF USER ZONE 2
//--- Properties

//--- Constructor
  public: cPtr_C_5F_canIndependantMessage (LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

