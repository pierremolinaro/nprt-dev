//--- START OF USER ZONE 1


//--- END OF USER ZONE 1
//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                     Pointer class for @C_independantTask class                                      *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

class cPtr_C_5F_independantTask : public cPtr_AC_5F_task {
//--- START OF USER ZONE 2

  public : virtual bool taskDependsOnTask (void) const ;
  public : virtual bool taskDependsOnMessage (void) const ;
  public : virtual uint32_t getTaskDependanceValue (void) const ;
  public : virtual uint32_t getTaskEveryParameter (void) const ;

//--- END OF USER ZONE 2
//--- Attributes

//--- Constructor
  public : cPtr_C_5F_independantTask (LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

