//--- START OF USER ZONE 1


//--- END OF USER ZONE 1
//--------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @C_taskDependsFromMessage class
//
//--------------------------------------------------------------------------------------------------

class cPtr_C_5F_taskDependsFromMessage : public cPtr_AC_5F_task {

  #ifndef DO_NOT_GENERATE_CHECKINGS
    public: virtual void printNonNullClassInstanceProperties (void) const override ;
  #endif

//--------------------------------- Initializers
  public: void C_5F_taskDependsFromMessage_init_21__21_ (const class GALGAS_uint & inOperand0,
                                                         const class GALGAS_luint & inOperand1,
                                                         Compiler * inCompiler) ;


//--- START OF USER ZONE 2

  public : virtual bool taskDependsOnTask (void) const override ;
  public : virtual bool taskDependsOnMessage (void) const override ;
  public : virtual uint32_t getTaskDependanceValue (void) const override ;
  public : virtual uint32_t getTaskEveryParameter (void) const override ;

//--- END OF USER ZONE 2
//--- Properties
  public: GALGAS_uint mProperty_mMessage ;
  public: GALGAS_luint mProperty_mEvery ;


//--- Default constructor
  public: cPtr_C_5F_taskDependsFromMessage (Compiler * inCompiler COMMA_LOCATION_ARGS) ;

//--- Constructor
  public: cPtr_C_5F_taskDependsFromMessage (const GALGAS_uint & in_mMessage,
                                            const GALGAS_luint & in_mEvery
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

