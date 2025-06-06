//--- START OF USER ZONE 1


//--- END OF USER ZONE 1
//--------------------------------------------------------------------------------------------------
// Phase 2: pointer class for @C_canMessageFromMessage class
//--------------------------------------------------------------------------------------------------

class cPtr_C_5F_canMessageFromMessage : public cPtr_AC_5F_canMessage {

  #ifndef DO_NOT_GENERATE_CHECKINGS
    public: virtual void printNonNullClassInstanceProperties (void) const override ;
  #endif

//--------------------------------- Initializers
  public: void C_5F_canMessageFromMessage_init_21_ (const class GGS_uint & inOperand0,
                                                    Compiler * inCompiler) ;


//--- START OF USER ZONE 2

  public : virtual bool messageDependsOnTask (void) const override ;
  public : virtual bool messageDependsOnMessage (void) const override ;
  public : virtual uint32_t getMessageDependanceValue (void) const override ;

//--- END OF USER ZONE 2
//--- Properties
  public: GGS_uint mProperty_mMessageIndex ;


//--- Default constructor
  public: cPtr_C_5F_canMessageFromMessage (Compiler * inCompiler COMMA_LOCATION_ARGS) ;

//--- Constructor
  public: cPtr_C_5F_canMessageFromMessage (const GGS_uint & in_mMessageIndex,
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

