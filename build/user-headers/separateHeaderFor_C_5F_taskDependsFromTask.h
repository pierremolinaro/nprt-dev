//--- START OF USER ZONE 1


//--- END OF USER ZONE 1
//--------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @C_taskDependsFromTask class
//
//--------------------------------------------------------------------------------------------------

class cPtr_C_5F_taskDependsFromTask : public cPtr_AC_5F_task {

  #ifndef DO_NOT_GENERATE_CHECKINGS
    public: virtual void printNonNullClassInstanceProperties (void) const override ;
  #endif

//--------------------------------- Initializers
  public: void C_5F_taskDependsFromTask_init_21__21_ (const class GGS_uint & inOperand0,
                                                      const class GGS_luint & inOperand1,
                                                      Compiler * inCompiler) ;


//--- START OF USER ZONE 2

  public : virtual bool taskDependsOnTask (void) const override ;
  public : virtual bool taskDependsOnMessage (void) const override ;
  public : virtual uint32_t getTaskDependanceValue (void) const override ;
  public : virtual uint32_t getTaskEveryParameter (void) const override ;

//--- END OF USER ZONE 2
//--- Properties
  public: GGS_uint mProperty_mTask ;
  public: GGS_luint mProperty_mEvery ;


//--- Default constructor
  public: cPtr_C_5F_taskDependsFromTask (Compiler * inCompiler COMMA_LOCATION_ARGS) ;

//--- Constructor
  public: cPtr_C_5F_taskDependsFromTask (const GGS_uint & in_mTask,
                                         const GGS_luint & in_mEvery,
                                         Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (Compiler * inCompiler COMMA_LOCATION_ARGS) const override ;

//--- Attribute accessors
//--- Description
  public: virtual void description (String & ioString,
                                    const int32_t inIndentation) const override ;

//--- Class descriptor
  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

