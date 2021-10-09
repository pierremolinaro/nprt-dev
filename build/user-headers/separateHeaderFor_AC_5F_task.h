//--- START OF USER ZONE 1


//--- END OF USER ZONE 1
//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @AC_task class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_AC_5F_task : public acPtr_class {
//--- START OF USER ZONE 2

  public : virtual bool taskDependsOnTask (void) const = 0 ;
  public : virtual bool taskDependsOnMessage (void) const = 0 ;
  public : virtual uint32_t getTaskDependanceValue (void) const = 0 ;
  public : virtual uint32_t getTaskEveryParameter (void) const = 0 ;

//--- END OF USER ZONE 2
//--- Attributes

//--- Constructor
  public: cPtr_AC_5F_task (LOCATION_ARGS) ;

//--- Attribute accessors
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const = 0 ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const = 0 ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const = 0 ;

} ;

