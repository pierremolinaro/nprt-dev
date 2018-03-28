//--- START OF USER ZONE 1


//--- END OF USER ZONE 1
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                   Pointer class for @C_taskDependsFromTask class                                    *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

class cPtr_C_5F_taskDependsFromTask : public cPtr_AC_5F_task {
//--- START OF USER ZONE 2

  public : virtual bool taskDependsOnTask (void) const ;
  public : virtual bool taskDependsOnMessage (void) const ;
  public : virtual uint32_t getTaskDependanceValue (void) const ;
  public : virtual uint32_t getTaskEveryParameter (void) const ;

//--- END OF USER ZONE 2
//--- Attributes
  public : GALGAS_uint mProperty_mTask ;
  public : GALGAS_luint mProperty_mEvery ;

//--- Constructor
  public : cPtr_C_5F_taskDependsFromTask (const GALGAS_uint & in_mTask,
                                          const GALGAS_luint & in_mEvery
                                          COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_uint getter_mTask (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_luint getter_mEvery (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

