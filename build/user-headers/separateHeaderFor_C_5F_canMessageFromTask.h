//--- START OF USER ZONE 1


//--- END OF USER ZONE 1
//--------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @C_canMessageFromTask class
//
//--------------------------------------------------------------------------------------------------

class cPtr_C_5F_canMessageFromTask : public cPtr_AC_5F_canMessage {

  #ifndef DO_NOT_GENERATE_CHECKINGS
    public: virtual void printNonNullClassInstanceProperties (void) const override ;
  #endif

//--------------------------------- Initializers
  public: void C_5F_canMessageFromTask_init_21_ (const class GALGAS_uint & inOperand0,
                                                 Compiler * inCompiler) ;


//--- START OF USER ZONE 2

  public : virtual bool messageDependsOnTask (void) const override ;
  public : virtual bool messageDependsOnMessage (void) const override ;
  public : virtual uint32_t getMessageDependanceValue (void) const override ;

//--- END OF USER ZONE 2
//--- Properties
  public: GALGAS_uint mProperty_mTaskIndex ;


//--- Default constructor
  public: cPtr_C_5F_canMessageFromTask (Compiler * inCompiler COMMA_LOCATION_ARGS) ;

//--- Constructor
  public: cPtr_C_5F_canMessageFromTask (const GALGAS_uint & in_mTaskIndex
                                        COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
//--- Description
  public: virtual void description (String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual ComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

