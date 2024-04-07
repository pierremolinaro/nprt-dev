//--- START OF USER ZONE 1


//--- END OF USER ZONE 1
//--------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @AC_task class
//
//--------------------------------------------------------------------------------------------------

class cPtr_AC_5F_task : public acStrongPtr_class {

  #ifndef DO_NOT_GENERATE_CHECKINGS
    public: virtual void printNonNullClassInstanceProperties (void) const override ;
  #endif

//--------------------------------- Initializers
  public: void AC_5F_task_init (Compiler * inCompiler) ;


//--- START OF USER ZONE 2

  public : virtual bool taskDependsOnTask (void) const = 0 ;
  public : virtual bool taskDependsOnMessage (void) const = 0 ;
  public : virtual uint32_t getTaskDependanceValue (void) const = 0 ;
  public : virtual uint32_t getTaskEveryParameter (void) const = 0 ;

//--- END OF USER ZONE 2
//--- Properties


//--- Default constructor
  public: cPtr_AC_5F_task (Compiler * inCompiler COMMA_LOCATION_ARGS) ;

//--- Constructor
  public: cPtr_AC_5F_task (LOCATION_ARGS) ;

//--- Attribute accessors
//--- Description
  public: virtual void description (String & ioString,
                                    const int32_t inIndentation) const override = 0 ;

  public: virtual ComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override = 0 ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override = 0 ;

} ;

