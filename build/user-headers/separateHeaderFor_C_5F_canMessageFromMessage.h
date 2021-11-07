//--- START OF USER ZONE 1


//--- END OF USER ZONE 1
//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @C_canMessageFromMessage class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_C_5F_canMessageFromMessage : public cPtr_AC_5F_canMessage {
//--- START OF USER ZONE 2

  public : virtual bool messageDependsOnTask (void) const ;
  public : virtual bool messageDependsOnMessage (void) const ;
  public : virtual uint32_t getMessageDependanceValue (void) const ;

//--- END OF USER ZONE 2
//--- Properties
  public: GALGAS_uint mProperty_mMessageIndex ;

//--- Constructor
  public: cPtr_C_5F_canMessageFromMessage (const GALGAS_uint & in_mMessageIndex
                                           COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

