//--- START OF USER ZONE 1


//--- END OF USER ZONE 1
//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @AC_canMessage class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_AC_5F_canMessage : public acStrongPtr_class {

  #ifndef DO_NOT_GENERATE_CHECKINGS
    public: virtual void printNonNullClassInstanceProperties (void) const override ;
  #endif
//--- START OF USER ZONE 2

  public : virtual bool messageDependsOnTask (void) const = 0 ;
  public : virtual bool messageDependsOnMessage (void) const = 0 ;
  public : virtual uint32_t getMessageDependanceValue (void) const = 0 ;

//--- END OF USER ZONE 2
//--- Properties

//--- Constructor
  public: cPtr_AC_5F_canMessage (LOCATION_ARGS) ;

//--- Attribute accessors
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override = 0 ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override = 0 ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override = 0 ;

} ;

