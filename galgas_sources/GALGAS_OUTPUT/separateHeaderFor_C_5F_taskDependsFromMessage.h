//---------------------------------------------------------------------------*
//                                                                           *
//          File 'separateHeaderFor_C_5F_taskDependsFromMessage.h'           *
//                 Generated by version GALGAS_BETA_VERSION                  *
//                     november 4th, 2010, at 17h40'59"                      *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

//---------------------------------------------------------------------------*
//                                                                           *
//             Pointer class for @C_taskDependsFromMessage class             *
//                                                                           *
//---------------------------------------------------------------------------*

class cPtr_C_5F_taskDependsFromMessage : public cPtr_AC_5F_task {

//--- START OF USER ZONE 2

  public : virtual bool taskDependsOnTask (void) const ;
  public : virtual bool taskDependsOnMessage (void) const ;
  public : virtual PMUInt32 getTaskDependanceValue (void) const ;
  public : virtual PMUInt32 getTaskEveryParameter (void) const ;

//--- END OF USER ZONE 2

//--- Attributes
  public : GALGAS_uint mAttribute_mMessage ;
  public : GALGAS_luint mAttribute_mEvery ;

//--- Constructor
  public : cPtr_C_5F_taskDependsFromMessage (const GALGAS_uint & in_mMessage,
                                             const GALGAS_luint & in_mEvery
                                             COMMA_LOCATION_ARGS) ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const PMSInt32 inIndentation) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;
