//--- START OF USER ZONE 1


//--- END OF USER ZONE 1
//--------------------------------------------------------------------------------------------------
// Phase 2: pointer class for @C_independantTask class
//--------------------------------------------------------------------------------------------------

class cPtr_C_5F_independantTask : public cPtr_AC_5F_task {

  #ifndef DO_NOT_GENERATE_CHECKINGS
    public: virtual void printNonNullClassInstanceProperties (void) const override ;
  #endif

//--------------------------------- Initializers
  public: void C_5F_independantTask_init (Compiler * inCompiler) ;


//--- START OF USER ZONE 2

  public : virtual bool taskDependsOnTask (void) const override ;
  public : virtual bool taskDependsOnMessage (void) const override ;
  public : virtual uint32_t getTaskDependanceValue (void) const override ;
  public : virtual uint32_t getTaskEveryParameter (void) const override ;

//--- END OF USER ZONE 2
//--- Properties



//--- Constructor
  public: cPtr_C_5F_independantTask (Compiler * inCompiler
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

