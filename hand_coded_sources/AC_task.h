#define macro_AC_task \
  public : virtual bool taskDependsOnTask (void) const = 0 ; \
  public : virtual bool taskDependsOnMessage (void) const = 0 ; \
  public : virtual uint32 getTaskDependanceValue (void) const = 0 ; \
  public : virtual uint32 getTaskEveryParameter (void) const = 0 ;

#define macroInheritFrom_AC_task \
  public : virtual bool taskDependsOnTask (void) const ; \
  public : virtual bool taskDependsOnMessage (void) const ; \
  public : virtual uint32 getTaskDependanceValue (void) const ; \
  public : virtual uint32 getTaskEveryParameter (void) const ;
