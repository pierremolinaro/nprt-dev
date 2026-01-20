#include "Compiler.h"
#include "galgas-input-output.h"
#include "C_galgas_CLI_Options.h"
#include "PrologueEpilogue.h"

//--------------------------------------------------------------------------------------------------

#include "all-declarations-0.h"

//--------------------------------------------------------------------------------------------------
//Class for element of '@_32_lstringlist' list
//--------------------------------------------------------------------------------------------------

class cCollectionElement__32_lstringlist : public cCollectionElement {
  public: GGS__32_lstringlist_2E_element mObject ;

//--- Class functions
  public: cCollectionElement__32_lstringlist (const GGS_lstring & in_mValue_30_,
                                              const GGS_lstring & in_mValue_31_
                                              COMMA_LOCATION_ARGS) ;
  public: cCollectionElement__32_lstringlist (const GGS__32_lstringlist_2E_element & inElement COMMA_LOCATION_ARGS) ;

//--- Virtual method that checks that all attributes are valid
  public: virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public: virtual cCollectionElement * copy (void) ;
} ;

//--------------------------------------------------------------------------------------------------

cCollectionElement__32_lstringlist::cCollectionElement__32_lstringlist (const GGS_lstring & in_mValue_30_,
                                                                        const GGS_lstring & in_mValue_31_
                                                                        COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_mValue_30_, in_mValue_31_) {
}

//--------------------------------------------------------------------------------------------------

cCollectionElement__32_lstringlist::cCollectionElement__32_lstringlist (const GGS__32_lstringlist_2E_element & inElement COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (inElement.mProperty_mValue_30_, inElement.mProperty_mValue_31_) {
}

//--------------------------------------------------------------------------------------------------

bool cCollectionElement__32_lstringlist::isValid (void) const {
  return true ;
}

//--------------------------------------------------------------------------------------------------

cCollectionElement * cCollectionElement__32_lstringlist::copy (void) {
  cCollectionElement * result = nullptr ;
  macroMyNew (result, cCollectionElement__32_lstringlist (mObject.mProperty_mValue_30_, mObject.mProperty_mValue_31_ COMMA_HERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------
// List type @_32_lstringlist
//--------------------------------------------------------------------------------------------------

GGS__32_lstringlist::GGS__32_lstringlist (void) :
mArray () {
}

//--------------------------------------------------------------------------------------------------

GGS__32_lstringlist::GGS__32_lstringlist (const capCollectionElementArray & inArray) :
mArray () {
  mArray.setCapacity (std::max (16, int32_t (inArray.count ()))) ;
  for (uint32_t i = 0 ; i < inArray.count () ; i++) {
    const capCollectionElement v = inArray.objectAtIndex (i COMMA_HERE) ;
    cCollectionElement__32_lstringlist * p = (cCollectionElement__32_lstringlist *) v.ptr () ;
    macroValidSharedObject (p, cCollectionElement__32_lstringlist) ;
    const GGS__32_lstringlist_2E_element element (p->mObject.mProperty_mValue_30_, p->mObject.mProperty_mValue_31_) ;
    mArray.appendObject (element) ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS__32_lstringlist::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                     const GGS_lstring & in_mValue_30_,
                                                     const GGS_lstring & in_mValue_31_
                                                     COMMA_LOCATION_ARGS) {
  cCollectionElement__32_lstringlist * p = nullptr ;
  macroMyNew (p, cCollectionElement__32_lstringlist (in_mValue_30_, in_mValue_31_ COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//--------------------------------------------------------------------------------------------------

GGS_uint GGS__32_lstringlist::getter_count (UNUSED_LOCATION_ARGS) const {
  GGS_uint result ;
  if (isValid ()) {
    result = GGS_uint (count ()) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_range GGS__32_lstringlist::getter_range (UNUSED_LOCATION_ARGS) const {
  GGS_range result ;
  if (isValid ()) {
    result = GGS_range (0, count ()) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

void GGS__32_lstringlist::description (String & ioString,
                                       const int32_t inIndentation) const {
  ioString.appendCString ("<list @") ;
  ioString.appendString (staticTypeDescriptor ()->mGalgasTypeName) ;
  ioString.appendCString (" (") ;
  ioString.appendUnsigned (count()) ;
  ioString.appendCString (" object") ;
  ioString.appendString ((count() > 1) ? "s" : "") ;
  ioString.appendCString ("):") ;
  if (isValid ()) {
    for (uint32_t i = 0 ; i < count () ; i++) {
      ioString.appendNewLine () ;
      ioString.appendStringMultiple ("| ", inIndentation) ;
      ioString.appendString ("|-at ") ;
      ioString.appendUnsigned (i) ;
      ioString.appendNewLine () ;
      ioString.appendStringMultiple ("| ", inIndentation + 1) ;
      ioString.appendString ("mValue0:") ;
      mArray (int32_t (i) COMMA_HERE).mProperty_mValue_30_.description (ioString, inIndentation + 1) ;
      ioString.appendNewLine () ;
      ioString.appendStringMultiple ("| ", inIndentation + 1) ;
      ioString.appendString ("mValue1:") ;
      mArray (int32_t (i) COMMA_HERE).mProperty_mValue_31_.description (ioString, inIndentation + 1) ;
    }
  }else{
    ioString.appendCString (" not built") ;
  }
  ioString.appendCString (">") ;
}

//--------------------------------------------------------------------------------------------------

GGS__32_lstringlist GGS__32_lstringlist::class_func_emptyList (UNUSED_LOCATION_ARGS) {
  GGS__32_lstringlist result ;
  result.mArray.setCapacity (16) ; // Build
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS__32_lstringlist GGS__32_lstringlist::init (Compiler * COMMA_UNUSED_LOCATION_ARGS) {
  GGS__32_lstringlist result ;
  result.mArray.setCapacity (16) ; // Build
  return result ;
}

//--------------------------------------------------------------------------------------------------

void GGS__32_lstringlist::plusPlusAssignOperation (const GGS__32_lstringlist_2E_element & inValue
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  if (isValid () && inValue.isValid ()) {
    mArray.appendObject (inValue) ;
  }
}

//--------------------------------------------------------------------------------------------------

GGS__32_lstringlist GGS__32_lstringlist::class_func_listWithValue (const GGS_lstring & inOperand0,
                                                                   const GGS_lstring & inOperand1
                                                                   COMMA_LOCATION_ARGS) {
  const GGS__32_lstringlist_2E_element element (inOperand0, inOperand1) ;
  GGS__32_lstringlist result ;
  if (element.isValid ()) {
    result.mArray.setCapacity (16) ; // Build
    result.plusPlusAssignOperation (element COMMA_THERE) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

void GGS__32_lstringlist::addAssignOperation (const GGS_lstring & inOperand0,
                                              const GGS_lstring & inOperand1
                                              COMMA_LOCATION_ARGS) {
  const GGS__32_lstringlist_2E_element newElement (inOperand0, inOperand1) ;
  plusPlusAssignOperation (newElement COMMA_THERE) ;
}

//--------------------------------------------------------------------------------------------------

void GGS__32_lstringlist::setter_append (const GGS_lstring inOperand0,
                                         const GGS_lstring inOperand1,
                                         Compiler * /* inCompiler */
                                         COMMA_LOCATION_ARGS) {
  const GGS__32_lstringlist_2E_element newElement (inOperand0, inOperand1) ;
  if (isValid () && newElement.isValid ()) {
    plusPlusAssignOperation (newElement COMMA_THERE) ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS__32_lstringlist::setter_insertAtIndex (const GGS_lstring inOperand0,
                                                const GGS_lstring inOperand1,
                                                const GGS_uint inInsertionIndex,
                                                Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  const GGS__32_lstringlist_2E_element newElement (inOperand0, inOperand1) ;
  if (isValid () && inInsertionIndex.isValid () && newElement.isValid ()) {
    const int32_t idx = int32_t (inInsertionIndex.uintValue ()) ;
    if (idx <= mArray.count ()) {
      mArray.insertObjectAtIndex (newElement, idx COMMA_THERE) ;
    }else{
      String message = "cannot insert at index " ;
      message.appendSigned (idx) ;
      message.appendCString (", list count is ") ;
      message.appendSigned (mArray.count ()) ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }
  }
}

//--------------------------------------------------------------------------------------------------

void GGS__32_lstringlist::setter_removeAtIndex (GGS_lstring & outOperand0,
                                                GGS_lstring & outOperand1,
                                                const GGS_uint inRemoveIndex,
                                                Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  bool removed = false ;
  if (isValid () && inRemoveIndex.isValid ()) {
    const int32_t idx = int32_t (inRemoveIndex.uintValue ()) ;
    if (idx < mArray.count ()) {
      removed = true ;
      outOperand0 = mArray (idx COMMA_HERE).mProperty_mValue_30_ ;
      outOperand1 = mArray (idx COMMA_HERE).mProperty_mValue_31_ ;
      mArray.removeObjectAtIndex (idx COMMA_HERE) ;
    }else{
      String message = "cannot remove at index " ;
      message.appendSigned (idx) ;
      message.appendCString (", list count is ") ;
      message.appendSigned (mArray.count ()) ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }
  }
  if (!removed) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS__32_lstringlist::setter_popFirst (GGS_lstring & outOperand0,
                                           GGS_lstring & outOperand1,
                                           Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) {
  bool removed = false ;
  if (isValid ()) {
    if (mArray.count () > 0) {
      removed = true ;
      outOperand0 = mArray (0 COMMA_THERE).mProperty_mValue_30_ ;
      outOperand1 = mArray (0 COMMA_THERE).mProperty_mValue_31_ ;
      mArray.removeObjectAtIndex (0 COMMA_HERE) ;
    }else{
      const String message = "cannot remove first element, list is empty" ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }
  }
  if (!removed) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS__32_lstringlist::setter_popLast (GGS_lstring & outOperand0,
                                          GGS_lstring & outOperand1,
                                          Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
  bool removed = false ;
  if (isValid ()) {
    if (mArray.count () > 0) {
      removed = true ;
      outOperand0 = mArray.lastObject (HERE).mProperty_mValue_30_ ;
      outOperand1 = mArray.lastObject (HERE).mProperty_mValue_31_ ;
      mArray.removeLastObject (HERE) ;
    }else{
      const String message = "cannot remove last element, list is empty" ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }
  }
  if (!removed) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS__32_lstringlist::method_first (GGS_lstring & outOperand0,
                                        GGS_lstring & outOperand1,
                                        Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) const {
  bool found = false ;
  if (isValid ()) {
    if (mArray.count () > 0) {
      found = true ;
      outOperand0 = mArray (0 COMMA_THERE).mProperty_mValue_30_ ;
      outOperand1 = mArray (0 COMMA_THERE).mProperty_mValue_31_ ;
    }else{
      const String message = "cannot get first element, list is empty" ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }
  }
  if (!found) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS__32_lstringlist::method_last (GGS_lstring & outOperand0,
                                       GGS_lstring & outOperand1,
                                       Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) const {
  bool found = false ;
  if (isValid ()) {
    if (mArray.count () > 0) {
      found = true ;
      outOperand0 = mArray.lastObject (HERE).mProperty_mValue_30_ ;
      outOperand1 = mArray.lastObject (HERE).mProperty_mValue_31_ ;
    }else{
      const String message = "cannot get last element, list is empty" ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }
  }
  if (!found) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }
}

//--------------------------------------------------------------------------------------------------

GGS__32_lstringlist GGS__32_lstringlist::add_operation (const GGS__32_lstringlist & inOperand,
                                                        Compiler * /* inCompiler */
                                                        COMMA_UNUSED_LOCATION_ARGS) const {
  GGS__32_lstringlist result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.mArray.setCapacity (1 + result.mArray.count () + inOperand.mArray.count ()) ;
    for (int32_t i = 0 ; i < inOperand.mArray.count () ; i++) {
      result.mArray.appendObject (inOperand.mArray (i COMMA_HERE)) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS__32_lstringlist GGS__32_lstringlist::subList (const int32_t inStart,
                                                  const int32_t inLength,
                                                  Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) const {
  GGS__32_lstringlist result ;
  const bool ok = (inStart >= 0) && (inLength >= 0) && ((inStart + inLength) <= int32_t (count ())) ;
  if (ok) {
    result.mArray.setCapacity (std::max (16, inLength)) ;
    for (int32_t i = inStart ; i < (inStart + inLength) ; i++) {
      result.mArray.appendObject (mArray (i COMMA_HERE)) ;
    }
  }else{
    String message = "cannot get sublist [start: " ;
    message.appendSigned (inStart) ;
    message.appendCString (", length: ") ;
    message.appendSigned (inLength) ;
    message.appendCString ("], list count is ") ;
    message.appendSigned (mArray.count ()) ;
    inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS__32_lstringlist GGS__32_lstringlist::getter_subListWithRange (const GGS_range & inRange,
                                                                  Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) const {
  GGS__32_lstringlist result ;
  if (isValid () && inRange.isValid ()) {
    const int32_t start  = int32_t (inRange.mProperty_start.uintValue ()) ;
    const int32_t length = int32_t (inRange.mProperty_length.uintValue ()) ;
    result = subList (start, length, inCompiler COMMA_THERE) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS__32_lstringlist GGS__32_lstringlist::getter_subListFromIndex (const GGS_uint & inIndex,
                                                                  Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) const {
  GGS__32_lstringlist result ;
  if (isValid () && inIndex.isValid ()) {
    const int32_t start  = int32_t (inIndex.uintValue ()) ;
    const int32_t length = int32_t (count ()) - start ;
    result = subList (start, length, inCompiler COMMA_THERE) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS__32_lstringlist GGS__32_lstringlist::getter_subListToIndex (const GGS_uint & inIndex,
                                                                Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) const {
  GGS__32_lstringlist result ;
  if (isValid () && inIndex.isValid ()) {
    const int32_t start  = 0 ;
    const int32_t length = int32_t (inIndex.uintValue ()) + 1 ;
    result = subList (start, length, inCompiler COMMA_THERE) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

void GGS__32_lstringlist::plusAssignOperation (const GGS__32_lstringlist inList,
                                               Compiler * /* inCompiler */
                                               COMMA_UNUSED_LOCATION_ARGS) {
  if (isValid () && inList.isValid ()) {
    mArray.setCapacity (1 + mArray.count () + inList.mArray.count ()) ;
    for (int32_t i=0 ; i < int32_t (inList.count ()) ; i++) {
      mArray.appendObject (inList.mArray (i COMMA_HERE)) ;
    }
  }
}

//--------------------------------------------------------------------------------------------------

void GGS__32_lstringlist::setter_setMValue_30_AtIndex (GGS_lstring inOperand,
                                                       GGS_uint inIndex,
                                                       Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) {
  if (isValid () && inOperand.isValid () && inIndex.isValid ()) {
    const uint32_t idx = inIndex.uintValue () ;
    if (idx < count ()) {
      mArray (int32_t (idx) COMMA_HERE).mProperty_mValue_30_ = inOperand ;
    }else{
      String message = "cannot access at index " ;
      message.appendUnsigned (idx) ;
      message.appendCString (", list count is ") ;
      message.appendSigned (mArray.count ()) ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }
  }
}
//--------------------------------------------------------------------------------------------------
  
GGS_lstring GGS__32_lstringlist::getter_mValue_30_AtIndex (const GGS_uint & inIndex,
                                                           Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) const {
  GGS_lstring result ;
  if (isValid () && inIndex.isValid ()) {
    const uint32_t idx = inIndex.uintValue () ;
    if (idx < count ()) {
      result = mArray (int32_t (idx) COMMA_HERE).mProperty_mValue_30_ ;
    }else{
      String message = "cannot access at index " ;
      message.appendUnsigned (idx) ;
      message.appendCString (", list count is ") ;
      message.appendSigned (mArray.count ()) ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }
  }
  return result ;
}
//--------------------------------------------------------------------------------------------------

void GGS__32_lstringlist::setter_setMValue_31_AtIndex (GGS_lstring inOperand,
                                                       GGS_uint inIndex,
                                                       Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) {
  if (isValid () && inOperand.isValid () && inIndex.isValid ()) {
    const uint32_t idx = inIndex.uintValue () ;
    if (idx < count ()) {
      mArray (int32_t (idx) COMMA_HERE).mProperty_mValue_31_ = inOperand ;
    }else{
      String message = "cannot access at index " ;
      message.appendUnsigned (idx) ;
      message.appendCString (", list count is ") ;
      message.appendSigned (mArray.count ()) ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }
  }
}
//--------------------------------------------------------------------------------------------------
  
GGS_lstring GGS__32_lstringlist::getter_mValue_31_AtIndex (const GGS_uint & inIndex,
                                                           Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) const {
  GGS_lstring result ;
  if (isValid () && inIndex.isValid ()) {
    const uint32_t idx = inIndex.uintValue () ;
    if (idx < count ()) {
      result = mArray (int32_t (idx) COMMA_HERE).mProperty_mValue_31_ ;
    }else{
      String message = "cannot access at index " ;
      message.appendUnsigned (idx) ;
      message.appendCString (", list count is ") ;
      message.appendSigned (mArray.count ()) ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }
  }
  return result ;
}
//--------------------------------------------------------------------------------------------------
// Down Enumerator for @_32_lstringlist
//--------------------------------------------------------------------------------------------------

DownEnumerator__32_lstringlist::DownEnumerator__32_lstringlist (const GGS__32_lstringlist & inEnumeratedObject) :
mArray (inEnumeratedObject.sortedElementArray ()),
mIndex (0) {
  mIndex = mArray.count () - 1 ;
}

//--------------------------------------------------------------------------------------------------

GGS__32_lstringlist_2E_element DownEnumerator__32_lstringlist::current (LOCATION_ARGS) const {
  return mArray (mIndex COMMA_THERE) ;
}

//--------------------------------------------------------------------------------------------------

GGS_lstring DownEnumerator__32_lstringlist::current_mValue_30_ (LOCATION_ARGS) const {
  return mArray (mIndex COMMA_THERE).mProperty_mValue_30_ ;
}

//--------------------------------------------------------------------------------------------------

GGS_lstring DownEnumerator__32_lstringlist::current_mValue_31_ (LOCATION_ARGS) const {
  return mArray (mIndex COMMA_THERE).mProperty_mValue_31_ ;
}



//--------------------------------------------------------------------------------------------------
// Up Enumerator for @_32_lstringlist
//--------------------------------------------------------------------------------------------------

UpEnumerator__32_lstringlist::UpEnumerator__32_lstringlist (const GGS__32_lstringlist & inEnumeratedObject) :
mArray (inEnumeratedObject.sortedElementArray ()),
mIndex (0) {
}

//--------------------------------------------------------------------------------------------------

GGS__32_lstringlist_2E_element UpEnumerator__32_lstringlist::current (LOCATION_ARGS) const {
  return mArray (mIndex COMMA_THERE) ;
}

//--------------------------------------------------------------------------------------------------

GGS_lstring UpEnumerator__32_lstringlist::current_mValue_30_ (LOCATION_ARGS) const {
  return mArray (mIndex COMMA_THERE).mProperty_mValue_30_ ;
}

//--------------------------------------------------------------------------------------------------

GGS_lstring UpEnumerator__32_lstringlist::current_mValue_31_ (LOCATION_ARGS) const {
  return mArray (mIndex COMMA_THERE).mProperty_mValue_31_ ;
}




//--------------------------------------------------------------------------------------------------
//     @2lstringlist generic code implementation
//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor kTypeDescriptor_GALGAS__32_lstringlist ("2lstringlist",
                                                                    nullptr) ;

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * GGS__32_lstringlist::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS__32_lstringlist ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GGS__32_lstringlist::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GGS__32_lstringlist (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS__32_lstringlist GGS__32_lstringlist::extractObject (const GGS_object & inObject,
                                                        Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) {
  GGS__32_lstringlist result ;
  const GGS__32_lstringlist * p = (const GGS__32_lstringlist *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GGS__32_lstringlist *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("2lstringlist", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//  Map type @M_5F_processor
//--------------------------------------------------------------------------------------------------

#include "GALGAS_GenericMapRoot.h"

//--------------------------------------------------------------------------------------------------

GGS_M_5F_processor::GGS_M_5F_processor (void) :
mSharedRoot () {
}

//--------------------------------------------------------------------------------------------------

GGS_M_5F_processor::~ GGS_M_5F_processor (void) {
}

//--------------------------------------------------------------------------------------------------

GGS_M_5F_processor::GGS_M_5F_processor (const GGS_M_5F_processor & inSource) :
mSharedRoot (inSource.mSharedRoot) {
}

//--------------------------------------------------------------------------------------------------

GGS_M_5F_processor & GGS_M_5F_processor::operator = (const GGS_M_5F_processor & inSource) {
  mSharedRoot = inSource.mSharedRoot ;
  return * this ;
}

//--------------------------------------------------------------------------------------------------

GGS_M_5F_processor GGS_M_5F_processor::init (Compiler * COMMA_LOCATION_ARGS) {
  GGS_M_5F_processor result ;
  result.build (THERE) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_M_5F_processor GGS_M_5F_processor::class_func_emptyMap (LOCATION_ARGS) {
  GGS_M_5F_processor result ;
  result.build (THERE) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_bool GGS_M_5F_processor::getter_hasKey (const GGS_string & inKey
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GGS_bool result ;
  if (isValid () && inKey.isValid ()) {
    result = GGS_bool (mSharedRoot->hasKey (inKey.stringValue (), 0)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_bool GGS_M_5F_processor::getter_hasKeyAtLevel (const GGS_string & inKey,
                                                   const GGS_uint & inLevel
                                                   COMMA_UNUSED_LOCATION_ARGS) const {
  GGS_bool result ;
  if (isValid () && inKey.isValid ()) {
    result = GGS_bool (mSharedRoot->hasKey (inKey.stringValue (), inLevel.uintValue ())) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_uint GGS_M_5F_processor::getter_count (UNUSED_LOCATION_ARGS) const {
  GGS_uint result ;
  if (isValid ()) {
    result = GGS_uint (uint32_t (mSharedRoot->count ())) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_uint GGS_M_5F_processor::getter_levels (UNUSED_LOCATION_ARGS) const {
  GGS_uint result ;
  if (isValid ()) {
    result = GGS_uint (mSharedRoot->levels ()) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_location GGS_M_5F_processor::getter_locationForKey (const GGS_string & inKey,
                                                        Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) const {
  GGS_location result ;
  if (isValid () && inKey.isValid ()) {
    const SharedGenericPtrWithValueSemantics <GGS_M_5F_processor_2E_element> info = infoForKey (inKey.stringValue ()) ;
    if (info.isNil ()) {
      String message = "'locationForKey' map reader run-time error: the '" ;
      message.appendString (inKey.stringValue ()) ;
      message.appendCString ("' does not exist in map") ;
      inCompiler->onTheFlyRunTimeError (message COMMA_THERE) ;
    }else{
      result = info->mProperty_lkey.mProperty_location ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_lstringlist GGS_M_5F_processor::getter_keyList (Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) const {
  GGS_lstringlist result ;
  if (isValid ()) {
    result = GGS_lstringlist::init (inCompiler COMMA_THERE) ;
    mSharedRoot->populateKeyList (result) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

bool GGS_M_5F_processor::isValid (void) const {
  return mSharedRoot.isNotNil () ;
}

//--------------------------------------------------------------------------------------------------

void GGS_M_5F_processor::drop (void)  {
  mSharedRoot.setToNil () ;
}

//--------------------------------------------------------------------------------------------------

void GGS_M_5F_processor::build (LOCATION_ARGS) {
  mSharedRoot = OptionalSharedRef <GenericMapRoot <GGS_M_5F_processor_2E_element>>::make (THERE) ;
}

//--------------------------------------------------------------------------------------------------

void GGS_M_5F_processor::performInsert (const GGS_M_5F_processor_2E_element & inElement,
                                 const char * inInsertErrorMessage,
                                 const char * inShadowErrorMessage,
                                 Compiler * inCompiler
                                 COMMA_LOCATION_ARGS) {
  if (isValid () && inElement.mProperty_lkey.isValid ()) {
    OptionalSharedRef <GenericMapNode <GGS_M_5F_processor_2E_element>> existingNode ;
    const bool allowReplacing = false ;
    mSharedRoot.insulate (THERE) ;
    mSharedRoot->insertOrReplaceInfo (
      inElement,
      allowReplacing,
      existingNode
      COMMA_THERE
    ) ;
    const GGS_lstring lkey = inElement.mProperty_lkey ;
    if (existingNode.isNotNil ()) {
      const GGS_location lstring_existingKey_location = existingNode->mSharedInfo->mProperty_lkey.mProperty_location ;
      inCompiler->semanticErrorWith_K_L_message (lkey, inInsertErrorMessage, lstring_existingKey_location COMMA_THERE) ;
    }else if ((inShadowErrorMessage != nullptr) && (mSharedRoot->overriddenRoot ().isNotNil ())) {
      const auto existingInfo = mSharedRoot->overriddenRoot ()->infoForKey (lkey.mProperty_string.stringValue()) ;
      if (existingInfo.isNotNil ()) {
        const GGS_location lstring_existingKey_location = existingInfo->mProperty_lkey.mProperty_location ;
        inCompiler->semanticErrorWith_K_L_message (lkey, inShadowErrorMessage, lstring_existingKey_location COMMA_THERE) ;
      }
    }
  }
}

//--------------------------------------------------------------------------------------------------

const SharedGenericPtrWithValueSemantics <GGS_M_5F_processor_2E_element>
GGS_M_5F_processor::infoForKey (const String & inKey) const {
  if (mSharedRoot.isNotNil ()) {
    return mSharedRoot->infoForKey (inKey) ;
  }else{
    return SharedGenericPtrWithValueSemantics <GGS_M_5F_processor_2E_element> () ;
  }
}

//--------------------------------------------------------------------------------------------------

int32_t GGS_M_5F_processor::count (void) const  {
  if (mSharedRoot.isNotNil ()) {
    return mSharedRoot->count () ;
  }else{
    return 0 ;
  }
}

//--------------------------------------------------------------------------------------------------

GenericArray <SharedGenericPtrWithValueSemantics <GGS_M_5F_processor_2E_element>>
GGS_M_5F_processor::sortedInfoArray (void) const {
  if (mSharedRoot.isNotNil ()) {
    return mSharedRoot->sortedInfoArray () ;
  }else{
    return GenericArray <SharedGenericPtrWithValueSemantics <GGS_M_5F_processor_2E_element>> () ;
  }
}

//--------------------------------------------------------------------------------------------------

GGS_stringset GGS_M_5F_processor::getter_keySet (Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) const {
  GGS_stringset result ;
  if (isValid ()) {
    result = GGS_stringset::init (inCompiler COMMA_THERE) ;
    mSharedRoot->populateKeySet (result, inCompiler) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

void GGS_M_5F_processor::findNearestKey (const String & inKey,
                                  GenericUniqueArray <String> & outNearestKeyArray) const {
  mSharedRoot->findNearestKey (inKey, outNearestKeyArray) ;
}

//--------------------------------------------------------------------------------------------------

GGS_M_5F_processor_2E_element_3F_ GGS_M_5F_processor
::readSubscript__3F_ (const class GGS_string & inKey,
                      Compiler * /* inCompiler */
                      COMMA_UNUSED_LOCATION_ARGS) const {
  GGS_M_5F_processor_2E_element_3F_ result ;
  if (isValid () && inKey.isValid ()) {
    const SharedGenericPtrWithValueSemantics <GGS_M_5F_processor_2E_element> info = infoForKey (inKey.stringValue ()) ;
    if (info.isNil ()) {
      result = GGS_M_5F_processor_2E_element_3F_::init_nil () ;
    }else{
      GGS_M_5F_processor_2E_element element ;
      element.mProperty_lkey = info->mProperty_lkey ;
      element.mProperty_mIndex = info->mProperty_mIndex ;
      element.mProperty_mStep = info->mProperty_mStep ;
      result = element ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_M_5F_processor GGS_M_5F_processor::class_func_mapWithMapToOverride (const GGS_M_5F_processor & inMapToOverride
                                                                        COMMA_LOCATION_ARGS) {
  GGS_M_5F_processor result ;
  if (inMapToOverride.isValid ()) {
    result.mSharedRoot = OptionalSharedRef <GenericMapRoot <GGS_M_5F_processor_2E_element>>::make (inMapToOverride.mSharedRoot COMMA_THERE) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_M_5F_processor GGS_M_5F_processor::getter_overriddenMap (Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) const {
  GGS_M_5F_processor result ;
  if (isValid ()) {
    result.mSharedRoot = mSharedRoot->overriddenRoot () ;
    if (result.mSharedRoot.isNil ()) {
      inCompiler->onTheFlySemanticError ("getter 'overriddenMap': no overriden map" COMMA_THERE) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

void GGS_M_5F_processor::setter_insertKey (GGS_lstring inLKey,
                                           GGS_uint inArgument0,
                                           GGS_luint inArgument1,
                                           Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) {
  const GGS_M_5F_processor_2E_element element (inLKey, inArgument0, inArgument1) ;
  const char * kInsertErrorMessage = "the processor '%K' has been already declared in %L" ;
  const char * kShadowErrorMessage = nullptr ;
  performInsert (element, kInsertErrorMessage, kShadowErrorMessage, inCompiler COMMA_THERE) ;
}

//--------------------------------------------------------------------------------------------------

void GGS_M_5F_processor::method_searchKey (GGS_lstring inLKey,
                                           GGS_uint & outArgument0,
                                           GGS_luint & outArgument1,
                                           Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) const {
  SharedGenericPtrWithValueSemantics <GGS_M_5F_processor_2E_element> info ;
  if (isValid () && inLKey.isValid ()) {
    const String key = inLKey.mProperty_string.stringValue () ;
    info = infoForKey (key) ;
    if (info.isNil ()) {
      GenericUniqueArray <String> nearestKeyArray ;
      findNearestKey (key, nearestKeyArray) ;
      const char * kSearchErrorMessage = "the processor '%K' is not declared" ;
      inCompiler->semanticErrorWith_K_message (inLKey, nearestKeyArray, kSearchErrorMessage COMMA_THERE) ;
    }
  }
  if (info.isNil ()) {
    outArgument0.drop () ;
    outArgument1.drop () ;
  }else{
    outArgument0 = info->mProperty_mIndex ;
    outArgument1 = info->mProperty_mStep ;
  }
}
//--------------------------------------------------------------------------------------------------

GGS_uint GGS_M_5F_processor::getter_mIndexForKey (const GGS_string & inKey,
                                                  Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) const {
  GGS_uint result ;
  if (isValid () && inKey.isValid ()) {
    const String key = inKey.stringValue () ;
    const SharedGenericPtrWithValueSemantics <GGS_M_5F_processor_2E_element> info = infoForKey (key) ;
    if (info.isNil ()) {
      String message = "cannot read property in map: the '" ;
      message.appendString (key) ;
      message.appendCString ("' key does not exist") ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }else{
      result = info->mProperty_mIndex ;
    }
  }
  return result ;
}
//--------------------------------------------------------------------------------------------------

GGS_luint GGS_M_5F_processor::getter_mStepForKey (const GGS_string & inKey,
                                                  Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) const {
  GGS_luint result ;
  if (isValid () && inKey.isValid ()) {
    const String key = inKey.stringValue () ;
    const SharedGenericPtrWithValueSemantics <GGS_M_5F_processor_2E_element> info = infoForKey (key) ;
    if (info.isNil ()) {
      String message = "cannot read property in map: the '" ;
      message.appendString (key) ;
      message.appendCString ("' key does not exist") ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }else{
      result = info->mProperty_mStep ;
    }
  }
  return result ;
}
//--------------------------------------------------------------------------------------------------

void GGS_M_5F_processor::setter_setMIndexForKey (GGS_uint inValue,
                                                 GGS_string inKey,
                                                 Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) {
  if (isValid () && inKey.isValid ()) {
    const String key = inKey.stringValue () ;
    mSharedRoot.insulate (HERE) ;
    OptionalSharedRef <GenericMapNode <GGS_M_5F_processor_2E_element>> node = mSharedRoot->searchNode (key) ;
    if (node.isNil ()) {
      String message = "cannot write property in map: the '" ;
      message.appendString (key) ;
      message.appendCString ("' key does not exist") ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }else{
      node->mSharedInfo->mProperty_mIndex = inValue ;
    }
  }
}
//--------------------------------------------------------------------------------------------------

void GGS_M_5F_processor::setter_setMStepForKey (GGS_luint inValue,
                                                GGS_string inKey,
                                                Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  if (isValid () && inKey.isValid ()) {
    const String key = inKey.stringValue () ;
    mSharedRoot.insulate (HERE) ;
    OptionalSharedRef <GenericMapNode <GGS_M_5F_processor_2E_element>> node = mSharedRoot->searchNode (key) ;
    if (node.isNil ()) {
      String message = "cannot write property in map: the '" ;
      message.appendString (key) ;
      message.appendCString ("' key does not exist") ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }else{
      node->mSharedInfo->mProperty_mStep = inValue ;
    }
  }
}
//--------------------------------------------------------------------------------------------------

static void GGS_M_5F_processor_internalDescription (const GenericArray <SharedGenericPtrWithValueSemantics <GGS_M_5F_processor_2E_element>> & inArray,
                                                        String & ioString,
                                                        const int32_t inIndentation) {
  const int32_t n = inArray.count () ;
  ioString.appendString (" (") ;
  ioString.appendSigned (n) ;
  ioString.appendString (" object") ;
  if (n > 1) {
    ioString.appendString ("s") ;
  }
  ioString.appendString ("):") ;
  for (int32_t i = 0 ; i < n ; i++) {
    ioString.appendNewLine () ;
    ioString.appendStringMultiple ("| ", inIndentation) ;
    ioString.appendString ("|-at ") ;
    ioString.appendSigned (i) ;
    ioString.appendString (": key '") ;
    ioString.appendString (inArray (i COMMA_HERE)->mProperty_lkey.mProperty_string.stringValue ()) ;
    ioString.appendString ("'") ;
    ioString.appendNewLine () ;
    ioString.appendStringMultiple ("| ", inIndentation + 2) ;
    ioString.appendString ("mIndex:") ;
    inArray (i COMMA_HERE)->mProperty_mIndex.description (ioString, inIndentation + 1) ;
    ioString.appendNewLine () ;
    ioString.appendStringMultiple ("| ", inIndentation + 2) ;
    ioString.appendString ("mStep:") ;
    inArray (i COMMA_HERE)->mProperty_mStep.description (ioString, inIndentation + 1) ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_M_5F_processor::description (String & ioString,
                                          const int32_t inIndentation) const {
  ioString.appendCString ("<map @") ;
  ioString.appendString (staticTypeDescriptor ()->mGalgasTypeName) ;
  if (isValid ()) {
    const GenericArray <SharedGenericPtrWithValueSemantics <GGS_M_5F_processor_2E_element>> array = sortedInfoArray () ;
    GGS_M_5F_processor_internalDescription (array, ioString, inIndentation) ;
    OptionalSharedRef <GenericMapRoot <GGS_M_5F_processor_2E_element>> subRoot = mSharedRoot->overriddenRoot () ;
    uint32_t idx = 0 ;
    while (subRoot.isNotNil ()) {
     idx += 1 ;
     ioString.appendNewLine () ;
     ioString.appendStringMultiple ("| ", inIndentation + 1) ;
     ioString.appendString (" override #") ;
     ioString.appendUnsigned (idx) ;
     const auto subRootArray = subRoot->sortedInfoArray () ;
     GGS_M_5F_processor_internalDescription (subRootArray, ioString, inIndentation) ;
     subRoot = subRoot->overriddenRoot () ;
    }
  }else{
    ioString.appendCString (" not built") ;
  }
  ioString.appendCString (">") ;
}



//--------------------------------------------------------------------------------------------------
//  Down Enumerator for @M_5F_processor
//--------------------------------------------------------------------------------------------------

DownEnumerator_M_5F_processor::DownEnumerator_M_5F_processor (const GGS_M_5F_processor & inMap) :
mInfoArray (inMap.sortedInfoArray ()),
mIndex (0) {
  mIndex = mInfoArray.count () - 1 ;
}

//--------------------------------------------------------------------------------------------------

GGS_M_5F_processor_2E_element DownEnumerator_M_5F_processor::current (LOCATION_ARGS) const {
  return mInfoArray (mIndex COMMA_THERE).value () ;
}

//--------------------------------------------------------------------------------------------------

GGS_lstring DownEnumerator_M_5F_processor::current_lkey (LOCATION_ARGS) const {
  return mInfoArray (mIndex COMMA_THERE)->mProperty_lkey ;
}

//--------------------------------------------------------------------------------------------------

GGS_uint DownEnumerator_M_5F_processor::current_mIndex (LOCATION_ARGS) const {
  return mInfoArray (mIndex COMMA_THERE)->mProperty_mIndex ;
}

//--------------------------------------------------------------------------------------------------

GGS_luint DownEnumerator_M_5F_processor::current_mStep (LOCATION_ARGS) const {
  return mInfoArray (mIndex COMMA_THERE)->mProperty_mStep ;
}

//--------------------------------------------------------------------------------------------------
//  Up Enumerator for @M_5F_processor
//--------------------------------------------------------------------------------------------------

UpEnumerator_M_5F_processor::UpEnumerator_M_5F_processor (const GGS_M_5F_processor & inMap) :
mInfoArray (inMap.sortedInfoArray ()),
mIndex (0) {
}

//--------------------------------------------------------------------------------------------------

GGS_M_5F_processor_2E_element UpEnumerator_M_5F_processor::current (LOCATION_ARGS) const {
  return mInfoArray (mIndex COMMA_THERE).value () ;
}

//--------------------------------------------------------------------------------------------------

GGS_lstring UpEnumerator_M_5F_processor::current_lkey (LOCATION_ARGS) const {
  return mInfoArray (mIndex COMMA_THERE)->mProperty_lkey ;
}

//--------------------------------------------------------------------------------------------------

GGS_uint UpEnumerator_M_5F_processor::current_mIndex (LOCATION_ARGS) const {
  return mInfoArray (mIndex COMMA_THERE)->mProperty_mIndex ;
}

//--------------------------------------------------------------------------------------------------

GGS_luint UpEnumerator_M_5F_processor::current_mStep (LOCATION_ARGS) const {
  return mInfoArray (mIndex COMMA_THERE)->mProperty_mStep ;
}


//--------------------------------------------------------------------------------------------------
//     @M_processor generic code implementation
//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor kTypeDescriptor_GALGAS_M_5F_processor ("M_processor",
                                                                   nullptr) ;

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * GGS_M_5F_processor::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_M_5F_processor ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GGS_M_5F_processor::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GGS_M_5F_processor (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_M_5F_processor GGS_M_5F_processor::extractObject (const GGS_object & inObject,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) {
  GGS_M_5F_processor result ;
  const GGS_M_5F_processor * p = (const GGS_M_5F_processor *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GGS_M_5F_processor *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("M_processor", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//  Map type @M_5F_network
//--------------------------------------------------------------------------------------------------

#include "GALGAS_GenericMapRoot.h"

//--------------------------------------------------------------------------------------------------

GGS_M_5F_network::GGS_M_5F_network (void) :
mSharedRoot () {
}

//--------------------------------------------------------------------------------------------------

GGS_M_5F_network::~ GGS_M_5F_network (void) {
}

//--------------------------------------------------------------------------------------------------

GGS_M_5F_network::GGS_M_5F_network (const GGS_M_5F_network & inSource) :
mSharedRoot (inSource.mSharedRoot) {
}

//--------------------------------------------------------------------------------------------------

GGS_M_5F_network & GGS_M_5F_network::operator = (const GGS_M_5F_network & inSource) {
  mSharedRoot = inSource.mSharedRoot ;
  return * this ;
}

//--------------------------------------------------------------------------------------------------

GGS_M_5F_network GGS_M_5F_network::init (Compiler * COMMA_LOCATION_ARGS) {
  GGS_M_5F_network result ;
  result.build (THERE) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_M_5F_network GGS_M_5F_network::class_func_emptyMap (LOCATION_ARGS) {
  GGS_M_5F_network result ;
  result.build (THERE) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_bool GGS_M_5F_network::getter_hasKey (const GGS_string & inKey
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GGS_bool result ;
  if (isValid () && inKey.isValid ()) {
    result = GGS_bool (mSharedRoot->hasKey (inKey.stringValue (), 0)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_bool GGS_M_5F_network::getter_hasKeyAtLevel (const GGS_string & inKey,
                                                 const GGS_uint & inLevel
                                                 COMMA_UNUSED_LOCATION_ARGS) const {
  GGS_bool result ;
  if (isValid () && inKey.isValid ()) {
    result = GGS_bool (mSharedRoot->hasKey (inKey.stringValue (), inLevel.uintValue ())) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_uint GGS_M_5F_network::getter_count (UNUSED_LOCATION_ARGS) const {
  GGS_uint result ;
  if (isValid ()) {
    result = GGS_uint (uint32_t (mSharedRoot->count ())) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_uint GGS_M_5F_network::getter_levels (UNUSED_LOCATION_ARGS) const {
  GGS_uint result ;
  if (isValid ()) {
    result = GGS_uint (mSharedRoot->levels ()) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_location GGS_M_5F_network::getter_locationForKey (const GGS_string & inKey,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) const {
  GGS_location result ;
  if (isValid () && inKey.isValid ()) {
    const SharedGenericPtrWithValueSemantics <GGS_M_5F_network_2E_element> info = infoForKey (inKey.stringValue ()) ;
    if (info.isNil ()) {
      String message = "'locationForKey' map reader run-time error: the '" ;
      message.appendString (inKey.stringValue ()) ;
      message.appendCString ("' does not exist in map") ;
      inCompiler->onTheFlyRunTimeError (message COMMA_THERE) ;
    }else{
      result = info->mProperty_lkey.mProperty_location ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_lstringlist GGS_M_5F_network::getter_keyList (Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) const {
  GGS_lstringlist result ;
  if (isValid ()) {
    result = GGS_lstringlist::init (inCompiler COMMA_THERE) ;
    mSharedRoot->populateKeyList (result) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

bool GGS_M_5F_network::isValid (void) const {
  return mSharedRoot.isNotNil () ;
}

//--------------------------------------------------------------------------------------------------

void GGS_M_5F_network::drop (void)  {
  mSharedRoot.setToNil () ;
}

//--------------------------------------------------------------------------------------------------

void GGS_M_5F_network::build (LOCATION_ARGS) {
  mSharedRoot = OptionalSharedRef <GenericMapRoot <GGS_M_5F_network_2E_element>>::make (THERE) ;
}

//--------------------------------------------------------------------------------------------------

void GGS_M_5F_network::performInsert (const GGS_M_5F_network_2E_element & inElement,
                                 const char * inInsertErrorMessage,
                                 const char * inShadowErrorMessage,
                                 Compiler * inCompiler
                                 COMMA_LOCATION_ARGS) {
  if (isValid () && inElement.mProperty_lkey.isValid ()) {
    OptionalSharedRef <GenericMapNode <GGS_M_5F_network_2E_element>> existingNode ;
    const bool allowReplacing = false ;
    mSharedRoot.insulate (THERE) ;
    mSharedRoot->insertOrReplaceInfo (
      inElement,
      allowReplacing,
      existingNode
      COMMA_THERE
    ) ;
    const GGS_lstring lkey = inElement.mProperty_lkey ;
    if (existingNode.isNotNil ()) {
      const GGS_location lstring_existingKey_location = existingNode->mSharedInfo->mProperty_lkey.mProperty_location ;
      inCompiler->semanticErrorWith_K_L_message (lkey, inInsertErrorMessage, lstring_existingKey_location COMMA_THERE) ;
    }else if ((inShadowErrorMessage != nullptr) && (mSharedRoot->overriddenRoot ().isNotNil ())) {
      const auto existingInfo = mSharedRoot->overriddenRoot ()->infoForKey (lkey.mProperty_string.stringValue()) ;
      if (existingInfo.isNotNil ()) {
        const GGS_location lstring_existingKey_location = existingInfo->mProperty_lkey.mProperty_location ;
        inCompiler->semanticErrorWith_K_L_message (lkey, inShadowErrorMessage, lstring_existingKey_location COMMA_THERE) ;
      }
    }
  }
}

//--------------------------------------------------------------------------------------------------

const SharedGenericPtrWithValueSemantics <GGS_M_5F_network_2E_element>
GGS_M_5F_network::infoForKey (const String & inKey) const {
  if (mSharedRoot.isNotNil ()) {
    return mSharedRoot->infoForKey (inKey) ;
  }else{
    return SharedGenericPtrWithValueSemantics <GGS_M_5F_network_2E_element> () ;
  }
}

//--------------------------------------------------------------------------------------------------

int32_t GGS_M_5F_network::count (void) const  {
  if (mSharedRoot.isNotNil ()) {
    return mSharedRoot->count () ;
  }else{
    return 0 ;
  }
}

//--------------------------------------------------------------------------------------------------

GenericArray <SharedGenericPtrWithValueSemantics <GGS_M_5F_network_2E_element>>
GGS_M_5F_network::sortedInfoArray (void) const {
  if (mSharedRoot.isNotNil ()) {
    return mSharedRoot->sortedInfoArray () ;
  }else{
    return GenericArray <SharedGenericPtrWithValueSemantics <GGS_M_5F_network_2E_element>> () ;
  }
}

//--------------------------------------------------------------------------------------------------

GGS_stringset GGS_M_5F_network::getter_keySet (Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) const {
  GGS_stringset result ;
  if (isValid ()) {
    result = GGS_stringset::init (inCompiler COMMA_THERE) ;
    mSharedRoot->populateKeySet (result, inCompiler) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

void GGS_M_5F_network::findNearestKey (const String & inKey,
                                  GenericUniqueArray <String> & outNearestKeyArray) const {
  mSharedRoot->findNearestKey (inKey, outNearestKeyArray) ;
}

//--------------------------------------------------------------------------------------------------

GGS_M_5F_network_2E_element_3F_ GGS_M_5F_network
::readSubscript__3F_ (const class GGS_string & inKey,
                      Compiler * /* inCompiler */
                      COMMA_UNUSED_LOCATION_ARGS) const {
  GGS_M_5F_network_2E_element_3F_ result ;
  if (isValid () && inKey.isValid ()) {
    const SharedGenericPtrWithValueSemantics <GGS_M_5F_network_2E_element> info = infoForKey (inKey.stringValue ()) ;
    if (info.isNil ()) {
      result = GGS_M_5F_network_2E_element_3F_::init_nil () ;
    }else{
      GGS_M_5F_network_2E_element element ;
      element.mProperty_lkey = info->mProperty_lkey ;
      element.mProperty_mIndex = info->mProperty_mIndex ;
      element.mProperty_mCANnetwork = info->mProperty_mCANnetwork ;
      element.mProperty_mScalingFactor = info->mProperty_mScalingFactor ;
      result = element ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_M_5F_network GGS_M_5F_network::class_func_mapWithMapToOverride (const GGS_M_5F_network & inMapToOverride
                                                                    COMMA_LOCATION_ARGS) {
  GGS_M_5F_network result ;
  if (inMapToOverride.isValid ()) {
    result.mSharedRoot = OptionalSharedRef <GenericMapRoot <GGS_M_5F_network_2E_element>>::make (inMapToOverride.mSharedRoot COMMA_THERE) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_M_5F_network GGS_M_5F_network::getter_overriddenMap (Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) const {
  GGS_M_5F_network result ;
  if (isValid ()) {
    result.mSharedRoot = mSharedRoot->overriddenRoot () ;
    if (result.mSharedRoot.isNil ()) {
      inCompiler->onTheFlySemanticError ("getter 'overriddenMap': no overriden map" COMMA_THERE) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

void GGS_M_5F_network::setter_insertKey (GGS_lstring inLKey,
                                         GGS_uint inArgument0,
                                         GGS_bool inArgument1,
                                         GGS_luint inArgument2,
                                         Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) {
  const GGS_M_5F_network_2E_element element (inLKey, inArgument0, inArgument1, inArgument2) ;
  const char * kInsertErrorMessage = "the processor '%K' has been already declared in %L" ;
  const char * kShadowErrorMessage = nullptr ;
  performInsert (element, kInsertErrorMessage, kShadowErrorMessage, inCompiler COMMA_THERE) ;
}

//--------------------------------------------------------------------------------------------------

void GGS_M_5F_network::method_searchKey (GGS_lstring inLKey,
                                         GGS_uint & outArgument0,
                                         GGS_bool & outArgument1,
                                         GGS_luint & outArgument2,
                                         Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) const {
  SharedGenericPtrWithValueSemantics <GGS_M_5F_network_2E_element> info ;
  if (isValid () && inLKey.isValid ()) {
    const String key = inLKey.mProperty_string.stringValue () ;
    info = infoForKey (key) ;
    if (info.isNil ()) {
      GenericUniqueArray <String> nearestKeyArray ;
      findNearestKey (key, nearestKeyArray) ;
      const char * kSearchErrorMessage = "the processor '%K' is not declared" ;
      inCompiler->semanticErrorWith_K_message (inLKey, nearestKeyArray, kSearchErrorMessage COMMA_THERE) ;
    }
  }
  if (info.isNil ()) {
    outArgument0.drop () ;
    outArgument1.drop () ;
    outArgument2.drop () ;
  }else{
    outArgument0 = info->mProperty_mIndex ;
    outArgument1 = info->mProperty_mCANnetwork ;
    outArgument2 = info->mProperty_mScalingFactor ;
  }
}
//--------------------------------------------------------------------------------------------------

GGS_uint GGS_M_5F_network::getter_mIndexForKey (const GGS_string & inKey,
                                                Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) const {
  GGS_uint result ;
  if (isValid () && inKey.isValid ()) {
    const String key = inKey.stringValue () ;
    const SharedGenericPtrWithValueSemantics <GGS_M_5F_network_2E_element> info = infoForKey (key) ;
    if (info.isNil ()) {
      String message = "cannot read property in map: the '" ;
      message.appendString (key) ;
      message.appendCString ("' key does not exist") ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }else{
      result = info->mProperty_mIndex ;
    }
  }
  return result ;
}
//--------------------------------------------------------------------------------------------------

GGS_bool GGS_M_5F_network::getter_mCANnetworkForKey (const GGS_string & inKey,
                                                     Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) const {
  GGS_bool result ;
  if (isValid () && inKey.isValid ()) {
    const String key = inKey.stringValue () ;
    const SharedGenericPtrWithValueSemantics <GGS_M_5F_network_2E_element> info = infoForKey (key) ;
    if (info.isNil ()) {
      String message = "cannot read property in map: the '" ;
      message.appendString (key) ;
      message.appendCString ("' key does not exist") ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }else{
      result = info->mProperty_mCANnetwork ;
    }
  }
  return result ;
}
//--------------------------------------------------------------------------------------------------

GGS_luint GGS_M_5F_network::getter_mScalingFactorForKey (const GGS_string & inKey,
                                                         Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) const {
  GGS_luint result ;
  if (isValid () && inKey.isValid ()) {
    const String key = inKey.stringValue () ;
    const SharedGenericPtrWithValueSemantics <GGS_M_5F_network_2E_element> info = infoForKey (key) ;
    if (info.isNil ()) {
      String message = "cannot read property in map: the '" ;
      message.appendString (key) ;
      message.appendCString ("' key does not exist") ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }else{
      result = info->mProperty_mScalingFactor ;
    }
  }
  return result ;
}
//--------------------------------------------------------------------------------------------------

void GGS_M_5F_network::setter_setMIndexForKey (GGS_uint inValue,
                                               GGS_string inKey,
                                               Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) {
  if (isValid () && inKey.isValid ()) {
    const String key = inKey.stringValue () ;
    mSharedRoot.insulate (HERE) ;
    OptionalSharedRef <GenericMapNode <GGS_M_5F_network_2E_element>> node = mSharedRoot->searchNode (key) ;
    if (node.isNil ()) {
      String message = "cannot write property in map: the '" ;
      message.appendString (key) ;
      message.appendCString ("' key does not exist") ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }else{
      node->mSharedInfo->mProperty_mIndex = inValue ;
    }
  }
}
//--------------------------------------------------------------------------------------------------

void GGS_M_5F_network::setter_setMCANnetworkForKey (GGS_bool inValue,
                                                    GGS_string inKey,
                                                    Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  if (isValid () && inKey.isValid ()) {
    const String key = inKey.stringValue () ;
    mSharedRoot.insulate (HERE) ;
    OptionalSharedRef <GenericMapNode <GGS_M_5F_network_2E_element>> node = mSharedRoot->searchNode (key) ;
    if (node.isNil ()) {
      String message = "cannot write property in map: the '" ;
      message.appendString (key) ;
      message.appendCString ("' key does not exist") ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }else{
      node->mSharedInfo->mProperty_mCANnetwork = inValue ;
    }
  }
}
//--------------------------------------------------------------------------------------------------

void GGS_M_5F_network::setter_setMScalingFactorForKey (GGS_luint inValue,
                                                       GGS_string inKey,
                                                       Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) {
  if (isValid () && inKey.isValid ()) {
    const String key = inKey.stringValue () ;
    mSharedRoot.insulate (HERE) ;
    OptionalSharedRef <GenericMapNode <GGS_M_5F_network_2E_element>> node = mSharedRoot->searchNode (key) ;
    if (node.isNil ()) {
      String message = "cannot write property in map: the '" ;
      message.appendString (key) ;
      message.appendCString ("' key does not exist") ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }else{
      node->mSharedInfo->mProperty_mScalingFactor = inValue ;
    }
  }
}
//--------------------------------------------------------------------------------------------------

static void GGS_M_5F_network_internalDescription (const GenericArray <SharedGenericPtrWithValueSemantics <GGS_M_5F_network_2E_element>> & inArray,
                                                        String & ioString,
                                                        const int32_t inIndentation) {
  const int32_t n = inArray.count () ;
  ioString.appendString (" (") ;
  ioString.appendSigned (n) ;
  ioString.appendString (" object") ;
  if (n > 1) {
    ioString.appendString ("s") ;
  }
  ioString.appendString ("):") ;
  for (int32_t i = 0 ; i < n ; i++) {
    ioString.appendNewLine () ;
    ioString.appendStringMultiple ("| ", inIndentation) ;
    ioString.appendString ("|-at ") ;
    ioString.appendSigned (i) ;
    ioString.appendString (": key '") ;
    ioString.appendString (inArray (i COMMA_HERE)->mProperty_lkey.mProperty_string.stringValue ()) ;
    ioString.appendString ("'") ;
    ioString.appendNewLine () ;
    ioString.appendStringMultiple ("| ", inIndentation + 2) ;
    ioString.appendString ("mIndex:") ;
    inArray (i COMMA_HERE)->mProperty_mIndex.description (ioString, inIndentation + 1) ;
    ioString.appendNewLine () ;
    ioString.appendStringMultiple ("| ", inIndentation + 2) ;
    ioString.appendString ("mCANnetwork:") ;
    inArray (i COMMA_HERE)->mProperty_mCANnetwork.description (ioString, inIndentation + 1) ;
    ioString.appendNewLine () ;
    ioString.appendStringMultiple ("| ", inIndentation + 2) ;
    ioString.appendString ("mScalingFactor:") ;
    inArray (i COMMA_HERE)->mProperty_mScalingFactor.description (ioString, inIndentation + 1) ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_M_5F_network::description (String & ioString,
                                          const int32_t inIndentation) const {
  ioString.appendCString ("<map @") ;
  ioString.appendString (staticTypeDescriptor ()->mGalgasTypeName) ;
  if (isValid ()) {
    const GenericArray <SharedGenericPtrWithValueSemantics <GGS_M_5F_network_2E_element>> array = sortedInfoArray () ;
    GGS_M_5F_network_internalDescription (array, ioString, inIndentation) ;
    OptionalSharedRef <GenericMapRoot <GGS_M_5F_network_2E_element>> subRoot = mSharedRoot->overriddenRoot () ;
    uint32_t idx = 0 ;
    while (subRoot.isNotNil ()) {
     idx += 1 ;
     ioString.appendNewLine () ;
     ioString.appendStringMultiple ("| ", inIndentation + 1) ;
     ioString.appendString (" override #") ;
     ioString.appendUnsigned (idx) ;
     const auto subRootArray = subRoot->sortedInfoArray () ;
     GGS_M_5F_network_internalDescription (subRootArray, ioString, inIndentation) ;
     subRoot = subRoot->overriddenRoot () ;
    }
  }else{
    ioString.appendCString (" not built") ;
  }
  ioString.appendCString (">") ;
}



//--------------------------------------------------------------------------------------------------
//  Down Enumerator for @M_5F_network
//--------------------------------------------------------------------------------------------------

DownEnumerator_M_5F_network::DownEnumerator_M_5F_network (const GGS_M_5F_network & inMap) :
mInfoArray (inMap.sortedInfoArray ()),
mIndex (0) {
  mIndex = mInfoArray.count () - 1 ;
}

//--------------------------------------------------------------------------------------------------

GGS_M_5F_network_2E_element DownEnumerator_M_5F_network::current (LOCATION_ARGS) const {
  return mInfoArray (mIndex COMMA_THERE).value () ;
}

//--------------------------------------------------------------------------------------------------

GGS_lstring DownEnumerator_M_5F_network::current_lkey (LOCATION_ARGS) const {
  return mInfoArray (mIndex COMMA_THERE)->mProperty_lkey ;
}

//--------------------------------------------------------------------------------------------------

GGS_uint DownEnumerator_M_5F_network::current_mIndex (LOCATION_ARGS) const {
  return mInfoArray (mIndex COMMA_THERE)->mProperty_mIndex ;
}

//--------------------------------------------------------------------------------------------------

GGS_bool DownEnumerator_M_5F_network::current_mCANnetwork (LOCATION_ARGS) const {
  return mInfoArray (mIndex COMMA_THERE)->mProperty_mCANnetwork ;
}

//--------------------------------------------------------------------------------------------------

GGS_luint DownEnumerator_M_5F_network::current_mScalingFactor (LOCATION_ARGS) const {
  return mInfoArray (mIndex COMMA_THERE)->mProperty_mScalingFactor ;
}

//--------------------------------------------------------------------------------------------------
//  Up Enumerator for @M_5F_network
//--------------------------------------------------------------------------------------------------

UpEnumerator_M_5F_network::UpEnumerator_M_5F_network (const GGS_M_5F_network & inMap) :
mInfoArray (inMap.sortedInfoArray ()),
mIndex (0) {
}

//--------------------------------------------------------------------------------------------------

GGS_M_5F_network_2E_element UpEnumerator_M_5F_network::current (LOCATION_ARGS) const {
  return mInfoArray (mIndex COMMA_THERE).value () ;
}

//--------------------------------------------------------------------------------------------------

GGS_lstring UpEnumerator_M_5F_network::current_lkey (LOCATION_ARGS) const {
  return mInfoArray (mIndex COMMA_THERE)->mProperty_lkey ;
}

//--------------------------------------------------------------------------------------------------

GGS_uint UpEnumerator_M_5F_network::current_mIndex (LOCATION_ARGS) const {
  return mInfoArray (mIndex COMMA_THERE)->mProperty_mIndex ;
}

//--------------------------------------------------------------------------------------------------

GGS_bool UpEnumerator_M_5F_network::current_mCANnetwork (LOCATION_ARGS) const {
  return mInfoArray (mIndex COMMA_THERE)->mProperty_mCANnetwork ;
}

//--------------------------------------------------------------------------------------------------

GGS_luint UpEnumerator_M_5F_network::current_mScalingFactor (LOCATION_ARGS) const {
  return mInfoArray (mIndex COMMA_THERE)->mProperty_mScalingFactor ;
}


//--------------------------------------------------------------------------------------------------
//     @M_network generic code implementation
//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor kTypeDescriptor_GALGAS_M_5F_network ("M_network",
                                                                 nullptr) ;

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * GGS_M_5F_network::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_M_5F_network ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GGS_M_5F_network::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GGS_M_5F_network (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_M_5F_network GGS_M_5F_network::extractObject (const GGS_object & inObject,
                                                  Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
  GGS_M_5F_network result ;
  const GGS_M_5F_network * p = (const GGS_M_5F_network *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GGS_M_5F_network *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("M_network", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
// @AC_5F_canMessage reference class
//--------------------------------------------------------------------------------------------------

ComparisonResult GGS_AC_5F_canMessage::objectCompare (const GGS_AC_5F_canMessage & inOperand) const {
  ComparisonResult result = ComparisonResult::invalid ;
  if (isValid () && inOperand.isValid ()) {
    const size_t myObjectPtr = size_t (mObjectPtr) ;
    const size_t operandObjectPtr = size_t (inOperand.mObjectPtr) ;
    if (myObjectPtr < operandObjectPtr) {
      result = ComparisonResult::firstOperandLowerThanSecond ;
    }else if (myObjectPtr > operandObjectPtr) {
      result = ComparisonResult::firstOperandGreaterThanSecond ;
    }else{
      result = ComparisonResult::operandEqual ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_AC_5F_canMessage::GGS_AC_5F_canMessage (void) :
AC_GALGAS_reference_class () {
}


void cPtr_AC_5F_canMessage::
AC_5F_canMessage_init (Compiler * /* inCompiler */) {
}

//--------------------------------------------------------------------------------------------------

GGS_AC_5F_canMessage::GGS_AC_5F_canMessage (const cPtr_AC_5F_canMessage * inSourcePtr) :
AC_GALGAS_reference_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_AC_5F_canMessage) ;
}
//--------------------------------------------------------------------------------------------------
//Pointer class for @AC_canMessage class
//--------------------------------------------------------------------------------------------------


//--------------------------------------------------------------------------------------------------

cPtr_AC_5F_canMessage::cPtr_AC_5F_canMessage (Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) :
acStrongPtr_class (inCompiler COMMA_THERE) {
}


//--------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  void cPtr_AC_5F_canMessage::printNonNullClassInstanceProperties (void) const {
    acStrongPtr_class::printNonNullClassInstanceProperties () ;
  }
#endif

//--------------------------------------------------------------------------------------------------
//     @AC_canMessage generic code implementation
//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor kTypeDescriptor_GALGAS_AC_5F_canMessage ("AC_canMessage",
                                                                     nullptr) ;

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * GGS_AC_5F_canMessage::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_AC_5F_canMessage ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GGS_AC_5F_canMessage::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GGS_AC_5F_canMessage (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_AC_5F_canMessage GGS_AC_5F_canMessage::extractObject (const GGS_object & inObject,
                                                          Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) {
  GGS_AC_5F_canMessage result ;
  const GGS_AC_5F_canMessage * p = (const GGS_AC_5F_canMessage *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GGS_AC_5F_canMessage *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("AC_canMessage", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

ComparisonResult GGS_AC_5F_canMessage_2E_weak::objectCompare (const GGS_AC_5F_canMessage_2E_weak & inOperand) const {
  ComparisonResult result = ComparisonResult::invalid ;
  if (isValid () && inOperand.isValid ()) {
    cPtr_weakReference_proxy * myPtr = mProxyPtr ;
    const size_t myObjectPtr = size_t (myPtr) ;
    cPtr_weakReference_proxy * operandPtr = inOperand.mProxyPtr ;
    const size_t operandObjectPtr = size_t (operandPtr) ;
    if (myObjectPtr < operandObjectPtr) {
      result = ComparisonResult::firstOperandLowerThanSecond ;
    }else if (myObjectPtr > operandObjectPtr) {
      result = ComparisonResult::firstOperandGreaterThanSecond ;
    }else{
      result = ComparisonResult::operandEqual ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_AC_5F_canMessage_2E_weak::GGS_AC_5F_canMessage_2E_weak (void) :
AC_GALGAS_weak_reference () {
}

//--------------------------------------------------------------------------------------------------

GGS_AC_5F_canMessage_2E_weak & GGS_AC_5F_canMessage_2E_weak::operator = (const GGS_AC_5F_canMessage & inSource) {
  cPtr_weakReference_proxy * proxyPtr = nullptr ;
  acStrongPtr_class * p = (acStrongPtr_class *) inSource.ptr () ;
  if (p != nullptr) {
    proxyPtr = p->getProxy () ;
  }
  macroAssignSharedObject (mProxyPtr, proxyPtr) ;
  return *this ;
}

//--------------------------------------------------------------------------------------------------

GGS_AC_5F_canMessage_2E_weak::GGS_AC_5F_canMessage_2E_weak (const GGS_AC_5F_canMessage & inSource) :
AC_GALGAS_weak_reference (inSource) {
}


//--------------------------------------------------------------------------------------------------

GGS_AC_5F_canMessage_2E_weak GGS_AC_5F_canMessage_2E_weak::class_func_nil (LOCATION_ARGS) {
  GGS_AC_5F_canMessage_2E_weak result ;
  macroMyNew (result.mProxyPtr, cPtr_weakReference_proxy (THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_AC_5F_canMessage GGS_AC_5F_canMessage_2E_weak::unwrappedValue (void) const {
  GGS_AC_5F_canMessage result ;
  if (isValid ()) {
    const cPtr_AC_5F_canMessage * p = (cPtr_AC_5F_canMessage *) ptr () ;
    if (nullptr != p) {
      result = GGS_AC_5F_canMessage (p) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_AC_5F_canMessage GGS_AC_5F_canMessage_2E_weak::bang_AC_5F_canMessage_2E_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const {
  GGS_AC_5F_canMessage result ;
  if (mProxyPtr != nullptr) {
    acStrongPtr_class * strongPtr = mProxyPtr->strongObject () ;
    if (strongPtr == nullptr) {
      inCompiler->onTheFlySemanticError ("weak reference is nil" COMMA_THERE) ;
    }else{
      macroValidSharedObject (strongPtr, cPtr_AC_5F_canMessage) ;
      result = GGS_AC_5F_canMessage ((cPtr_AC_5F_canMessage *) strongPtr) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//     @AC_canMessage.weak generic code implementation
//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor kTypeDescriptor_GALGAS_AC_5F_canMessage_2E_weak ("AC_canMessage.weak",
                                                                             nullptr) ;

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * GGS_AC_5F_canMessage_2E_weak::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_AC_5F_canMessage_2E_weak ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GGS_AC_5F_canMessage_2E_weak::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GGS_AC_5F_canMessage_2E_weak (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_AC_5F_canMessage_2E_weak GGS_AC_5F_canMessage_2E_weak::extractObject (const GGS_object & inObject,
                                                                          Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) {
  GGS_AC_5F_canMessage_2E_weak result ;
  const GGS_AC_5F_canMessage_2E_weak * p = (const GGS_AC_5F_canMessage_2E_weak *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GGS_AC_5F_canMessage_2E_weak *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("AC_canMessage.weak", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
// @C_5F_canIndependantMessage reference class
//--------------------------------------------------------------------------------------------------

ComparisonResult GGS_C_5F_canIndependantMessage::objectCompare (const GGS_C_5F_canIndependantMessage & inOperand) const {
  ComparisonResult result = ComparisonResult::invalid ;
  if (isValid () && inOperand.isValid ()) {
    const size_t myObjectPtr = size_t (mObjectPtr) ;
    const size_t operandObjectPtr = size_t (inOperand.mObjectPtr) ;
    if (myObjectPtr < operandObjectPtr) {
      result = ComparisonResult::firstOperandLowerThanSecond ;
    }else if (myObjectPtr > operandObjectPtr) {
      result = ComparisonResult::firstOperandGreaterThanSecond ;
    }else{
      result = ComparisonResult::operandEqual ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_C_5F_canIndependantMessage::GGS_C_5F_canIndependantMessage (void) :
GGS_AC_5F_canMessage () {
}

//--- Synthetized initializer ----------------------------------------------------------------------

GGS_C_5F_canIndependantMessage GGS_C_5F_canIndependantMessage::
init (Compiler * inCompiler
          COMMA_LOCATION_ARGS) {
  cPtr_C_5F_canIndependantMessage * object = nullptr ;
  macroMyNew (object, cPtr_C_5F_canIndependantMessage (inCompiler COMMA_THERE)) ;
  object->C_5F_canIndependantMessage_init (inCompiler) ;
  const GGS_C_5F_canIndependantMessage result (object) ;
  macroDetachSharedObject (object) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

void cPtr_C_5F_canIndependantMessage::
C_5F_canIndependantMessage_init (Compiler * /* inCompiler */) {
}

//--------------------------------------------------------------------------------------------------

GGS_C_5F_canIndependantMessage::GGS_C_5F_canIndependantMessage (const cPtr_C_5F_canIndependantMessage * inSourcePtr) :
GGS_AC_5F_canMessage (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_C_5F_canIndependantMessage) ;
}
//--------------------------------------------------------------------------------------------------

GGS_C_5F_canIndependantMessage GGS_C_5F_canIndependantMessage::class_func_new (Compiler * inCompiler COMMA_LOCATION_ARGS) {
  GGS_C_5F_canIndependantMessage result ;
  macroMyNew (result.mObjectPtr, cPtr_C_5F_canIndependantMessage (inCompiler COMMA_THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------
//Pointer class for @C_canIndependantMessage class
//--------------------------------------------------------------------------------------------------


//--------------------------------------------------------------------------------------------------

cPtr_C_5F_canIndependantMessage::cPtr_C_5F_canIndependantMessage (Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) :
cPtr_AC_5F_canMessage (inCompiler COMMA_THERE) {
}

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * cPtr_C_5F_canIndependantMessage::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_C_5F_canIndependantMessage ;
}

void cPtr_C_5F_canIndependantMessage::description (String & ioString,
                                                   const int32_t /* inIndentation */) const {
  ioString.appendCString ("[@C_canIndependantMessage]") ;
}

//--------------------------------------------------------------------------------------------------

acPtr_class * cPtr_C_5F_canIndependantMessage::duplicate (Compiler * inCompiler COMMA_LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_C_5F_canIndependantMessage (inCompiler COMMA_THERE)) ;
  return ptr ;
}


//--------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  void cPtr_C_5F_canIndependantMessage::printNonNullClassInstanceProperties (void) const {
    cPtr_AC_5F_canMessage::printNonNullClassInstanceProperties () ;
  }
#endif

//--------------------------------------------------------------------------------------------------
//     @C_canIndependantMessage generic code implementation
//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor kTypeDescriptor_GALGAS_C_5F_canIndependantMessage ("C_canIndependantMessage",
                                                                               & kTypeDescriptor_GALGAS_AC_5F_canMessage) ;

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * GGS_C_5F_canIndependantMessage::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_C_5F_canIndependantMessage ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GGS_C_5F_canIndependantMessage::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GGS_C_5F_canIndependantMessage (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_C_5F_canIndependantMessage GGS_C_5F_canIndependantMessage::extractObject (const GGS_object & inObject,
                                                                              Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) {
  GGS_C_5F_canIndependantMessage result ;
  const GGS_C_5F_canIndependantMessage * p = (const GGS_C_5F_canIndependantMessage *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GGS_C_5F_canIndependantMessage *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("C_canIndependantMessage", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

ComparisonResult GGS_C_5F_canIndependantMessage_2E_weak::objectCompare (const GGS_C_5F_canIndependantMessage_2E_weak & inOperand) const {
  ComparisonResult result = ComparisonResult::invalid ;
  if (isValid () && inOperand.isValid ()) {
    cPtr_weakReference_proxy * myPtr = mProxyPtr ;
    const size_t myObjectPtr = size_t (myPtr) ;
    cPtr_weakReference_proxy * operandPtr = inOperand.mProxyPtr ;
    const size_t operandObjectPtr = size_t (operandPtr) ;
    if (myObjectPtr < operandObjectPtr) {
      result = ComparisonResult::firstOperandLowerThanSecond ;
    }else if (myObjectPtr > operandObjectPtr) {
      result = ComparisonResult::firstOperandGreaterThanSecond ;
    }else{
      result = ComparisonResult::operandEqual ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_C_5F_canIndependantMessage_2E_weak::GGS_C_5F_canIndependantMessage_2E_weak (void) :
GGS_AC_5F_canMessage_2E_weak () {
}

//--------------------------------------------------------------------------------------------------

GGS_C_5F_canIndependantMessage_2E_weak & GGS_C_5F_canIndependantMessage_2E_weak::operator = (const GGS_C_5F_canIndependantMessage & inSource) {
  cPtr_weakReference_proxy * proxyPtr = nullptr ;
  acStrongPtr_class * p = (acStrongPtr_class *) inSource.ptr () ;
  if (p != nullptr) {
    proxyPtr = p->getProxy () ;
  }
  macroAssignSharedObject (mProxyPtr, proxyPtr) ;
  return *this ;
}

//--------------------------------------------------------------------------------------------------

GGS_C_5F_canIndependantMessage_2E_weak::GGS_C_5F_canIndependantMessage_2E_weak (const GGS_C_5F_canIndependantMessage & inSource) :
GGS_AC_5F_canMessage_2E_weak (inSource) {
}


//--------------------------------------------------------------------------------------------------

GGS_C_5F_canIndependantMessage_2E_weak GGS_C_5F_canIndependantMessage_2E_weak::class_func_nil (LOCATION_ARGS) {
  GGS_C_5F_canIndependantMessage_2E_weak result ;
  macroMyNew (result.mProxyPtr, cPtr_weakReference_proxy (THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_C_5F_canIndependantMessage GGS_C_5F_canIndependantMessage_2E_weak::unwrappedValue (void) const {
  GGS_C_5F_canIndependantMessage result ;
  if (isValid ()) {
    const cPtr_C_5F_canIndependantMessage * p = (cPtr_C_5F_canIndependantMessage *) ptr () ;
    if (nullptr != p) {
      result = GGS_C_5F_canIndependantMessage (p) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_C_5F_canIndependantMessage GGS_C_5F_canIndependantMessage_2E_weak::bang_C_5F_canIndependantMessage_2E_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const {
  GGS_C_5F_canIndependantMessage result ;
  if (mProxyPtr != nullptr) {
    acStrongPtr_class * strongPtr = mProxyPtr->strongObject () ;
    if (strongPtr == nullptr) {
      inCompiler->onTheFlySemanticError ("weak reference is nil" COMMA_THERE) ;
    }else{
      macroValidSharedObject (strongPtr, cPtr_C_5F_canIndependantMessage) ;
      result = GGS_C_5F_canIndependantMessage ((cPtr_C_5F_canIndependantMessage *) strongPtr) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//     @C_canIndependantMessage.weak generic code implementation
//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor kTypeDescriptor_GALGAS_C_5F_canIndependantMessage_2E_weak ("C_canIndependantMessage.weak",
                                                                                       & kTypeDescriptor_GALGAS_AC_5F_canMessage_2E_weak) ;

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * GGS_C_5F_canIndependantMessage_2E_weak::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_C_5F_canIndependantMessage_2E_weak ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GGS_C_5F_canIndependantMessage_2E_weak::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GGS_C_5F_canIndependantMessage_2E_weak (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_C_5F_canIndependantMessage_2E_weak GGS_C_5F_canIndependantMessage_2E_weak::extractObject (const GGS_object & inObject,
                                                                                              Compiler * inCompiler
                                                                                              COMMA_LOCATION_ARGS) {
  GGS_C_5F_canIndependantMessage_2E_weak result ;
  const GGS_C_5F_canIndependantMessage_2E_weak * p = (const GGS_C_5F_canIndependantMessage_2E_weak *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GGS_C_5F_canIndependantMessage_2E_weak *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("C_canIndependantMessage.weak", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
// @C_5F_canMessageFromMessage reference class
//--------------------------------------------------------------------------------------------------

ComparisonResult GGS_C_5F_canMessageFromMessage::objectCompare (const GGS_C_5F_canMessageFromMessage & inOperand) const {
  ComparisonResult result = ComparisonResult::invalid ;
  if (isValid () && inOperand.isValid ()) {
    const size_t myObjectPtr = size_t (mObjectPtr) ;
    const size_t operandObjectPtr = size_t (inOperand.mObjectPtr) ;
    if (myObjectPtr < operandObjectPtr) {
      result = ComparisonResult::firstOperandLowerThanSecond ;
    }else if (myObjectPtr > operandObjectPtr) {
      result = ComparisonResult::firstOperandGreaterThanSecond ;
    }else{
      result = ComparisonResult::operandEqual ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_C_5F_canMessageFromMessage::GGS_C_5F_canMessageFromMessage (void) :
GGS_AC_5F_canMessage () {
}

//--- Synthetized initializer ----------------------------------------------------------------------

GGS_C_5F_canMessageFromMessage GGS_C_5F_canMessageFromMessage::
init_21_ (const GGS_uint & in_mMessageIndex,
          Compiler * inCompiler
          COMMA_LOCATION_ARGS) {
  cPtr_C_5F_canMessageFromMessage * object = nullptr ;
  macroMyNew (object, cPtr_C_5F_canMessageFromMessage (inCompiler COMMA_THERE)) ;
  object->C_5F_canMessageFromMessage_init_21_ (in_mMessageIndex, inCompiler) ;
  const GGS_C_5F_canMessageFromMessage result (object) ;
  macroDetachSharedObject (object) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

void cPtr_C_5F_canMessageFromMessage::
C_5F_canMessageFromMessage_init_21_ (const GGS_uint & in_mMessageIndex,
                                     Compiler * /* inCompiler */) {
  mProperty_mMessageIndex = in_mMessageIndex ;
}

//--------------------------------------------------------------------------------------------------

GGS_C_5F_canMessageFromMessage::GGS_C_5F_canMessageFromMessage (const cPtr_C_5F_canMessageFromMessage * inSourcePtr) :
GGS_AC_5F_canMessage (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_C_5F_canMessageFromMessage) ;
}
//--------------------------------------------------------------------------------------------------

GGS_C_5F_canMessageFromMessage GGS_C_5F_canMessageFromMessage::class_func_new (const GGS_uint & in_mMessageIndex,
                                                                               Compiler * inCompiler
                                                                               COMMA_LOCATION_ARGS) {
  GGS_C_5F_canMessageFromMessage result ;
  macroMyNew (result.mObjectPtr, cPtr_C_5F_canMessageFromMessage (in_mMessageIndex,  inCompiler COMMA_THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_uint GGS_C_5F_canMessageFromMessage::readProperty_mMessageIndex (void) const {
  if (nullptr == mObjectPtr) {
    return GGS_uint () ;
  }else{
    cPtr_C_5F_canMessageFromMessage * p = (cPtr_C_5F_canMessageFromMessage *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_C_5F_canMessageFromMessage) ;
    return p->mProperty_mMessageIndex ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_C_5F_canMessageFromMessage::setProperty_mMessageIndex (const GGS_uint & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_C_5F_canMessageFromMessage * p = (cPtr_C_5F_canMessageFromMessage *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_C_5F_canMessageFromMessage) ;
    p->mProperty_mMessageIndex = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------
//Pointer class for @C_canMessageFromMessage class
//--------------------------------------------------------------------------------------------------

cPtr_C_5F_canMessageFromMessage::cPtr_C_5F_canMessageFromMessage (Compiler * inCompiler COMMA_LOCATION_ARGS) :
cPtr_AC_5F_canMessage (inCompiler COMMA_THERE),
mProperty_mMessageIndex () {
}

//--------------------------------------------------------------------------------------------------

cPtr_C_5F_canMessageFromMessage::cPtr_C_5F_canMessageFromMessage (const GGS_uint & in_mMessageIndex,
                                                                  Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) :
cPtr_AC_5F_canMessage (inCompiler COMMA_THERE),
mProperty_mMessageIndex () {
  mProperty_mMessageIndex = in_mMessageIndex ;
}

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * cPtr_C_5F_canMessageFromMessage::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_C_5F_canMessageFromMessage ;
}

void cPtr_C_5F_canMessageFromMessage::description (String & ioString,
                                                   const int32_t inIndentation) const {
  ioString.appendCString ("[@C_canMessageFromMessage:") ;
  mProperty_mMessageIndex.description (ioString, inIndentation+1) ;
  ioString.appendCString ("]") ;
}

//--------------------------------------------------------------------------------------------------

acPtr_class * cPtr_C_5F_canMessageFromMessage::duplicate (Compiler * inCompiler COMMA_LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_C_5F_canMessageFromMessage (mProperty_mMessageIndex, inCompiler COMMA_THERE)) ;
  return ptr ;
}


//--------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  void cPtr_C_5F_canMessageFromMessage::printNonNullClassInstanceProperties (void) const {
    cPtr_AC_5F_canMessage::printNonNullClassInstanceProperties () ;
    mProperty_mMessageIndex.printNonNullClassInstanceProperties ("mMessageIndex") ;
  }
#endif

//--------------------------------------------------------------------------------------------------
//     @C_canMessageFromMessage generic code implementation
//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor kTypeDescriptor_GALGAS_C_5F_canMessageFromMessage ("C_canMessageFromMessage",
                                                                               & kTypeDescriptor_GALGAS_AC_5F_canMessage) ;

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * GGS_C_5F_canMessageFromMessage::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_C_5F_canMessageFromMessage ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GGS_C_5F_canMessageFromMessage::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GGS_C_5F_canMessageFromMessage (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_C_5F_canMessageFromMessage GGS_C_5F_canMessageFromMessage::extractObject (const GGS_object & inObject,
                                                                              Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) {
  GGS_C_5F_canMessageFromMessage result ;
  const GGS_C_5F_canMessageFromMessage * p = (const GGS_C_5F_canMessageFromMessage *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GGS_C_5F_canMessageFromMessage *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("C_canMessageFromMessage", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

ComparisonResult GGS_C_5F_canMessageFromMessage_2E_weak::objectCompare (const GGS_C_5F_canMessageFromMessage_2E_weak & inOperand) const {
  ComparisonResult result = ComparisonResult::invalid ;
  if (isValid () && inOperand.isValid ()) {
    cPtr_weakReference_proxy * myPtr = mProxyPtr ;
    const size_t myObjectPtr = size_t (myPtr) ;
    cPtr_weakReference_proxy * operandPtr = inOperand.mProxyPtr ;
    const size_t operandObjectPtr = size_t (operandPtr) ;
    if (myObjectPtr < operandObjectPtr) {
      result = ComparisonResult::firstOperandLowerThanSecond ;
    }else if (myObjectPtr > operandObjectPtr) {
      result = ComparisonResult::firstOperandGreaterThanSecond ;
    }else{
      result = ComparisonResult::operandEqual ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_C_5F_canMessageFromMessage_2E_weak::GGS_C_5F_canMessageFromMessage_2E_weak (void) :
GGS_AC_5F_canMessage_2E_weak () {
}

//--------------------------------------------------------------------------------------------------

GGS_C_5F_canMessageFromMessage_2E_weak & GGS_C_5F_canMessageFromMessage_2E_weak::operator = (const GGS_C_5F_canMessageFromMessage & inSource) {
  cPtr_weakReference_proxy * proxyPtr = nullptr ;
  acStrongPtr_class * p = (acStrongPtr_class *) inSource.ptr () ;
  if (p != nullptr) {
    proxyPtr = p->getProxy () ;
  }
  macroAssignSharedObject (mProxyPtr, proxyPtr) ;
  return *this ;
}

//--------------------------------------------------------------------------------------------------

GGS_C_5F_canMessageFromMessage_2E_weak::GGS_C_5F_canMessageFromMessage_2E_weak (const GGS_C_5F_canMessageFromMessage & inSource) :
GGS_AC_5F_canMessage_2E_weak (inSource) {
}


//--------------------------------------------------------------------------------------------------

GGS_C_5F_canMessageFromMessage_2E_weak GGS_C_5F_canMessageFromMessage_2E_weak::class_func_nil (LOCATION_ARGS) {
  GGS_C_5F_canMessageFromMessage_2E_weak result ;
  macroMyNew (result.mProxyPtr, cPtr_weakReference_proxy (THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_C_5F_canMessageFromMessage GGS_C_5F_canMessageFromMessage_2E_weak::unwrappedValue (void) const {
  GGS_C_5F_canMessageFromMessage result ;
  if (isValid ()) {
    const cPtr_C_5F_canMessageFromMessage * p = (cPtr_C_5F_canMessageFromMessage *) ptr () ;
    if (nullptr != p) {
      result = GGS_C_5F_canMessageFromMessage (p) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_C_5F_canMessageFromMessage GGS_C_5F_canMessageFromMessage_2E_weak::bang_C_5F_canMessageFromMessage_2E_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const {
  GGS_C_5F_canMessageFromMessage result ;
  if (mProxyPtr != nullptr) {
    acStrongPtr_class * strongPtr = mProxyPtr->strongObject () ;
    if (strongPtr == nullptr) {
      inCompiler->onTheFlySemanticError ("weak reference is nil" COMMA_THERE) ;
    }else{
      macroValidSharedObject (strongPtr, cPtr_C_5F_canMessageFromMessage) ;
      result = GGS_C_5F_canMessageFromMessage ((cPtr_C_5F_canMessageFromMessage *) strongPtr) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//     @C_canMessageFromMessage.weak generic code implementation
//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor kTypeDescriptor_GALGAS_C_5F_canMessageFromMessage_2E_weak ("C_canMessageFromMessage.weak",
                                                                                       & kTypeDescriptor_GALGAS_AC_5F_canMessage_2E_weak) ;

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * GGS_C_5F_canMessageFromMessage_2E_weak::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_C_5F_canMessageFromMessage_2E_weak ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GGS_C_5F_canMessageFromMessage_2E_weak::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GGS_C_5F_canMessageFromMessage_2E_weak (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_C_5F_canMessageFromMessage_2E_weak GGS_C_5F_canMessageFromMessage_2E_weak::extractObject (const GGS_object & inObject,
                                                                                              Compiler * inCompiler
                                                                                              COMMA_LOCATION_ARGS) {
  GGS_C_5F_canMessageFromMessage_2E_weak result ;
  const GGS_C_5F_canMessageFromMessage_2E_weak * p = (const GGS_C_5F_canMessageFromMessage_2E_weak *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GGS_C_5F_canMessageFromMessage_2E_weak *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("C_canMessageFromMessage.weak", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
// @C_5F_canMessageFromTask reference class
//--------------------------------------------------------------------------------------------------

ComparisonResult GGS_C_5F_canMessageFromTask::objectCompare (const GGS_C_5F_canMessageFromTask & inOperand) const {
  ComparisonResult result = ComparisonResult::invalid ;
  if (isValid () && inOperand.isValid ()) {
    const size_t myObjectPtr = size_t (mObjectPtr) ;
    const size_t operandObjectPtr = size_t (inOperand.mObjectPtr) ;
    if (myObjectPtr < operandObjectPtr) {
      result = ComparisonResult::firstOperandLowerThanSecond ;
    }else if (myObjectPtr > operandObjectPtr) {
      result = ComparisonResult::firstOperandGreaterThanSecond ;
    }else{
      result = ComparisonResult::operandEqual ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_C_5F_canMessageFromTask::GGS_C_5F_canMessageFromTask (void) :
GGS_AC_5F_canMessage () {
}

//--- Synthetized initializer ----------------------------------------------------------------------

GGS_C_5F_canMessageFromTask GGS_C_5F_canMessageFromTask::
init_21_ (const GGS_uint & in_mTaskIndex,
          Compiler * inCompiler
          COMMA_LOCATION_ARGS) {
  cPtr_C_5F_canMessageFromTask * object = nullptr ;
  macroMyNew (object, cPtr_C_5F_canMessageFromTask (inCompiler COMMA_THERE)) ;
  object->C_5F_canMessageFromTask_init_21_ (in_mTaskIndex, inCompiler) ;
  const GGS_C_5F_canMessageFromTask result (object) ;
  macroDetachSharedObject (object) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

void cPtr_C_5F_canMessageFromTask::
C_5F_canMessageFromTask_init_21_ (const GGS_uint & in_mTaskIndex,
                                  Compiler * /* inCompiler */) {
  mProperty_mTaskIndex = in_mTaskIndex ;
}

//--------------------------------------------------------------------------------------------------

GGS_C_5F_canMessageFromTask::GGS_C_5F_canMessageFromTask (const cPtr_C_5F_canMessageFromTask * inSourcePtr) :
GGS_AC_5F_canMessage (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_C_5F_canMessageFromTask) ;
}
//--------------------------------------------------------------------------------------------------

GGS_C_5F_canMessageFromTask GGS_C_5F_canMessageFromTask::class_func_new (const GGS_uint & in_mTaskIndex,
                                                                         Compiler * inCompiler
                                                                         COMMA_LOCATION_ARGS) {
  GGS_C_5F_canMessageFromTask result ;
  macroMyNew (result.mObjectPtr, cPtr_C_5F_canMessageFromTask (in_mTaskIndex,  inCompiler COMMA_THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_uint GGS_C_5F_canMessageFromTask::readProperty_mTaskIndex (void) const {
  if (nullptr == mObjectPtr) {
    return GGS_uint () ;
  }else{
    cPtr_C_5F_canMessageFromTask * p = (cPtr_C_5F_canMessageFromTask *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_C_5F_canMessageFromTask) ;
    return p->mProperty_mTaskIndex ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_C_5F_canMessageFromTask::setProperty_mTaskIndex (const GGS_uint & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_C_5F_canMessageFromTask * p = (cPtr_C_5F_canMessageFromTask *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_C_5F_canMessageFromTask) ;
    p->mProperty_mTaskIndex = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------
//Pointer class for @C_canMessageFromTask class
//--------------------------------------------------------------------------------------------------

cPtr_C_5F_canMessageFromTask::cPtr_C_5F_canMessageFromTask (Compiler * inCompiler COMMA_LOCATION_ARGS) :
cPtr_AC_5F_canMessage (inCompiler COMMA_THERE),
mProperty_mTaskIndex () {
}

//--------------------------------------------------------------------------------------------------

cPtr_C_5F_canMessageFromTask::cPtr_C_5F_canMessageFromTask (const GGS_uint & in_mTaskIndex,
                                                            Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) :
cPtr_AC_5F_canMessage (inCompiler COMMA_THERE),
mProperty_mTaskIndex () {
  mProperty_mTaskIndex = in_mTaskIndex ;
}

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * cPtr_C_5F_canMessageFromTask::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_C_5F_canMessageFromTask ;
}

void cPtr_C_5F_canMessageFromTask::description (String & ioString,
                                                const int32_t inIndentation) const {
  ioString.appendCString ("[@C_canMessageFromTask:") ;
  mProperty_mTaskIndex.description (ioString, inIndentation+1) ;
  ioString.appendCString ("]") ;
}

//--------------------------------------------------------------------------------------------------

acPtr_class * cPtr_C_5F_canMessageFromTask::duplicate (Compiler * inCompiler COMMA_LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_C_5F_canMessageFromTask (mProperty_mTaskIndex, inCompiler COMMA_THERE)) ;
  return ptr ;
}


//--------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  void cPtr_C_5F_canMessageFromTask::printNonNullClassInstanceProperties (void) const {
    cPtr_AC_5F_canMessage::printNonNullClassInstanceProperties () ;
    mProperty_mTaskIndex.printNonNullClassInstanceProperties ("mTaskIndex") ;
  }
#endif

//--------------------------------------------------------------------------------------------------
//     @C_canMessageFromTask generic code implementation
//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor kTypeDescriptor_GALGAS_C_5F_canMessageFromTask ("C_canMessageFromTask",
                                                                            & kTypeDescriptor_GALGAS_AC_5F_canMessage) ;

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * GGS_C_5F_canMessageFromTask::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_C_5F_canMessageFromTask ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GGS_C_5F_canMessageFromTask::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GGS_C_5F_canMessageFromTask (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_C_5F_canMessageFromTask GGS_C_5F_canMessageFromTask::extractObject (const GGS_object & inObject,
                                                                        Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) {
  GGS_C_5F_canMessageFromTask result ;
  const GGS_C_5F_canMessageFromTask * p = (const GGS_C_5F_canMessageFromTask *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GGS_C_5F_canMessageFromTask *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("C_canMessageFromTask", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

ComparisonResult GGS_C_5F_canMessageFromTask_2E_weak::objectCompare (const GGS_C_5F_canMessageFromTask_2E_weak & inOperand) const {
  ComparisonResult result = ComparisonResult::invalid ;
  if (isValid () && inOperand.isValid ()) {
    cPtr_weakReference_proxy * myPtr = mProxyPtr ;
    const size_t myObjectPtr = size_t (myPtr) ;
    cPtr_weakReference_proxy * operandPtr = inOperand.mProxyPtr ;
    const size_t operandObjectPtr = size_t (operandPtr) ;
    if (myObjectPtr < operandObjectPtr) {
      result = ComparisonResult::firstOperandLowerThanSecond ;
    }else if (myObjectPtr > operandObjectPtr) {
      result = ComparisonResult::firstOperandGreaterThanSecond ;
    }else{
      result = ComparisonResult::operandEqual ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_C_5F_canMessageFromTask_2E_weak::GGS_C_5F_canMessageFromTask_2E_weak (void) :
GGS_AC_5F_canMessage_2E_weak () {
}

//--------------------------------------------------------------------------------------------------

GGS_C_5F_canMessageFromTask_2E_weak & GGS_C_5F_canMessageFromTask_2E_weak::operator = (const GGS_C_5F_canMessageFromTask & inSource) {
  cPtr_weakReference_proxy * proxyPtr = nullptr ;
  acStrongPtr_class * p = (acStrongPtr_class *) inSource.ptr () ;
  if (p != nullptr) {
    proxyPtr = p->getProxy () ;
  }
  macroAssignSharedObject (mProxyPtr, proxyPtr) ;
  return *this ;
}

//--------------------------------------------------------------------------------------------------

GGS_C_5F_canMessageFromTask_2E_weak::GGS_C_5F_canMessageFromTask_2E_weak (const GGS_C_5F_canMessageFromTask & inSource) :
GGS_AC_5F_canMessage_2E_weak (inSource) {
}


//--------------------------------------------------------------------------------------------------

GGS_C_5F_canMessageFromTask_2E_weak GGS_C_5F_canMessageFromTask_2E_weak::class_func_nil (LOCATION_ARGS) {
  GGS_C_5F_canMessageFromTask_2E_weak result ;
  macroMyNew (result.mProxyPtr, cPtr_weakReference_proxy (THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_C_5F_canMessageFromTask GGS_C_5F_canMessageFromTask_2E_weak::unwrappedValue (void) const {
  GGS_C_5F_canMessageFromTask result ;
  if (isValid ()) {
    const cPtr_C_5F_canMessageFromTask * p = (cPtr_C_5F_canMessageFromTask *) ptr () ;
    if (nullptr != p) {
      result = GGS_C_5F_canMessageFromTask (p) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_C_5F_canMessageFromTask GGS_C_5F_canMessageFromTask_2E_weak::bang_C_5F_canMessageFromTask_2E_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const {
  GGS_C_5F_canMessageFromTask result ;
  if (mProxyPtr != nullptr) {
    acStrongPtr_class * strongPtr = mProxyPtr->strongObject () ;
    if (strongPtr == nullptr) {
      inCompiler->onTheFlySemanticError ("weak reference is nil" COMMA_THERE) ;
    }else{
      macroValidSharedObject (strongPtr, cPtr_C_5F_canMessageFromTask) ;
      result = GGS_C_5F_canMessageFromTask ((cPtr_C_5F_canMessageFromTask *) strongPtr) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//     @C_canMessageFromTask.weak generic code implementation
//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor kTypeDescriptor_GALGAS_C_5F_canMessageFromTask_2E_weak ("C_canMessageFromTask.weak",
                                                                                    & kTypeDescriptor_GALGAS_AC_5F_canMessage_2E_weak) ;

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * GGS_C_5F_canMessageFromTask_2E_weak::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_C_5F_canMessageFromTask_2E_weak ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GGS_C_5F_canMessageFromTask_2E_weak::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GGS_C_5F_canMessageFromTask_2E_weak (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_C_5F_canMessageFromTask_2E_weak GGS_C_5F_canMessageFromTask_2E_weak::extractObject (const GGS_object & inObject,
                                                                                        Compiler * inCompiler
                                                                                        COMMA_LOCATION_ARGS) {
  GGS_C_5F_canMessageFromTask_2E_weak result ;
  const GGS_C_5F_canMessageFromTask_2E_weak * p = (const GGS_C_5F_canMessageFromTask_2E_weak *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GGS_C_5F_canMessageFromTask_2E_weak *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("C_canMessageFromTask.weak", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//  Map type @M_5F_messages
//--------------------------------------------------------------------------------------------------

#include "GALGAS_GenericMapRoot.h"

//--------------------------------------------------------------------------------------------------

GGS_M_5F_messages::GGS_M_5F_messages (void) :
mSharedRoot () {
}

//--------------------------------------------------------------------------------------------------

GGS_M_5F_messages::~ GGS_M_5F_messages (void) {
}

//--------------------------------------------------------------------------------------------------

GGS_M_5F_messages::GGS_M_5F_messages (const GGS_M_5F_messages & inSource) :
mSharedRoot (inSource.mSharedRoot) {
}

//--------------------------------------------------------------------------------------------------

GGS_M_5F_messages & GGS_M_5F_messages::operator = (const GGS_M_5F_messages & inSource) {
  mSharedRoot = inSource.mSharedRoot ;
  return * this ;
}

//--------------------------------------------------------------------------------------------------

GGS_M_5F_messages GGS_M_5F_messages::init (Compiler * COMMA_LOCATION_ARGS) {
  GGS_M_5F_messages result ;
  result.build (THERE) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_M_5F_messages GGS_M_5F_messages::class_func_emptyMap (LOCATION_ARGS) {
  GGS_M_5F_messages result ;
  result.build (THERE) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_bool GGS_M_5F_messages::getter_hasKey (const GGS_string & inKey
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GGS_bool result ;
  if (isValid () && inKey.isValid ()) {
    result = GGS_bool (mSharedRoot->hasKey (inKey.stringValue (), 0)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_bool GGS_M_5F_messages::getter_hasKeyAtLevel (const GGS_string & inKey,
                                                  const GGS_uint & inLevel
                                                  COMMA_UNUSED_LOCATION_ARGS) const {
  GGS_bool result ;
  if (isValid () && inKey.isValid ()) {
    result = GGS_bool (mSharedRoot->hasKey (inKey.stringValue (), inLevel.uintValue ())) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_uint GGS_M_5F_messages::getter_count (UNUSED_LOCATION_ARGS) const {
  GGS_uint result ;
  if (isValid ()) {
    result = GGS_uint (uint32_t (mSharedRoot->count ())) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_uint GGS_M_5F_messages::getter_levels (UNUSED_LOCATION_ARGS) const {
  GGS_uint result ;
  if (isValid ()) {
    result = GGS_uint (mSharedRoot->levels ()) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_location GGS_M_5F_messages::getter_locationForKey (const GGS_string & inKey,
                                                       Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) const {
  GGS_location result ;
  if (isValid () && inKey.isValid ()) {
    const SharedGenericPtrWithValueSemantics <GGS_M_5F_messages_2E_element> info = infoForKey (inKey.stringValue ()) ;
    if (info.isNil ()) {
      String message = "'locationForKey' map reader run-time error: the '" ;
      message.appendString (inKey.stringValue ()) ;
      message.appendCString ("' does not exist in map") ;
      inCompiler->onTheFlyRunTimeError (message COMMA_THERE) ;
    }else{
      result = info->mProperty_lkey.mProperty_location ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_lstringlist GGS_M_5F_messages::getter_keyList (Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) const {
  GGS_lstringlist result ;
  if (isValid ()) {
    result = GGS_lstringlist::init (inCompiler COMMA_THERE) ;
    mSharedRoot->populateKeyList (result) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

bool GGS_M_5F_messages::isValid (void) const {
  return mSharedRoot.isNotNil () ;
}

//--------------------------------------------------------------------------------------------------

void GGS_M_5F_messages::drop (void)  {
  mSharedRoot.setToNil () ;
}

//--------------------------------------------------------------------------------------------------

void GGS_M_5F_messages::build (LOCATION_ARGS) {
  mSharedRoot = OptionalSharedRef <GenericMapRoot <GGS_M_5F_messages_2E_element>>::make (THERE) ;
}

//--------------------------------------------------------------------------------------------------

void GGS_M_5F_messages::performInsert (const GGS_M_5F_messages_2E_element & inElement,
                                 const char * inInsertErrorMessage,
                                 const char * inShadowErrorMessage,
                                 Compiler * inCompiler
                                 COMMA_LOCATION_ARGS) {
  if (isValid () && inElement.mProperty_lkey.isValid ()) {
    OptionalSharedRef <GenericMapNode <GGS_M_5F_messages_2E_element>> existingNode ;
    const bool allowReplacing = false ;
    mSharedRoot.insulate (THERE) ;
    mSharedRoot->insertOrReplaceInfo (
      inElement,
      allowReplacing,
      existingNode
      COMMA_THERE
    ) ;
    const GGS_lstring lkey = inElement.mProperty_lkey ;
    if (existingNode.isNotNil ()) {
      const GGS_location lstring_existingKey_location = existingNode->mSharedInfo->mProperty_lkey.mProperty_location ;
      inCompiler->semanticErrorWith_K_L_message (lkey, inInsertErrorMessage, lstring_existingKey_location COMMA_THERE) ;
    }else if ((inShadowErrorMessage != nullptr) && (mSharedRoot->overriddenRoot ().isNotNil ())) {
      const auto existingInfo = mSharedRoot->overriddenRoot ()->infoForKey (lkey.mProperty_string.stringValue()) ;
      if (existingInfo.isNotNil ()) {
        const GGS_location lstring_existingKey_location = existingInfo->mProperty_lkey.mProperty_location ;
        inCompiler->semanticErrorWith_K_L_message (lkey, inShadowErrorMessage, lstring_existingKey_location COMMA_THERE) ;
      }
    }
  }
}

//--------------------------------------------------------------------------------------------------

const SharedGenericPtrWithValueSemantics <GGS_M_5F_messages_2E_element>
GGS_M_5F_messages::infoForKey (const String & inKey) const {
  if (mSharedRoot.isNotNil ()) {
    return mSharedRoot->infoForKey (inKey) ;
  }else{
    return SharedGenericPtrWithValueSemantics <GGS_M_5F_messages_2E_element> () ;
  }
}

//--------------------------------------------------------------------------------------------------

int32_t GGS_M_5F_messages::count (void) const  {
  if (mSharedRoot.isNotNil ()) {
    return mSharedRoot->count () ;
  }else{
    return 0 ;
  }
}

//--------------------------------------------------------------------------------------------------

GenericArray <SharedGenericPtrWithValueSemantics <GGS_M_5F_messages_2E_element>>
GGS_M_5F_messages::sortedInfoArray (void) const {
  if (mSharedRoot.isNotNil ()) {
    return mSharedRoot->sortedInfoArray () ;
  }else{
    return GenericArray <SharedGenericPtrWithValueSemantics <GGS_M_5F_messages_2E_element>> () ;
  }
}

//--------------------------------------------------------------------------------------------------

GGS_stringset GGS_M_5F_messages::getter_keySet (Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) const {
  GGS_stringset result ;
  if (isValid ()) {
    result = GGS_stringset::init (inCompiler COMMA_THERE) ;
    mSharedRoot->populateKeySet (result, inCompiler) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

void GGS_M_5F_messages::findNearestKey (const String & inKey,
                                  GenericUniqueArray <String> & outNearestKeyArray) const {
  mSharedRoot->findNearestKey (inKey, outNearestKeyArray) ;
}

//--------------------------------------------------------------------------------------------------

GGS_M_5F_messages_2E_element_3F_ GGS_M_5F_messages
::readSubscript__3F_ (const class GGS_string & inKey,
                      Compiler * /* inCompiler */
                      COMMA_UNUSED_LOCATION_ARGS) const {
  GGS_M_5F_messages_2E_element_3F_ result ;
  if (isValid () && inKey.isValid ()) {
    const SharedGenericPtrWithValueSemantics <GGS_M_5F_messages_2E_element> info = infoForKey (inKey.stringValue ()) ;
    if (info.isNil ()) {
      result = GGS_M_5F_messages_2E_element_3F_::init_nil () ;
    }else{
      GGS_M_5F_messages_2E_element element ;
      element.mProperty_lkey = info->mProperty_lkey ;
      element.mProperty_mIndex = info->mProperty_mIndex ;
      element.mProperty_mClass = info->mProperty_mClass ;
      element.mProperty_mNetworkIndex = info->mProperty_mNetworkIndex ;
      element.mProperty_mBytesCount = info->mProperty_mBytesCount ;
      element.mProperty_mPriority = info->mProperty_mPriority ;
      element.mProperty_mOffset = info->mProperty_mOffset ;
      element.mProperty_mDeadline = info->mProperty_mDeadline ;
      element.mProperty_mPeriod = info->mProperty_mPeriod ;
      element.mProperty_mMessageKind = info->mProperty_mMessageKind ;
      result = element ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_M_5F_messages GGS_M_5F_messages::class_func_mapWithMapToOverride (const GGS_M_5F_messages & inMapToOverride
                                                                      COMMA_LOCATION_ARGS) {
  GGS_M_5F_messages result ;
  if (inMapToOverride.isValid ()) {
    result.mSharedRoot = OptionalSharedRef <GenericMapRoot <GGS_M_5F_messages_2E_element>>::make (inMapToOverride.mSharedRoot COMMA_THERE) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_M_5F_messages GGS_M_5F_messages::getter_overriddenMap (Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) const {
  GGS_M_5F_messages result ;
  if (isValid ()) {
    result.mSharedRoot = mSharedRoot->overriddenRoot () ;
    if (result.mSharedRoot.isNil ()) {
      inCompiler->onTheFlySemanticError ("getter 'overriddenMap': no overriden map" COMMA_THERE) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

void GGS_M_5F_messages::setter_insertKey (GGS_lstring inLKey,
                                          GGS_uint inArgument0,
                                          GGS_luint inArgument1,
                                          GGS_uint inArgument2,
                                          GGS_luint inArgument3,
                                          GGS_luint inArgument4,
                                          GGS_luint inArgument5,
                                          GGS_luint inArgument6,
                                          GGS_luint inArgument7,
                                          GGS_AC_5F_canMessage inArgument8,
                                          Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
  const GGS_M_5F_messages_2E_element element (inLKey, inArgument0, inArgument1, inArgument2, inArgument3, inArgument4, inArgument5, inArgument6, inArgument7, inArgument8) ;
  const char * kInsertErrorMessage = "the CAN message '%K' has been already declared in %L" ;
  const char * kShadowErrorMessage = nullptr ;
  performInsert (element, kInsertErrorMessage, kShadowErrorMessage, inCompiler COMMA_THERE) ;
}

//--------------------------------------------------------------------------------------------------

void GGS_M_5F_messages::method_searchKey (GGS_lstring inLKey,
                                          GGS_uint & outArgument0,
                                          GGS_luint & outArgument1,
                                          GGS_uint & outArgument2,
                                          GGS_luint & outArgument3,
                                          GGS_luint & outArgument4,
                                          GGS_luint & outArgument5,
                                          GGS_luint & outArgument6,
                                          GGS_luint & outArgument7,
                                          GGS_AC_5F_canMessage & outArgument8,
                                          Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) const {
  SharedGenericPtrWithValueSemantics <GGS_M_5F_messages_2E_element> info ;
  if (isValid () && inLKey.isValid ()) {
    const String key = inLKey.mProperty_string.stringValue () ;
    info = infoForKey (key) ;
    if (info.isNil ()) {
      GenericUniqueArray <String> nearestKeyArray ;
      findNearestKey (key, nearestKeyArray) ;
      const char * kSearchErrorMessage = "the CAN message '%K' is not declared" ;
      inCompiler->semanticErrorWith_K_message (inLKey, nearestKeyArray, kSearchErrorMessage COMMA_THERE) ;
    }
  }
  if (info.isNil ()) {
    outArgument0.drop () ;
    outArgument1.drop () ;
    outArgument2.drop () ;
    outArgument3.drop () ;
    outArgument4.drop () ;
    outArgument5.drop () ;
    outArgument6.drop () ;
    outArgument7.drop () ;
    outArgument8.drop () ;
  }else{
    outArgument0 = info->mProperty_mIndex ;
    outArgument1 = info->mProperty_mClass ;
    outArgument2 = info->mProperty_mNetworkIndex ;
    outArgument3 = info->mProperty_mBytesCount ;
    outArgument4 = info->mProperty_mPriority ;
    outArgument5 = info->mProperty_mOffset ;
    outArgument6 = info->mProperty_mDeadline ;
    outArgument7 = info->mProperty_mPeriod ;
    outArgument8 = info->mProperty_mMessageKind ;
  }
}
//--------------------------------------------------------------------------------------------------

GGS_uint GGS_M_5F_messages::getter_mIndexForKey (const GGS_string & inKey,
                                                 Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) const {
  GGS_uint result ;
  if (isValid () && inKey.isValid ()) {
    const String key = inKey.stringValue () ;
    const SharedGenericPtrWithValueSemantics <GGS_M_5F_messages_2E_element> info = infoForKey (key) ;
    if (info.isNil ()) {
      String message = "cannot read property in map: the '" ;
      message.appendString (key) ;
      message.appendCString ("' key does not exist") ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }else{
      result = info->mProperty_mIndex ;
    }
  }
  return result ;
}
//--------------------------------------------------------------------------------------------------

GGS_luint GGS_M_5F_messages::getter_mClassForKey (const GGS_string & inKey,
                                                  Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) const {
  GGS_luint result ;
  if (isValid () && inKey.isValid ()) {
    const String key = inKey.stringValue () ;
    const SharedGenericPtrWithValueSemantics <GGS_M_5F_messages_2E_element> info = infoForKey (key) ;
    if (info.isNil ()) {
      String message = "cannot read property in map: the '" ;
      message.appendString (key) ;
      message.appendCString ("' key does not exist") ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }else{
      result = info->mProperty_mClass ;
    }
  }
  return result ;
}
//--------------------------------------------------------------------------------------------------

GGS_uint GGS_M_5F_messages::getter_mNetworkIndexForKey (const GGS_string & inKey,
                                                        Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) const {
  GGS_uint result ;
  if (isValid () && inKey.isValid ()) {
    const String key = inKey.stringValue () ;
    const SharedGenericPtrWithValueSemantics <GGS_M_5F_messages_2E_element> info = infoForKey (key) ;
    if (info.isNil ()) {
      String message = "cannot read property in map: the '" ;
      message.appendString (key) ;
      message.appendCString ("' key does not exist") ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }else{
      result = info->mProperty_mNetworkIndex ;
    }
  }
  return result ;
}
//--------------------------------------------------------------------------------------------------

GGS_luint GGS_M_5F_messages::getter_mBytesCountForKey (const GGS_string & inKey,
                                                       Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) const {
  GGS_luint result ;
  if (isValid () && inKey.isValid ()) {
    const String key = inKey.stringValue () ;
    const SharedGenericPtrWithValueSemantics <GGS_M_5F_messages_2E_element> info = infoForKey (key) ;
    if (info.isNil ()) {
      String message = "cannot read property in map: the '" ;
      message.appendString (key) ;
      message.appendCString ("' key does not exist") ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }else{
      result = info->mProperty_mBytesCount ;
    }
  }
  return result ;
}
//--------------------------------------------------------------------------------------------------

GGS_luint GGS_M_5F_messages::getter_mPriorityForKey (const GGS_string & inKey,
                                                     Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) const {
  GGS_luint result ;
  if (isValid () && inKey.isValid ()) {
    const String key = inKey.stringValue () ;
    const SharedGenericPtrWithValueSemantics <GGS_M_5F_messages_2E_element> info = infoForKey (key) ;
    if (info.isNil ()) {
      String message = "cannot read property in map: the '" ;
      message.appendString (key) ;
      message.appendCString ("' key does not exist") ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }else{
      result = info->mProperty_mPriority ;
    }
  }
  return result ;
}
//--------------------------------------------------------------------------------------------------

GGS_luint GGS_M_5F_messages::getter_mOffsetForKey (const GGS_string & inKey,
                                                   Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) const {
  GGS_luint result ;
  if (isValid () && inKey.isValid ()) {
    const String key = inKey.stringValue () ;
    const SharedGenericPtrWithValueSemantics <GGS_M_5F_messages_2E_element> info = infoForKey (key) ;
    if (info.isNil ()) {
      String message = "cannot read property in map: the '" ;
      message.appendString (key) ;
      message.appendCString ("' key does not exist") ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }else{
      result = info->mProperty_mOffset ;
    }
  }
  return result ;
}
//--------------------------------------------------------------------------------------------------

GGS_luint GGS_M_5F_messages::getter_mDeadlineForKey (const GGS_string & inKey,
                                                     Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) const {
  GGS_luint result ;
  if (isValid () && inKey.isValid ()) {
    const String key = inKey.stringValue () ;
    const SharedGenericPtrWithValueSemantics <GGS_M_5F_messages_2E_element> info = infoForKey (key) ;
    if (info.isNil ()) {
      String message = "cannot read property in map: the '" ;
      message.appendString (key) ;
      message.appendCString ("' key does not exist") ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }else{
      result = info->mProperty_mDeadline ;
    }
  }
  return result ;
}
//--------------------------------------------------------------------------------------------------

GGS_luint GGS_M_5F_messages::getter_mPeriodForKey (const GGS_string & inKey,
                                                   Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) const {
  GGS_luint result ;
  if (isValid () && inKey.isValid ()) {
    const String key = inKey.stringValue () ;
    const SharedGenericPtrWithValueSemantics <GGS_M_5F_messages_2E_element> info = infoForKey (key) ;
    if (info.isNil ()) {
      String message = "cannot read property in map: the '" ;
      message.appendString (key) ;
      message.appendCString ("' key does not exist") ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }else{
      result = info->mProperty_mPeriod ;
    }
  }
  return result ;
}
//--------------------------------------------------------------------------------------------------

GGS_AC_5F_canMessage GGS_M_5F_messages::getter_mMessageKindForKey (const GGS_string & inKey,
                                                                   Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) const {
  GGS_AC_5F_canMessage result ;
  if (isValid () && inKey.isValid ()) {
    const String key = inKey.stringValue () ;
    const SharedGenericPtrWithValueSemantics <GGS_M_5F_messages_2E_element> info = infoForKey (key) ;
    if (info.isNil ()) {
      String message = "cannot read property in map: the '" ;
      message.appendString (key) ;
      message.appendCString ("' key does not exist") ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }else{
      result = info->mProperty_mMessageKind ;
    }
  }
  return result ;
}
//--------------------------------------------------------------------------------------------------

void GGS_M_5F_messages::setter_setMIndexForKey (GGS_uint inValue,
                                                GGS_string inKey,
                                                Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  if (isValid () && inKey.isValid ()) {
    const String key = inKey.stringValue () ;
    mSharedRoot.insulate (HERE) ;
    OptionalSharedRef <GenericMapNode <GGS_M_5F_messages_2E_element>> node = mSharedRoot->searchNode (key) ;
    if (node.isNil ()) {
      String message = "cannot write property in map: the '" ;
      message.appendString (key) ;
      message.appendCString ("' key does not exist") ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }else{
      node->mSharedInfo->mProperty_mIndex = inValue ;
    }
  }
}
//--------------------------------------------------------------------------------------------------

void GGS_M_5F_messages::setter_setMClassForKey (GGS_luint inValue,
                                                GGS_string inKey,
                                                Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  if (isValid () && inKey.isValid ()) {
    const String key = inKey.stringValue () ;
    mSharedRoot.insulate (HERE) ;
    OptionalSharedRef <GenericMapNode <GGS_M_5F_messages_2E_element>> node = mSharedRoot->searchNode (key) ;
    if (node.isNil ()) {
      String message = "cannot write property in map: the '" ;
      message.appendString (key) ;
      message.appendCString ("' key does not exist") ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }else{
      node->mSharedInfo->mProperty_mClass = inValue ;
    }
  }
}
//--------------------------------------------------------------------------------------------------

void GGS_M_5F_messages::setter_setMNetworkIndexForKey (GGS_uint inValue,
                                                       GGS_string inKey,
                                                       Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) {
  if (isValid () && inKey.isValid ()) {
    const String key = inKey.stringValue () ;
    mSharedRoot.insulate (HERE) ;
    OptionalSharedRef <GenericMapNode <GGS_M_5F_messages_2E_element>> node = mSharedRoot->searchNode (key) ;
    if (node.isNil ()) {
      String message = "cannot write property in map: the '" ;
      message.appendString (key) ;
      message.appendCString ("' key does not exist") ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }else{
      node->mSharedInfo->mProperty_mNetworkIndex = inValue ;
    }
  }
}
//--------------------------------------------------------------------------------------------------

void GGS_M_5F_messages::setter_setMBytesCountForKey (GGS_luint inValue,
                                                     GGS_string inKey,
                                                     Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) {
  if (isValid () && inKey.isValid ()) {
    const String key = inKey.stringValue () ;
    mSharedRoot.insulate (HERE) ;
    OptionalSharedRef <GenericMapNode <GGS_M_5F_messages_2E_element>> node = mSharedRoot->searchNode (key) ;
    if (node.isNil ()) {
      String message = "cannot write property in map: the '" ;
      message.appendString (key) ;
      message.appendCString ("' key does not exist") ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }else{
      node->mSharedInfo->mProperty_mBytesCount = inValue ;
    }
  }
}
//--------------------------------------------------------------------------------------------------

void GGS_M_5F_messages::setter_setMPriorityForKey (GGS_luint inValue,
                                                   GGS_string inKey,
                                                   Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) {
  if (isValid () && inKey.isValid ()) {
    const String key = inKey.stringValue () ;
    mSharedRoot.insulate (HERE) ;
    OptionalSharedRef <GenericMapNode <GGS_M_5F_messages_2E_element>> node = mSharedRoot->searchNode (key) ;
    if (node.isNil ()) {
      String message = "cannot write property in map: the '" ;
      message.appendString (key) ;
      message.appendCString ("' key does not exist") ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }else{
      node->mSharedInfo->mProperty_mPriority = inValue ;
    }
  }
}
//--------------------------------------------------------------------------------------------------

void GGS_M_5F_messages::setter_setMOffsetForKey (GGS_luint inValue,
                                                 GGS_string inKey,
                                                 Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) {
  if (isValid () && inKey.isValid ()) {
    const String key = inKey.stringValue () ;
    mSharedRoot.insulate (HERE) ;
    OptionalSharedRef <GenericMapNode <GGS_M_5F_messages_2E_element>> node = mSharedRoot->searchNode (key) ;
    if (node.isNil ()) {
      String message = "cannot write property in map: the '" ;
      message.appendString (key) ;
      message.appendCString ("' key does not exist") ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }else{
      node->mSharedInfo->mProperty_mOffset = inValue ;
    }
  }
}
//--------------------------------------------------------------------------------------------------

void GGS_M_5F_messages::setter_setMDeadlineForKey (GGS_luint inValue,
                                                   GGS_string inKey,
                                                   Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) {
  if (isValid () && inKey.isValid ()) {
    const String key = inKey.stringValue () ;
    mSharedRoot.insulate (HERE) ;
    OptionalSharedRef <GenericMapNode <GGS_M_5F_messages_2E_element>> node = mSharedRoot->searchNode (key) ;
    if (node.isNil ()) {
      String message = "cannot write property in map: the '" ;
      message.appendString (key) ;
      message.appendCString ("' key does not exist") ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }else{
      node->mSharedInfo->mProperty_mDeadline = inValue ;
    }
  }
}
//--------------------------------------------------------------------------------------------------

void GGS_M_5F_messages::setter_setMPeriodForKey (GGS_luint inValue,
                                                 GGS_string inKey,
                                                 Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) {
  if (isValid () && inKey.isValid ()) {
    const String key = inKey.stringValue () ;
    mSharedRoot.insulate (HERE) ;
    OptionalSharedRef <GenericMapNode <GGS_M_5F_messages_2E_element>> node = mSharedRoot->searchNode (key) ;
    if (node.isNil ()) {
      String message = "cannot write property in map: the '" ;
      message.appendString (key) ;
      message.appendCString ("' key does not exist") ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }else{
      node->mSharedInfo->mProperty_mPeriod = inValue ;
    }
  }
}
//--------------------------------------------------------------------------------------------------

void GGS_M_5F_messages::setter_setMMessageKindForKey (GGS_AC_5F_canMessage inValue,
                                                      GGS_string inKey,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) {
  if (isValid () && inKey.isValid ()) {
    const String key = inKey.stringValue () ;
    mSharedRoot.insulate (HERE) ;
    OptionalSharedRef <GenericMapNode <GGS_M_5F_messages_2E_element>> node = mSharedRoot->searchNode (key) ;
    if (node.isNil ()) {
      String message = "cannot write property in map: the '" ;
      message.appendString (key) ;
      message.appendCString ("' key does not exist") ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }else{
      node->mSharedInfo->mProperty_mMessageKind = inValue ;
    }
  }
}
//--------------------------------------------------------------------------------------------------

static void GGS_M_5F_messages_internalDescription (const GenericArray <SharedGenericPtrWithValueSemantics <GGS_M_5F_messages_2E_element>> & inArray,
                                                        String & ioString,
                                                        const int32_t inIndentation) {
  const int32_t n = inArray.count () ;
  ioString.appendString (" (") ;
  ioString.appendSigned (n) ;
  ioString.appendString (" object") ;
  if (n > 1) {
    ioString.appendString ("s") ;
  }
  ioString.appendString ("):") ;
  for (int32_t i = 0 ; i < n ; i++) {
    ioString.appendNewLine () ;
    ioString.appendStringMultiple ("| ", inIndentation) ;
    ioString.appendString ("|-at ") ;
    ioString.appendSigned (i) ;
    ioString.appendString (": key '") ;
    ioString.appendString (inArray (i COMMA_HERE)->mProperty_lkey.mProperty_string.stringValue ()) ;
    ioString.appendString ("'") ;
    ioString.appendNewLine () ;
    ioString.appendStringMultiple ("| ", inIndentation + 2) ;
    ioString.appendString ("mIndex:") ;
    inArray (i COMMA_HERE)->mProperty_mIndex.description (ioString, inIndentation + 1) ;
    ioString.appendNewLine () ;
    ioString.appendStringMultiple ("| ", inIndentation + 2) ;
    ioString.appendString ("mClass:") ;
    inArray (i COMMA_HERE)->mProperty_mClass.description (ioString, inIndentation + 1) ;
    ioString.appendNewLine () ;
    ioString.appendStringMultiple ("| ", inIndentation + 2) ;
    ioString.appendString ("mNetworkIndex:") ;
    inArray (i COMMA_HERE)->mProperty_mNetworkIndex.description (ioString, inIndentation + 1) ;
    ioString.appendNewLine () ;
    ioString.appendStringMultiple ("| ", inIndentation + 2) ;
    ioString.appendString ("mBytesCount:") ;
    inArray (i COMMA_HERE)->mProperty_mBytesCount.description (ioString, inIndentation + 1) ;
    ioString.appendNewLine () ;
    ioString.appendStringMultiple ("| ", inIndentation + 2) ;
    ioString.appendString ("mPriority:") ;
    inArray (i COMMA_HERE)->mProperty_mPriority.description (ioString, inIndentation + 1) ;
    ioString.appendNewLine () ;
    ioString.appendStringMultiple ("| ", inIndentation + 2) ;
    ioString.appendString ("mOffset:") ;
    inArray (i COMMA_HERE)->mProperty_mOffset.description (ioString, inIndentation + 1) ;
    ioString.appendNewLine () ;
    ioString.appendStringMultiple ("| ", inIndentation + 2) ;
    ioString.appendString ("mDeadline:") ;
    inArray (i COMMA_HERE)->mProperty_mDeadline.description (ioString, inIndentation + 1) ;
    ioString.appendNewLine () ;
    ioString.appendStringMultiple ("| ", inIndentation + 2) ;
    ioString.appendString ("mPeriod:") ;
    inArray (i COMMA_HERE)->mProperty_mPeriod.description (ioString, inIndentation + 1) ;
    ioString.appendNewLine () ;
    ioString.appendStringMultiple ("| ", inIndentation + 2) ;
    ioString.appendString ("mMessageKind:") ;
    inArray (i COMMA_HERE)->mProperty_mMessageKind.description (ioString, inIndentation + 1) ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_M_5F_messages::description (String & ioString,
                                          const int32_t inIndentation) const {
  ioString.appendCString ("<map @") ;
  ioString.appendString (staticTypeDescriptor ()->mGalgasTypeName) ;
  if (isValid ()) {
    const GenericArray <SharedGenericPtrWithValueSemantics <GGS_M_5F_messages_2E_element>> array = sortedInfoArray () ;
    GGS_M_5F_messages_internalDescription (array, ioString, inIndentation) ;
    OptionalSharedRef <GenericMapRoot <GGS_M_5F_messages_2E_element>> subRoot = mSharedRoot->overriddenRoot () ;
    uint32_t idx = 0 ;
    while (subRoot.isNotNil ()) {
     idx += 1 ;
     ioString.appendNewLine () ;
     ioString.appendStringMultiple ("| ", inIndentation + 1) ;
     ioString.appendString (" override #") ;
     ioString.appendUnsigned (idx) ;
     const auto subRootArray = subRoot->sortedInfoArray () ;
     GGS_M_5F_messages_internalDescription (subRootArray, ioString, inIndentation) ;
     subRoot = subRoot->overriddenRoot () ;
    }
  }else{
    ioString.appendCString (" not built") ;
  }
  ioString.appendCString (">") ;
}



//--------------------------------------------------------------------------------------------------
//  Down Enumerator for @M_5F_messages
//--------------------------------------------------------------------------------------------------

DownEnumerator_M_5F_messages::DownEnumerator_M_5F_messages (const GGS_M_5F_messages & inMap) :
mInfoArray (inMap.sortedInfoArray ()),
mIndex (0) {
  mIndex = mInfoArray.count () - 1 ;
}

//--------------------------------------------------------------------------------------------------

GGS_M_5F_messages_2E_element DownEnumerator_M_5F_messages::current (LOCATION_ARGS) const {
  return mInfoArray (mIndex COMMA_THERE).value () ;
}

//--------------------------------------------------------------------------------------------------

GGS_lstring DownEnumerator_M_5F_messages::current_lkey (LOCATION_ARGS) const {
  return mInfoArray (mIndex COMMA_THERE)->mProperty_lkey ;
}

//--------------------------------------------------------------------------------------------------

GGS_uint DownEnumerator_M_5F_messages::current_mIndex (LOCATION_ARGS) const {
  return mInfoArray (mIndex COMMA_THERE)->mProperty_mIndex ;
}

//--------------------------------------------------------------------------------------------------

GGS_luint DownEnumerator_M_5F_messages::current_mClass (LOCATION_ARGS) const {
  return mInfoArray (mIndex COMMA_THERE)->mProperty_mClass ;
}

//--------------------------------------------------------------------------------------------------

GGS_uint DownEnumerator_M_5F_messages::current_mNetworkIndex (LOCATION_ARGS) const {
  return mInfoArray (mIndex COMMA_THERE)->mProperty_mNetworkIndex ;
}

//--------------------------------------------------------------------------------------------------

GGS_luint DownEnumerator_M_5F_messages::current_mBytesCount (LOCATION_ARGS) const {
  return mInfoArray (mIndex COMMA_THERE)->mProperty_mBytesCount ;
}

//--------------------------------------------------------------------------------------------------

GGS_luint DownEnumerator_M_5F_messages::current_mPriority (LOCATION_ARGS) const {
  return mInfoArray (mIndex COMMA_THERE)->mProperty_mPriority ;
}

//--------------------------------------------------------------------------------------------------

GGS_luint DownEnumerator_M_5F_messages::current_mOffset (LOCATION_ARGS) const {
  return mInfoArray (mIndex COMMA_THERE)->mProperty_mOffset ;
}

//--------------------------------------------------------------------------------------------------

GGS_luint DownEnumerator_M_5F_messages::current_mDeadline (LOCATION_ARGS) const {
  return mInfoArray (mIndex COMMA_THERE)->mProperty_mDeadline ;
}

//--------------------------------------------------------------------------------------------------

GGS_luint DownEnumerator_M_5F_messages::current_mPeriod (LOCATION_ARGS) const {
  return mInfoArray (mIndex COMMA_THERE)->mProperty_mPeriod ;
}

//--------------------------------------------------------------------------------------------------

GGS_AC_5F_canMessage DownEnumerator_M_5F_messages::current_mMessageKind (LOCATION_ARGS) const {
  return mInfoArray (mIndex COMMA_THERE)->mProperty_mMessageKind ;
}

//--------------------------------------------------------------------------------------------------
//  Up Enumerator for @M_5F_messages
//--------------------------------------------------------------------------------------------------

UpEnumerator_M_5F_messages::UpEnumerator_M_5F_messages (const GGS_M_5F_messages & inMap) :
mInfoArray (inMap.sortedInfoArray ()),
mIndex (0) {
}

//--------------------------------------------------------------------------------------------------

GGS_M_5F_messages_2E_element UpEnumerator_M_5F_messages::current (LOCATION_ARGS) const {
  return mInfoArray (mIndex COMMA_THERE).value () ;
}

//--------------------------------------------------------------------------------------------------

GGS_lstring UpEnumerator_M_5F_messages::current_lkey (LOCATION_ARGS) const {
  return mInfoArray (mIndex COMMA_THERE)->mProperty_lkey ;
}

//--------------------------------------------------------------------------------------------------

GGS_uint UpEnumerator_M_5F_messages::current_mIndex (LOCATION_ARGS) const {
  return mInfoArray (mIndex COMMA_THERE)->mProperty_mIndex ;
}

//--------------------------------------------------------------------------------------------------

GGS_luint UpEnumerator_M_5F_messages::current_mClass (LOCATION_ARGS) const {
  return mInfoArray (mIndex COMMA_THERE)->mProperty_mClass ;
}

//--------------------------------------------------------------------------------------------------

GGS_uint UpEnumerator_M_5F_messages::current_mNetworkIndex (LOCATION_ARGS) const {
  return mInfoArray (mIndex COMMA_THERE)->mProperty_mNetworkIndex ;
}

//--------------------------------------------------------------------------------------------------

GGS_luint UpEnumerator_M_5F_messages::current_mBytesCount (LOCATION_ARGS) const {
  return mInfoArray (mIndex COMMA_THERE)->mProperty_mBytesCount ;
}

//--------------------------------------------------------------------------------------------------

GGS_luint UpEnumerator_M_5F_messages::current_mPriority (LOCATION_ARGS) const {
  return mInfoArray (mIndex COMMA_THERE)->mProperty_mPriority ;
}

//--------------------------------------------------------------------------------------------------

GGS_luint UpEnumerator_M_5F_messages::current_mOffset (LOCATION_ARGS) const {
  return mInfoArray (mIndex COMMA_THERE)->mProperty_mOffset ;
}

//--------------------------------------------------------------------------------------------------

GGS_luint UpEnumerator_M_5F_messages::current_mDeadline (LOCATION_ARGS) const {
  return mInfoArray (mIndex COMMA_THERE)->mProperty_mDeadline ;
}

//--------------------------------------------------------------------------------------------------

GGS_luint UpEnumerator_M_5F_messages::current_mPeriod (LOCATION_ARGS) const {
  return mInfoArray (mIndex COMMA_THERE)->mProperty_mPeriod ;
}

//--------------------------------------------------------------------------------------------------

GGS_AC_5F_canMessage UpEnumerator_M_5F_messages::current_mMessageKind (LOCATION_ARGS) const {
  return mInfoArray (mIndex COMMA_THERE)->mProperty_mMessageKind ;
}


//--------------------------------------------------------------------------------------------------
//     @M_messages generic code implementation
//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor kTypeDescriptor_GALGAS_M_5F_messages ("M_messages",
                                                                  nullptr) ;

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * GGS_M_5F_messages::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_M_5F_messages ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GGS_M_5F_messages::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GGS_M_5F_messages (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_M_5F_messages GGS_M_5F_messages::extractObject (const GGS_object & inObject,
                                                    Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  GGS_M_5F_messages result ;
  const GGS_M_5F_messages * p = (const GGS_M_5F_messages *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GGS_M_5F_messages *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("M_messages", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
// @AC_5F_task reference class
//--------------------------------------------------------------------------------------------------

ComparisonResult GGS_AC_5F_task::objectCompare (const GGS_AC_5F_task & inOperand) const {
  ComparisonResult result = ComparisonResult::invalid ;
  if (isValid () && inOperand.isValid ()) {
    const size_t myObjectPtr = size_t (mObjectPtr) ;
    const size_t operandObjectPtr = size_t (inOperand.mObjectPtr) ;
    if (myObjectPtr < operandObjectPtr) {
      result = ComparisonResult::firstOperandLowerThanSecond ;
    }else if (myObjectPtr > operandObjectPtr) {
      result = ComparisonResult::firstOperandGreaterThanSecond ;
    }else{
      result = ComparisonResult::operandEqual ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_AC_5F_task::GGS_AC_5F_task (void) :
AC_GALGAS_reference_class () {
}


void cPtr_AC_5F_task::
AC_5F_task_init (Compiler * /* inCompiler */) {
}

//--------------------------------------------------------------------------------------------------

GGS_AC_5F_task::GGS_AC_5F_task (const cPtr_AC_5F_task * inSourcePtr) :
AC_GALGAS_reference_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_AC_5F_task) ;
}
//--------------------------------------------------------------------------------------------------
//Pointer class for @AC_task class
//--------------------------------------------------------------------------------------------------


//--------------------------------------------------------------------------------------------------

cPtr_AC_5F_task::cPtr_AC_5F_task (Compiler * inCompiler
                                  COMMA_LOCATION_ARGS) :
acStrongPtr_class (inCompiler COMMA_THERE) {
}


//--------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  void cPtr_AC_5F_task::printNonNullClassInstanceProperties (void) const {
    acStrongPtr_class::printNonNullClassInstanceProperties () ;
  }
#endif

//--------------------------------------------------------------------------------------------------
//     @AC_task generic code implementation
//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor kTypeDescriptor_GALGAS_AC_5F_task ("AC_task",
                                                               nullptr) ;

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * GGS_AC_5F_task::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_AC_5F_task ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GGS_AC_5F_task::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GGS_AC_5F_task (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_AC_5F_task GGS_AC_5F_task::extractObject (const GGS_object & inObject,
                                              Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  GGS_AC_5F_task result ;
  const GGS_AC_5F_task * p = (const GGS_AC_5F_task *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GGS_AC_5F_task *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("AC_task", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

ComparisonResult GGS_AC_5F_task_2E_weak::objectCompare (const GGS_AC_5F_task_2E_weak & inOperand) const {
  ComparisonResult result = ComparisonResult::invalid ;
  if (isValid () && inOperand.isValid ()) {
    cPtr_weakReference_proxy * myPtr = mProxyPtr ;
    const size_t myObjectPtr = size_t (myPtr) ;
    cPtr_weakReference_proxy * operandPtr = inOperand.mProxyPtr ;
    const size_t operandObjectPtr = size_t (operandPtr) ;
    if (myObjectPtr < operandObjectPtr) {
      result = ComparisonResult::firstOperandLowerThanSecond ;
    }else if (myObjectPtr > operandObjectPtr) {
      result = ComparisonResult::firstOperandGreaterThanSecond ;
    }else{
      result = ComparisonResult::operandEqual ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_AC_5F_task_2E_weak::GGS_AC_5F_task_2E_weak (void) :
AC_GALGAS_weak_reference () {
}

//--------------------------------------------------------------------------------------------------

GGS_AC_5F_task_2E_weak & GGS_AC_5F_task_2E_weak::operator = (const GGS_AC_5F_task & inSource) {
  cPtr_weakReference_proxy * proxyPtr = nullptr ;
  acStrongPtr_class * p = (acStrongPtr_class *) inSource.ptr () ;
  if (p != nullptr) {
    proxyPtr = p->getProxy () ;
  }
  macroAssignSharedObject (mProxyPtr, proxyPtr) ;
  return *this ;
}

//--------------------------------------------------------------------------------------------------

GGS_AC_5F_task_2E_weak::GGS_AC_5F_task_2E_weak (const GGS_AC_5F_task & inSource) :
AC_GALGAS_weak_reference (inSource) {
}


//--------------------------------------------------------------------------------------------------

GGS_AC_5F_task_2E_weak GGS_AC_5F_task_2E_weak::class_func_nil (LOCATION_ARGS) {
  GGS_AC_5F_task_2E_weak result ;
  macroMyNew (result.mProxyPtr, cPtr_weakReference_proxy (THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_AC_5F_task GGS_AC_5F_task_2E_weak::unwrappedValue (void) const {
  GGS_AC_5F_task result ;
  if (isValid ()) {
    const cPtr_AC_5F_task * p = (cPtr_AC_5F_task *) ptr () ;
    if (nullptr != p) {
      result = GGS_AC_5F_task (p) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_AC_5F_task GGS_AC_5F_task_2E_weak::bang_AC_5F_task_2E_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const {
  GGS_AC_5F_task result ;
  if (mProxyPtr != nullptr) {
    acStrongPtr_class * strongPtr = mProxyPtr->strongObject () ;
    if (strongPtr == nullptr) {
      inCompiler->onTheFlySemanticError ("weak reference is nil" COMMA_THERE) ;
    }else{
      macroValidSharedObject (strongPtr, cPtr_AC_5F_task) ;
      result = GGS_AC_5F_task ((cPtr_AC_5F_task *) strongPtr) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//     @AC_task.weak generic code implementation
//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor kTypeDescriptor_GALGAS_AC_5F_task_2E_weak ("AC_task.weak",
                                                                       nullptr) ;

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * GGS_AC_5F_task_2E_weak::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_AC_5F_task_2E_weak ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GGS_AC_5F_task_2E_weak::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GGS_AC_5F_task_2E_weak (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_AC_5F_task_2E_weak GGS_AC_5F_task_2E_weak::extractObject (const GGS_object & inObject,
                                                              Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) {
  GGS_AC_5F_task_2E_weak result ;
  const GGS_AC_5F_task_2E_weak * p = (const GGS_AC_5F_task_2E_weak *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GGS_AC_5F_task_2E_weak *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("AC_task.weak", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
// @C_5F_independantTask reference class
//--------------------------------------------------------------------------------------------------

ComparisonResult GGS_C_5F_independantTask::objectCompare (const GGS_C_5F_independantTask & inOperand) const {
  ComparisonResult result = ComparisonResult::invalid ;
  if (isValid () && inOperand.isValid ()) {
    const size_t myObjectPtr = size_t (mObjectPtr) ;
    const size_t operandObjectPtr = size_t (inOperand.mObjectPtr) ;
    if (myObjectPtr < operandObjectPtr) {
      result = ComparisonResult::firstOperandLowerThanSecond ;
    }else if (myObjectPtr > operandObjectPtr) {
      result = ComparisonResult::firstOperandGreaterThanSecond ;
    }else{
      result = ComparisonResult::operandEqual ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_C_5F_independantTask::GGS_C_5F_independantTask (void) :
GGS_AC_5F_task () {
}

//--- Synthetized initializer ----------------------------------------------------------------------

GGS_C_5F_independantTask GGS_C_5F_independantTask::
init (Compiler * inCompiler
          COMMA_LOCATION_ARGS) {
  cPtr_C_5F_independantTask * object = nullptr ;
  macroMyNew (object, cPtr_C_5F_independantTask (inCompiler COMMA_THERE)) ;
  object->C_5F_independantTask_init (inCompiler) ;
  const GGS_C_5F_independantTask result (object) ;
  macroDetachSharedObject (object) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

void cPtr_C_5F_independantTask::
C_5F_independantTask_init (Compiler * /* inCompiler */) {
}

//--------------------------------------------------------------------------------------------------

GGS_C_5F_independantTask::GGS_C_5F_independantTask (const cPtr_C_5F_independantTask * inSourcePtr) :
GGS_AC_5F_task (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_C_5F_independantTask) ;
}
//--------------------------------------------------------------------------------------------------

GGS_C_5F_independantTask GGS_C_5F_independantTask::class_func_new (Compiler * inCompiler COMMA_LOCATION_ARGS) {
  GGS_C_5F_independantTask result ;
  macroMyNew (result.mObjectPtr, cPtr_C_5F_independantTask (inCompiler COMMA_THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------
//Pointer class for @C_independantTask class
//--------------------------------------------------------------------------------------------------


//--------------------------------------------------------------------------------------------------

cPtr_C_5F_independantTask::cPtr_C_5F_independantTask (Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) :
cPtr_AC_5F_task (inCompiler COMMA_THERE) {
}

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * cPtr_C_5F_independantTask::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_C_5F_independantTask ;
}

void cPtr_C_5F_independantTask::description (String & ioString,
                                             const int32_t /* inIndentation */) const {
  ioString.appendCString ("[@C_independantTask]") ;
}

//--------------------------------------------------------------------------------------------------

acPtr_class * cPtr_C_5F_independantTask::duplicate (Compiler * inCompiler COMMA_LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_C_5F_independantTask (inCompiler COMMA_THERE)) ;
  return ptr ;
}


//--------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  void cPtr_C_5F_independantTask::printNonNullClassInstanceProperties (void) const {
    cPtr_AC_5F_task::printNonNullClassInstanceProperties () ;
  }
#endif

//--------------------------------------------------------------------------------------------------
//     @C_independantTask generic code implementation
//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor kTypeDescriptor_GALGAS_C_5F_independantTask ("C_independantTask",
                                                                         & kTypeDescriptor_GALGAS_AC_5F_task) ;

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * GGS_C_5F_independantTask::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_C_5F_independantTask ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GGS_C_5F_independantTask::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GGS_C_5F_independantTask (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_C_5F_independantTask GGS_C_5F_independantTask::extractObject (const GGS_object & inObject,
                                                                  Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) {
  GGS_C_5F_independantTask result ;
  const GGS_C_5F_independantTask * p = (const GGS_C_5F_independantTask *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GGS_C_5F_independantTask *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("C_independantTask", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

ComparisonResult GGS_C_5F_independantTask_2E_weak::objectCompare (const GGS_C_5F_independantTask_2E_weak & inOperand) const {
  ComparisonResult result = ComparisonResult::invalid ;
  if (isValid () && inOperand.isValid ()) {
    cPtr_weakReference_proxy * myPtr = mProxyPtr ;
    const size_t myObjectPtr = size_t (myPtr) ;
    cPtr_weakReference_proxy * operandPtr = inOperand.mProxyPtr ;
    const size_t operandObjectPtr = size_t (operandPtr) ;
    if (myObjectPtr < operandObjectPtr) {
      result = ComparisonResult::firstOperandLowerThanSecond ;
    }else if (myObjectPtr > operandObjectPtr) {
      result = ComparisonResult::firstOperandGreaterThanSecond ;
    }else{
      result = ComparisonResult::operandEqual ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_C_5F_independantTask_2E_weak::GGS_C_5F_independantTask_2E_weak (void) :
GGS_AC_5F_task_2E_weak () {
}

//--------------------------------------------------------------------------------------------------

GGS_C_5F_independantTask_2E_weak & GGS_C_5F_independantTask_2E_weak::operator = (const GGS_C_5F_independantTask & inSource) {
  cPtr_weakReference_proxy * proxyPtr = nullptr ;
  acStrongPtr_class * p = (acStrongPtr_class *) inSource.ptr () ;
  if (p != nullptr) {
    proxyPtr = p->getProxy () ;
  }
  macroAssignSharedObject (mProxyPtr, proxyPtr) ;
  return *this ;
}

//--------------------------------------------------------------------------------------------------

GGS_C_5F_independantTask_2E_weak::GGS_C_5F_independantTask_2E_weak (const GGS_C_5F_independantTask & inSource) :
GGS_AC_5F_task_2E_weak (inSource) {
}


//--------------------------------------------------------------------------------------------------

GGS_C_5F_independantTask_2E_weak GGS_C_5F_independantTask_2E_weak::class_func_nil (LOCATION_ARGS) {
  GGS_C_5F_independantTask_2E_weak result ;
  macroMyNew (result.mProxyPtr, cPtr_weakReference_proxy (THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_C_5F_independantTask GGS_C_5F_independantTask_2E_weak::unwrappedValue (void) const {
  GGS_C_5F_independantTask result ;
  if (isValid ()) {
    const cPtr_C_5F_independantTask * p = (cPtr_C_5F_independantTask *) ptr () ;
    if (nullptr != p) {
      result = GGS_C_5F_independantTask (p) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_C_5F_independantTask GGS_C_5F_independantTask_2E_weak::bang_C_5F_independantTask_2E_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const {
  GGS_C_5F_independantTask result ;
  if (mProxyPtr != nullptr) {
    acStrongPtr_class * strongPtr = mProxyPtr->strongObject () ;
    if (strongPtr == nullptr) {
      inCompiler->onTheFlySemanticError ("weak reference is nil" COMMA_THERE) ;
    }else{
      macroValidSharedObject (strongPtr, cPtr_C_5F_independantTask) ;
      result = GGS_C_5F_independantTask ((cPtr_C_5F_independantTask *) strongPtr) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//     @C_independantTask.weak generic code implementation
//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor kTypeDescriptor_GALGAS_C_5F_independantTask_2E_weak ("C_independantTask.weak",
                                                                                 & kTypeDescriptor_GALGAS_AC_5F_task_2E_weak) ;

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * GGS_C_5F_independantTask_2E_weak::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_C_5F_independantTask_2E_weak ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GGS_C_5F_independantTask_2E_weak::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GGS_C_5F_independantTask_2E_weak (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_C_5F_independantTask_2E_weak GGS_C_5F_independantTask_2E_weak::extractObject (const GGS_object & inObject,
                                                                                  Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) {
  GGS_C_5F_independantTask_2E_weak result ;
  const GGS_C_5F_independantTask_2E_weak * p = (const GGS_C_5F_independantTask_2E_weak *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GGS_C_5F_independantTask_2E_weak *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("C_independantTask.weak", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

ComparisonResult GGS_C_5F_taskDependsFromTask_2E_weak::objectCompare (const GGS_C_5F_taskDependsFromTask_2E_weak & inOperand) const {
  ComparisonResult result = ComparisonResult::invalid ;
  if (isValid () && inOperand.isValid ()) {
    cPtr_weakReference_proxy * myPtr = mProxyPtr ;
    const size_t myObjectPtr = size_t (myPtr) ;
    cPtr_weakReference_proxy * operandPtr = inOperand.mProxyPtr ;
    const size_t operandObjectPtr = size_t (operandPtr) ;
    if (myObjectPtr < operandObjectPtr) {
      result = ComparisonResult::firstOperandLowerThanSecond ;
    }else if (myObjectPtr > operandObjectPtr) {
      result = ComparisonResult::firstOperandGreaterThanSecond ;
    }else{
      result = ComparisonResult::operandEqual ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_C_5F_taskDependsFromTask_2E_weak::GGS_C_5F_taskDependsFromTask_2E_weak (void) :
GGS_AC_5F_task_2E_weak () {
}

//--------------------------------------------------------------------------------------------------

GGS_C_5F_taskDependsFromTask_2E_weak & GGS_C_5F_taskDependsFromTask_2E_weak::operator = (const GGS_C_5F_taskDependsFromTask & inSource) {
  cPtr_weakReference_proxy * proxyPtr = nullptr ;
  acStrongPtr_class * p = (acStrongPtr_class *) inSource.ptr () ;
  if (p != nullptr) {
    proxyPtr = p->getProxy () ;
  }
  macroAssignSharedObject (mProxyPtr, proxyPtr) ;
  return *this ;
}

//--------------------------------------------------------------------------------------------------

GGS_C_5F_taskDependsFromTask_2E_weak::GGS_C_5F_taskDependsFromTask_2E_weak (const GGS_C_5F_taskDependsFromTask & inSource) :
GGS_AC_5F_task_2E_weak (inSource) {
}


//--------------------------------------------------------------------------------------------------

GGS_C_5F_taskDependsFromTask_2E_weak GGS_C_5F_taskDependsFromTask_2E_weak::class_func_nil (LOCATION_ARGS) {
  GGS_C_5F_taskDependsFromTask_2E_weak result ;
  macroMyNew (result.mProxyPtr, cPtr_weakReference_proxy (THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_C_5F_taskDependsFromTask GGS_C_5F_taskDependsFromTask_2E_weak::unwrappedValue (void) const {
  GGS_C_5F_taskDependsFromTask result ;
  if (isValid ()) {
    const cPtr_C_5F_taskDependsFromTask * p = (cPtr_C_5F_taskDependsFromTask *) ptr () ;
    if (nullptr != p) {
      result = GGS_C_5F_taskDependsFromTask (p) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_C_5F_taskDependsFromTask GGS_C_5F_taskDependsFromTask_2E_weak::bang_C_5F_taskDependsFromTask_2E_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const {
  GGS_C_5F_taskDependsFromTask result ;
  if (mProxyPtr != nullptr) {
    acStrongPtr_class * strongPtr = mProxyPtr->strongObject () ;
    if (strongPtr == nullptr) {
      inCompiler->onTheFlySemanticError ("weak reference is nil" COMMA_THERE) ;
    }else{
      macroValidSharedObject (strongPtr, cPtr_C_5F_taskDependsFromTask) ;
      result = GGS_C_5F_taskDependsFromTask ((cPtr_C_5F_taskDependsFromTask *) strongPtr) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//     @C_taskDependsFromTask.weak generic code implementation
//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor kTypeDescriptor_GALGAS_C_5F_taskDependsFromTask_2E_weak ("C_taskDependsFromTask.weak",
                                                                                     & kTypeDescriptor_GALGAS_AC_5F_task_2E_weak) ;

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * GGS_C_5F_taskDependsFromTask_2E_weak::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_C_5F_taskDependsFromTask_2E_weak ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GGS_C_5F_taskDependsFromTask_2E_weak::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GGS_C_5F_taskDependsFromTask_2E_weak (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_C_5F_taskDependsFromTask_2E_weak GGS_C_5F_taskDependsFromTask_2E_weak::extractObject (const GGS_object & inObject,
                                                                                          Compiler * inCompiler
                                                                                          COMMA_LOCATION_ARGS) {
  GGS_C_5F_taskDependsFromTask_2E_weak result ;
  const GGS_C_5F_taskDependsFromTask_2E_weak * p = (const GGS_C_5F_taskDependsFromTask_2E_weak *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GGS_C_5F_taskDependsFromTask_2E_weak *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("C_taskDependsFromTask.weak", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

ComparisonResult GGS_C_5F_taskDependsFromMessage_2E_weak::objectCompare (const GGS_C_5F_taskDependsFromMessage_2E_weak & inOperand) const {
  ComparisonResult result = ComparisonResult::invalid ;
  if (isValid () && inOperand.isValid ()) {
    cPtr_weakReference_proxy * myPtr = mProxyPtr ;
    const size_t myObjectPtr = size_t (myPtr) ;
    cPtr_weakReference_proxy * operandPtr = inOperand.mProxyPtr ;
    const size_t operandObjectPtr = size_t (operandPtr) ;
    if (myObjectPtr < operandObjectPtr) {
      result = ComparisonResult::firstOperandLowerThanSecond ;
    }else if (myObjectPtr > operandObjectPtr) {
      result = ComparisonResult::firstOperandGreaterThanSecond ;
    }else{
      result = ComparisonResult::operandEqual ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_C_5F_taskDependsFromMessage_2E_weak::GGS_C_5F_taskDependsFromMessage_2E_weak (void) :
GGS_AC_5F_task_2E_weak () {
}

//--------------------------------------------------------------------------------------------------

GGS_C_5F_taskDependsFromMessage_2E_weak & GGS_C_5F_taskDependsFromMessage_2E_weak::operator = (const GGS_C_5F_taskDependsFromMessage & inSource) {
  cPtr_weakReference_proxy * proxyPtr = nullptr ;
  acStrongPtr_class * p = (acStrongPtr_class *) inSource.ptr () ;
  if (p != nullptr) {
    proxyPtr = p->getProxy () ;
  }
  macroAssignSharedObject (mProxyPtr, proxyPtr) ;
  return *this ;
}

//--------------------------------------------------------------------------------------------------

GGS_C_5F_taskDependsFromMessage_2E_weak::GGS_C_5F_taskDependsFromMessage_2E_weak (const GGS_C_5F_taskDependsFromMessage & inSource) :
GGS_AC_5F_task_2E_weak (inSource) {
}


//--------------------------------------------------------------------------------------------------

GGS_C_5F_taskDependsFromMessage_2E_weak GGS_C_5F_taskDependsFromMessage_2E_weak::class_func_nil (LOCATION_ARGS) {
  GGS_C_5F_taskDependsFromMessage_2E_weak result ;
  macroMyNew (result.mProxyPtr, cPtr_weakReference_proxy (THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_C_5F_taskDependsFromMessage GGS_C_5F_taskDependsFromMessage_2E_weak::unwrappedValue (void) const {
  GGS_C_5F_taskDependsFromMessage result ;
  if (isValid ()) {
    const cPtr_C_5F_taskDependsFromMessage * p = (cPtr_C_5F_taskDependsFromMessage *) ptr () ;
    if (nullptr != p) {
      result = GGS_C_5F_taskDependsFromMessage (p) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_C_5F_taskDependsFromMessage GGS_C_5F_taskDependsFromMessage_2E_weak::bang_C_5F_taskDependsFromMessage_2E_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const {
  GGS_C_5F_taskDependsFromMessage result ;
  if (mProxyPtr != nullptr) {
    acStrongPtr_class * strongPtr = mProxyPtr->strongObject () ;
    if (strongPtr == nullptr) {
      inCompiler->onTheFlySemanticError ("weak reference is nil" COMMA_THERE) ;
    }else{
      macroValidSharedObject (strongPtr, cPtr_C_5F_taskDependsFromMessage) ;
      result = GGS_C_5F_taskDependsFromMessage ((cPtr_C_5F_taskDependsFromMessage *) strongPtr) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//     @C_taskDependsFromMessage.weak generic code implementation
//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor kTypeDescriptor_GALGAS_C_5F_taskDependsFromMessage_2E_weak ("C_taskDependsFromMessage.weak",
                                                                                        & kTypeDescriptor_GALGAS_AC_5F_task_2E_weak) ;

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * GGS_C_5F_taskDependsFromMessage_2E_weak::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_C_5F_taskDependsFromMessage_2E_weak ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GGS_C_5F_taskDependsFromMessage_2E_weak::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GGS_C_5F_taskDependsFromMessage_2E_weak (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_C_5F_taskDependsFromMessage_2E_weak GGS_C_5F_taskDependsFromMessage_2E_weak::extractObject (const GGS_object & inObject,
                                                                                                Compiler * inCompiler
                                                                                                COMMA_LOCATION_ARGS) {
  GGS_C_5F_taskDependsFromMessage_2E_weak result ;
  const GGS_C_5F_taskDependsFromMessage_2E_weak * p = (const GGS_C_5F_taskDependsFromMessage_2E_weak *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GGS_C_5F_taskDependsFromMessage_2E_weak *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("C_taskDependsFromMessage.weak", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//  Map type @M_5F_tasks
//--------------------------------------------------------------------------------------------------

#include "GALGAS_GenericMapRoot.h"

//--------------------------------------------------------------------------------------------------

GGS_M_5F_tasks::GGS_M_5F_tasks (void) :
mSharedRoot () {
}

//--------------------------------------------------------------------------------------------------

GGS_M_5F_tasks::~ GGS_M_5F_tasks (void) {
}

//--------------------------------------------------------------------------------------------------

GGS_M_5F_tasks::GGS_M_5F_tasks (const GGS_M_5F_tasks & inSource) :
mSharedRoot (inSource.mSharedRoot) {
}

//--------------------------------------------------------------------------------------------------

GGS_M_5F_tasks & GGS_M_5F_tasks::operator = (const GGS_M_5F_tasks & inSource) {
  mSharedRoot = inSource.mSharedRoot ;
  return * this ;
}

//--------------------------------------------------------------------------------------------------

GGS_M_5F_tasks GGS_M_5F_tasks::init (Compiler * COMMA_LOCATION_ARGS) {
  GGS_M_5F_tasks result ;
  result.build (THERE) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_M_5F_tasks GGS_M_5F_tasks::class_func_emptyMap (LOCATION_ARGS) {
  GGS_M_5F_tasks result ;
  result.build (THERE) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_bool GGS_M_5F_tasks::getter_hasKey (const GGS_string & inKey
                                        COMMA_UNUSED_LOCATION_ARGS) const {
  GGS_bool result ;
  if (isValid () && inKey.isValid ()) {
    result = GGS_bool (mSharedRoot->hasKey (inKey.stringValue (), 0)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_bool GGS_M_5F_tasks::getter_hasKeyAtLevel (const GGS_string & inKey,
                                               const GGS_uint & inLevel
                                               COMMA_UNUSED_LOCATION_ARGS) const {
  GGS_bool result ;
  if (isValid () && inKey.isValid ()) {
    result = GGS_bool (mSharedRoot->hasKey (inKey.stringValue (), inLevel.uintValue ())) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_uint GGS_M_5F_tasks::getter_count (UNUSED_LOCATION_ARGS) const {
  GGS_uint result ;
  if (isValid ()) {
    result = GGS_uint (uint32_t (mSharedRoot->count ())) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_uint GGS_M_5F_tasks::getter_levels (UNUSED_LOCATION_ARGS) const {
  GGS_uint result ;
  if (isValid ()) {
    result = GGS_uint (mSharedRoot->levels ()) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_location GGS_M_5F_tasks::getter_locationForKey (const GGS_string & inKey,
                                                    Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) const {
  GGS_location result ;
  if (isValid () && inKey.isValid ()) {
    const SharedGenericPtrWithValueSemantics <GGS_M_5F_tasks_2E_element> info = infoForKey (inKey.stringValue ()) ;
    if (info.isNil ()) {
      String message = "'locationForKey' map reader run-time error: the '" ;
      message.appendString (inKey.stringValue ()) ;
      message.appendCString ("' does not exist in map") ;
      inCompiler->onTheFlyRunTimeError (message COMMA_THERE) ;
    }else{
      result = info->mProperty_lkey.mProperty_location ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_lstringlist GGS_M_5F_tasks::getter_keyList (Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) const {
  GGS_lstringlist result ;
  if (isValid ()) {
    result = GGS_lstringlist::init (inCompiler COMMA_THERE) ;
    mSharedRoot->populateKeyList (result) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

bool GGS_M_5F_tasks::isValid (void) const {
  return mSharedRoot.isNotNil () ;
}

//--------------------------------------------------------------------------------------------------

void GGS_M_5F_tasks::drop (void)  {
  mSharedRoot.setToNil () ;
}

//--------------------------------------------------------------------------------------------------

void GGS_M_5F_tasks::build (LOCATION_ARGS) {
  mSharedRoot = OptionalSharedRef <GenericMapRoot <GGS_M_5F_tasks_2E_element>>::make (THERE) ;
}

//--------------------------------------------------------------------------------------------------

void GGS_M_5F_tasks::performInsert (const GGS_M_5F_tasks_2E_element & inElement,
                                 const char * inInsertErrorMessage,
                                 const char * inShadowErrorMessage,
                                 Compiler * inCompiler
                                 COMMA_LOCATION_ARGS) {
  if (isValid () && inElement.mProperty_lkey.isValid ()) {
    OptionalSharedRef <GenericMapNode <GGS_M_5F_tasks_2E_element>> existingNode ;
    const bool allowReplacing = false ;
    mSharedRoot.insulate (THERE) ;
    mSharedRoot->insertOrReplaceInfo (
      inElement,
      allowReplacing,
      existingNode
      COMMA_THERE
    ) ;
    const GGS_lstring lkey = inElement.mProperty_lkey ;
    if (existingNode.isNotNil ()) {
      const GGS_location lstring_existingKey_location = existingNode->mSharedInfo->mProperty_lkey.mProperty_location ;
      inCompiler->semanticErrorWith_K_L_message (lkey, inInsertErrorMessage, lstring_existingKey_location COMMA_THERE) ;
    }else if ((inShadowErrorMessage != nullptr) && (mSharedRoot->overriddenRoot ().isNotNil ())) {
      const auto existingInfo = mSharedRoot->overriddenRoot ()->infoForKey (lkey.mProperty_string.stringValue()) ;
      if (existingInfo.isNotNil ()) {
        const GGS_location lstring_existingKey_location = existingInfo->mProperty_lkey.mProperty_location ;
        inCompiler->semanticErrorWith_K_L_message (lkey, inShadowErrorMessage, lstring_existingKey_location COMMA_THERE) ;
      }
    }
  }
}

//--------------------------------------------------------------------------------------------------

const SharedGenericPtrWithValueSemantics <GGS_M_5F_tasks_2E_element>
GGS_M_5F_tasks::infoForKey (const String & inKey) const {
  if (mSharedRoot.isNotNil ()) {
    return mSharedRoot->infoForKey (inKey) ;
  }else{
    return SharedGenericPtrWithValueSemantics <GGS_M_5F_tasks_2E_element> () ;
  }
}

//--------------------------------------------------------------------------------------------------

int32_t GGS_M_5F_tasks::count (void) const  {
  if (mSharedRoot.isNotNil ()) {
    return mSharedRoot->count () ;
  }else{
    return 0 ;
  }
}

//--------------------------------------------------------------------------------------------------

GenericArray <SharedGenericPtrWithValueSemantics <GGS_M_5F_tasks_2E_element>>
GGS_M_5F_tasks::sortedInfoArray (void) const {
  if (mSharedRoot.isNotNil ()) {
    return mSharedRoot->sortedInfoArray () ;
  }else{
    return GenericArray <SharedGenericPtrWithValueSemantics <GGS_M_5F_tasks_2E_element>> () ;
  }
}

//--------------------------------------------------------------------------------------------------

GGS_stringset GGS_M_5F_tasks::getter_keySet (Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) const {
  GGS_stringset result ;
  if (isValid ()) {
    result = GGS_stringset::init (inCompiler COMMA_THERE) ;
    mSharedRoot->populateKeySet (result, inCompiler) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

void GGS_M_5F_tasks::findNearestKey (const String & inKey,
                                  GenericUniqueArray <String> & outNearestKeyArray) const {
  mSharedRoot->findNearestKey (inKey, outNearestKeyArray) ;
}

//--------------------------------------------------------------------------------------------------

GGS_M_5F_tasks_2E_element_3F_ GGS_M_5F_tasks
::readSubscript__3F_ (const class GGS_string & inKey,
                      Compiler * /* inCompiler */
                      COMMA_UNUSED_LOCATION_ARGS) const {
  GGS_M_5F_tasks_2E_element_3F_ result ;
  if (isValid () && inKey.isValid ()) {
    const SharedGenericPtrWithValueSemantics <GGS_M_5F_tasks_2E_element> info = infoForKey (inKey.stringValue ()) ;
    if (info.isNil ()) {
      result = GGS_M_5F_tasks_2E_element_3F_::init_nil () ;
    }else{
      GGS_M_5F_tasks_2E_element element ;
      element.mProperty_lkey = info->mProperty_lkey ;
      element.mProperty_mIndex = info->mProperty_mIndex ;
      element.mProperty_mPriority = info->mProperty_mPriority ;
      element.mProperty_mOffset = info->mProperty_mOffset ;
      element.mProperty_mDeadline = info->mProperty_mDeadline ;
      element.mProperty_mDurationMin = info->mProperty_mDurationMin ;
      element.mProperty_mDurationMax = info->mProperty_mDurationMax ;
      element.mProperty_mProcessor = info->mProperty_mProcessor ;
      element.mProperty_mPeriod = info->mProperty_mPeriod ;
      element.mProperty_mTaskKind = info->mProperty_mTaskKind ;
      result = element ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_M_5F_tasks GGS_M_5F_tasks::class_func_mapWithMapToOverride (const GGS_M_5F_tasks & inMapToOverride
                                                                COMMA_LOCATION_ARGS) {
  GGS_M_5F_tasks result ;
  if (inMapToOverride.isValid ()) {
    result.mSharedRoot = OptionalSharedRef <GenericMapRoot <GGS_M_5F_tasks_2E_element>>::make (inMapToOverride.mSharedRoot COMMA_THERE) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_M_5F_tasks GGS_M_5F_tasks::getter_overriddenMap (Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) const {
  GGS_M_5F_tasks result ;
  if (isValid ()) {
    result.mSharedRoot = mSharedRoot->overriddenRoot () ;
    if (result.mSharedRoot.isNil ()) {
      inCompiler->onTheFlySemanticError ("getter 'overriddenMap': no overriden map" COMMA_THERE) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

void GGS_M_5F_tasks::setter_insertKey (GGS_lstring inLKey,
                                       GGS_uint inArgument0,
                                       GGS_luint inArgument1,
                                       GGS_luint inArgument2,
                                       GGS_luint inArgument3,
                                       GGS_luint inArgument4,
                                       GGS_luint inArgument5,
                                       GGS_uint inArgument6,
                                       GGS_luint inArgument7,
                                       GGS_AC_5F_task inArgument8,
                                       Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) {
  const GGS_M_5F_tasks_2E_element element (inLKey, inArgument0, inArgument1, inArgument2, inArgument3, inArgument4, inArgument5, inArgument6, inArgument7, inArgument8) ;
  const char * kInsertErrorMessage = "the task '%K' has been already declared in %L" ;
  const char * kShadowErrorMessage = nullptr ;
  performInsert (element, kInsertErrorMessage, kShadowErrorMessage, inCompiler COMMA_THERE) ;
}

//--------------------------------------------------------------------------------------------------

void GGS_M_5F_tasks::method_searchKey (GGS_lstring inLKey,
                                       GGS_uint & outArgument0,
                                       GGS_luint & outArgument1,
                                       GGS_luint & outArgument2,
                                       GGS_luint & outArgument3,
                                       GGS_luint & outArgument4,
                                       GGS_luint & outArgument5,
                                       GGS_uint & outArgument6,
                                       GGS_luint & outArgument7,
                                       GGS_AC_5F_task & outArgument8,
                                       Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) const {
  SharedGenericPtrWithValueSemantics <GGS_M_5F_tasks_2E_element> info ;
  if (isValid () && inLKey.isValid ()) {
    const String key = inLKey.mProperty_string.stringValue () ;
    info = infoForKey (key) ;
    if (info.isNil ()) {
      GenericUniqueArray <String> nearestKeyArray ;
      findNearestKey (key, nearestKeyArray) ;
      const char * kSearchErrorMessage = "the task '%K' is not declared" ;
      inCompiler->semanticErrorWith_K_message (inLKey, nearestKeyArray, kSearchErrorMessage COMMA_THERE) ;
    }
  }
  if (info.isNil ()) {
    outArgument0.drop () ;
    outArgument1.drop () ;
    outArgument2.drop () ;
    outArgument3.drop () ;
    outArgument4.drop () ;
    outArgument5.drop () ;
    outArgument6.drop () ;
    outArgument7.drop () ;
    outArgument8.drop () ;
  }else{
    outArgument0 = info->mProperty_mIndex ;
    outArgument1 = info->mProperty_mPriority ;
    outArgument2 = info->mProperty_mOffset ;
    outArgument3 = info->mProperty_mDeadline ;
    outArgument4 = info->mProperty_mDurationMin ;
    outArgument5 = info->mProperty_mDurationMax ;
    outArgument6 = info->mProperty_mProcessor ;
    outArgument7 = info->mProperty_mPeriod ;
    outArgument8 = info->mProperty_mTaskKind ;
  }
}
//--------------------------------------------------------------------------------------------------

GGS_uint GGS_M_5F_tasks::getter_mIndexForKey (const GGS_string & inKey,
                                              Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const {
  GGS_uint result ;
  if (isValid () && inKey.isValid ()) {
    const String key = inKey.stringValue () ;
    const SharedGenericPtrWithValueSemantics <GGS_M_5F_tasks_2E_element> info = infoForKey (key) ;
    if (info.isNil ()) {
      String message = "cannot read property in map: the '" ;
      message.appendString (key) ;
      message.appendCString ("' key does not exist") ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }else{
      result = info->mProperty_mIndex ;
    }
  }
  return result ;
}
//--------------------------------------------------------------------------------------------------

GGS_luint GGS_M_5F_tasks::getter_mPriorityForKey (const GGS_string & inKey,
                                                  Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) const {
  GGS_luint result ;
  if (isValid () && inKey.isValid ()) {
    const String key = inKey.stringValue () ;
    const SharedGenericPtrWithValueSemantics <GGS_M_5F_tasks_2E_element> info = infoForKey (key) ;
    if (info.isNil ()) {
      String message = "cannot read property in map: the '" ;
      message.appendString (key) ;
      message.appendCString ("' key does not exist") ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }else{
      result = info->mProperty_mPriority ;
    }
  }
  return result ;
}
//--------------------------------------------------------------------------------------------------

GGS_luint GGS_M_5F_tasks::getter_mOffsetForKey (const GGS_string & inKey,
                                                Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) const {
  GGS_luint result ;
  if (isValid () && inKey.isValid ()) {
    const String key = inKey.stringValue () ;
    const SharedGenericPtrWithValueSemantics <GGS_M_5F_tasks_2E_element> info = infoForKey (key) ;
    if (info.isNil ()) {
      String message = "cannot read property in map: the '" ;
      message.appendString (key) ;
      message.appendCString ("' key does not exist") ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }else{
      result = info->mProperty_mOffset ;
    }
  }
  return result ;
}
//--------------------------------------------------------------------------------------------------

GGS_luint GGS_M_5F_tasks::getter_mDeadlineForKey (const GGS_string & inKey,
                                                  Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) const {
  GGS_luint result ;
  if (isValid () && inKey.isValid ()) {
    const String key = inKey.stringValue () ;
    const SharedGenericPtrWithValueSemantics <GGS_M_5F_tasks_2E_element> info = infoForKey (key) ;
    if (info.isNil ()) {
      String message = "cannot read property in map: the '" ;
      message.appendString (key) ;
      message.appendCString ("' key does not exist") ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }else{
      result = info->mProperty_mDeadline ;
    }
  }
  return result ;
}
//--------------------------------------------------------------------------------------------------

GGS_luint GGS_M_5F_tasks::getter_mDurationMinForKey (const GGS_string & inKey,
                                                     Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) const {
  GGS_luint result ;
  if (isValid () && inKey.isValid ()) {
    const String key = inKey.stringValue () ;
    const SharedGenericPtrWithValueSemantics <GGS_M_5F_tasks_2E_element> info = infoForKey (key) ;
    if (info.isNil ()) {
      String message = "cannot read property in map: the '" ;
      message.appendString (key) ;
      message.appendCString ("' key does not exist") ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }else{
      result = info->mProperty_mDurationMin ;
    }
  }
  return result ;
}
//--------------------------------------------------------------------------------------------------

GGS_luint GGS_M_5F_tasks::getter_mDurationMaxForKey (const GGS_string & inKey,
                                                     Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) const {
  GGS_luint result ;
  if (isValid () && inKey.isValid ()) {
    const String key = inKey.stringValue () ;
    const SharedGenericPtrWithValueSemantics <GGS_M_5F_tasks_2E_element> info = infoForKey (key) ;
    if (info.isNil ()) {
      String message = "cannot read property in map: the '" ;
      message.appendString (key) ;
      message.appendCString ("' key does not exist") ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }else{
      result = info->mProperty_mDurationMax ;
    }
  }
  return result ;
}
//--------------------------------------------------------------------------------------------------

GGS_uint GGS_M_5F_tasks::getter_mProcessorForKey (const GGS_string & inKey,
                                                  Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) const {
  GGS_uint result ;
  if (isValid () && inKey.isValid ()) {
    const String key = inKey.stringValue () ;
    const SharedGenericPtrWithValueSemantics <GGS_M_5F_tasks_2E_element> info = infoForKey (key) ;
    if (info.isNil ()) {
      String message = "cannot read property in map: the '" ;
      message.appendString (key) ;
      message.appendCString ("' key does not exist") ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }else{
      result = info->mProperty_mProcessor ;
    }
  }
  return result ;
}
//--------------------------------------------------------------------------------------------------

GGS_luint GGS_M_5F_tasks::getter_mPeriodForKey (const GGS_string & inKey,
                                                Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) const {
  GGS_luint result ;
  if (isValid () && inKey.isValid ()) {
    const String key = inKey.stringValue () ;
    const SharedGenericPtrWithValueSemantics <GGS_M_5F_tasks_2E_element> info = infoForKey (key) ;
    if (info.isNil ()) {
      String message = "cannot read property in map: the '" ;
      message.appendString (key) ;
      message.appendCString ("' key does not exist") ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }else{
      result = info->mProperty_mPeriod ;
    }
  }
  return result ;
}
//--------------------------------------------------------------------------------------------------

GGS_AC_5F_task GGS_M_5F_tasks::getter_mTaskKindForKey (const GGS_string & inKey,
                                                       Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) const {
  GGS_AC_5F_task result ;
  if (isValid () && inKey.isValid ()) {
    const String key = inKey.stringValue () ;
    const SharedGenericPtrWithValueSemantics <GGS_M_5F_tasks_2E_element> info = infoForKey (key) ;
    if (info.isNil ()) {
      String message = "cannot read property in map: the '" ;
      message.appendString (key) ;
      message.appendCString ("' key does not exist") ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }else{
      result = info->mProperty_mTaskKind ;
    }
  }
  return result ;
}
//--------------------------------------------------------------------------------------------------

void GGS_M_5F_tasks::setter_setMIndexForKey (GGS_uint inValue,
                                             GGS_string inKey,
                                             Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) {
  if (isValid () && inKey.isValid ()) {
    const String key = inKey.stringValue () ;
    mSharedRoot.insulate (HERE) ;
    OptionalSharedRef <GenericMapNode <GGS_M_5F_tasks_2E_element>> node = mSharedRoot->searchNode (key) ;
    if (node.isNil ()) {
      String message = "cannot write property in map: the '" ;
      message.appendString (key) ;
      message.appendCString ("' key does not exist") ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }else{
      node->mSharedInfo->mProperty_mIndex = inValue ;
    }
  }
}
//--------------------------------------------------------------------------------------------------

void GGS_M_5F_tasks::setter_setMPriorityForKey (GGS_luint inValue,
                                                GGS_string inKey,
                                                Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  if (isValid () && inKey.isValid ()) {
    const String key = inKey.stringValue () ;
    mSharedRoot.insulate (HERE) ;
    OptionalSharedRef <GenericMapNode <GGS_M_5F_tasks_2E_element>> node = mSharedRoot->searchNode (key) ;
    if (node.isNil ()) {
      String message = "cannot write property in map: the '" ;
      message.appendString (key) ;
      message.appendCString ("' key does not exist") ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }else{
      node->mSharedInfo->mProperty_mPriority = inValue ;
    }
  }
}
//--------------------------------------------------------------------------------------------------

void GGS_M_5F_tasks::setter_setMOffsetForKey (GGS_luint inValue,
                                              GGS_string inKey,
                                              Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  if (isValid () && inKey.isValid ()) {
    const String key = inKey.stringValue () ;
    mSharedRoot.insulate (HERE) ;
    OptionalSharedRef <GenericMapNode <GGS_M_5F_tasks_2E_element>> node = mSharedRoot->searchNode (key) ;
    if (node.isNil ()) {
      String message = "cannot write property in map: the '" ;
      message.appendString (key) ;
      message.appendCString ("' key does not exist") ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }else{
      node->mSharedInfo->mProperty_mOffset = inValue ;
    }
  }
}
//--------------------------------------------------------------------------------------------------

void GGS_M_5F_tasks::setter_setMDeadlineForKey (GGS_luint inValue,
                                                GGS_string inKey,
                                                Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  if (isValid () && inKey.isValid ()) {
    const String key = inKey.stringValue () ;
    mSharedRoot.insulate (HERE) ;
    OptionalSharedRef <GenericMapNode <GGS_M_5F_tasks_2E_element>> node = mSharedRoot->searchNode (key) ;
    if (node.isNil ()) {
      String message = "cannot write property in map: the '" ;
      message.appendString (key) ;
      message.appendCString ("' key does not exist") ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }else{
      node->mSharedInfo->mProperty_mDeadline = inValue ;
    }
  }
}
//--------------------------------------------------------------------------------------------------

void GGS_M_5F_tasks::setter_setMDurationMinForKey (GGS_luint inValue,
                                                   GGS_string inKey,
                                                   Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) {
  if (isValid () && inKey.isValid ()) {
    const String key = inKey.stringValue () ;
    mSharedRoot.insulate (HERE) ;
    OptionalSharedRef <GenericMapNode <GGS_M_5F_tasks_2E_element>> node = mSharedRoot->searchNode (key) ;
    if (node.isNil ()) {
      String message = "cannot write property in map: the '" ;
      message.appendString (key) ;
      message.appendCString ("' key does not exist") ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }else{
      node->mSharedInfo->mProperty_mDurationMin = inValue ;
    }
  }
}
//--------------------------------------------------------------------------------------------------

void GGS_M_5F_tasks::setter_setMDurationMaxForKey (GGS_luint inValue,
                                                   GGS_string inKey,
                                                   Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) {
  if (isValid () && inKey.isValid ()) {
    const String key = inKey.stringValue () ;
    mSharedRoot.insulate (HERE) ;
    OptionalSharedRef <GenericMapNode <GGS_M_5F_tasks_2E_element>> node = mSharedRoot->searchNode (key) ;
    if (node.isNil ()) {
      String message = "cannot write property in map: the '" ;
      message.appendString (key) ;
      message.appendCString ("' key does not exist") ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }else{
      node->mSharedInfo->mProperty_mDurationMax = inValue ;
    }
  }
}
//--------------------------------------------------------------------------------------------------

void GGS_M_5F_tasks::setter_setMProcessorForKey (GGS_uint inValue,
                                                 GGS_string inKey,
                                                 Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) {
  if (isValid () && inKey.isValid ()) {
    const String key = inKey.stringValue () ;
    mSharedRoot.insulate (HERE) ;
    OptionalSharedRef <GenericMapNode <GGS_M_5F_tasks_2E_element>> node = mSharedRoot->searchNode (key) ;
    if (node.isNil ()) {
      String message = "cannot write property in map: the '" ;
      message.appendString (key) ;
      message.appendCString ("' key does not exist") ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }else{
      node->mSharedInfo->mProperty_mProcessor = inValue ;
    }
  }
}
//--------------------------------------------------------------------------------------------------

void GGS_M_5F_tasks::setter_setMPeriodForKey (GGS_luint inValue,
                                              GGS_string inKey,
                                              Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  if (isValid () && inKey.isValid ()) {
    const String key = inKey.stringValue () ;
    mSharedRoot.insulate (HERE) ;
    OptionalSharedRef <GenericMapNode <GGS_M_5F_tasks_2E_element>> node = mSharedRoot->searchNode (key) ;
    if (node.isNil ()) {
      String message = "cannot write property in map: the '" ;
      message.appendString (key) ;
      message.appendCString ("' key does not exist") ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }else{
      node->mSharedInfo->mProperty_mPeriod = inValue ;
    }
  }
}
//--------------------------------------------------------------------------------------------------

void GGS_M_5F_tasks::setter_setMTaskKindForKey (GGS_AC_5F_task inValue,
                                                GGS_string inKey,
                                                Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  if (isValid () && inKey.isValid ()) {
    const String key = inKey.stringValue () ;
    mSharedRoot.insulate (HERE) ;
    OptionalSharedRef <GenericMapNode <GGS_M_5F_tasks_2E_element>> node = mSharedRoot->searchNode (key) ;
    if (node.isNil ()) {
      String message = "cannot write property in map: the '" ;
      message.appendString (key) ;
      message.appendCString ("' key does not exist") ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }else{
      node->mSharedInfo->mProperty_mTaskKind = inValue ;
    }
  }
}
//--------------------------------------------------------------------------------------------------

static void GGS_M_5F_tasks_internalDescription (const GenericArray <SharedGenericPtrWithValueSemantics <GGS_M_5F_tasks_2E_element>> & inArray,
                                                        String & ioString,
                                                        const int32_t inIndentation) {
  const int32_t n = inArray.count () ;
  ioString.appendString (" (") ;
  ioString.appendSigned (n) ;
  ioString.appendString (" object") ;
  if (n > 1) {
    ioString.appendString ("s") ;
  }
  ioString.appendString ("):") ;
  for (int32_t i = 0 ; i < n ; i++) {
    ioString.appendNewLine () ;
    ioString.appendStringMultiple ("| ", inIndentation) ;
    ioString.appendString ("|-at ") ;
    ioString.appendSigned (i) ;
    ioString.appendString (": key '") ;
    ioString.appendString (inArray (i COMMA_HERE)->mProperty_lkey.mProperty_string.stringValue ()) ;
    ioString.appendString ("'") ;
    ioString.appendNewLine () ;
    ioString.appendStringMultiple ("| ", inIndentation + 2) ;
    ioString.appendString ("mIndex:") ;
    inArray (i COMMA_HERE)->mProperty_mIndex.description (ioString, inIndentation + 1) ;
    ioString.appendNewLine () ;
    ioString.appendStringMultiple ("| ", inIndentation + 2) ;
    ioString.appendString ("mPriority:") ;
    inArray (i COMMA_HERE)->mProperty_mPriority.description (ioString, inIndentation + 1) ;
    ioString.appendNewLine () ;
    ioString.appendStringMultiple ("| ", inIndentation + 2) ;
    ioString.appendString ("mOffset:") ;
    inArray (i COMMA_HERE)->mProperty_mOffset.description (ioString, inIndentation + 1) ;
    ioString.appendNewLine () ;
    ioString.appendStringMultiple ("| ", inIndentation + 2) ;
    ioString.appendString ("mDeadline:") ;
    inArray (i COMMA_HERE)->mProperty_mDeadline.description (ioString, inIndentation + 1) ;
    ioString.appendNewLine () ;
    ioString.appendStringMultiple ("| ", inIndentation + 2) ;
    ioString.appendString ("mDurationMin:") ;
    inArray (i COMMA_HERE)->mProperty_mDurationMin.description (ioString, inIndentation + 1) ;
    ioString.appendNewLine () ;
    ioString.appendStringMultiple ("| ", inIndentation + 2) ;
    ioString.appendString ("mDurationMax:") ;
    inArray (i COMMA_HERE)->mProperty_mDurationMax.description (ioString, inIndentation + 1) ;
    ioString.appendNewLine () ;
    ioString.appendStringMultiple ("| ", inIndentation + 2) ;
    ioString.appendString ("mProcessor:") ;
    inArray (i COMMA_HERE)->mProperty_mProcessor.description (ioString, inIndentation + 1) ;
    ioString.appendNewLine () ;
    ioString.appendStringMultiple ("| ", inIndentation + 2) ;
    ioString.appendString ("mPeriod:") ;
    inArray (i COMMA_HERE)->mProperty_mPeriod.description (ioString, inIndentation + 1) ;
    ioString.appendNewLine () ;
    ioString.appendStringMultiple ("| ", inIndentation + 2) ;
    ioString.appendString ("mTaskKind:") ;
    inArray (i COMMA_HERE)->mProperty_mTaskKind.description (ioString, inIndentation + 1) ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_M_5F_tasks::description (String & ioString,
                                          const int32_t inIndentation) const {
  ioString.appendCString ("<map @") ;
  ioString.appendString (staticTypeDescriptor ()->mGalgasTypeName) ;
  if (isValid ()) {
    const GenericArray <SharedGenericPtrWithValueSemantics <GGS_M_5F_tasks_2E_element>> array = sortedInfoArray () ;
    GGS_M_5F_tasks_internalDescription (array, ioString, inIndentation) ;
    OptionalSharedRef <GenericMapRoot <GGS_M_5F_tasks_2E_element>> subRoot = mSharedRoot->overriddenRoot () ;
    uint32_t idx = 0 ;
    while (subRoot.isNotNil ()) {
     idx += 1 ;
     ioString.appendNewLine () ;
     ioString.appendStringMultiple ("| ", inIndentation + 1) ;
     ioString.appendString (" override #") ;
     ioString.appendUnsigned (idx) ;
     const auto subRootArray = subRoot->sortedInfoArray () ;
     GGS_M_5F_tasks_internalDescription (subRootArray, ioString, inIndentation) ;
     subRoot = subRoot->overriddenRoot () ;
    }
  }else{
    ioString.appendCString (" not built") ;
  }
  ioString.appendCString (">") ;
}



//--------------------------------------------------------------------------------------------------
//  Down Enumerator for @M_5F_tasks
//--------------------------------------------------------------------------------------------------

DownEnumerator_M_5F_tasks::DownEnumerator_M_5F_tasks (const GGS_M_5F_tasks & inMap) :
mInfoArray (inMap.sortedInfoArray ()),
mIndex (0) {
  mIndex = mInfoArray.count () - 1 ;
}

//--------------------------------------------------------------------------------------------------

GGS_M_5F_tasks_2E_element DownEnumerator_M_5F_tasks::current (LOCATION_ARGS) const {
  return mInfoArray (mIndex COMMA_THERE).value () ;
}

//--------------------------------------------------------------------------------------------------

GGS_lstring DownEnumerator_M_5F_tasks::current_lkey (LOCATION_ARGS) const {
  return mInfoArray (mIndex COMMA_THERE)->mProperty_lkey ;
}

//--------------------------------------------------------------------------------------------------

GGS_uint DownEnumerator_M_5F_tasks::current_mIndex (LOCATION_ARGS) const {
  return mInfoArray (mIndex COMMA_THERE)->mProperty_mIndex ;
}

//--------------------------------------------------------------------------------------------------

GGS_luint DownEnumerator_M_5F_tasks::current_mPriority (LOCATION_ARGS) const {
  return mInfoArray (mIndex COMMA_THERE)->mProperty_mPriority ;
}

//--------------------------------------------------------------------------------------------------

GGS_luint DownEnumerator_M_5F_tasks::current_mOffset (LOCATION_ARGS) const {
  return mInfoArray (mIndex COMMA_THERE)->mProperty_mOffset ;
}

//--------------------------------------------------------------------------------------------------

GGS_luint DownEnumerator_M_5F_tasks::current_mDeadline (LOCATION_ARGS) const {
  return mInfoArray (mIndex COMMA_THERE)->mProperty_mDeadline ;
}

//--------------------------------------------------------------------------------------------------

GGS_luint DownEnumerator_M_5F_tasks::current_mDurationMin (LOCATION_ARGS) const {
  return mInfoArray (mIndex COMMA_THERE)->mProperty_mDurationMin ;
}

//--------------------------------------------------------------------------------------------------

GGS_luint DownEnumerator_M_5F_tasks::current_mDurationMax (LOCATION_ARGS) const {
  return mInfoArray (mIndex COMMA_THERE)->mProperty_mDurationMax ;
}

//--------------------------------------------------------------------------------------------------

GGS_uint DownEnumerator_M_5F_tasks::current_mProcessor (LOCATION_ARGS) const {
  return mInfoArray (mIndex COMMA_THERE)->mProperty_mProcessor ;
}

//--------------------------------------------------------------------------------------------------

GGS_luint DownEnumerator_M_5F_tasks::current_mPeriod (LOCATION_ARGS) const {
  return mInfoArray (mIndex COMMA_THERE)->mProperty_mPeriod ;
}

//--------------------------------------------------------------------------------------------------

GGS_AC_5F_task DownEnumerator_M_5F_tasks::current_mTaskKind (LOCATION_ARGS) const {
  return mInfoArray (mIndex COMMA_THERE)->mProperty_mTaskKind ;
}

//--------------------------------------------------------------------------------------------------
//  Up Enumerator for @M_5F_tasks
//--------------------------------------------------------------------------------------------------

UpEnumerator_M_5F_tasks::UpEnumerator_M_5F_tasks (const GGS_M_5F_tasks & inMap) :
mInfoArray (inMap.sortedInfoArray ()),
mIndex (0) {
}

//--------------------------------------------------------------------------------------------------

GGS_M_5F_tasks_2E_element UpEnumerator_M_5F_tasks::current (LOCATION_ARGS) const {
  return mInfoArray (mIndex COMMA_THERE).value () ;
}

//--------------------------------------------------------------------------------------------------

GGS_lstring UpEnumerator_M_5F_tasks::current_lkey (LOCATION_ARGS) const {
  return mInfoArray (mIndex COMMA_THERE)->mProperty_lkey ;
}

//--------------------------------------------------------------------------------------------------

GGS_uint UpEnumerator_M_5F_tasks::current_mIndex (LOCATION_ARGS) const {
  return mInfoArray (mIndex COMMA_THERE)->mProperty_mIndex ;
}

//--------------------------------------------------------------------------------------------------

GGS_luint UpEnumerator_M_5F_tasks::current_mPriority (LOCATION_ARGS) const {
  return mInfoArray (mIndex COMMA_THERE)->mProperty_mPriority ;
}

//--------------------------------------------------------------------------------------------------

GGS_luint UpEnumerator_M_5F_tasks::current_mOffset (LOCATION_ARGS) const {
  return mInfoArray (mIndex COMMA_THERE)->mProperty_mOffset ;
}

//--------------------------------------------------------------------------------------------------

GGS_luint UpEnumerator_M_5F_tasks::current_mDeadline (LOCATION_ARGS) const {
  return mInfoArray (mIndex COMMA_THERE)->mProperty_mDeadline ;
}

//--------------------------------------------------------------------------------------------------

GGS_luint UpEnumerator_M_5F_tasks::current_mDurationMin (LOCATION_ARGS) const {
  return mInfoArray (mIndex COMMA_THERE)->mProperty_mDurationMin ;
}

//--------------------------------------------------------------------------------------------------

GGS_luint UpEnumerator_M_5F_tasks::current_mDurationMax (LOCATION_ARGS) const {
  return mInfoArray (mIndex COMMA_THERE)->mProperty_mDurationMax ;
}

//--------------------------------------------------------------------------------------------------

GGS_uint UpEnumerator_M_5F_tasks::current_mProcessor (LOCATION_ARGS) const {
  return mInfoArray (mIndex COMMA_THERE)->mProperty_mProcessor ;
}

//--------------------------------------------------------------------------------------------------

GGS_luint UpEnumerator_M_5F_tasks::current_mPeriod (LOCATION_ARGS) const {
  return mInfoArray (mIndex COMMA_THERE)->mProperty_mPeriod ;
}

//--------------------------------------------------------------------------------------------------

GGS_AC_5F_task UpEnumerator_M_5F_tasks::current_mTaskKind (LOCATION_ARGS) const {
  return mInfoArray (mIndex COMMA_THERE)->mProperty_mTaskKind ;
}


//--------------------------------------------------------------------------------------------------
//     @M_tasks generic code implementation
//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor kTypeDescriptor_GALGAS_M_5F_tasks ("M_tasks",
                                                               nullptr) ;

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * GGS_M_5F_tasks::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_M_5F_tasks ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GGS_M_5F_tasks::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GGS_M_5F_tasks (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_M_5F_tasks GGS_M_5F_tasks::extractObject (const GGS_object & inObject,
                                              Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  GGS_M_5F_tasks result ;
  const GGS_M_5F_tasks * p = (const GGS_M_5F_tasks *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GGS_M_5F_tasks *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("M_tasks", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//
//     L E X I Q U E                                                                             
//
//--------------------------------------------------------------------------------------------------

#include "utf32.h"
#include "scanner_actions.h"
#include "LexiqueIntrospection.h"

//--------------------------------------------------------------------------------------------------

cTokenFor_oa_5F_scanner::cTokenFor_oa_5F_scanner (void) :
mLexicalAttribute_identifierString (),
mLexicalAttribute_ulongValue () {
}

//--------------------------------------------------------------------------------------------------

Lexique_oa_5F_scanner::Lexique_oa_5F_scanner (Compiler * inCallerCompiler,
                                              const String & inSourceFileName
                                              COMMA_LOCATION_ARGS) :
Lexique (inCallerCompiler, inSourceFileName COMMA_THERE) {
}

//--------------------------------------------------------------------------------------------------

Lexique_oa_5F_scanner::Lexique_oa_5F_scanner (Compiler * inCallerCompiler,
                                              const String & inSourceString,
                                              const String & inStringForError
                                              COMMA_LOCATION_ARGS) :
Lexique (inCallerCompiler, inSourceString, inStringForError COMMA_THERE) {
}

//--------------------------------------------------------------------------------------------------
//                        Lexical error message list                                             
//--------------------------------------------------------------------------------------------------

static const char * gLexicalMessage_oa_5F_scanner_decimalNumberTooLarge = "decimal number too large" ;

static const char * gLexicalMessage_oa_5F_scanner_incorrectEndOfComment = "incorrect end of comment" ;

static const char * gLexicalMessage_oa_5F_scanner_internalError = "internal error" ;

//--------------------------------------------------------------------------------------------------
//                getMessageForTerminal                                                          
//--------------------------------------------------------------------------------------------------

String Lexique_oa_5F_scanner::getMessageForTerminal (const int32_t inTerminalIndex) const {
  String result = "<unknown>" ;
  if ((inTerminalIndex >= 0) && (inTerminalIndex < 25)) {
    static const char * syntaxErrorMessageArray [25] = {kEndOfSourceLexicalErrorMessage,
        "an identifier",
        "a decimal number",
        "the 'system' key word",
        "the 'end' key word",
        "the 'task' key word",
        "the 'standard' key word",
        "the 'extended' key word",
        "the 'message' key word",
        "the 'length' key word",
        "the 'priority' key word",
        "the 'period' key word",
        "the 'offset' key word",
        "the 'on' key word",
        "the 'deadline' key word",
        "the 'duration' key word",
        "the 'processor' key word",
        "the 'can' key word",
        "the 'van' key word",
        "the 'network' key word",
        "the 'scalingfactor' key word",
        "the 'every' key word",
        "the '','' delimitor",
        "the '';'' delimitor",
        "the ''..'' delimitor"
    } ;
    result = syntaxErrorMessageArray [inTerminalIndex] ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//                      U N I C O D E    S T R I N G S                                           
//--------------------------------------------------------------------------------------------------

//--- Unicode string for '$,$'
static const std::initializer_list <utf32> kUnicodeString_oa_5F_scanner__2C_ = {
  utf32 (','),
} ;

//--- Unicode string for '$..$'
static const std::initializer_list <utf32> kUnicodeString_oa_5F_scanner__2E__2E_ = {
  utf32 ('.'),
  utf32 ('.'),
} ;

//--- Unicode string for '$;$'
static const std::initializer_list <utf32> kUnicodeString_oa_5F_scanner__3B_ = {
  utf32 (';'),
} ;

//--- Unicode string for '$can$'
static const std::initializer_list <utf32> kUnicodeString_oa_5F_scanner_can = {
  utf32 ('c'),
  utf32 ('a'),
  utf32 ('n'),
} ;

//--- Unicode string for '$deadline$'
static const std::initializer_list <utf32> kUnicodeString_oa_5F_scanner_deadline = {
  utf32 ('d'),
  utf32 ('e'),
  utf32 ('a'),
  utf32 ('d'),
  utf32 ('l'),
  utf32 ('i'),
  utf32 ('n'),
  utf32 ('e'),
} ;

//--- Unicode string for '$duration$'
static const std::initializer_list <utf32> kUnicodeString_oa_5F_scanner_duration = {
  utf32 ('d'),
  utf32 ('u'),
  utf32 ('r'),
  utf32 ('a'),
  utf32 ('t'),
  utf32 ('i'),
  utf32 ('o'),
  utf32 ('n'),
} ;

//--- Unicode string for '$end$'
static const std::initializer_list <utf32> kUnicodeString_oa_5F_scanner_end = {
  utf32 ('e'),
  utf32 ('n'),
  utf32 ('d'),
} ;

//--- Unicode string for '$every$'
static const std::initializer_list <utf32> kUnicodeString_oa_5F_scanner_every = {
  utf32 ('e'),
  utf32 ('v'),
  utf32 ('e'),
  utf32 ('r'),
  utf32 ('y'),
} ;

//--- Unicode string for '$extended$'
static const std::initializer_list <utf32> kUnicodeString_oa_5F_scanner_extended = {
  utf32 ('e'),
  utf32 ('x'),
  utf32 ('t'),
  utf32 ('e'),
  utf32 ('n'),
  utf32 ('d'),
  utf32 ('e'),
  utf32 ('d'),
} ;

//--- Unicode string for '$length$'
static const std::initializer_list <utf32> kUnicodeString_oa_5F_scanner_length = {
  utf32 ('l'),
  utf32 ('e'),
  utf32 ('n'),
  utf32 ('g'),
  utf32 ('t'),
  utf32 ('h'),
} ;

//--- Unicode string for '$message$'
static const std::initializer_list <utf32> kUnicodeString_oa_5F_scanner_message = {
  utf32 ('m'),
  utf32 ('e'),
  utf32 ('s'),
  utf32 ('s'),
  utf32 ('a'),
  utf32 ('g'),
  utf32 ('e'),
} ;

//--- Unicode string for '$network$'
static const std::initializer_list <utf32> kUnicodeString_oa_5F_scanner_network = {
  utf32 ('n'),
  utf32 ('e'),
  utf32 ('t'),
  utf32 ('w'),
  utf32 ('o'),
  utf32 ('r'),
  utf32 ('k'),
} ;

//--- Unicode string for '$offset$'
static const std::initializer_list <utf32> kUnicodeString_oa_5F_scanner_offset = {
  utf32 ('o'),
  utf32 ('f'),
  utf32 ('f'),
  utf32 ('s'),
  utf32 ('e'),
  utf32 ('t'),
} ;

//--- Unicode string for '$on$'
static const std::initializer_list <utf32> kUnicodeString_oa_5F_scanner_on = {
  utf32 ('o'),
  utf32 ('n'),
} ;

//--- Unicode string for '$period$'
static const std::initializer_list <utf32> kUnicodeString_oa_5F_scanner_period = {
  utf32 ('p'),
  utf32 ('e'),
  utf32 ('r'),
  utf32 ('i'),
  utf32 ('o'),
  utf32 ('d'),
} ;

//--- Unicode string for '$priority$'
static const std::initializer_list <utf32> kUnicodeString_oa_5F_scanner_priority = {
  utf32 ('p'),
  utf32 ('r'),
  utf32 ('i'),
  utf32 ('o'),
  utf32 ('r'),
  utf32 ('i'),
  utf32 ('t'),
  utf32 ('y'),
} ;

//--- Unicode string for '$processor$'
static const std::initializer_list <utf32> kUnicodeString_oa_5F_scanner_processor = {
  utf32 ('p'),
  utf32 ('r'),
  utf32 ('o'),
  utf32 ('c'),
  utf32 ('e'),
  utf32 ('s'),
  utf32 ('s'),
  utf32 ('o'),
  utf32 ('r'),
} ;

//--- Unicode string for '$scalingfactor$'
static const std::initializer_list <utf32> kUnicodeString_oa_5F_scanner_scalingfactor = {
  utf32 ('s'),
  utf32 ('c'),
  utf32 ('a'),
  utf32 ('l'),
  utf32 ('i'),
  utf32 ('n'),
  utf32 ('g'),
  utf32 ('f'),
  utf32 ('a'),
  utf32 ('c'),
  utf32 ('t'),
  utf32 ('o'),
  utf32 ('r'),
} ;

//--- Unicode string for '$standard$'
static const std::initializer_list <utf32> kUnicodeString_oa_5F_scanner_standard = {
  utf32 ('s'),
  utf32 ('t'),
  utf32 ('a'),
  utf32 ('n'),
  utf32 ('d'),
  utf32 ('a'),
  utf32 ('r'),
  utf32 ('d'),
} ;

//--- Unicode string for '$system$'
static const std::initializer_list <utf32> kUnicodeString_oa_5F_scanner_system = {
  utf32 ('s'),
  utf32 ('y'),
  utf32 ('s'),
  utf32 ('t'),
  utf32 ('e'),
  utf32 ('m'),
} ;

//--- Unicode string for '$task$'
static const std::initializer_list <utf32> kUnicodeString_oa_5F_scanner_task = {
  utf32 ('t'),
  utf32 ('a'),
  utf32 ('s'),
  utf32 ('k'),
} ;

//--- Unicode string for '$van$'
static const std::initializer_list <utf32> kUnicodeString_oa_5F_scanner_van = {
  utf32 ('v'),
  utf32 ('a'),
  utf32 ('n'),
} ;

//--------------------------------------------------------------------------------------------------
//             Key words table 'delimitorsList'      
//--------------------------------------------------------------------------------------------------

static const int32_t ktable_size_oa_5F_scanner_delimitorsList = 3 ;

static const C_unicode_lexique_table_entry ktable_for_oa_5F_scanner_delimitorsList [ktable_size_oa_5F_scanner_delimitorsList] = {
  C_unicode_lexique_table_entry (kUnicodeString_oa_5F_scanner__2C_, Lexique_oa_5F_scanner::kToken__2C_),
  C_unicode_lexique_table_entry (kUnicodeString_oa_5F_scanner__3B_, Lexique_oa_5F_scanner::kToken__3B_),
  C_unicode_lexique_table_entry (kUnicodeString_oa_5F_scanner__2E__2E_, Lexique_oa_5F_scanner::kToken__2E__2E_)
} ;

int32_t Lexique_oa_5F_scanner::search_into_delimitorsList (const String & inSearchedString) {
  return searchInList (inSearchedString, ktable_for_oa_5F_scanner_delimitorsList, ktable_size_oa_5F_scanner_delimitorsList) ;
}

//--------------------------------------------------------------------------------------------------
//             Key words table 'keyWordList'      
//--------------------------------------------------------------------------------------------------

static const int32_t ktable_size_oa_5F_scanner_keyWordList = 19 ;

static const C_unicode_lexique_table_entry ktable_for_oa_5F_scanner_keyWordList [ktable_size_oa_5F_scanner_keyWordList] = {
  C_unicode_lexique_table_entry (kUnicodeString_oa_5F_scanner_on, Lexique_oa_5F_scanner::kToken_on),
  C_unicode_lexique_table_entry (kUnicodeString_oa_5F_scanner_can, Lexique_oa_5F_scanner::kToken_can),
  C_unicode_lexique_table_entry (kUnicodeString_oa_5F_scanner_end, Lexique_oa_5F_scanner::kToken_end),
  C_unicode_lexique_table_entry (kUnicodeString_oa_5F_scanner_van, Lexique_oa_5F_scanner::kToken_van),
  C_unicode_lexique_table_entry (kUnicodeString_oa_5F_scanner_task, Lexique_oa_5F_scanner::kToken_task),
  C_unicode_lexique_table_entry (kUnicodeString_oa_5F_scanner_every, Lexique_oa_5F_scanner::kToken_every),
  C_unicode_lexique_table_entry (kUnicodeString_oa_5F_scanner_length, Lexique_oa_5F_scanner::kToken_length),
  C_unicode_lexique_table_entry (kUnicodeString_oa_5F_scanner_offset, Lexique_oa_5F_scanner::kToken_offset),
  C_unicode_lexique_table_entry (kUnicodeString_oa_5F_scanner_period, Lexique_oa_5F_scanner::kToken_period),
  C_unicode_lexique_table_entry (kUnicodeString_oa_5F_scanner_system, Lexique_oa_5F_scanner::kToken_system),
  C_unicode_lexique_table_entry (kUnicodeString_oa_5F_scanner_message, Lexique_oa_5F_scanner::kToken_message),
  C_unicode_lexique_table_entry (kUnicodeString_oa_5F_scanner_network, Lexique_oa_5F_scanner::kToken_network),
  C_unicode_lexique_table_entry (kUnicodeString_oa_5F_scanner_deadline, Lexique_oa_5F_scanner::kToken_deadline),
  C_unicode_lexique_table_entry (kUnicodeString_oa_5F_scanner_duration, Lexique_oa_5F_scanner::kToken_duration),
  C_unicode_lexique_table_entry (kUnicodeString_oa_5F_scanner_extended, Lexique_oa_5F_scanner::kToken_extended),
  C_unicode_lexique_table_entry (kUnicodeString_oa_5F_scanner_priority, Lexique_oa_5F_scanner::kToken_priority),
  C_unicode_lexique_table_entry (kUnicodeString_oa_5F_scanner_standard, Lexique_oa_5F_scanner::kToken_standard),
  C_unicode_lexique_table_entry (kUnicodeString_oa_5F_scanner_processor, Lexique_oa_5F_scanner::kToken_processor),
  C_unicode_lexique_table_entry (kUnicodeString_oa_5F_scanner_scalingfactor, Lexique_oa_5F_scanner::kToken_scalingfactor)
} ;

int32_t Lexique_oa_5F_scanner::search_into_keyWordList (const String & inSearchedString) {
  return searchInList (inSearchedString, ktable_for_oa_5F_scanner_keyWordList, ktable_size_oa_5F_scanner_keyWordList) ;
}


//--------------------------------------------------------------------------------------------------
//                          getCurrentTokenString                                                
//--------------------------------------------------------------------------------------------------

String Lexique_oa_5F_scanner::getCurrentTokenString (const cToken * inTokenPtr) const {
  const cTokenFor_oa_5F_scanner * ptr = (const cTokenFor_oa_5F_scanner *) inTokenPtr ;
  String s ;
  if (ptr == nullptr) {
    s.appendCString ("$$") ;
  }else{
    switch (ptr->mTokenCode) {
    case kToken_:
      s.appendCString ("$$") ;
      break ;
    case kToken_identifier:
      s.appendChar (utf32 ('$')) ;
      s.appendCString ("identifier") ;
      s.appendChar (utf32 ('$')) ;
      s.appendChar (utf32 (' ')) ;
      s.appendStringAsCLiteralStringConstant (ptr->mLexicalAttribute_identifierString) ;
      break ;
    case kToken_literal_5F_integer:
      s.appendChar (utf32 ('$')) ;
      s.appendCString ("literal_integer") ;
      s.appendChar (utf32 ('$')) ;
      s.appendChar (utf32 (' ')) ;
      s.appendUnsigned (ptr->mLexicalAttribute_ulongValue) ;
      break ;
    case kToken_system:
      s.appendChar (utf32 ('$')) ;
      s.appendCString ("system") ;
      s.appendChar (utf32 ('$')) ;
      break ;
    case kToken_end:
      s.appendChar (utf32 ('$')) ;
      s.appendCString ("end") ;
      s.appendChar (utf32 ('$')) ;
      break ;
    case kToken_task:
      s.appendChar (utf32 ('$')) ;
      s.appendCString ("task") ;
      s.appendChar (utf32 ('$')) ;
      break ;
    case kToken_standard:
      s.appendChar (utf32 ('$')) ;
      s.appendCString ("standard") ;
      s.appendChar (utf32 ('$')) ;
      break ;
    case kToken_extended:
      s.appendChar (utf32 ('$')) ;
      s.appendCString ("extended") ;
      s.appendChar (utf32 ('$')) ;
      break ;
    case kToken_message:
      s.appendChar (utf32 ('$')) ;
      s.appendCString ("message") ;
      s.appendChar (utf32 ('$')) ;
      break ;
    case kToken_length:
      s.appendChar (utf32 ('$')) ;
      s.appendCString ("length") ;
      s.appendChar (utf32 ('$')) ;
      break ;
    case kToken_priority:
      s.appendChar (utf32 ('$')) ;
      s.appendCString ("priority") ;
      s.appendChar (utf32 ('$')) ;
      break ;
    case kToken_period:
      s.appendChar (utf32 ('$')) ;
      s.appendCString ("period") ;
      s.appendChar (utf32 ('$')) ;
      break ;
    case kToken_offset:
      s.appendChar (utf32 ('$')) ;
      s.appendCString ("offset") ;
      s.appendChar (utf32 ('$')) ;
      break ;
    case kToken_on:
      s.appendChar (utf32 ('$')) ;
      s.appendCString ("on") ;
      s.appendChar (utf32 ('$')) ;
      break ;
    case kToken_deadline:
      s.appendChar (utf32 ('$')) ;
      s.appendCString ("deadline") ;
      s.appendChar (utf32 ('$')) ;
      break ;
    case kToken_duration:
      s.appendChar (utf32 ('$')) ;
      s.appendCString ("duration") ;
      s.appendChar (utf32 ('$')) ;
      break ;
    case kToken_processor:
      s.appendChar (utf32 ('$')) ;
      s.appendCString ("processor") ;
      s.appendChar (utf32 ('$')) ;
      break ;
    case kToken_can:
      s.appendChar (utf32 ('$')) ;
      s.appendCString ("can") ;
      s.appendChar (utf32 ('$')) ;
      break ;
    case kToken_van:
      s.appendChar (utf32 ('$')) ;
      s.appendCString ("van") ;
      s.appendChar (utf32 ('$')) ;
      break ;
    case kToken_network:
      s.appendChar (utf32 ('$')) ;
      s.appendCString ("network") ;
      s.appendChar (utf32 ('$')) ;
      break ;
    case kToken_scalingfactor:
      s.appendChar (utf32 ('$')) ;
      s.appendCString ("scalingfactor") ;
      s.appendChar (utf32 ('$')) ;
      break ;
    case kToken_every:
      s.appendChar (utf32 ('$')) ;
      s.appendCString ("every") ;
      s.appendChar (utf32 ('$')) ;
      break ;
    case kToken__2C_:
      s.appendChar (utf32 ('$')) ;
      s.appendCString (",") ;
      s.appendChar (utf32 ('$')) ;
      break ;
    case kToken__3B_:
      s.appendChar (utf32 ('$')) ;
      s.appendCString (";") ;
      s.appendChar (utf32 ('$')) ;
      break ;
    case kToken__2E__2E_:
      s.appendChar (utf32 ('$')) ;
      s.appendCString ("..") ;
      s.appendChar (utf32 ('$')) ;
      break ;
    default:
      break ;
    }
  }
  return s ;
}

//--------------------------------------------------------------------------------------------------
//                           Template Delimiters                                                 
//--------------------------------------------------------------------------------------------------


//--------------------------------------------------------------------------------------------------
//                           Template Replacements                                               
//--------------------------------------------------------------------------------------------------


//--------------------------------------------------------------------------------------------------
//            Terminal Symbols as end of script in template mark                                 
//--------------------------------------------------------------------------------------------------


//--------------------------------------------------------------------------------------------------
//               INTERNAL PARSE LEXICAL TOKEN                                         
//--------------------------------------------------------------------------------------------------

void Lexique_oa_5F_scanner::internalParseLexicalToken (cTokenFor_oa_5F_scanner & token) {
  bool loop = true ;
  token.mLexicalAttribute_identifierString.removeAllKeepingCapacity () ;
  token.mLexicalAttribute_ulongValue = 0 ;
  mTokenStartLocation = mCurrentLocation ;
  try{
    if (testForInputUTF32CharRange (utf32 ('a'), utf32 ('z')) || testForInputUTF32CharRange (utf32 ('A'), utf32 ('Z'))) {
      do {
        ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_identifierString, previousChar ()) ;
        if (testForInputUTF32CharRange (utf32 ('a'), utf32 ('z')) || testForInputUTF32CharRange (utf32 ('A'), utf32 ('Z')) || testForInputUTF32Char (utf32 ('_')) || testForInputUTF32CharRange (utf32 ('0'), utf32 ('9'))) {
        }else{
          loop = false ;
        }
      }while (loop) ;
      loop = true ;
      if (token.mTokenCode == -1) {
        token.mTokenCode = search_into_keyWordList (token.mLexicalAttribute_identifierString) ;
      }
      if (token.mTokenCode == -1) {
        token.mTokenCode = kToken_identifier ;
      }
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_oa_5F_scanner__2E__2E_, true)) {
      token.mTokenCode = kToken__2E__2E_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_oa_5F_scanner__3B_, true)) {
      token.mTokenCode = kToken__3B_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_oa_5F_scanner__2C_, true)) {
      token.mTokenCode = kToken__2C_ ;
      enterToken (token) ;
    }else if (testForInputUTF32CharRange (utf32 ('0'), utf32 ('9'))) {
      ::scanner_routine_enterDigitIntoUInt (*this, previousChar (), token.mLexicalAttribute_ulongValue, gLexicalMessage_oa_5F_scanner_decimalNumberTooLarge, gLexicalMessage_oa_5F_scanner_internalError) ;
      do {
        if (testForInputUTF32CharRange (utf32 ('0'), utf32 ('9'))) {
          ::scanner_routine_enterDigitIntoUInt (*this, previousChar (), token.mLexicalAttribute_ulongValue, gLexicalMessage_oa_5F_scanner_decimalNumberTooLarge, gLexicalMessage_oa_5F_scanner_internalError) ;
        }else if (testForInputUTF32Char (utf32 ('_'))) {
        }else{
          loop = false ;
        }
      }while (loop) ;
      loop = true ;
      token.mTokenCode = kToken_literal_5F_integer ;
      enterToken (token) ;
    }else if (testForInputUTF32CharRange (utf32 (1), utf32 (' '))) {
    }else if (testForInputUTF32Char (utf32 ('#'))) {
      do {
        if (testForInputUTF32CharRange (utf32 (1), utf32 ('\t')) || testForInputUTF32CharRange (utf32 ('\v'), utf32 ('~'))) {
        }else{
          loop = false ;
        }
      }while (loop) ;
      loop = true ;
      if (testForInputUTF32Char (utf32 ('\n'))) {
      }else{
        lexicalError (gLexicalMessage_oa_5F_scanner_incorrectEndOfComment COMMA_LINE_AND_SOURCE_FILE) ;
      }
    }else if (testForInputUTF32Char (utf32 ('\0'))) { // End of source text ? 
      token.mTokenCode = kToken_ ; // Empty string code
    }else{ // Unknown input character
      unknownCharacterLexicalError (LINE_AND_SOURCE_FILE) ;
      token.mTokenCode = -1 ; // No token
      advance () ; // ... go throught unknown character
    }
  }catch (const C_lexicalErrorException &) {
    token.mTokenCode = -1 ; // No token
    advance () ; // ... go throught unknown character
  }
}

//--------------------------------------------------------------------------------------------------
//               P A R S E    L E X I C A L    T O K E N                                         
//--------------------------------------------------------------------------------------------------

bool Lexique_oa_5F_scanner::parseLexicalToken (void) {
  cTokenFor_oa_5F_scanner token ;
  token.mTokenCode = -1 ;
  while ((token.mTokenCode < 0) && (mCurrentChar.u32 () != '\0')) {
    internalParseLexicalToken (token) ;
  }
  if (mCurrentChar.u32 () == '\0') {
    token.mTokenCode = 0 ;
    enterToken (token) ;
  }
  return token.mTokenCode > 0 ;
}

//--------------------------------------------------------------------------------------------------
//                         E N T E R    T O K E N                                                
//--------------------------------------------------------------------------------------------------

void Lexique_oa_5F_scanner::enterToken (cTokenFor_oa_5F_scanner & ioToken) {
  cTokenFor_oa_5F_scanner * ptr = nullptr ;
  macroMyNew (ptr, cTokenFor_oa_5F_scanner ()) ;
  ptr->mTokenCode = ioToken.mTokenCode ;
  ptr->mStartLocation = mTokenStartLocation ;
  ptr->mEndLocation = mTokenEndLocation ;
  ptr->mTemplateStringBeforeToken = ioToken.mTemplateStringBeforeToken ;
  ioToken.mTemplateStringBeforeToken = "" ;
  ptr->mLexicalAttribute_identifierString = ioToken.mLexicalAttribute_identifierString ;
  ptr->mLexicalAttribute_ulongValue = ioToken.mLexicalAttribute_ulongValue ;
  enterTokenFromPointer (ptr) ;
}

//--------------------------------------------------------------------------------------------------
//               A T T R I B U T E   A C C E S S                                                 
//--------------------------------------------------------------------------------------------------

String Lexique_oa_5F_scanner::attributeValue_identifierString (void) const {
  cTokenFor_oa_5F_scanner * ptr = (cTokenFor_oa_5F_scanner *) currentTokenPtr (HERE) ;
  return ptr->mLexicalAttribute_identifierString ;
}

//--------------------------------------------------------------------------------------------------

uint32_t Lexique_oa_5F_scanner::attributeValue_ulongValue (void) const {
  cTokenFor_oa_5F_scanner * ptr = (cTokenFor_oa_5F_scanner *) currentTokenPtr (HERE) ;
  return ptr->mLexicalAttribute_ulongValue ;
}

//--------------------------------------------------------------------------------------------------
//         A S S I G N    F R O M    A T T R I B U T E                                           
//--------------------------------------------------------------------------------------------------

GGS_lstring Lexique_oa_5F_scanner::synthetizedAttribute_identifierString (void) const {
  cTokenFor_oa_5F_scanner * ptr = (cTokenFor_oa_5F_scanner *) currentTokenPtr (HERE) ;
  macroValidSharedObject (ptr, cTokenFor_oa_5F_scanner) ;
  GGS_location currentLocation (ptr->mStartLocation, ptr->mEndLocation, sourceText ()) ;
  GGS_string value (ptr->mLexicalAttribute_identifierString) ;
  GGS_lstring result (value, currentLocation) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_luint Lexique_oa_5F_scanner::synthetizedAttribute_ulongValue (void) const {
  cTokenFor_oa_5F_scanner * ptr = (cTokenFor_oa_5F_scanner *) currentTokenPtr (HERE) ;
  macroValidSharedObject (ptr, cTokenFor_oa_5F_scanner) ;
  GGS_location currentLocation (ptr->mStartLocation, ptr->mEndLocation, sourceText ()) ;
  GGS_uint value (ptr->mLexicalAttribute_ulongValue) ;
  GGS_luint result (value, currentLocation) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------
//                         I N T R O S P E C T I O N                                             
//--------------------------------------------------------------------------------------------------

GGS_stringlist Lexique_oa_5F_scanner::symbols (LOCATION_ARGS) {
  GGS_stringlist result = GGS_stringlist::class_func_emptyList (THERE) ;
  result.addAssignOperation (GGS_string ("identifier") COMMA_HERE) ;
  result.addAssignOperation (GGS_string ("literal_integer") COMMA_HERE) ;
  result.addAssignOperation (GGS_string ("system") COMMA_HERE) ;
  result.addAssignOperation (GGS_string ("end") COMMA_HERE) ;
  result.addAssignOperation (GGS_string ("task") COMMA_HERE) ;
  result.addAssignOperation (GGS_string ("standard") COMMA_HERE) ;
  result.addAssignOperation (GGS_string ("extended") COMMA_HERE) ;
  result.addAssignOperation (GGS_string ("message") COMMA_HERE) ;
  result.addAssignOperation (GGS_string ("length") COMMA_HERE) ;
  result.addAssignOperation (GGS_string ("priority") COMMA_HERE) ;
  result.addAssignOperation (GGS_string ("period") COMMA_HERE) ;
  result.addAssignOperation (GGS_string ("offset") COMMA_HERE) ;
  result.addAssignOperation (GGS_string ("on") COMMA_HERE) ;
  result.addAssignOperation (GGS_string ("deadline") COMMA_HERE) ;
  result.addAssignOperation (GGS_string ("duration") COMMA_HERE) ;
  result.addAssignOperation (GGS_string ("processor") COMMA_HERE) ;
  result.addAssignOperation (GGS_string ("can") COMMA_HERE) ;
  result.addAssignOperation (GGS_string ("van") COMMA_HERE) ;
  result.addAssignOperation (GGS_string ("network") COMMA_HERE) ;
  result.addAssignOperation (GGS_string ("scalingfactor") COMMA_HERE) ;
  result.addAssignOperation (GGS_string ("every") COMMA_HERE) ;
  result.addAssignOperation (GGS_string (",") COMMA_HERE) ;
  result.addAssignOperation (GGS_string (";") COMMA_HERE) ;
  result.addAssignOperation (GGS_string ("..") COMMA_HERE) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

static void getKeywordLists_oa_5F_scanner (GenericUniqueArray <String> & ioList) {
  ioList.appendObject ("oa_scanner:delimitorsList") ;
  ioList.appendObject ("oa_scanner:keyWordList") ;
}

//--------------------------------------------------------------------------------------------------

static void getKeywordsForIdentifier_oa_5F_scanner (const String & inIdentifier,
                                                    bool & ioFound,
                                                    GenericUniqueArray <String> & ioList) {
  if (inIdentifier == "oa_scanner:delimitorsList") {
    ioFound = true ;
    ioList.appendObject (",") ;
    ioList.appendObject (";") ;
    ioList.appendObject ("..") ;
    ioList.sortArrayUsingCompareMethod() ;
  }
  if (inIdentifier == "oa_scanner:keyWordList") {
    ioFound = true ;
    ioList.appendObject ("on") ;
    ioList.appendObject ("can") ;
    ioList.appendObject ("end") ;
    ioList.appendObject ("van") ;
    ioList.appendObject ("task") ;
    ioList.appendObject ("every") ;
    ioList.appendObject ("length") ;
    ioList.appendObject ("offset") ;
    ioList.appendObject ("period") ;
    ioList.appendObject ("system") ;
    ioList.appendObject ("message") ;
    ioList.appendObject ("network") ;
    ioList.appendObject ("deadline") ;
    ioList.appendObject ("duration") ;
    ioList.appendObject ("extended") ;
    ioList.appendObject ("priority") ;
    ioList.appendObject ("standard") ;
    ioList.appendObject ("processor") ;
    ioList.appendObject ("scalingfactor") ;
    ioList.sortArrayUsingCompareMethod() ;
  }
}

//--------------------------------------------------------------------------------------------------

static LexiqueIntrospection lexiqueIntrospection_oa_5F_scanner
__attribute__ ((used))
__attribute__ ((unused)) (getKeywordLists_oa_5F_scanner, getKeywordsForIdentifier_oa_5F_scanner) ;

//--------------------------------------------------------------------------------------------------
//   S T Y L E   I N D E X    F O R    T E R M I N A L                                           
//--------------------------------------------------------------------------------------------------

uint32_t Lexique_oa_5F_scanner::styleIndexForTerminal (const int32_t inTerminalIndex) const {
  static const uint32_t kTerminalSymbolStyles [25] = {0,
    1 /* oa_scanner_1_identifier */,
    4 /* oa_scanner_1_literal_5F_integer */,
    2 /* oa_scanner_1_system */,
    2 /* oa_scanner_1_end */,
    2 /* oa_scanner_1_task */,
    2 /* oa_scanner_1_standard */,
    2 /* oa_scanner_1_extended */,
    2 /* oa_scanner_1_message */,
    2 /* oa_scanner_1_length */,
    2 /* oa_scanner_1_priority */,
    2 /* oa_scanner_1_period */,
    2 /* oa_scanner_1_offset */,
    2 /* oa_scanner_1_on */,
    2 /* oa_scanner_1_deadline */,
    2 /* oa_scanner_1_duration */,
    2 /* oa_scanner_1_processor */,
    2 /* oa_scanner_1_can */,
    2 /* oa_scanner_1_van */,
    2 /* oa_scanner_1_network */,
    2 /* oa_scanner_1_scalingfactor */,
    2 /* oa_scanner_1_every */,
    3 /* oa_scanner_1__2C_ */,
    3 /* oa_scanner_1__3B_ */,
    3 /* oa_scanner_1__2E__2E_ */
  } ;
  return (inTerminalIndex >= 0) ? kTerminalSymbolStyles [inTerminalIndex] : 0 ;
}

//--------------------------------------------------------------------------------------------------
//   S T Y L E   N A M E    F O R    S T Y L E    I N D E X                                      
//--------------------------------------------------------------------------------------------------

String Lexique_oa_5F_scanner::styleNameForIndex (const uint32_t inStyleIndex) const {
  String result ;
  if (inStyleIndex < 5) {
    static const char * kStyleArray [5] = {
      "",
      "identifier",
      "keyWords",
      "delimitors",
      "integerStyle"
    } ;
    result = kStyleArray [inStyleIndex] ;
  }
  return result ;
}



//------------------------------------------------------------------------------------------------

void cParser_oa_5F_parser::rule_oa_5F_parser_axiome_i0_ (Lexique_oa_5F_scanner * inCompiler) {
  GGS_M_5F_processor var_outProcessorMap_474 = GGS_M_5F_processor::init (inCompiler COMMA_HERE) ;
  GGS_M_5F_network var_outNetworkMap_525 = GGS_M_5F_network::init (inCompiler COMMA_HERE) ;
  GGS_M_5F_messages var_outMessagesMap_573 = GGS_M_5F_messages::init (inCompiler COMMA_HERE) ;
  GGS_M_5F_tasks var_outTaskMap_620 = GGS_M_5F_tasks::init (inCompiler COMMA_HERE) ;
  inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_system COMMA_SOURCE_FILE ("oa_parser.galgas", 16)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_oa_5F_parser_0 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_processor COMMA_SOURCE_FILE ("oa_parser.galgas", 19)) ;
      GGS_lstring var_processorName_711 = inCompiler->synthetizedAttribute_identifierString () ;
      inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("oa_parser.galgas", 20)) ;
      GGS_luint var_step_740 ;
      switch (select_oa_5F_parser_1 (inCompiler)) {
      case 1: {
        var_step_740 = GGS_luint::init_21__21_ (GGS_uint (uint32_t (1U)), GGS_location::class_func_here (inCompiler  COMMA_SOURCE_FILE ("oa_parser.galgas", 23)), inCompiler COMMA_HERE) ;
      } break ;
      case 2: {
        inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_scalingfactor COMMA_SOURCE_FILE ("oa_parser.galgas", 25)) ;
        var_step_740 = inCompiler->synthetizedAttribute_ulongValue () ;
        inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("oa_parser.galgas", 26)) ;
        GalgasBool test_1 = GalgasBool::boolTrue ;
        if (GalgasBool::boolTrue == test_1) {
          test_1 = GGS_bool (ComparisonKind::equal, var_step_740.readProperty_uint ().objectCompare (GGS_uint (uint32_t (0U)))).boolEnum () ;
          if (GalgasBool::boolTrue == test_1) {
            GenericArray <FixItDescription> fixItArray2 ;
            inCompiler->emitSemanticError (var_step_740.readProperty_location (), GGS_string ("the step value must be > 0"), fixItArray2  COMMA_SOURCE_FILE ("oa_parser.galgas", 28)) ;
          }
        }
      } break ;
      default:
        break ;
      }
      {
      var_outProcessorMap_474.setter_insertKey (var_processorName_711, var_outProcessorMap_474.getter_count (SOURCE_FILE ("oa_parser.galgas", 31)), var_step_740, inCompiler COMMA_SOURCE_FILE ("oa_parser.galgas", 31)) ;
      }
      inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken__3B_ COMMA_SOURCE_FILE ("oa_parser.galgas", 32)) ;
    } break ;
    case 3: {
      GGS_bool var_network_1064 ;
      switch (select_oa_5F_parser_2 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_can COMMA_SOURCE_FILE ("oa_parser.galgas", 36)) ;
        var_network_1064 = GGS_bool (true) ;
      } break ;
      case 2: {
        inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_van COMMA_SOURCE_FILE ("oa_parser.galgas", 39)) ;
        var_network_1064 = GGS_bool (false) ;
      } break ;
      default:
        break ;
      }
      inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_network COMMA_SOURCE_FILE ("oa_parser.galgas", 42)) ;
      GGS_lstring var_networkName_1201 = inCompiler->synthetizedAttribute_identifierString () ;
      inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("oa_parser.galgas", 43)) ;
      GGS_luint var_factor_1228 ;
      switch (select_oa_5F_parser_3 (inCompiler)) {
      case 1: {
        var_factor_1228 = GGS_luint::init_21__21_ (GGS_uint (uint32_t (1U)), GGS_location::class_func_here (inCompiler  COMMA_SOURCE_FILE ("oa_parser.galgas", 46)), inCompiler COMMA_HERE) ;
      } break ;
      case 2: {
        inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_scalingfactor COMMA_SOURCE_FILE ("oa_parser.galgas", 48)) ;
        var_factor_1228 = inCompiler->synthetizedAttribute_ulongValue () ;
        inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("oa_parser.galgas", 49)) ;
        GalgasBool test_3 = GalgasBool::boolTrue ;
        if (GalgasBool::boolTrue == test_3) {
          test_3 = GGS_bool (ComparisonKind::equal, var_factor_1228.readProperty_uint ().objectCompare (GGS_uint (uint32_t (0U)))).boolEnum () ;
          if (GalgasBool::boolTrue == test_3) {
            GenericArray <FixItDescription> fixItArray4 ;
            inCompiler->emitSemanticError (var_factor_1228.readProperty_location (), GGS_string ("the factor value must be > 0"), fixItArray4  COMMA_SOURCE_FILE ("oa_parser.galgas", 51)) ;
          }
        }
      } break ;
      default:
        break ;
      }
      {
      var_outNetworkMap_525.setter_insertKey (var_networkName_1201, var_outNetworkMap_525.getter_count (SOURCE_FILE ("oa_parser.galgas", 54)), var_network_1064, var_factor_1228, inCompiler COMMA_SOURCE_FILE ("oa_parser.galgas", 54)) ;
      }
      inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken__3B_ COMMA_SOURCE_FILE ("oa_parser.galgas", 55)) ;
    } break ;
    case 4: {
      inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_task COMMA_SOURCE_FILE ("oa_parser.galgas", 57)) ;
      GGS_lstring var_taskName_1588 = inCompiler->synthetizedAttribute_identifierString () ;
      inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("oa_parser.galgas", 58)) ;
      inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_priority COMMA_SOURCE_FILE ("oa_parser.galgas", 59)) ;
      GGS_luint var_taskPriority_1639 = inCompiler->synthetizedAttribute_ulongValue () ;
      inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("oa_parser.galgas", 60)) ;
      inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_duration COMMA_SOURCE_FILE ("oa_parser.galgas", 61)) ;
      GGS_luint var_taskDurationMin_1694 = inCompiler->synthetizedAttribute_ulongValue () ;
      inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("oa_parser.galgas", 62)) ;
      inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken__2E__2E_ COMMA_SOURCE_FILE ("oa_parser.galgas", 63)) ;
      GGS_luint var_taskDurationMax_1746 = inCompiler->synthetizedAttribute_ulongValue () ;
      inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("oa_parser.galgas", 64)) ;
      GGS_luint var_taskOffset_1777 ;
      GGS_bool var_explicitOffset_1802 ;
      switch (select_oa_5F_parser_4 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_offset COMMA_SOURCE_FILE ("oa_parser.galgas", 68)) ;
        var_taskOffset_1777 = inCompiler->synthetizedAttribute_ulongValue () ;
        inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("oa_parser.galgas", 69)) ;
        var_explicitOffset_1802 = GGS_bool (true) ;
      } break ;
      case 2: {
        var_taskOffset_1777 = GGS_luint::init_21__21_ (GGS_uint (uint32_t (0U)), GGS_location::class_func_here (inCompiler  COMMA_SOURCE_FILE ("oa_parser.galgas", 72)), inCompiler COMMA_HERE) ;
        var_explicitOffset_1802 = GGS_bool (false) ;
      } break ;
      default:
        break ;
      }
      GGS_luint var_taskDeadline_2016 ;
      switch (select_oa_5F_parser_5 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_deadline COMMA_SOURCE_FILE ("oa_parser.galgas", 77)) ;
        var_taskDeadline_2016 = inCompiler->synthetizedAttribute_ulongValue () ;
        inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("oa_parser.galgas", 78)) ;
      } break ;
      case 2: {
        var_taskDeadline_2016 = GGS_luint::init_21__21_ (GGS_uint (uint32_t (4294967295U)), GGS_location::class_func_here (inCompiler  COMMA_SOURCE_FILE ("oa_parser.galgas", 80)), inCompiler COMMA_HERE) ;
      } break ;
      default:
        break ;
      }
      GGS_AC_5F_task var_taskKind_2187 ;
      GGS_uint var_taskProcessorIndex_2210 ;
      GGS_luint var_taskPeriod_2244 ;
      switch (select_oa_5F_parser_6 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_period COMMA_SOURCE_FILE ("oa_parser.galgas", 86)) ;
        var_taskPeriod_2244 = inCompiler->synthetizedAttribute_ulongValue () ;
        inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("oa_parser.galgas", 87)) ;
        inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_processor COMMA_SOURCE_FILE ("oa_parser.galgas", 88)) ;
        GGS_lstring var_taskProcessorName_2360 = inCompiler->synthetizedAttribute_identifierString () ;
        inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("oa_parser.galgas", 89)) ;
        GGS_luint joker_2450 ; // Joker input parameter
        var_outProcessorMap_474.method_searchKey (var_taskProcessorName_2360, var_taskProcessorIndex_2210, joker_2450, inCompiler COMMA_SOURCE_FILE ("oa_parser.galgas", 90)) ;
        var_taskKind_2187 = GGS_C_5F_independantTask::init (inCompiler COMMA_HERE) ;
      } break ;
      case 2: {
        inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_on COMMA_SOURCE_FILE ("oa_parser.galgas", 93)) ;
        GalgasBool test_5 = GalgasBool::boolTrue ;
        if (GalgasBool::boolTrue == test_5) {
          test_5 = var_explicitOffset_1802.boolEnum () ;
          if (GalgasBool::boolTrue == test_5) {
            GenericArray <FixItDescription> fixItArray6 ;
            inCompiler->emitSemanticError (GGS_location::class_func_here (inCompiler  COMMA_SOURCE_FILE ("oa_parser.galgas", 95)), GGS_string ("A dependant task cannot have an offset"), fixItArray6  COMMA_SOURCE_FILE ("oa_parser.galgas", 95)) ;
          }
        }
        switch (select_oa_5F_parser_7 (inCompiler)) {
        case 1: {
          inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_task COMMA_SOURCE_FILE ("oa_parser.galgas", 98)) ;
          GGS_lstring var_masterTaskName_2676 = inCompiler->synthetizedAttribute_identifierString () ;
          inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("oa_parser.galgas", 99)) ;
          GGS_luint var_every_2710 ;
          switch (select_oa_5F_parser_8 (inCompiler)) {
          case 1: {
            var_every_2710 = GGS_luint::init_21__21_ (GGS_uint (uint32_t (1U)), GGS_location::class_func_here (inCompiler  COMMA_SOURCE_FILE ("oa_parser.galgas", 102)), inCompiler COMMA_HERE) ;
          } break ;
          case 2: {
            inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_every COMMA_SOURCE_FILE ("oa_parser.galgas", 104)) ;
            var_every_2710 = inCompiler->synthetizedAttribute_ulongValue () ;
            inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("oa_parser.galgas", 105)) ;
          } break ;
          default:
            break ;
          }
          GGS_uint var_masterTaskIndex_2906 ;
          GGS_luint joker_2922 ; // Joker input parameter
          GGS_luint joker_2925 ; // Joker input parameter
          GGS_luint joker_2928 ; // Joker input parameter
          GGS_luint joker_2931 ; // Joker input parameter
          GGS_luint joker_2934 ; // Joker input parameter
          GGS_AC_5F_task joker_2969 ; // Joker input parameter
          var_outTaskMap_620.method_searchKey (var_masterTaskName_2676, var_masterTaskIndex_2906, joker_2922, joker_2925, joker_2928, joker_2931, joker_2934, var_taskProcessorIndex_2210, var_taskPeriod_2244, joker_2969, inCompiler COMMA_SOURCE_FILE ("oa_parser.galgas", 107)) ;
          var_taskKind_2187 = GGS_C_5F_taskDependsFromTask::init_21__21_ (var_masterTaskIndex_2906, var_every_2710, inCompiler COMMA_HERE) ;
        } break ;
        case 2: {
          inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_message COMMA_SOURCE_FILE ("oa_parser.galgas", 110)) ;
          GGS_lstring var_masterMessageName_3095 = inCompiler->synthetizedAttribute_identifierString () ;
          inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("oa_parser.galgas", 111)) ;
          GGS_uint var_masterMessageIndex_3171 ;
          GGS_luint joker_3190 ; // Joker input parameter
          GGS_uint joker_3193 ; // Joker input parameter
          GGS_luint joker_3196 ; // Joker input parameter
          GGS_luint joker_3199 ; // Joker input parameter
          GGS_luint joker_3202 ; // Joker input parameter
          GGS_luint joker_3205 ; // Joker input parameter
          GGS_AC_5F_canMessage joker_3220 ; // Joker input parameter
          var_outMessagesMap_573.method_searchKey (var_masterMessageName_3095, var_masterMessageIndex_3171, joker_3190, joker_3193, joker_3196, joker_3199, joker_3202, joker_3205, var_taskPeriod_2244, joker_3220, inCompiler COMMA_SOURCE_FILE ("oa_parser.galgas", 112)) ;
          inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_processor COMMA_SOURCE_FILE ("oa_parser.galgas", 113)) ;
          GGS_lstring var_taskProcessorName_3270 = inCompiler->synthetizedAttribute_identifierString () ;
          inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("oa_parser.galgas", 114)) ;
          GGS_luint var_every_3307 ;
          switch (select_oa_5F_parser_9 (inCompiler)) {
          case 1: {
            var_every_3307 = GGS_luint::init_21__21_ (GGS_uint (uint32_t (1U)), GGS_location::class_func_here (inCompiler  COMMA_SOURCE_FILE ("oa_parser.galgas", 117)), inCompiler COMMA_HERE) ;
          } break ;
          case 2: {
            inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_every COMMA_SOURCE_FILE ("oa_parser.galgas", 119)) ;
            var_every_3307 = inCompiler->synthetizedAttribute_ulongValue () ;
            inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("oa_parser.galgas", 120)) ;
          } break ;
          default:
            break ;
          }
          GGS_luint joker_3526 ; // Joker input parameter
          var_outProcessorMap_474.method_searchKey (var_taskProcessorName_3270, var_taskProcessorIndex_2210, joker_3526, inCompiler COMMA_SOURCE_FILE ("oa_parser.galgas", 122)) ;
          var_taskKind_2187 = GGS_C_5F_taskDependsFromMessage::init_21__21_ (var_masterMessageIndex_3171, var_every_3307, inCompiler COMMA_HERE) ;
        } break ;
        default:
          break ;
        }
      } break ;
      default:
        break ;
      }
      {
      var_outTaskMap_620.setter_insertKey (var_taskName_1588, var_outTaskMap_620.getter_count (SOURCE_FILE ("oa_parser.galgas", 126)), var_taskPriority_1639, var_taskOffset_1777, var_taskDeadline_2016, var_taskDurationMin_1694, var_taskDurationMax_1746, var_taskProcessorIndex_2210, var_taskPeriod_2244, var_taskKind_2187, inCompiler COMMA_SOURCE_FILE ("oa_parser.galgas", 126)) ;
      }
      inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken__3B_ COMMA_SOURCE_FILE ("oa_parser.galgas", 135)) ;
    } break ;
    case 5: {
      GGS_luint var_messageClass_4147 ;
      switch (select_oa_5F_parser_10 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_standard COMMA_SOURCE_FILE ("oa_parser.galgas", 139)) ;
        var_messageClass_4147 = GGS_luint::init_21__21_ (GGS_uint (uint32_t (0U)), GGS_location::class_func_here (inCompiler  COMMA_SOURCE_FILE ("oa_parser.galgas", 140)), inCompiler COMMA_HERE) ;
        inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_message COMMA_SOURCE_FILE ("oa_parser.galgas", 141)) ;
      } break ;
      case 2: {
        inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_extended COMMA_SOURCE_FILE ("oa_parser.galgas", 143)) ;
        var_messageClass_4147 = GGS_luint::init_21__21_ (GGS_uint (uint32_t (1U)), GGS_location::class_func_here (inCompiler  COMMA_SOURCE_FILE ("oa_parser.galgas", 144)), inCompiler COMMA_HERE) ;
        inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_message COMMA_SOURCE_FILE ("oa_parser.galgas", 145)) ;
      } break ;
      case 3: {
        inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_message COMMA_SOURCE_FILE ("oa_parser.galgas", 147)) ;
        var_messageClass_4147 = GGS_luint::init_21__21_ (GGS_uint (uint32_t (2U)), GGS_location::class_func_here (inCompiler  COMMA_SOURCE_FILE ("oa_parser.galgas", 148)), inCompiler COMMA_HERE) ;
      } break ;
      default:
        break ;
      }
      GGS_lstring var_messageName_4447 = inCompiler->synthetizedAttribute_identifierString () ;
      inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("oa_parser.galgas", 150)) ;
      inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_network COMMA_SOURCE_FILE ("oa_parser.galgas", 151)) ;
      GGS_lstring var_networkName_4495 = inCompiler->synthetizedAttribute_identifierString () ;
      inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("oa_parser.galgas", 152)) ;
      GGS_uint var_networkIndex_4554 ;
      GGS_bool var_CANnetwork_4572 ;
      GGS_luint joker_4583 ; // Joker input parameter
      var_outNetworkMap_525.method_searchKey (var_networkName_4495, var_networkIndex_4554, var_CANnetwork_4572, joker_4583, inCompiler COMMA_SOURCE_FILE ("oa_parser.galgas", 153)) ;
      GalgasBool test_7 = GalgasBool::boolTrue ;
      if (GalgasBool::boolTrue == test_7) {
        test_7 = var_CANnetwork_4572.operator_and (GGS_bool (ComparisonKind::equal, var_messageClass_4147.readProperty_uint ().objectCompare (GGS_uint (uint32_t (2U)))) COMMA_SOURCE_FILE ("oa_parser.galgas", 154)).boolEnum () ;
        if (GalgasBool::boolTrue == test_7) {
          GenericArray <FixItDescription> fixItArray8 ;
          inCompiler->emitSemanticError (var_messageClass_4147.readProperty_location (), GGS_string ("a CAN message must be either standard either extended"), fixItArray8  COMMA_SOURCE_FILE ("oa_parser.galgas", 155)) ;
        }
      }
      if (GalgasBool::boolFalse == test_7) {
        GalgasBool test_9 = GalgasBool::boolTrue ;
        if (GalgasBool::boolTrue == test_9) {
          test_9 = var_CANnetwork_4572.operator_not (SOURCE_FILE ("oa_parser.galgas", 156)).operator_and (GGS_bool (ComparisonKind::notEqual, var_messageClass_4147.readProperty_uint ().objectCompare (GGS_uint (uint32_t (2U)))) COMMA_SOURCE_FILE ("oa_parser.galgas", 156)).boolEnum () ;
          if (GalgasBool::boolTrue == test_9) {
            GenericArray <FixItDescription> fixItArray10 ;
            inCompiler->emitSemanticError (var_messageClass_4147.readProperty_location (), GGS_string ("a VAN message cannot be standard or extended"), fixItArray10  COMMA_SOURCE_FILE ("oa_parser.galgas", 157)) ;
          }
        }
      }
      inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_length COMMA_SOURCE_FILE ("oa_parser.galgas", 159)) ;
      GGS_luint var_bytesCount_4901 = inCompiler->synthetizedAttribute_ulongValue () ;
      inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("oa_parser.galgas", 160)) ;
      GalgasBool test_11 = GalgasBool::boolTrue ;
      if (GalgasBool::boolTrue == test_11) {
        test_11 = var_CANnetwork_4572.operator_and (GGS_bool (ComparisonKind::greaterThan, var_bytesCount_4901.readProperty_uint ().objectCompare (GGS_uint (uint32_t (8U)))) COMMA_SOURCE_FILE ("oa_parser.galgas", 161)).boolEnum () ;
        if (GalgasBool::boolTrue == test_11) {
          GenericArray <FixItDescription> fixItArray12 ;
          inCompiler->emitSemanticError (var_bytesCount_4901.readProperty_location (), GGS_string ("CAN message length must be <= 8 bytes"), fixItArray12  COMMA_SOURCE_FILE ("oa_parser.galgas", 162)) ;
        }
      }
      if (GalgasBool::boolFalse == test_11) {
        GalgasBool test_13 = GalgasBool::boolTrue ;
        if (GalgasBool::boolTrue == test_13) {
          test_13 = var_CANnetwork_4572.operator_not (SOURCE_FILE ("oa_parser.galgas", 163)).operator_and (GGS_bool (ComparisonKind::greaterThan, var_bytesCount_4901.readProperty_uint ().objectCompare (GGS_uint (uint32_t (28U)))) COMMA_SOURCE_FILE ("oa_parser.galgas", 163)).boolEnum () ;
          if (GalgasBool::boolTrue == test_13) {
            GenericArray <FixItDescription> fixItArray14 ;
            inCompiler->emitSemanticError (var_bytesCount_4901.readProperty_location (), GGS_string ("VAN message must be <= 28 bytes"), fixItArray14  COMMA_SOURCE_FILE ("oa_parser.galgas", 164)) ;
          }
        }
      }
      inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_priority COMMA_SOURCE_FILE ("oa_parser.galgas", 166)) ;
      GGS_luint var_priority_5190 = inCompiler->synthetizedAttribute_ulongValue () ;
      inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("oa_parser.galgas", 167)) ;
      GGS_luint var_offset_5214 ;
      GGS_bool var_explicitOffset_5235 ;
      switch (select_oa_5F_parser_11 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_offset COMMA_SOURCE_FILE ("oa_parser.galgas", 171)) ;
        var_offset_5214 = inCompiler->synthetizedAttribute_ulongValue () ;
        inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("oa_parser.galgas", 172)) ;
        var_explicitOffset_5235 = GGS_bool (true) ;
      } break ;
      case 2: {
        var_offset_5214 = GGS_luint::init_21__21_ (GGS_uint (uint32_t (0U)), GGS_location::class_func_here (inCompiler  COMMA_SOURCE_FILE ("oa_parser.galgas", 175)), inCompiler COMMA_HERE) ;
        var_explicitOffset_5235 = GGS_bool (false) ;
      } break ;
      default:
        break ;
      }
      GGS_luint var_deadline_5440 ;
      switch (select_oa_5F_parser_12 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_deadline COMMA_SOURCE_FILE ("oa_parser.galgas", 180)) ;
        var_deadline_5440 = inCompiler->synthetizedAttribute_ulongValue () ;
        inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("oa_parser.galgas", 181)) ;
      } break ;
      case 2: {
        var_deadline_5440 = GGS_luint::init_21__21_ (GGS_uint (uint32_t (4294967295U)), GGS_location::class_func_here (inCompiler  COMMA_SOURCE_FILE ("oa_parser.galgas", 183)), inCompiler COMMA_HERE) ;
      } break ;
      default:
        break ;
      }
      GGS_AC_5F_canMessage var_messageKind_5605 ;
      GGS_luint var_period_5632 ;
      switch (select_oa_5F_parser_13 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_period COMMA_SOURCE_FILE ("oa_parser.galgas", 188)) ;
        var_period_5632 = inCompiler->synthetizedAttribute_ulongValue () ;
        inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("oa_parser.galgas", 189)) ;
        var_messageKind_5605 = GGS_C_5F_canIndependantMessage::init (inCompiler COMMA_HERE) ;
      } break ;
      case 2: {
        inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_on COMMA_SOURCE_FILE ("oa_parser.galgas", 192)) ;
        GalgasBool test_15 = GalgasBool::boolTrue ;
        if (GalgasBool::boolTrue == test_15) {
          test_15 = var_explicitOffset_5235.boolEnum () ;
          if (GalgasBool::boolTrue == test_15) {
            GenericArray <FixItDescription> fixItArray16 ;
            inCompiler->emitSemanticError (GGS_location::class_func_here (inCompiler  COMMA_SOURCE_FILE ("oa_parser.galgas", 194)), GGS_string ("A dependant task cannot have an offset"), fixItArray16  COMMA_SOURCE_FILE ("oa_parser.galgas", 194)) ;
          }
        }
        switch (select_oa_5F_parser_14 (inCompiler)) {
        case 1: {
          inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_message COMMA_SOURCE_FILE ("oa_parser.galgas", 197)) ;
          GGS_lstring var_name_5932 = inCompiler->synthetizedAttribute_identifierString () ;
          inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("oa_parser.galgas", 198)) ;
          GGS_uint var_messageIndex_5982 ;
          GGS_luint joker_5995 ; // Joker input parameter
          GGS_uint joker_5998 ; // Joker input parameter
          GGS_luint joker_6001 ; // Joker input parameter
          GGS_luint joker_6004 ; // Joker input parameter
          GGS_luint joker_6007 ; // Joker input parameter
          GGS_luint joker_6010 ; // Joker input parameter
          GGS_AC_5F_canMessage joker_6021 ; // Joker input parameter
          var_outMessagesMap_573.method_searchKey (var_name_5932, var_messageIndex_5982, joker_5995, joker_5998, joker_6001, joker_6004, joker_6007, joker_6010, var_period_5632, joker_6021, inCompiler COMMA_SOURCE_FILE ("oa_parser.galgas", 199)) ;
          var_messageKind_5605 = GGS_C_5F_canMessageFromMessage::init_21_ (var_messageIndex_5982, inCompiler COMMA_HERE) ;
        } break ;
        case 2: {
          inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_task COMMA_SOURCE_FILE ("oa_parser.galgas", 202)) ;
          GGS_lstring var_taskName_6139 = inCompiler->synthetizedAttribute_identifierString () ;
          inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("oa_parser.galgas", 203)) ;
          GGS_uint var_taskIndex_6193 ;
          GGS_luint joker_6203 ; // Joker input parameter
          GGS_luint joker_6206 ; // Joker input parameter
          GGS_luint joker_6209 ; // Joker input parameter
          GGS_luint joker_6212 ; // Joker input parameter
          GGS_luint joker_6215 ; // Joker input parameter
          GGS_uint joker_6218 ; // Joker input parameter
          GGS_AC_5F_task joker_6229 ; // Joker input parameter
          var_outTaskMap_620.method_searchKey (var_taskName_6139, var_taskIndex_6193, joker_6203, joker_6206, joker_6209, joker_6212, joker_6215, joker_6218, var_period_5632, joker_6229, inCompiler COMMA_SOURCE_FILE ("oa_parser.galgas", 204)) ;
          var_messageKind_5605 = GGS_C_5F_canMessageFromTask::init_21_ (var_taskIndex_6193, inCompiler COMMA_HERE) ;
        } break ;
        default:
          break ;
        }
      } break ;
      default:
        break ;
      }
      {
      var_outMessagesMap_573.setter_insertKey (var_messageName_4447, var_outMessagesMap_573.getter_count (SOURCE_FILE ("oa_parser.galgas", 208)), var_messageClass_4147, var_networkIndex_4554, var_bytesCount_4901, var_priority_5190, var_offset_5214, var_deadline_5440, var_period_5632, var_messageKind_5605, inCompiler COMMA_SOURCE_FILE ("oa_parser.galgas", 208)) ;
      }
      inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken__3B_ COMMA_SOURCE_FILE ("oa_parser.galgas", 210)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_end COMMA_SOURCE_FILE ("oa_parser.galgas", 212)) ;
  {
  routine_performComputations_26__26__26__26_ (var_outProcessorMap_474, var_outNetworkMap_525, var_outMessagesMap_573, var_outTaskMap_620, inCompiler  COMMA_SOURCE_FILE ("oa_parser.galgas", 213)) ;
  }
}

//------------------------------------------------------------------------------------------------

void cParser_oa_5F_parser::rule_oa_5F_parser_axiome_i0_parse (Lexique_oa_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_system COMMA_SOURCE_FILE ("oa_parser.galgas", 16)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_oa_5F_parser_0 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_processor COMMA_SOURCE_FILE ("oa_parser.galgas", 19)) ;
      inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("oa_parser.galgas", 20)) ;
      switch (select_oa_5F_parser_1 (inCompiler)) {
      case 1: {
      } break ;
      case 2: {
        inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_scalingfactor COMMA_SOURCE_FILE ("oa_parser.galgas", 25)) ;
        inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("oa_parser.galgas", 26)) ;
      } break ;
      default:
        break ;
      }
      inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken__3B_ COMMA_SOURCE_FILE ("oa_parser.galgas", 32)) ;
    } break ;
    case 3: {
      switch (select_oa_5F_parser_2 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_can COMMA_SOURCE_FILE ("oa_parser.galgas", 36)) ;
      } break ;
      case 2: {
        inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_van COMMA_SOURCE_FILE ("oa_parser.galgas", 39)) ;
      } break ;
      default:
        break ;
      }
      inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_network COMMA_SOURCE_FILE ("oa_parser.galgas", 42)) ;
      inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("oa_parser.galgas", 43)) ;
      switch (select_oa_5F_parser_3 (inCompiler)) {
      case 1: {
      } break ;
      case 2: {
        inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_scalingfactor COMMA_SOURCE_FILE ("oa_parser.galgas", 48)) ;
        inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("oa_parser.galgas", 49)) ;
      } break ;
      default:
        break ;
      }
      inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken__3B_ COMMA_SOURCE_FILE ("oa_parser.galgas", 55)) ;
    } break ;
    case 4: {
      inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_task COMMA_SOURCE_FILE ("oa_parser.galgas", 57)) ;
      inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("oa_parser.galgas", 58)) ;
      inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_priority COMMA_SOURCE_FILE ("oa_parser.galgas", 59)) ;
      inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("oa_parser.galgas", 60)) ;
      inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_duration COMMA_SOURCE_FILE ("oa_parser.galgas", 61)) ;
      inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("oa_parser.galgas", 62)) ;
      inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken__2E__2E_ COMMA_SOURCE_FILE ("oa_parser.galgas", 63)) ;
      inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("oa_parser.galgas", 64)) ;
      switch (select_oa_5F_parser_4 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_offset COMMA_SOURCE_FILE ("oa_parser.galgas", 68)) ;
        inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("oa_parser.galgas", 69)) ;
      } break ;
      case 2: {
      } break ;
      default:
        break ;
      }
      switch (select_oa_5F_parser_5 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_deadline COMMA_SOURCE_FILE ("oa_parser.galgas", 77)) ;
        inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("oa_parser.galgas", 78)) ;
      } break ;
      case 2: {
      } break ;
      default:
        break ;
      }
      switch (select_oa_5F_parser_6 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_period COMMA_SOURCE_FILE ("oa_parser.galgas", 86)) ;
        inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("oa_parser.galgas", 87)) ;
        inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_processor COMMA_SOURCE_FILE ("oa_parser.galgas", 88)) ;
        inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("oa_parser.galgas", 89)) ;
      } break ;
      case 2: {
        inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_on COMMA_SOURCE_FILE ("oa_parser.galgas", 93)) ;
        switch (select_oa_5F_parser_7 (inCompiler)) {
        case 1: {
          inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_task COMMA_SOURCE_FILE ("oa_parser.galgas", 98)) ;
          inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("oa_parser.galgas", 99)) ;
          switch (select_oa_5F_parser_8 (inCompiler)) {
          case 1: {
          } break ;
          case 2: {
            inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_every COMMA_SOURCE_FILE ("oa_parser.galgas", 104)) ;
            inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("oa_parser.galgas", 105)) ;
          } break ;
          default:
            break ;
          }
        } break ;
        case 2: {
          inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_message COMMA_SOURCE_FILE ("oa_parser.galgas", 110)) ;
          inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("oa_parser.galgas", 111)) ;
          inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_processor COMMA_SOURCE_FILE ("oa_parser.galgas", 113)) ;
          inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("oa_parser.galgas", 114)) ;
          switch (select_oa_5F_parser_9 (inCompiler)) {
          case 1: {
          } break ;
          case 2: {
            inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_every COMMA_SOURCE_FILE ("oa_parser.galgas", 119)) ;
            inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("oa_parser.galgas", 120)) ;
          } break ;
          default:
            break ;
          }
        } break ;
        default:
          break ;
        }
      } break ;
      default:
        break ;
      }
      inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken__3B_ COMMA_SOURCE_FILE ("oa_parser.galgas", 135)) ;
    } break ;
    case 5: {
      switch (select_oa_5F_parser_10 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_standard COMMA_SOURCE_FILE ("oa_parser.galgas", 139)) ;
        inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_message COMMA_SOURCE_FILE ("oa_parser.galgas", 141)) ;
      } break ;
      case 2: {
        inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_extended COMMA_SOURCE_FILE ("oa_parser.galgas", 143)) ;
        inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_message COMMA_SOURCE_FILE ("oa_parser.galgas", 145)) ;
      } break ;
      case 3: {
        inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_message COMMA_SOURCE_FILE ("oa_parser.galgas", 147)) ;
      } break ;
      default:
        break ;
      }
      inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("oa_parser.galgas", 150)) ;
      inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_network COMMA_SOURCE_FILE ("oa_parser.galgas", 151)) ;
      inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("oa_parser.galgas", 152)) ;
      inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_length COMMA_SOURCE_FILE ("oa_parser.galgas", 159)) ;
      inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("oa_parser.galgas", 160)) ;
      inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_priority COMMA_SOURCE_FILE ("oa_parser.galgas", 166)) ;
      inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("oa_parser.galgas", 167)) ;
      switch (select_oa_5F_parser_11 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_offset COMMA_SOURCE_FILE ("oa_parser.galgas", 171)) ;
        inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("oa_parser.galgas", 172)) ;
      } break ;
      case 2: {
      } break ;
      default:
        break ;
      }
      switch (select_oa_5F_parser_12 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_deadline COMMA_SOURCE_FILE ("oa_parser.galgas", 180)) ;
        inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("oa_parser.galgas", 181)) ;
      } break ;
      case 2: {
      } break ;
      default:
        break ;
      }
      switch (select_oa_5F_parser_13 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_period COMMA_SOURCE_FILE ("oa_parser.galgas", 188)) ;
        inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("oa_parser.galgas", 189)) ;
      } break ;
      case 2: {
        inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_on COMMA_SOURCE_FILE ("oa_parser.galgas", 192)) ;
        switch (select_oa_5F_parser_14 (inCompiler)) {
        case 1: {
          inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_message COMMA_SOURCE_FILE ("oa_parser.galgas", 197)) ;
          inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("oa_parser.galgas", 198)) ;
        } break ;
        case 2: {
          inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_task COMMA_SOURCE_FILE ("oa_parser.galgas", 202)) ;
          inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("oa_parser.galgas", 203)) ;
        } break ;
        default:
          break ;
        }
      } break ;
      default:
        break ;
      }
      inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken__3B_ COMMA_SOURCE_FILE ("oa_parser.galgas", 210)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_end COMMA_SOURCE_FILE ("oa_parser.galgas", 212)) ;
  inCompiler->resetTemplateString () ;
}

//------------------------------------------------------------------------------------------------

void cParser_oa_5F_parser::rule_oa_5F_parser_axiome_i0_indexing (Lexique_oa_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_system COMMA_SOURCE_FILE ("oa_parser.galgas", 16)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_oa_5F_parser_0 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_processor COMMA_SOURCE_FILE ("oa_parser.galgas", 19)) ;
      inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("oa_parser.galgas", 20)) ;
      switch (select_oa_5F_parser_1 (inCompiler)) {
      case 1: {
      } break ;
      case 2: {
        inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_scalingfactor COMMA_SOURCE_FILE ("oa_parser.galgas", 25)) ;
        inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("oa_parser.galgas", 26)) ;
      } break ;
      default:
        break ;
      }
      inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken__3B_ COMMA_SOURCE_FILE ("oa_parser.galgas", 32)) ;
    } break ;
    case 3: {
      switch (select_oa_5F_parser_2 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_can COMMA_SOURCE_FILE ("oa_parser.galgas", 36)) ;
      } break ;
      case 2: {
        inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_van COMMA_SOURCE_FILE ("oa_parser.galgas", 39)) ;
      } break ;
      default:
        break ;
      }
      inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_network COMMA_SOURCE_FILE ("oa_parser.galgas", 42)) ;
      inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("oa_parser.galgas", 43)) ;
      switch (select_oa_5F_parser_3 (inCompiler)) {
      case 1: {
      } break ;
      case 2: {
        inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_scalingfactor COMMA_SOURCE_FILE ("oa_parser.galgas", 48)) ;
        inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("oa_parser.galgas", 49)) ;
      } break ;
      default:
        break ;
      }
      inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken__3B_ COMMA_SOURCE_FILE ("oa_parser.galgas", 55)) ;
    } break ;
    case 4: {
      inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_task COMMA_SOURCE_FILE ("oa_parser.galgas", 57)) ;
      inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("oa_parser.galgas", 58)) ;
      inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_priority COMMA_SOURCE_FILE ("oa_parser.galgas", 59)) ;
      inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("oa_parser.galgas", 60)) ;
      inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_duration COMMA_SOURCE_FILE ("oa_parser.galgas", 61)) ;
      inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("oa_parser.galgas", 62)) ;
      inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken__2E__2E_ COMMA_SOURCE_FILE ("oa_parser.galgas", 63)) ;
      inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("oa_parser.galgas", 64)) ;
      switch (select_oa_5F_parser_4 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_offset COMMA_SOURCE_FILE ("oa_parser.galgas", 68)) ;
        inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("oa_parser.galgas", 69)) ;
      } break ;
      case 2: {
      } break ;
      default:
        break ;
      }
      switch (select_oa_5F_parser_5 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_deadline COMMA_SOURCE_FILE ("oa_parser.galgas", 77)) ;
        inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("oa_parser.galgas", 78)) ;
      } break ;
      case 2: {
      } break ;
      default:
        break ;
      }
      switch (select_oa_5F_parser_6 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_period COMMA_SOURCE_FILE ("oa_parser.galgas", 86)) ;
        inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("oa_parser.galgas", 87)) ;
        inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_processor COMMA_SOURCE_FILE ("oa_parser.galgas", 88)) ;
        inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("oa_parser.galgas", 89)) ;
      } break ;
      case 2: {
        inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_on COMMA_SOURCE_FILE ("oa_parser.galgas", 93)) ;
        switch (select_oa_5F_parser_7 (inCompiler)) {
        case 1: {
          inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_task COMMA_SOURCE_FILE ("oa_parser.galgas", 98)) ;
          inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("oa_parser.galgas", 99)) ;
          switch (select_oa_5F_parser_8 (inCompiler)) {
          case 1: {
          } break ;
          case 2: {
            inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_every COMMA_SOURCE_FILE ("oa_parser.galgas", 104)) ;
            inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("oa_parser.galgas", 105)) ;
          } break ;
          default:
            break ;
          }
        } break ;
        case 2: {
          inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_message COMMA_SOURCE_FILE ("oa_parser.galgas", 110)) ;
          inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("oa_parser.galgas", 111)) ;
          inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_processor COMMA_SOURCE_FILE ("oa_parser.galgas", 113)) ;
          inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("oa_parser.galgas", 114)) ;
          switch (select_oa_5F_parser_9 (inCompiler)) {
          case 1: {
          } break ;
          case 2: {
            inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_every COMMA_SOURCE_FILE ("oa_parser.galgas", 119)) ;
            inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("oa_parser.galgas", 120)) ;
          } break ;
          default:
            break ;
          }
        } break ;
        default:
          break ;
        }
      } break ;
      default:
        break ;
      }
      inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken__3B_ COMMA_SOURCE_FILE ("oa_parser.galgas", 135)) ;
    } break ;
    case 5: {
      switch (select_oa_5F_parser_10 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_standard COMMA_SOURCE_FILE ("oa_parser.galgas", 139)) ;
        inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_message COMMA_SOURCE_FILE ("oa_parser.galgas", 141)) ;
      } break ;
      case 2: {
        inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_extended COMMA_SOURCE_FILE ("oa_parser.galgas", 143)) ;
        inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_message COMMA_SOURCE_FILE ("oa_parser.galgas", 145)) ;
      } break ;
      case 3: {
        inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_message COMMA_SOURCE_FILE ("oa_parser.galgas", 147)) ;
      } break ;
      default:
        break ;
      }
      inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("oa_parser.galgas", 150)) ;
      inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_network COMMA_SOURCE_FILE ("oa_parser.galgas", 151)) ;
      inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("oa_parser.galgas", 152)) ;
      inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_length COMMA_SOURCE_FILE ("oa_parser.galgas", 159)) ;
      inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("oa_parser.galgas", 160)) ;
      inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_priority COMMA_SOURCE_FILE ("oa_parser.galgas", 166)) ;
      inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("oa_parser.galgas", 167)) ;
      switch (select_oa_5F_parser_11 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_offset COMMA_SOURCE_FILE ("oa_parser.galgas", 171)) ;
        inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("oa_parser.galgas", 172)) ;
      } break ;
      case 2: {
      } break ;
      default:
        break ;
      }
      switch (select_oa_5F_parser_12 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_deadline COMMA_SOURCE_FILE ("oa_parser.galgas", 180)) ;
        inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("oa_parser.galgas", 181)) ;
      } break ;
      case 2: {
      } break ;
      default:
        break ;
      }
      switch (select_oa_5F_parser_13 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_period COMMA_SOURCE_FILE ("oa_parser.galgas", 188)) ;
        inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("oa_parser.galgas", 189)) ;
      } break ;
      case 2: {
        inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_on COMMA_SOURCE_FILE ("oa_parser.galgas", 192)) ;
        switch (select_oa_5F_parser_14 (inCompiler)) {
        case 1: {
          inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_message COMMA_SOURCE_FILE ("oa_parser.galgas", 197)) ;
          inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("oa_parser.galgas", 198)) ;
        } break ;
        case 2: {
          inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_task COMMA_SOURCE_FILE ("oa_parser.galgas", 202)) ;
          inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("oa_parser.galgas", 203)) ;
        } break ;
        default:
          break ;
        }
      } break ;
      default:
        break ;
      }
      inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken__3B_ COMMA_SOURCE_FILE ("oa_parser.galgas", 210)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->acceptTerminal (Lexique_oa_5F_scanner::kToken_end COMMA_SOURCE_FILE ("oa_parser.galgas", 212)) ;
}

//--------------------------------------------------------------------------------------------------
// @C_5F_taskDependsFromTask reference class
//--------------------------------------------------------------------------------------------------

ComparisonResult GGS_C_5F_taskDependsFromTask::objectCompare (const GGS_C_5F_taskDependsFromTask & inOperand) const {
  ComparisonResult result = ComparisonResult::invalid ;
  if (isValid () && inOperand.isValid ()) {
    const size_t myObjectPtr = size_t (mObjectPtr) ;
    const size_t operandObjectPtr = size_t (inOperand.mObjectPtr) ;
    if (myObjectPtr < operandObjectPtr) {
      result = ComparisonResult::firstOperandLowerThanSecond ;
    }else if (myObjectPtr > operandObjectPtr) {
      result = ComparisonResult::firstOperandGreaterThanSecond ;
    }else{
      result = ComparisonResult::operandEqual ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_C_5F_taskDependsFromTask::GGS_C_5F_taskDependsFromTask (void) :
GGS_AC_5F_task () {
}

//--- Synthetized initializer ----------------------------------------------------------------------

GGS_C_5F_taskDependsFromTask GGS_C_5F_taskDependsFromTask::
init_21__21_ (const GGS_uint & in_mTask,
              const GGS_luint & in_mEvery,
              Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  cPtr_C_5F_taskDependsFromTask * object = nullptr ;
  macroMyNew (object, cPtr_C_5F_taskDependsFromTask (inCompiler COMMA_THERE)) ;
  object->C_5F_taskDependsFromTask_init_21__21_ (in_mTask, in_mEvery, inCompiler) ;
  const GGS_C_5F_taskDependsFromTask result (object) ;
  macroDetachSharedObject (object) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

void cPtr_C_5F_taskDependsFromTask::
C_5F_taskDependsFromTask_init_21__21_ (const GGS_uint & in_mTask,
                                       const GGS_luint & in_mEvery,
                                       Compiler * /* inCompiler */) {
  mProperty_mTask = in_mTask ;
  mProperty_mEvery = in_mEvery ;
}

//--------------------------------------------------------------------------------------------------

GGS_C_5F_taskDependsFromTask::GGS_C_5F_taskDependsFromTask (const cPtr_C_5F_taskDependsFromTask * inSourcePtr) :
GGS_AC_5F_task (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_C_5F_taskDependsFromTask) ;
}
//--------------------------------------------------------------------------------------------------

GGS_C_5F_taskDependsFromTask GGS_C_5F_taskDependsFromTask::class_func_new (const GGS_uint & in_mTask,
                                                                           const GGS_luint & in_mEvery,
                                                                           Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) {
  GGS_C_5F_taskDependsFromTask result ;
  macroMyNew (result.mObjectPtr, cPtr_C_5F_taskDependsFromTask (in_mTask, in_mEvery,  inCompiler COMMA_THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_uint GGS_C_5F_taskDependsFromTask::readProperty_mTask (void) const {
  if (nullptr == mObjectPtr) {
    return GGS_uint () ;
  }else{
    cPtr_C_5F_taskDependsFromTask * p = (cPtr_C_5F_taskDependsFromTask *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_C_5F_taskDependsFromTask) ;
    return p->mProperty_mTask ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_C_5F_taskDependsFromTask::setProperty_mTask (const GGS_uint & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_C_5F_taskDependsFromTask * p = (cPtr_C_5F_taskDependsFromTask *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_C_5F_taskDependsFromTask) ;
    p->mProperty_mTask = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

GGS_luint GGS_C_5F_taskDependsFromTask::readProperty_mEvery (void) const {
  if (nullptr == mObjectPtr) {
    return GGS_luint () ;
  }else{
    cPtr_C_5F_taskDependsFromTask * p = (cPtr_C_5F_taskDependsFromTask *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_C_5F_taskDependsFromTask) ;
    return p->mProperty_mEvery ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_C_5F_taskDependsFromTask::setProperty_mEvery (const GGS_luint & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_C_5F_taskDependsFromTask * p = (cPtr_C_5F_taskDependsFromTask *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_C_5F_taskDependsFromTask) ;
    p->mProperty_mEvery = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------
//Pointer class for @C_taskDependsFromTask class
//--------------------------------------------------------------------------------------------------

cPtr_C_5F_taskDependsFromTask::cPtr_C_5F_taskDependsFromTask (Compiler * inCompiler COMMA_LOCATION_ARGS) :
cPtr_AC_5F_task (inCompiler COMMA_THERE),
mProperty_mTask (),
mProperty_mEvery () {
}

//--------------------------------------------------------------------------------------------------

cPtr_C_5F_taskDependsFromTask::cPtr_C_5F_taskDependsFromTask (const GGS_uint & in_mTask,
                                                              const GGS_luint & in_mEvery,
                                                              Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) :
cPtr_AC_5F_task (inCompiler COMMA_THERE),
mProperty_mTask (),
mProperty_mEvery () {
  mProperty_mTask = in_mTask ;
  mProperty_mEvery = in_mEvery ;
}

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * cPtr_C_5F_taskDependsFromTask::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_C_5F_taskDependsFromTask ;
}

void cPtr_C_5F_taskDependsFromTask::description (String & ioString,
                                                 const int32_t inIndentation) const {
  ioString.appendCString ("[@C_taskDependsFromTask:") ;
  mProperty_mTask.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_mEvery.description (ioString, inIndentation+1) ;
  ioString.appendCString ("]") ;
}

//--------------------------------------------------------------------------------------------------

acPtr_class * cPtr_C_5F_taskDependsFromTask::duplicate (Compiler * inCompiler COMMA_LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_C_5F_taskDependsFromTask (mProperty_mTask, mProperty_mEvery, inCompiler COMMA_THERE)) ;
  return ptr ;
}


//--------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  void cPtr_C_5F_taskDependsFromTask::printNonNullClassInstanceProperties (void) const {
    cPtr_AC_5F_task::printNonNullClassInstanceProperties () ;
    mProperty_mTask.printNonNullClassInstanceProperties ("mTask") ;
    mProperty_mEvery.printNonNullClassInstanceProperties ("mEvery") ;
  }
#endif

//--------------------------------------------------------------------------------------------------
//     @C_taskDependsFromTask generic code implementation
//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor kTypeDescriptor_GALGAS_C_5F_taskDependsFromTask ("C_taskDependsFromTask",
                                                                             & kTypeDescriptor_GALGAS_AC_5F_task) ;

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * GGS_C_5F_taskDependsFromTask::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_C_5F_taskDependsFromTask ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GGS_C_5F_taskDependsFromTask::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GGS_C_5F_taskDependsFromTask (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_C_5F_taskDependsFromTask GGS_C_5F_taskDependsFromTask::extractObject (const GGS_object & inObject,
                                                                          Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) {
  GGS_C_5F_taskDependsFromTask result ;
  const GGS_C_5F_taskDependsFromTask * p = (const GGS_C_5F_taskDependsFromTask *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GGS_C_5F_taskDependsFromTask *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("C_taskDependsFromTask", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
// @C_5F_taskDependsFromMessage reference class
//--------------------------------------------------------------------------------------------------

ComparisonResult GGS_C_5F_taskDependsFromMessage::objectCompare (const GGS_C_5F_taskDependsFromMessage & inOperand) const {
  ComparisonResult result = ComparisonResult::invalid ;
  if (isValid () && inOperand.isValid ()) {
    const size_t myObjectPtr = size_t (mObjectPtr) ;
    const size_t operandObjectPtr = size_t (inOperand.mObjectPtr) ;
    if (myObjectPtr < operandObjectPtr) {
      result = ComparisonResult::firstOperandLowerThanSecond ;
    }else if (myObjectPtr > operandObjectPtr) {
      result = ComparisonResult::firstOperandGreaterThanSecond ;
    }else{
      result = ComparisonResult::operandEqual ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_C_5F_taskDependsFromMessage::GGS_C_5F_taskDependsFromMessage (void) :
GGS_AC_5F_task () {
}

//--- Synthetized initializer ----------------------------------------------------------------------

GGS_C_5F_taskDependsFromMessage GGS_C_5F_taskDependsFromMessage::
init_21__21_ (const GGS_uint & in_mMessage,
              const GGS_luint & in_mEvery,
              Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  cPtr_C_5F_taskDependsFromMessage * object = nullptr ;
  macroMyNew (object, cPtr_C_5F_taskDependsFromMessage (inCompiler COMMA_THERE)) ;
  object->C_5F_taskDependsFromMessage_init_21__21_ (in_mMessage, in_mEvery, inCompiler) ;
  const GGS_C_5F_taskDependsFromMessage result (object) ;
  macroDetachSharedObject (object) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

void cPtr_C_5F_taskDependsFromMessage::
C_5F_taskDependsFromMessage_init_21__21_ (const GGS_uint & in_mMessage,
                                          const GGS_luint & in_mEvery,
                                          Compiler * /* inCompiler */) {
  mProperty_mMessage = in_mMessage ;
  mProperty_mEvery = in_mEvery ;
}

//--------------------------------------------------------------------------------------------------

GGS_C_5F_taskDependsFromMessage::GGS_C_5F_taskDependsFromMessage (const cPtr_C_5F_taskDependsFromMessage * inSourcePtr) :
GGS_AC_5F_task (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_C_5F_taskDependsFromMessage) ;
}
//--------------------------------------------------------------------------------------------------

GGS_C_5F_taskDependsFromMessage GGS_C_5F_taskDependsFromMessage::class_func_new (const GGS_uint & in_mMessage,
                                                                                 const GGS_luint & in_mEvery,
                                                                                 Compiler * inCompiler
                                                                                 COMMA_LOCATION_ARGS) {
  GGS_C_5F_taskDependsFromMessage result ;
  macroMyNew (result.mObjectPtr, cPtr_C_5F_taskDependsFromMessage (in_mMessage, in_mEvery,  inCompiler COMMA_THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_uint GGS_C_5F_taskDependsFromMessage::readProperty_mMessage (void) const {
  if (nullptr == mObjectPtr) {
    return GGS_uint () ;
  }else{
    cPtr_C_5F_taskDependsFromMessage * p = (cPtr_C_5F_taskDependsFromMessage *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_C_5F_taskDependsFromMessage) ;
    return p->mProperty_mMessage ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_C_5F_taskDependsFromMessage::setProperty_mMessage (const GGS_uint & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_C_5F_taskDependsFromMessage * p = (cPtr_C_5F_taskDependsFromMessage *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_C_5F_taskDependsFromMessage) ;
    p->mProperty_mMessage = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

GGS_luint GGS_C_5F_taskDependsFromMessage::readProperty_mEvery (void) const {
  if (nullptr == mObjectPtr) {
    return GGS_luint () ;
  }else{
    cPtr_C_5F_taskDependsFromMessage * p = (cPtr_C_5F_taskDependsFromMessage *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_C_5F_taskDependsFromMessage) ;
    return p->mProperty_mEvery ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_C_5F_taskDependsFromMessage::setProperty_mEvery (const GGS_luint & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_C_5F_taskDependsFromMessage * p = (cPtr_C_5F_taskDependsFromMessage *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_C_5F_taskDependsFromMessage) ;
    p->mProperty_mEvery = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------
//Pointer class for @C_taskDependsFromMessage class
//--------------------------------------------------------------------------------------------------

cPtr_C_5F_taskDependsFromMessage::cPtr_C_5F_taskDependsFromMessage (Compiler * inCompiler COMMA_LOCATION_ARGS) :
cPtr_AC_5F_task (inCompiler COMMA_THERE),
mProperty_mMessage (),
mProperty_mEvery () {
}

//--------------------------------------------------------------------------------------------------

cPtr_C_5F_taskDependsFromMessage::cPtr_C_5F_taskDependsFromMessage (const GGS_uint & in_mMessage,
                                                                    const GGS_luint & in_mEvery,
                                                                    Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) :
cPtr_AC_5F_task (inCompiler COMMA_THERE),
mProperty_mMessage (),
mProperty_mEvery () {
  mProperty_mMessage = in_mMessage ;
  mProperty_mEvery = in_mEvery ;
}

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * cPtr_C_5F_taskDependsFromMessage::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_C_5F_taskDependsFromMessage ;
}

void cPtr_C_5F_taskDependsFromMessage::description (String & ioString,
                                                    const int32_t inIndentation) const {
  ioString.appendCString ("[@C_taskDependsFromMessage:") ;
  mProperty_mMessage.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_mEvery.description (ioString, inIndentation+1) ;
  ioString.appendCString ("]") ;
}

//--------------------------------------------------------------------------------------------------

acPtr_class * cPtr_C_5F_taskDependsFromMessage::duplicate (Compiler * inCompiler COMMA_LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_C_5F_taskDependsFromMessage (mProperty_mMessage, mProperty_mEvery, inCompiler COMMA_THERE)) ;
  return ptr ;
}


//--------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  void cPtr_C_5F_taskDependsFromMessage::printNonNullClassInstanceProperties (void) const {
    cPtr_AC_5F_task::printNonNullClassInstanceProperties () ;
    mProperty_mMessage.printNonNullClassInstanceProperties ("mMessage") ;
    mProperty_mEvery.printNonNullClassInstanceProperties ("mEvery") ;
  }
#endif

//--------------------------------------------------------------------------------------------------
//     @C_taskDependsFromMessage generic code implementation
//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor kTypeDescriptor_GALGAS_C_5F_taskDependsFromMessage ("C_taskDependsFromMessage",
                                                                                & kTypeDescriptor_GALGAS_AC_5F_task) ;

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * GGS_C_5F_taskDependsFromMessage::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_C_5F_taskDependsFromMessage ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GGS_C_5F_taskDependsFromMessage::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GGS_C_5F_taskDependsFromMessage (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_C_5F_taskDependsFromMessage GGS_C_5F_taskDependsFromMessage::extractObject (const GGS_object & inObject,
                                                                                Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) {
  GGS_C_5F_taskDependsFromMessage result ;
  const GGS_C_5F_taskDependsFromMessage * p = (const GGS_C_5F_taskDependsFromMessage *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GGS_C_5F_taskDependsFromMessage *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("C_taskDependsFromMessage", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

#include "MF_MemoryControl.h"
#include "C_galgas_CLI_Options.h"

#include "FileManager.h"

//--------------------------------------------------------------------------------------------------


//--------------------------------------------------------------------------------------------------
//
//                                     LL(1) PRODUCTION RULES                                       
//
//--------------------------------------------------------------------------------------------------

static const int32_t gProductions_oa_grammar [] = {
// At index 0 : <axiome>, in file 'oa_parser.ggs', line 11
  TOP_DOWN_TERMINAL (Lexique_oa_5F_scanner::kToken_system) // $system$
, TOP_DOWN_NONTERMINAL (1) // <select_oa_5F_parser_0>
, TOP_DOWN_TERMINAL (Lexique_oa_5F_scanner::kToken_end) // $end$
, TOP_DOWN_END_PRODUCTION ()
//---- Added productions from 'select' and 'repeat' instructions
// At index 4 : <select_oa_5F_parser_0>, in file 'oa_parser.ggs', line 17
, TOP_DOWN_END_PRODUCTION ()
// At index 5 : <select_oa_5F_parser_0>, in file 'oa_parser.ggs', line 17
, TOP_DOWN_TERMINAL (Lexique_oa_5F_scanner::kToken_processor) // $processor$
, TOP_DOWN_TERMINAL (Lexique_oa_5F_scanner::kToken_identifier) // $identifier$
, TOP_DOWN_NONTERMINAL (2) // <select_oa_5F_parser_1>
, TOP_DOWN_TERMINAL (Lexique_oa_5F_scanner::kToken__3B_) // $;$
, TOP_DOWN_NONTERMINAL (1) // <select_oa_5F_parser_0>
, TOP_DOWN_END_PRODUCTION ()
// At index 11 : <select_oa_5F_parser_0>, in file 'oa_parser.ggs', line 17
, TOP_DOWN_NONTERMINAL (3) // <select_oa_5F_parser_2>
, TOP_DOWN_TERMINAL (Lexique_oa_5F_scanner::kToken_network) // $network$
, TOP_DOWN_TERMINAL (Lexique_oa_5F_scanner::kToken_identifier) // $identifier$
, TOP_DOWN_NONTERMINAL (4) // <select_oa_5F_parser_3>
, TOP_DOWN_TERMINAL (Lexique_oa_5F_scanner::kToken__3B_) // $;$
, TOP_DOWN_NONTERMINAL (1) // <select_oa_5F_parser_0>
, TOP_DOWN_END_PRODUCTION ()
// At index 18 : <select_oa_5F_parser_0>, in file 'oa_parser.ggs', line 17
, TOP_DOWN_TERMINAL (Lexique_oa_5F_scanner::kToken_task) // $task$
, TOP_DOWN_TERMINAL (Lexique_oa_5F_scanner::kToken_identifier) // $identifier$
, TOP_DOWN_TERMINAL (Lexique_oa_5F_scanner::kToken_priority) // $priority$
, TOP_DOWN_TERMINAL (Lexique_oa_5F_scanner::kToken_literal_5F_integer) // $literal_integer$
, TOP_DOWN_TERMINAL (Lexique_oa_5F_scanner::kToken_duration) // $duration$
, TOP_DOWN_TERMINAL (Lexique_oa_5F_scanner::kToken_literal_5F_integer) // $literal_integer$
, TOP_DOWN_TERMINAL (Lexique_oa_5F_scanner::kToken__2E__2E_) // $..$
, TOP_DOWN_TERMINAL (Lexique_oa_5F_scanner::kToken_literal_5F_integer) // $literal_integer$
, TOP_DOWN_NONTERMINAL (5) // <select_oa_5F_parser_4>
, TOP_DOWN_NONTERMINAL (6) // <select_oa_5F_parser_5>
, TOP_DOWN_NONTERMINAL (7) // <select_oa_5F_parser_6>
, TOP_DOWN_TERMINAL (Lexique_oa_5F_scanner::kToken__3B_) // $;$
, TOP_DOWN_NONTERMINAL (1) // <select_oa_5F_parser_0>
, TOP_DOWN_END_PRODUCTION ()
// At index 32 : <select_oa_5F_parser_0>, in file 'oa_parser.ggs', line 17
, TOP_DOWN_NONTERMINAL (11) // <select_oa_5F_parser_10>
, TOP_DOWN_TERMINAL (Lexique_oa_5F_scanner::kToken_identifier) // $identifier$
, TOP_DOWN_TERMINAL (Lexique_oa_5F_scanner::kToken_network) // $network$
, TOP_DOWN_TERMINAL (Lexique_oa_5F_scanner::kToken_identifier) // $identifier$
, TOP_DOWN_TERMINAL (Lexique_oa_5F_scanner::kToken_length) // $length$
, TOP_DOWN_TERMINAL (Lexique_oa_5F_scanner::kToken_literal_5F_integer) // $literal_integer$
, TOP_DOWN_TERMINAL (Lexique_oa_5F_scanner::kToken_priority) // $priority$
, TOP_DOWN_TERMINAL (Lexique_oa_5F_scanner::kToken_literal_5F_integer) // $literal_integer$
, TOP_DOWN_NONTERMINAL (12) // <select_oa_5F_parser_11>
, TOP_DOWN_NONTERMINAL (13) // <select_oa_5F_parser_12>
, TOP_DOWN_NONTERMINAL (14) // <select_oa_5F_parser_13>
, TOP_DOWN_TERMINAL (Lexique_oa_5F_scanner::kToken__3B_) // $;$
, TOP_DOWN_NONTERMINAL (1) // <select_oa_5F_parser_0>
, TOP_DOWN_END_PRODUCTION ()
// At index 46 : <select_oa_5F_parser_1>, in file 'oa_parser.ggs', line 22
, TOP_DOWN_END_PRODUCTION ()
// At index 47 : <select_oa_5F_parser_1>, in file 'oa_parser.ggs', line 22
, TOP_DOWN_TERMINAL (Lexique_oa_5F_scanner::kToken_scalingfactor) // $scalingfactor$
, TOP_DOWN_TERMINAL (Lexique_oa_5F_scanner::kToken_literal_5F_integer) // $literal_integer$
, TOP_DOWN_END_PRODUCTION ()
// At index 50 : <select_oa_5F_parser_2>, in file 'oa_parser.ggs', line 35
, TOP_DOWN_TERMINAL (Lexique_oa_5F_scanner::kToken_can) // $can$
, TOP_DOWN_END_PRODUCTION ()
// At index 52 : <select_oa_5F_parser_2>, in file 'oa_parser.ggs', line 35
, TOP_DOWN_TERMINAL (Lexique_oa_5F_scanner::kToken_van) // $van$
, TOP_DOWN_END_PRODUCTION ()
// At index 54 : <select_oa_5F_parser_3>, in file 'oa_parser.ggs', line 45
, TOP_DOWN_END_PRODUCTION ()
// At index 55 : <select_oa_5F_parser_3>, in file 'oa_parser.ggs', line 45
, TOP_DOWN_TERMINAL (Lexique_oa_5F_scanner::kToken_scalingfactor) // $scalingfactor$
, TOP_DOWN_TERMINAL (Lexique_oa_5F_scanner::kToken_literal_5F_integer) // $literal_integer$
, TOP_DOWN_END_PRODUCTION ()
// At index 58 : <select_oa_5F_parser_4>, in file 'oa_parser.ggs', line 67
, TOP_DOWN_TERMINAL (Lexique_oa_5F_scanner::kToken_offset) // $offset$
, TOP_DOWN_TERMINAL (Lexique_oa_5F_scanner::kToken_literal_5F_integer) // $literal_integer$
, TOP_DOWN_END_PRODUCTION ()
// At index 61 : <select_oa_5F_parser_4>, in file 'oa_parser.ggs', line 67
, TOP_DOWN_END_PRODUCTION ()
// At index 62 : <select_oa_5F_parser_5>, in file 'oa_parser.ggs', line 76
, TOP_DOWN_TERMINAL (Lexique_oa_5F_scanner::kToken_deadline) // $deadline$
, TOP_DOWN_TERMINAL (Lexique_oa_5F_scanner::kToken_literal_5F_integer) // $literal_integer$
, TOP_DOWN_END_PRODUCTION ()
// At index 65 : <select_oa_5F_parser_5>, in file 'oa_parser.ggs', line 76
, TOP_DOWN_END_PRODUCTION ()
// At index 66 : <select_oa_5F_parser_6>, in file 'oa_parser.ggs', line 85
, TOP_DOWN_TERMINAL (Lexique_oa_5F_scanner::kToken_period) // $period$
, TOP_DOWN_TERMINAL (Lexique_oa_5F_scanner::kToken_literal_5F_integer) // $literal_integer$
, TOP_DOWN_TERMINAL (Lexique_oa_5F_scanner::kToken_processor) // $processor$
, TOP_DOWN_TERMINAL (Lexique_oa_5F_scanner::kToken_identifier) // $identifier$
, TOP_DOWN_END_PRODUCTION ()
// At index 71 : <select_oa_5F_parser_6>, in file 'oa_parser.ggs', line 85
, TOP_DOWN_TERMINAL (Lexique_oa_5F_scanner::kToken_on) // $on$
, TOP_DOWN_NONTERMINAL (8) // <select_oa_5F_parser_7>
, TOP_DOWN_END_PRODUCTION ()
// At index 74 : <select_oa_5F_parser_7>, in file 'oa_parser.ggs', line 97
, TOP_DOWN_TERMINAL (Lexique_oa_5F_scanner::kToken_task) // $task$
, TOP_DOWN_TERMINAL (Lexique_oa_5F_scanner::kToken_identifier) // $identifier$
, TOP_DOWN_NONTERMINAL (9) // <select_oa_5F_parser_8>
, TOP_DOWN_END_PRODUCTION ()
// At index 78 : <select_oa_5F_parser_7>, in file 'oa_parser.ggs', line 97
, TOP_DOWN_TERMINAL (Lexique_oa_5F_scanner::kToken_message) // $message$
, TOP_DOWN_TERMINAL (Lexique_oa_5F_scanner::kToken_identifier) // $identifier$
, TOP_DOWN_TERMINAL (Lexique_oa_5F_scanner::kToken_processor) // $processor$
, TOP_DOWN_TERMINAL (Lexique_oa_5F_scanner::kToken_identifier) // $identifier$
, TOP_DOWN_NONTERMINAL (10) // <select_oa_5F_parser_9>
, TOP_DOWN_END_PRODUCTION ()
// At index 84 : <select_oa_5F_parser_8>, in file 'oa_parser.ggs', line 101
, TOP_DOWN_END_PRODUCTION ()
// At index 85 : <select_oa_5F_parser_8>, in file 'oa_parser.ggs', line 101
, TOP_DOWN_TERMINAL (Lexique_oa_5F_scanner::kToken_every) // $every$
, TOP_DOWN_TERMINAL (Lexique_oa_5F_scanner::kToken_literal_5F_integer) // $literal_integer$
, TOP_DOWN_END_PRODUCTION ()
// At index 88 : <select_oa_5F_parser_9>, in file 'oa_parser.ggs', line 116
, TOP_DOWN_END_PRODUCTION ()
// At index 89 : <select_oa_5F_parser_9>, in file 'oa_parser.ggs', line 116
, TOP_DOWN_TERMINAL (Lexique_oa_5F_scanner::kToken_every) // $every$
, TOP_DOWN_TERMINAL (Lexique_oa_5F_scanner::kToken_literal_5F_integer) // $literal_integer$
, TOP_DOWN_END_PRODUCTION ()
// At index 92 : <select_oa_5F_parser_10>, in file 'oa_parser.ggs', line 138
, TOP_DOWN_TERMINAL (Lexique_oa_5F_scanner::kToken_standard) // $standard$
, TOP_DOWN_TERMINAL (Lexique_oa_5F_scanner::kToken_message) // $message$
, TOP_DOWN_END_PRODUCTION ()
// At index 95 : <select_oa_5F_parser_10>, in file 'oa_parser.ggs', line 138
, TOP_DOWN_TERMINAL (Lexique_oa_5F_scanner::kToken_extended) // $extended$
, TOP_DOWN_TERMINAL (Lexique_oa_5F_scanner::kToken_message) // $message$
, TOP_DOWN_END_PRODUCTION ()
// At index 98 : <select_oa_5F_parser_10>, in file 'oa_parser.ggs', line 138
, TOP_DOWN_TERMINAL (Lexique_oa_5F_scanner::kToken_message) // $message$
, TOP_DOWN_END_PRODUCTION ()
// At index 100 : <select_oa_5F_parser_11>, in file 'oa_parser.ggs', line 170
, TOP_DOWN_TERMINAL (Lexique_oa_5F_scanner::kToken_offset) // $offset$
, TOP_DOWN_TERMINAL (Lexique_oa_5F_scanner::kToken_literal_5F_integer) // $literal_integer$
, TOP_DOWN_END_PRODUCTION ()
// At index 103 : <select_oa_5F_parser_11>, in file 'oa_parser.ggs', line 170
, TOP_DOWN_END_PRODUCTION ()
// At index 104 : <select_oa_5F_parser_12>, in file 'oa_parser.ggs', line 179
, TOP_DOWN_TERMINAL (Lexique_oa_5F_scanner::kToken_deadline) // $deadline$
, TOP_DOWN_TERMINAL (Lexique_oa_5F_scanner::kToken_literal_5F_integer) // $literal_integer$
, TOP_DOWN_END_PRODUCTION ()
// At index 107 : <select_oa_5F_parser_12>, in file 'oa_parser.ggs', line 179
, TOP_DOWN_END_PRODUCTION ()
// At index 108 : <select_oa_5F_parser_13>, in file 'oa_parser.ggs', line 187
, TOP_DOWN_TERMINAL (Lexique_oa_5F_scanner::kToken_period) // $period$
, TOP_DOWN_TERMINAL (Lexique_oa_5F_scanner::kToken_literal_5F_integer) // $literal_integer$
, TOP_DOWN_END_PRODUCTION ()
// At index 111 : <select_oa_5F_parser_13>, in file 'oa_parser.ggs', line 187
, TOP_DOWN_TERMINAL (Lexique_oa_5F_scanner::kToken_on) // $on$
, TOP_DOWN_NONTERMINAL (15) // <select_oa_5F_parser_14>
, TOP_DOWN_END_PRODUCTION ()
// At index 114 : <select_oa_5F_parser_14>, in file 'oa_parser.ggs', line 196
, TOP_DOWN_TERMINAL (Lexique_oa_5F_scanner::kToken_message) // $message$
, TOP_DOWN_TERMINAL (Lexique_oa_5F_scanner::kToken_identifier) // $identifier$
, TOP_DOWN_END_PRODUCTION ()
// At index 117 : <select_oa_5F_parser_14>, in file 'oa_parser.ggs', line 196
, TOP_DOWN_TERMINAL (Lexique_oa_5F_scanner::kToken_task) // $task$
, TOP_DOWN_TERMINAL (Lexique_oa_5F_scanner::kToken_identifier) // $identifier$
, TOP_DOWN_END_PRODUCTION ()
// At index 120 : <>, in file '.ggs', line 0
, TOP_DOWN_NONTERMINAL (0) // <axiome>
, TOP_DOWN_END_PRODUCTION ()
} ;

//--------------------------------------------------------------------------------------------------
//
//                                P R O D U C T I O N    N A M E S                                  
//
//--------------------------------------------------------------------------------------------------

static const ProductionNameDescriptor gProductionNames_oa_grammar [36] = {
 {"<axiome>", "oa_parser", 0}, // at index 0
 {"<select_oa_5F_parser_0>", "oa_parser", 4}, // at index 1
 {"<select_oa_5F_parser_0>", "oa_parser", 5}, // at index 2
 {"<select_oa_5F_parser_0>", "oa_parser", 11}, // at index 3
 {"<select_oa_5F_parser_0>", "oa_parser", 18}, // at index 4
 {"<select_oa_5F_parser_0>", "oa_parser", 32}, // at index 5
 {"<select_oa_5F_parser_1>", "oa_parser", 46}, // at index 6
 {"<select_oa_5F_parser_1>", "oa_parser", 47}, // at index 7
 {"<select_oa_5F_parser_2>", "oa_parser", 50}, // at index 8
 {"<select_oa_5F_parser_2>", "oa_parser", 52}, // at index 9
 {"<select_oa_5F_parser_3>", "oa_parser", 54}, // at index 10
 {"<select_oa_5F_parser_3>", "oa_parser", 55}, // at index 11
 {"<select_oa_5F_parser_4>", "oa_parser", 58}, // at index 12
 {"<select_oa_5F_parser_4>", "oa_parser", 61}, // at index 13
 {"<select_oa_5F_parser_5>", "oa_parser", 62}, // at index 14
 {"<select_oa_5F_parser_5>", "oa_parser", 65}, // at index 15
 {"<select_oa_5F_parser_6>", "oa_parser", 66}, // at index 16
 {"<select_oa_5F_parser_6>", "oa_parser", 71}, // at index 17
 {"<select_oa_5F_parser_7>", "oa_parser", 74}, // at index 18
 {"<select_oa_5F_parser_7>", "oa_parser", 78}, // at index 19
 {"<select_oa_5F_parser_8>", "oa_parser", 84}, // at index 20
 {"<select_oa_5F_parser_8>", "oa_parser", 85}, // at index 21
 {"<select_oa_5F_parser_9>", "oa_parser", 88}, // at index 22
 {"<select_oa_5F_parser_9>", "oa_parser", 89}, // at index 23
 {"<select_oa_5F_parser_10>", "oa_parser", 92}, // at index 24
 {"<select_oa_5F_parser_10>", "oa_parser", 95}, // at index 25
 {"<select_oa_5F_parser_10>", "oa_parser", 98}, // at index 26
 {"<select_oa_5F_parser_11>", "oa_parser", 100}, // at index 27
 {"<select_oa_5F_parser_11>", "oa_parser", 103}, // at index 28
 {"<select_oa_5F_parser_12>", "oa_parser", 104}, // at index 29
 {"<select_oa_5F_parser_12>", "oa_parser", 107}, // at index 30
 {"<select_oa_5F_parser_13>", "oa_parser", 108}, // at index 31
 {"<select_oa_5F_parser_13>", "oa_parser", 111}, // at index 32
 {"<select_oa_5F_parser_14>", "oa_parser", 114}, // at index 33
 {"<select_oa_5F_parser_14>", "oa_parser", 117}, // at index 34
 {"<>", "", 120} // at index 35
} ;

//--------------------------------------------------------------------------------------------------
//
//                       L L ( 1 )    P R O D U C T I O N    I N D E X E S                          
//
//--------------------------------------------------------------------------------------------------

static const int32_t gProductionIndexes_oa_grammar [36] = {
0, // index 0 : <axiome>, in file 'oa_parser.ggs', line 11
4, // index 1 : <select_oa_5F_parser_0>, in file 'oa_parser.ggs', line 17
5, // index 2 : <select_oa_5F_parser_0>, in file 'oa_parser.ggs', line 17
11, // index 3 : <select_oa_5F_parser_0>, in file 'oa_parser.ggs', line 17
18, // index 4 : <select_oa_5F_parser_0>, in file 'oa_parser.ggs', line 17
32, // index 5 : <select_oa_5F_parser_0>, in file 'oa_parser.ggs', line 17
46, // index 6 : <select_oa_5F_parser_1>, in file 'oa_parser.ggs', line 22
47, // index 7 : <select_oa_5F_parser_1>, in file 'oa_parser.ggs', line 22
50, // index 8 : <select_oa_5F_parser_2>, in file 'oa_parser.ggs', line 35
52, // index 9 : <select_oa_5F_parser_2>, in file 'oa_parser.ggs', line 35
54, // index 10 : <select_oa_5F_parser_3>, in file 'oa_parser.ggs', line 45
55, // index 11 : <select_oa_5F_parser_3>, in file 'oa_parser.ggs', line 45
58, // index 12 : <select_oa_5F_parser_4>, in file 'oa_parser.ggs', line 67
61, // index 13 : <select_oa_5F_parser_4>, in file 'oa_parser.ggs', line 67
62, // index 14 : <select_oa_5F_parser_5>, in file 'oa_parser.ggs', line 76
65, // index 15 : <select_oa_5F_parser_5>, in file 'oa_parser.ggs', line 76
66, // index 16 : <select_oa_5F_parser_6>, in file 'oa_parser.ggs', line 85
71, // index 17 : <select_oa_5F_parser_6>, in file 'oa_parser.ggs', line 85
74, // index 18 : <select_oa_5F_parser_7>, in file 'oa_parser.ggs', line 97
78, // index 19 : <select_oa_5F_parser_7>, in file 'oa_parser.ggs', line 97
84, // index 20 : <select_oa_5F_parser_8>, in file 'oa_parser.ggs', line 101
85, // index 21 : <select_oa_5F_parser_8>, in file 'oa_parser.ggs', line 101
88, // index 22 : <select_oa_5F_parser_9>, in file 'oa_parser.ggs', line 116
89, // index 23 : <select_oa_5F_parser_9>, in file 'oa_parser.ggs', line 116
92, // index 24 : <select_oa_5F_parser_10>, in file 'oa_parser.ggs', line 138
95, // index 25 : <select_oa_5F_parser_10>, in file 'oa_parser.ggs', line 138
98, // index 26 : <select_oa_5F_parser_10>, in file 'oa_parser.ggs', line 138
100, // index 27 : <select_oa_5F_parser_11>, in file 'oa_parser.ggs', line 170
103, // index 28 : <select_oa_5F_parser_11>, in file 'oa_parser.ggs', line 170
104, // index 29 : <select_oa_5F_parser_12>, in file 'oa_parser.ggs', line 179
107, // index 30 : <select_oa_5F_parser_12>, in file 'oa_parser.ggs', line 179
108, // index 31 : <select_oa_5F_parser_13>, in file 'oa_parser.ggs', line 187
111, // index 32 : <select_oa_5F_parser_13>, in file 'oa_parser.ggs', line 187
114, // index 33 : <select_oa_5F_parser_14>, in file 'oa_parser.ggs', line 196
117, // index 34 : <select_oa_5F_parser_14>, in file 'oa_parser.ggs', line 196
120 // index 35 : <>, in file '.ggs', line 0
} ;

//--------------------------------------------------------------------------------------------------
//
//                 L L ( 1 )    F I R S T    P R O D U C T I O N    I N D E X E S                   
//
//--------------------------------------------------------------------------------------------------

static const int32_t gFirstProductionIndexes_oa_grammar [18] = {
0, // at 0 : <axiome>
1, // at 1 : <select_oa_5F_parser_0>
6, // at 2 : <select_oa_5F_parser_1>
8, // at 3 : <select_oa_5F_parser_2>
10, // at 4 : <select_oa_5F_parser_3>
12, // at 5 : <select_oa_5F_parser_4>
14, // at 6 : <select_oa_5F_parser_5>
16, // at 7 : <select_oa_5F_parser_6>
18, // at 8 : <select_oa_5F_parser_7>
20, // at 9 : <select_oa_5F_parser_8>
22, // at 10 : <select_oa_5F_parser_9>
24, // at 11 : <select_oa_5F_parser_10>
27, // at 12 : <select_oa_5F_parser_11>
29, // at 13 : <select_oa_5F_parser_12>
31, // at 14 : <select_oa_5F_parser_13>
33, // at 15 : <select_oa_5F_parser_14>
35, // at 16 : <>
0} ;

//--------------------------------------------------------------------------------------------------
//
//                          L L ( 1 )    D E C I S I O N    T A B L E S                             
//
//--------------------------------------------------------------------------------------------------

static const int32_t gDecision_oa_grammar [] = {
// At index 0 : <axiome> only one production, no choice
  -1,
//---- Added non terminal symbols from 'select' and 'repeat' instructions
// At index 1 : <select_oa_5F_parser_0>
Lexique_oa_5F_scanner::kToken_end, -1, // Choice 1
Lexique_oa_5F_scanner::kToken_processor, -1, // Choice 2
Lexique_oa_5F_scanner::kToken_can, Lexique_oa_5F_scanner::kToken_van, -1, // Choice 3
Lexique_oa_5F_scanner::kToken_task, -1, // Choice 4
Lexique_oa_5F_scanner::kToken_message, Lexique_oa_5F_scanner::kToken_standard, Lexique_oa_5F_scanner::kToken_extended, -1, // Choice 5
  -1,
// At index 15 : <select_oa_5F_parser_1>
Lexique_oa_5F_scanner::kToken__3B_, -1, // Choice 1
Lexique_oa_5F_scanner::kToken_scalingfactor, -1, // Choice 2
  -1,
// At index 20 : <select_oa_5F_parser_2>
Lexique_oa_5F_scanner::kToken_can, -1, // Choice 1
Lexique_oa_5F_scanner::kToken_van, -1, // Choice 2
  -1,
// At index 25 : <select_oa_5F_parser_3>
Lexique_oa_5F_scanner::kToken__3B_, -1, // Choice 1
Lexique_oa_5F_scanner::kToken_scalingfactor, -1, // Choice 2
  -1,
// At index 30 : <select_oa_5F_parser_4>
Lexique_oa_5F_scanner::kToken_offset, -1, // Choice 1
Lexique_oa_5F_scanner::kToken_deadline, Lexique_oa_5F_scanner::kToken_period, Lexique_oa_5F_scanner::kToken_on, -1, // Choice 2
  -1,
// At index 37 : <select_oa_5F_parser_5>
Lexique_oa_5F_scanner::kToken_deadline, -1, // Choice 1
Lexique_oa_5F_scanner::kToken_period, Lexique_oa_5F_scanner::kToken_on, -1, // Choice 2
  -1,
// At index 43 : <select_oa_5F_parser_6>
Lexique_oa_5F_scanner::kToken_period, -1, // Choice 1
Lexique_oa_5F_scanner::kToken_on, -1, // Choice 2
  -1,
// At index 48 : <select_oa_5F_parser_7>
Lexique_oa_5F_scanner::kToken_task, -1, // Choice 1
Lexique_oa_5F_scanner::kToken_message, -1, // Choice 2
  -1,
// At index 53 : <select_oa_5F_parser_8>
Lexique_oa_5F_scanner::kToken__3B_, -1, // Choice 1
Lexique_oa_5F_scanner::kToken_every, -1, // Choice 2
  -1,
// At index 58 : <select_oa_5F_parser_9>
Lexique_oa_5F_scanner::kToken__3B_, -1, // Choice 1
Lexique_oa_5F_scanner::kToken_every, -1, // Choice 2
  -1,
// At index 63 : <select_oa_5F_parser_10>
Lexique_oa_5F_scanner::kToken_standard, -1, // Choice 1
Lexique_oa_5F_scanner::kToken_extended, -1, // Choice 2
Lexique_oa_5F_scanner::kToken_message, -1, // Choice 3
  -1,
// At index 70 : <select_oa_5F_parser_11>
Lexique_oa_5F_scanner::kToken_offset, -1, // Choice 1
Lexique_oa_5F_scanner::kToken_deadline, Lexique_oa_5F_scanner::kToken_period, Lexique_oa_5F_scanner::kToken_on, -1, // Choice 2
  -1,
// At index 77 : <select_oa_5F_parser_12>
Lexique_oa_5F_scanner::kToken_deadline, -1, // Choice 1
Lexique_oa_5F_scanner::kToken_period, Lexique_oa_5F_scanner::kToken_on, -1, // Choice 2
  -1,
// At index 83 : <select_oa_5F_parser_13>
Lexique_oa_5F_scanner::kToken_period, -1, // Choice 1
Lexique_oa_5F_scanner::kToken_on, -1, // Choice 2
  -1,
// At index 88 : <select_oa_5F_parser_14>
Lexique_oa_5F_scanner::kToken_message, -1, // Choice 1
Lexique_oa_5F_scanner::kToken_task, -1, // Choice 2
  -1,
// At index 93 : <> only one production, no choice
  -1,
0} ;

//--------------------------------------------------------------------------------------------------
//
//                  L L ( 1 )    D E C I S I O N    T A B L E S    I N D E X E S                    
//
//--------------------------------------------------------------------------------------------------

static const int32_t gDecisionIndexes_oa_grammar [18] = {
0, // at 0 : <axiome>
1, // at 1 : <select_oa_5F_parser_0>
15, // at 2 : <select_oa_5F_parser_1>
20, // at 3 : <select_oa_5F_parser_2>
25, // at 4 : <select_oa_5F_parser_3>
30, // at 5 : <select_oa_5F_parser_4>
37, // at 6 : <select_oa_5F_parser_5>
43, // at 7 : <select_oa_5F_parser_6>
48, // at 8 : <select_oa_5F_parser_7>
53, // at 9 : <select_oa_5F_parser_8>
58, // at 10 : <select_oa_5F_parser_9>
63, // at 11 : <select_oa_5F_parser_10>
70, // at 12 : <select_oa_5F_parser_11>
77, // at 13 : <select_oa_5F_parser_12>
83, // at 14 : <select_oa_5F_parser_13>
88, // at 15 : <select_oa_5F_parser_14>
93, // at 16 : <>
0} ;

//--------------------------------------------------------------------------------------------------
//
//                              'axiome' non terminal implementation                                
//
//--------------------------------------------------------------------------------------------------

void cGrammar_oa_5F_grammar::nt_axiome_parse (Lexique_oa_5F_scanner * inLexique) {
  rule_oa_5F_parser_axiome_i0_parse(inLexique) ;
}

void cGrammar_oa_5F_grammar::nt_axiome_indexing (Lexique_oa_5F_scanner * inLexique) {
  rule_oa_5F_parser_axiome_i0_indexing(inLexique) ;
}

void cGrammar_oa_5F_grammar::nt_axiome_ (Lexique_oa_5F_scanner * inLexique) {
  rule_oa_5F_parser_axiome_i0_(inLexique) ;
}

void cGrammar_oa_5F_grammar::performIndexing (Compiler * inCompiler,
             const String & inSourceFilePath) {
  Lexique_oa_5F_scanner * scanner = nullptr ;
  macroMyNew (scanner, Lexique_oa_5F_scanner (inCompiler, inSourceFilePath COMMA_HERE)) ;
  scanner->enableIndexing () ;
  if (scanner->sourceText ().isValid ()) {
    const bool ok = scanner->performTopDownParsing (gProductions_oa_grammar, gProductionNames_oa_grammar, gProductionIndexes_oa_grammar,
                                                    gFirstProductionIndexes_oa_grammar, gDecision_oa_grammar, gDecisionIndexes_oa_grammar, 120) ;
    if (ok) {
      cGrammar_oa_5F_grammar grammar ;
      grammar.nt_axiome_indexing (scanner) ;
    }
    scanner->generateIndexFile () ;
  }
  macroDetachSharedObject (scanner) ;
}

void cGrammar_oa_5F_grammar::performOnlyLexicalAnalysis (Compiler * inCompiler,
             const String & inSourceFilePath) {
  Lexique_oa_5F_scanner * scanner = nullptr ;
  macroMyNew (scanner, Lexique_oa_5F_scanner (inCompiler, inSourceFilePath COMMA_HERE)) ;
  if (scanner->sourceText ().isValid ()) {
    scanner->performLexicalAnalysis () ;
  }
  macroDetachSharedObject (scanner) ;
}

void cGrammar_oa_5F_grammar::performOnlySyntaxAnalysis (Compiler * inCompiler,
             const String & inSourceFilePath) {
  Lexique_oa_5F_scanner * scanner = nullptr ;
  macroMyNew (scanner, Lexique_oa_5F_scanner (inCompiler, inSourceFilePath COMMA_HERE)) ;
  if (scanner->sourceText ().isValid ()) {
    scanner->performTopDownParsing (gProductions_oa_grammar, gProductionNames_oa_grammar, gProductionIndexes_oa_grammar,
                                    gFirstProductionIndexes_oa_grammar, gDecision_oa_grammar, gDecisionIndexes_oa_grammar, 120) ;
  }
  macroDetachSharedObject (scanner) ;
}

//--------------------------------------------------------------------------------------------------
//
//                              Grammar start symbol implementation                                 
//
//--------------------------------------------------------------------------------------------------

void cGrammar_oa_5F_grammar::_performSourceFileParsing_ (Compiler * inCompiler,
                                GGS_lstring inFilePath
                                COMMA_LOCATION_ARGS) {
  if (inFilePath.isValid ()) {
    const GGS_string filePathAsString = inFilePath.readProperty_string () ;
    String filePath = filePathAsString.stringValue () ;
    if (! FileManager::isAbsolutePath (filePath)) {
      filePath = inCompiler->sourceFilePath ().deletingLastPathComponent ().appendingPathComponent (filePath) ;
    }
    if (FileManager::fileExistsAtPath (filePath)) {
    Lexique_oa_5F_scanner * scanner = nullptr ;
    macroMyNew (scanner, Lexique_oa_5F_scanner (inCompiler, filePath COMMA_HERE)) ;
    if (scanner->sourceText ().isValid ()) {
      const bool ok = scanner->performTopDownParsing (gProductions_oa_grammar, gProductionNames_oa_grammar, gProductionIndexes_oa_grammar,
                                                      gFirstProductionIndexes_oa_grammar, gDecision_oa_grammar, gDecisionIndexes_oa_grammar, 120) ;
      if (ok && ! executionModeIsSyntaxAnalysisOnly ()) {
        cGrammar_oa_5F_grammar grammar ;
        grammar.nt_axiome_ (scanner) ;
        }
      }else{
        String message ;
        message.appendString ("the '") ;
        message.appendString (filePath) ;
        message.appendString ("' file exists, but cannot be read") ;
        const GGS_location errorLocation (inFilePath.readProperty_location ()) ;
        inCompiler->semanticErrorAtLocation (errorLocation, message, GenericArray <FixItDescription> () COMMA_THERE) ;
      }
      macroDetachSharedObject (scanner) ;
    }else{
      String message ;
      message.appendString ("the '") ;
      message.appendString (filePath) ;
      message.appendString ("' file does not exist") ;
      const GGS_location errorLocation (inFilePath.readProperty_location ()) ;
      inCompiler->semanticErrorAtLocation (errorLocation, message, GenericArray <FixItDescription> () COMMA_THERE) ;
    }
  }
}

//--------------------------------------------------------------------------------------------------

void cGrammar_oa_5F_grammar::_performSourceStringParsing_ (Compiler * inCompiler,
                                GGS_string inSourceString,
                                GGS_string inNameString
                                COMMA_UNUSED_LOCATION_ARGS) {
  if (inSourceString.isValid () && inNameString.isValid ()) {
    const String sourceString = inSourceString.stringValue () ;
    const String nameString = inNameString.stringValue () ;
    Lexique_oa_5F_scanner * scanner = nullptr ;
    macroMyNew (scanner, Lexique_oa_5F_scanner (inCompiler, sourceString, nameString COMMA_HERE)) ;
    const bool ok = scanner->performTopDownParsing (gProductions_oa_grammar, gProductionNames_oa_grammar, gProductionIndexes_oa_grammar,
                                                    gFirstProductionIndexes_oa_grammar, gDecision_oa_grammar, gDecisionIndexes_oa_grammar, 120) ;
    if (ok && ! executionModeIsSyntaxAnalysisOnly ()) {
      cGrammar_oa_5F_grammar grammar ;
      grammar.nt_axiome_ (scanner) ;
    }
    macroDetachSharedObject (scanner) ;
  }
}

//--------------------------------------------------------------------------------------------------
//
//                   'select_oa_5F_parser_0' added non terminal implementation                      
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_oa_5F_grammar::select_oa_5F_parser_0 (Lexique_oa_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//                   'select_oa_5F_parser_1' added non terminal implementation                      
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_oa_5F_grammar::select_oa_5F_parser_1 (Lexique_oa_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//                   'select_oa_5F_parser_2' added non terminal implementation                      
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_oa_5F_grammar::select_oa_5F_parser_2 (Lexique_oa_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//                   'select_oa_5F_parser_3' added non terminal implementation                      
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_oa_5F_grammar::select_oa_5F_parser_3 (Lexique_oa_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//                   'select_oa_5F_parser_4' added non terminal implementation                      
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_oa_5F_grammar::select_oa_5F_parser_4 (Lexique_oa_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//                   'select_oa_5F_parser_5' added non terminal implementation                      
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_oa_5F_grammar::select_oa_5F_parser_5 (Lexique_oa_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//                   'select_oa_5F_parser_6' added non terminal implementation                      
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_oa_5F_grammar::select_oa_5F_parser_6 (Lexique_oa_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//                   'select_oa_5F_parser_7' added non terminal implementation                      
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_oa_5F_grammar::select_oa_5F_parser_7 (Lexique_oa_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//                   'select_oa_5F_parser_8' added non terminal implementation                      
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_oa_5F_grammar::select_oa_5F_parser_8 (Lexique_oa_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//                   'select_oa_5F_parser_9' added non terminal implementation                      
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_oa_5F_grammar::select_oa_5F_parser_9 (Lexique_oa_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//                   'select_oa_5F_parser_10' added non terminal implementation                     
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_oa_5F_grammar::select_oa_5F_parser_10 (Lexique_oa_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//                   'select_oa_5F_parser_11' added non terminal implementation                     
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_oa_5F_grammar::select_oa_5F_parser_11 (Lexique_oa_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//                   'select_oa_5F_parser_12' added non terminal implementation                     
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_oa_5F_grammar::select_oa_5F_parser_12 (Lexique_oa_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//                   'select_oa_5F_parser_13' added non terminal implementation                     
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_oa_5F_grammar::select_oa_5F_parser_13 (Lexique_oa_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//                   'select_oa_5F_parser_14' added non terminal implementation                     
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_oa_5F_grammar::select_oa_5F_parser_14 (Lexique_oa_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------

GGS__32_lstringlist_2E_element::GGS__32_lstringlist_2E_element (void) :
mProperty_mValue_30_ (),
mProperty_mValue_31_ () {
}

//--------------------------------------------------------------------------------------------------

GGS__32_lstringlist_2E_element::GGS__32_lstringlist_2E_element (const GGS__32_lstringlist_2E_element & inSource) :
mProperty_mValue_30_ (inSource.mProperty_mValue_30_),
mProperty_mValue_31_ (inSource.mProperty_mValue_31_) {
}

//--------------------------------------------------------------------------------------------------

GGS__32_lstringlist_2E_element & GGS__32_lstringlist_2E_element::operator = (const GGS__32_lstringlist_2E_element & inSource) {
  mProperty_mValue_30_ = inSource.mProperty_mValue_30_ ;
  mProperty_mValue_31_ = inSource.mProperty_mValue_31_ ;
  return *this ;
}

//---Synthetized initializer -----------------------------------------------------------------------

GGS__32_lstringlist_2E_element GGS__32_lstringlist_2E_element::init_21__21_ (const GGS_lstring & in_mValue_30_,
                                                                             const GGS_lstring & in_mValue_31_,
                                                                             Compiler * inCompiler
                                                                             COMMA_UNUSED_LOCATION_ARGS) {
  GGS__32_lstringlist_2E_element result ;
  result.setInitializedProperties (inCompiler) ;
  result.mProperty_mValue_30_ = in_mValue_30_ ;
  result.mProperty_mValue_31_ = in_mValue_31_ ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

void GGS__32_lstringlist_2E_element::setInitializedProperties (Compiler * /* inCompiler */) {
}

//--------------------------------------------------------------------------------------------------

GGS__32_lstringlist_2E_element::GGS__32_lstringlist_2E_element (const GGS_lstring & inOperand0,
                                                                const GGS_lstring & inOperand1) :
mProperty_mValue_30_ (inOperand0),
mProperty_mValue_31_ (inOperand1) {
}

//--------------------------------------------------------------------------------------------------

GGS__32_lstringlist_2E_element GGS__32_lstringlist_2E_element::class_func_new (const GGS_lstring & in_mValue0,
                                                                               const GGS_lstring & in_mValue1,
                                                                               Compiler * inCompiler
                                                                               COMMA_UNUSED_LOCATION_ARGS) {
  GGS__32_lstringlist_2E_element result ;
  result.setInitializedProperties (inCompiler) ;
  result.mProperty_mValue_30_ = in_mValue0 ;
  result.mProperty_mValue_31_ = in_mValue1 ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

bool GGS__32_lstringlist_2E_element::isValid (void) const {
  return mProperty_mValue_30_.isValid () && mProperty_mValue_31_.isValid () ;
}

//--------------------------------------------------------------------------------------------------

void GGS__32_lstringlist_2E_element::drop (void) {
  mProperty_mValue_30_.drop () ;
  mProperty_mValue_31_.drop () ;
}

//--------------------------------------------------------------------------------------------------

void GGS__32_lstringlist_2E_element::description (String & ioString,
                                                  const int32_t inIndentation) const {
  ioString.appendCString ("<struct @2lstringlist.element:") ;
  if (! isValid ()) {
    ioString.appendCString (" not built") ;
  }else{
    mProperty_mValue_30_.description (ioString, inIndentation+1) ;
    ioString.appendCString (", ") ;
    mProperty_mValue_31_.description (ioString, inIndentation+1) ;
  }
  ioString.appendCString (">") ;
}

//--------------------------------------------------------------------------------------------------
//     @2lstringlist.element generic code implementation
//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor kTypeDescriptor_GALGAS__32_lstringlist_2E_element ("2lstringlist.element",
                                                                               nullptr) ;

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * GGS__32_lstringlist_2E_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS__32_lstringlist_2E_element ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GGS__32_lstringlist_2E_element::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GGS__32_lstringlist_2E_element (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS__32_lstringlist_2E_element GGS__32_lstringlist_2E_element::extractObject (const GGS_object & inObject,
                                                                              Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) {
  GGS__32_lstringlist_2E_element result ;
  const GGS__32_lstringlist_2E_element * p = (const GGS__32_lstringlist_2E_element *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GGS__32_lstringlist_2E_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("2lstringlist.element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_M_5F_processor_2E_element::GGS_M_5F_processor_2E_element (void) :
mProperty_lkey (),
mProperty_mIndex (),
mProperty_mStep () {
}

//--------------------------------------------------------------------------------------------------

GGS_M_5F_processor_2E_element::GGS_M_5F_processor_2E_element (const GGS_M_5F_processor_2E_element & inSource) :
mProperty_lkey (inSource.mProperty_lkey),
mProperty_mIndex (inSource.mProperty_mIndex),
mProperty_mStep (inSource.mProperty_mStep) {
}

//--------------------------------------------------------------------------------------------------

GGS_M_5F_processor_2E_element & GGS_M_5F_processor_2E_element::operator = (const GGS_M_5F_processor_2E_element & inSource) {
  mProperty_lkey = inSource.mProperty_lkey ;
  mProperty_mIndex = inSource.mProperty_mIndex ;
  mProperty_mStep = inSource.mProperty_mStep ;
  return *this ;
}

//---Synthetized initializer -----------------------------------------------------------------------

GGS_M_5F_processor_2E_element GGS_M_5F_processor_2E_element::init_21__21__21_ (const GGS_lstring & in_lkey,
                                                                               const GGS_uint & in_mIndex,
                                                                               const GGS_luint & in_mStep,
                                                                               Compiler * inCompiler
                                                                               COMMA_UNUSED_LOCATION_ARGS) {
  GGS_M_5F_processor_2E_element result ;
  result.setInitializedProperties (inCompiler) ;
  result.mProperty_lkey = in_lkey ;
  result.mProperty_mIndex = in_mIndex ;
  result.mProperty_mStep = in_mStep ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

void GGS_M_5F_processor_2E_element::setInitializedProperties (Compiler * /* inCompiler */) {
}

//--------------------------------------------------------------------------------------------------

GGS_M_5F_processor_2E_element::GGS_M_5F_processor_2E_element (const GGS_lstring & inOperand0,
                                                              const GGS_uint & inOperand1,
                                                              const GGS_luint & inOperand2) :
mProperty_lkey (inOperand0),
mProperty_mIndex (inOperand1),
mProperty_mStep (inOperand2) {
}

//--------------------------------------------------------------------------------------------------

GGS_M_5F_processor_2E_element GGS_M_5F_processor_2E_element::class_func_new (const GGS_lstring & in_lkey,
                                                                             const GGS_uint & in_mIndex,
                                                                             const GGS_luint & in_mStep,
                                                                             Compiler * inCompiler
                                                                             COMMA_UNUSED_LOCATION_ARGS) {
  GGS_M_5F_processor_2E_element result ;
  result.setInitializedProperties (inCompiler) ;
  result.mProperty_lkey = in_lkey ;
  result.mProperty_mIndex = in_mIndex ;
  result.mProperty_mStep = in_mStep ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

bool GGS_M_5F_processor_2E_element::isValid (void) const {
  return mProperty_lkey.isValid () && mProperty_mIndex.isValid () && mProperty_mStep.isValid () ;
}

//--------------------------------------------------------------------------------------------------

void GGS_M_5F_processor_2E_element::drop (void) {
  mProperty_lkey.drop () ;
  mProperty_mIndex.drop () ;
  mProperty_mStep.drop () ;
}

//--------------------------------------------------------------------------------------------------

void GGS_M_5F_processor_2E_element::description (String & ioString,
                                                 const int32_t inIndentation) const {
  ioString.appendCString ("<struct @M_processor.element:") ;
  if (! isValid ()) {
    ioString.appendCString (" not built") ;
  }else{
    mProperty_lkey.description (ioString, inIndentation+1) ;
    ioString.appendCString (", ") ;
    mProperty_mIndex.description (ioString, inIndentation+1) ;
    ioString.appendCString (", ") ;
    mProperty_mStep.description (ioString, inIndentation+1) ;
  }
  ioString.appendCString (">") ;
}

//--------------------------------------------------------------------------------------------------
//     @M_processor.element generic code implementation
//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor kTypeDescriptor_GALGAS_M_5F_processor_2E_element ("M_processor.element",
                                                                              nullptr) ;

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * GGS_M_5F_processor_2E_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_M_5F_processor_2E_element ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GGS_M_5F_processor_2E_element::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GGS_M_5F_processor_2E_element (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_M_5F_processor_2E_element GGS_M_5F_processor_2E_element::extractObject (const GGS_object & inObject,
                                                                            Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) {
  GGS_M_5F_processor_2E_element result ;
  const GGS_M_5F_processor_2E_element * p = (const GGS_M_5F_processor_2E_element *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GGS_M_5F_processor_2E_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("M_processor.element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//Optional @M_5F_processor_2E_element_3F_
//--------------------------------------------------------------------------------------------------

GGS_M_5F_processor_2E_element_3F_::GGS_M_5F_processor_2E_element_3F_ (void) :
AC_GALGAS_root (),
mValue (),
mState (OptionalState::invalid) {
}

//--------------------------------------------------------------------------------------------------

GGS_M_5F_processor_2E_element_3F_::GGS_M_5F_processor_2E_element_3F_ (const GGS_M_5F_processor_2E_element & inSource) :
AC_GALGAS_root (),
mValue (inSource),
mState (OptionalState::valuated) {
}


//--------------------------------------------------------------------------------------------------

GGS_M_5F_processor_2E_element_3F_ GGS_M_5F_processor_2E_element_3F_::init_nil (void) {
  GGS_M_5F_processor_2E_element_3F_ result ;
  result.mState = OptionalState::isNil ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

bool GGS_M_5F_processor_2E_element_3F_::isValid (void) const {
  bool result = false ;
  switch (mState) {
  case OptionalState::invalid :
    break ;
  case OptionalState::isNil :
    result = true ;
    break ;
  case OptionalState::valuated :
    result = mValue.isValid () ;
    break ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

bool GGS_M_5F_processor_2E_element_3F_::isValuated (void) const {
  return (mState == OptionalState::valuated) && mValue.isValid () ;
}

//--------------------------------------------------------------------------------------------------

void GGS_M_5F_processor_2E_element_3F_::drop (void) {
  mState = OptionalState::invalid ;
  mValue = GGS_M_5F_processor_2E_element () ;
}

//--------------------------------------------------------------------------------------------------

void GGS_M_5F_processor_2E_element_3F_::description (String & ioString,
                                                     const int32_t inIndentation) const {
  ioString.appendCString ("<optional @") ;
  ioString.appendString (staticTypeDescriptor ()->mGalgasTypeName) ;
  ioString.appendCString (": ") ;
  switch (mState) {
  case OptionalState::invalid :
    ioString.appendCString ("invalid") ;
    break ;
  case OptionalState::isNil :
    ioString.appendCString ("nil") ;
    break ;
  case OptionalState::valuated :
    mValue.description (ioString, inIndentation) ;
    break ;
  }
  ioString.appendCString (">") ;
}

//--------------------------------------------------------------------------------------------------
//     @M_processor.element? generic code implementation
//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor kTypeDescriptor_GALGAS_M_5F_processor_2E_element_3F_ ("M_processor.element?",
                                                                                  nullptr) ;

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * GGS_M_5F_processor_2E_element_3F_::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_M_5F_processor_2E_element_3F_ ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GGS_M_5F_processor_2E_element_3F_::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GGS_M_5F_processor_2E_element_3F_ (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_M_5F_processor_2E_element_3F_ GGS_M_5F_processor_2E_element_3F_::extractObject (const GGS_object & inObject,
                                                                                    Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) {
  GGS_M_5F_processor_2E_element_3F_ result ;
  const GGS_M_5F_processor_2E_element_3F_ * p = (const GGS_M_5F_processor_2E_element_3F_ *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GGS_M_5F_processor_2E_element_3F_ *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("M_processor.element?", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_M_5F_network_2E_element::GGS_M_5F_network_2E_element (void) :
mProperty_lkey (),
mProperty_mIndex (),
mProperty_mCANnetwork (),
mProperty_mScalingFactor () {
}

//--------------------------------------------------------------------------------------------------

GGS_M_5F_network_2E_element::GGS_M_5F_network_2E_element (const GGS_M_5F_network_2E_element & inSource) :
mProperty_lkey (inSource.mProperty_lkey),
mProperty_mIndex (inSource.mProperty_mIndex),
mProperty_mCANnetwork (inSource.mProperty_mCANnetwork),
mProperty_mScalingFactor (inSource.mProperty_mScalingFactor) {
}

//--------------------------------------------------------------------------------------------------

GGS_M_5F_network_2E_element & GGS_M_5F_network_2E_element::operator = (const GGS_M_5F_network_2E_element & inSource) {
  mProperty_lkey = inSource.mProperty_lkey ;
  mProperty_mIndex = inSource.mProperty_mIndex ;
  mProperty_mCANnetwork = inSource.mProperty_mCANnetwork ;
  mProperty_mScalingFactor = inSource.mProperty_mScalingFactor ;
  return *this ;
}

//---Synthetized initializer -----------------------------------------------------------------------

GGS_M_5F_network_2E_element GGS_M_5F_network_2E_element::init_21__21__21__21_ (const GGS_lstring & in_lkey,
                                                                               const GGS_uint & in_mIndex,
                                                                               const GGS_bool & in_mCANnetwork,
                                                                               const GGS_luint & in_mScalingFactor,
                                                                               Compiler * inCompiler
                                                                               COMMA_UNUSED_LOCATION_ARGS) {
  GGS_M_5F_network_2E_element result ;
  result.setInitializedProperties (inCompiler) ;
  result.mProperty_lkey = in_lkey ;
  result.mProperty_mIndex = in_mIndex ;
  result.mProperty_mCANnetwork = in_mCANnetwork ;
  result.mProperty_mScalingFactor = in_mScalingFactor ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

void GGS_M_5F_network_2E_element::setInitializedProperties (Compiler * /* inCompiler */) {
}

//--------------------------------------------------------------------------------------------------

GGS_M_5F_network_2E_element::GGS_M_5F_network_2E_element (const GGS_lstring & inOperand0,
                                                          const GGS_uint & inOperand1,
                                                          const GGS_bool & inOperand2,
                                                          const GGS_luint & inOperand3) :
mProperty_lkey (inOperand0),
mProperty_mIndex (inOperand1),
mProperty_mCANnetwork (inOperand2),
mProperty_mScalingFactor (inOperand3) {
}

//--------------------------------------------------------------------------------------------------

GGS_M_5F_network_2E_element GGS_M_5F_network_2E_element::class_func_new (const GGS_lstring & in_lkey,
                                                                         const GGS_uint & in_mIndex,
                                                                         const GGS_bool & in_mCANnetwork,
                                                                         const GGS_luint & in_mScalingFactor,
                                                                         Compiler * inCompiler
                                                                         COMMA_UNUSED_LOCATION_ARGS) {
  GGS_M_5F_network_2E_element result ;
  result.setInitializedProperties (inCompiler) ;
  result.mProperty_lkey = in_lkey ;
  result.mProperty_mIndex = in_mIndex ;
  result.mProperty_mCANnetwork = in_mCANnetwork ;
  result.mProperty_mScalingFactor = in_mScalingFactor ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

bool GGS_M_5F_network_2E_element::isValid (void) const {
  return mProperty_lkey.isValid () && mProperty_mIndex.isValid () && mProperty_mCANnetwork.isValid () && mProperty_mScalingFactor.isValid () ;
}

//--------------------------------------------------------------------------------------------------

void GGS_M_5F_network_2E_element::drop (void) {
  mProperty_lkey.drop () ;
  mProperty_mIndex.drop () ;
  mProperty_mCANnetwork.drop () ;
  mProperty_mScalingFactor.drop () ;
}

//--------------------------------------------------------------------------------------------------

void GGS_M_5F_network_2E_element::description (String & ioString,
                                               const int32_t inIndentation) const {
  ioString.appendCString ("<struct @M_network.element:") ;
  if (! isValid ()) {
    ioString.appendCString (" not built") ;
  }else{
    mProperty_lkey.description (ioString, inIndentation+1) ;
    ioString.appendCString (", ") ;
    mProperty_mIndex.description (ioString, inIndentation+1) ;
    ioString.appendCString (", ") ;
    mProperty_mCANnetwork.description (ioString, inIndentation+1) ;
    ioString.appendCString (", ") ;
    mProperty_mScalingFactor.description (ioString, inIndentation+1) ;
  }
  ioString.appendCString (">") ;
}

//--------------------------------------------------------------------------------------------------
//     @M_network.element generic code implementation
//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor kTypeDescriptor_GALGAS_M_5F_network_2E_element ("M_network.element",
                                                                            nullptr) ;

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * GGS_M_5F_network_2E_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_M_5F_network_2E_element ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GGS_M_5F_network_2E_element::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GGS_M_5F_network_2E_element (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_M_5F_network_2E_element GGS_M_5F_network_2E_element::extractObject (const GGS_object & inObject,
                                                                        Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) {
  GGS_M_5F_network_2E_element result ;
  const GGS_M_5F_network_2E_element * p = (const GGS_M_5F_network_2E_element *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GGS_M_5F_network_2E_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("M_network.element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//Optional @M_5F_network_2E_element_3F_
//--------------------------------------------------------------------------------------------------

GGS_M_5F_network_2E_element_3F_::GGS_M_5F_network_2E_element_3F_ (void) :
AC_GALGAS_root (),
mValue (),
mState (OptionalState::invalid) {
}

//--------------------------------------------------------------------------------------------------

GGS_M_5F_network_2E_element_3F_::GGS_M_5F_network_2E_element_3F_ (const GGS_M_5F_network_2E_element & inSource) :
AC_GALGAS_root (),
mValue (inSource),
mState (OptionalState::valuated) {
}


//--------------------------------------------------------------------------------------------------

GGS_M_5F_network_2E_element_3F_ GGS_M_5F_network_2E_element_3F_::init_nil (void) {
  GGS_M_5F_network_2E_element_3F_ result ;
  result.mState = OptionalState::isNil ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

bool GGS_M_5F_network_2E_element_3F_::isValid (void) const {
  bool result = false ;
  switch (mState) {
  case OptionalState::invalid :
    break ;
  case OptionalState::isNil :
    result = true ;
    break ;
  case OptionalState::valuated :
    result = mValue.isValid () ;
    break ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

bool GGS_M_5F_network_2E_element_3F_::isValuated (void) const {
  return (mState == OptionalState::valuated) && mValue.isValid () ;
}

//--------------------------------------------------------------------------------------------------

void GGS_M_5F_network_2E_element_3F_::drop (void) {
  mState = OptionalState::invalid ;
  mValue = GGS_M_5F_network_2E_element () ;
}

//--------------------------------------------------------------------------------------------------

void GGS_M_5F_network_2E_element_3F_::description (String & ioString,
                                                   const int32_t inIndentation) const {
  ioString.appendCString ("<optional @") ;
  ioString.appendString (staticTypeDescriptor ()->mGalgasTypeName) ;
  ioString.appendCString (": ") ;
  switch (mState) {
  case OptionalState::invalid :
    ioString.appendCString ("invalid") ;
    break ;
  case OptionalState::isNil :
    ioString.appendCString ("nil") ;
    break ;
  case OptionalState::valuated :
    mValue.description (ioString, inIndentation) ;
    break ;
  }
  ioString.appendCString (">") ;
}

//--------------------------------------------------------------------------------------------------
//     @M_network.element? generic code implementation
//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor kTypeDescriptor_GALGAS_M_5F_network_2E_element_3F_ ("M_network.element?",
                                                                                nullptr) ;

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * GGS_M_5F_network_2E_element_3F_::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_M_5F_network_2E_element_3F_ ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GGS_M_5F_network_2E_element_3F_::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GGS_M_5F_network_2E_element_3F_ (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_M_5F_network_2E_element_3F_ GGS_M_5F_network_2E_element_3F_::extractObject (const GGS_object & inObject,
                                                                                Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) {
  GGS_M_5F_network_2E_element_3F_ result ;
  const GGS_M_5F_network_2E_element_3F_ * p = (const GGS_M_5F_network_2E_element_3F_ *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GGS_M_5F_network_2E_element_3F_ *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("M_network.element?", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_M_5F_messages_2E_element::GGS_M_5F_messages_2E_element (void) :
mProperty_lkey (),
mProperty_mIndex (),
mProperty_mClass (),
mProperty_mNetworkIndex (),
mProperty_mBytesCount (),
mProperty_mPriority (),
mProperty_mOffset (),
mProperty_mDeadline (),
mProperty_mPeriod (),
mProperty_mMessageKind () {
}

//--------------------------------------------------------------------------------------------------

GGS_M_5F_messages_2E_element::GGS_M_5F_messages_2E_element (const GGS_M_5F_messages_2E_element & inSource) :
mProperty_lkey (inSource.mProperty_lkey),
mProperty_mIndex (inSource.mProperty_mIndex),
mProperty_mClass (inSource.mProperty_mClass),
mProperty_mNetworkIndex (inSource.mProperty_mNetworkIndex),
mProperty_mBytesCount (inSource.mProperty_mBytesCount),
mProperty_mPriority (inSource.mProperty_mPriority),
mProperty_mOffset (inSource.mProperty_mOffset),
mProperty_mDeadline (inSource.mProperty_mDeadline),
mProperty_mPeriod (inSource.mProperty_mPeriod),
mProperty_mMessageKind (inSource.mProperty_mMessageKind) {
}

//--------------------------------------------------------------------------------------------------

GGS_M_5F_messages_2E_element & GGS_M_5F_messages_2E_element::operator = (const GGS_M_5F_messages_2E_element & inSource) {
  mProperty_lkey = inSource.mProperty_lkey ;
  mProperty_mIndex = inSource.mProperty_mIndex ;
  mProperty_mClass = inSource.mProperty_mClass ;
  mProperty_mNetworkIndex = inSource.mProperty_mNetworkIndex ;
  mProperty_mBytesCount = inSource.mProperty_mBytesCount ;
  mProperty_mPriority = inSource.mProperty_mPriority ;
  mProperty_mOffset = inSource.mProperty_mOffset ;
  mProperty_mDeadline = inSource.mProperty_mDeadline ;
  mProperty_mPeriod = inSource.mProperty_mPeriod ;
  mProperty_mMessageKind = inSource.mProperty_mMessageKind ;
  return *this ;
}

//---Synthetized initializer -----------------------------------------------------------------------

GGS_M_5F_messages_2E_element GGS_M_5F_messages_2E_element::init_21__21__21__21__21__21__21__21__21__21_ (const GGS_lstring & in_lkey,
                                                                                                         const GGS_uint & in_mIndex,
                                                                                                         const GGS_luint & in_mClass,
                                                                                                         const GGS_uint & in_mNetworkIndex,
                                                                                                         const GGS_luint & in_mBytesCount,
                                                                                                         const GGS_luint & in_mPriority,
                                                                                                         const GGS_luint & in_mOffset,
                                                                                                         const GGS_luint & in_mDeadline,
                                                                                                         const GGS_luint & in_mPeriod,
                                                                                                         const GGS_AC_5F_canMessage & in_mMessageKind,
                                                                                                         Compiler * inCompiler
                                                                                                         COMMA_UNUSED_LOCATION_ARGS) {
  GGS_M_5F_messages_2E_element result ;
  result.setInitializedProperties (inCompiler) ;
  result.mProperty_lkey = in_lkey ;
  result.mProperty_mIndex = in_mIndex ;
  result.mProperty_mClass = in_mClass ;
  result.mProperty_mNetworkIndex = in_mNetworkIndex ;
  result.mProperty_mBytesCount = in_mBytesCount ;
  result.mProperty_mPriority = in_mPriority ;
  result.mProperty_mOffset = in_mOffset ;
  result.mProperty_mDeadline = in_mDeadline ;
  result.mProperty_mPeriod = in_mPeriod ;
  result.mProperty_mMessageKind = in_mMessageKind ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

void GGS_M_5F_messages_2E_element::setInitializedProperties (Compiler * /* inCompiler */) {
}

//--------------------------------------------------------------------------------------------------

GGS_M_5F_messages_2E_element::GGS_M_5F_messages_2E_element (const GGS_lstring & inOperand0,
                                                            const GGS_uint & inOperand1,
                                                            const GGS_luint & inOperand2,
                                                            const GGS_uint & inOperand3,
                                                            const GGS_luint & inOperand4,
                                                            const GGS_luint & inOperand5,
                                                            const GGS_luint & inOperand6,
                                                            const GGS_luint & inOperand7,
                                                            const GGS_luint & inOperand8,
                                                            const GGS_AC_5F_canMessage & inOperand9) :
mProperty_lkey (inOperand0),
mProperty_mIndex (inOperand1),
mProperty_mClass (inOperand2),
mProperty_mNetworkIndex (inOperand3),
mProperty_mBytesCount (inOperand4),
mProperty_mPriority (inOperand5),
mProperty_mOffset (inOperand6),
mProperty_mDeadline (inOperand7),
mProperty_mPeriod (inOperand8),
mProperty_mMessageKind (inOperand9) {
}

//--------------------------------------------------------------------------------------------------

GGS_M_5F_messages_2E_element GGS_M_5F_messages_2E_element::class_func_new (const GGS_lstring & in_lkey,
                                                                           const GGS_uint & in_mIndex,
                                                                           const GGS_luint & in_mClass,
                                                                           const GGS_uint & in_mNetworkIndex,
                                                                           const GGS_luint & in_mBytesCount,
                                                                           const GGS_luint & in_mPriority,
                                                                           const GGS_luint & in_mOffset,
                                                                           const GGS_luint & in_mDeadline,
                                                                           const GGS_luint & in_mPeriod,
                                                                           const GGS_AC_5F_canMessage & in_mMessageKind,
                                                                           Compiler * inCompiler
                                                                           COMMA_UNUSED_LOCATION_ARGS) {
  GGS_M_5F_messages_2E_element result ;
  result.setInitializedProperties (inCompiler) ;
  result.mProperty_lkey = in_lkey ;
  result.mProperty_mIndex = in_mIndex ;
  result.mProperty_mClass = in_mClass ;
  result.mProperty_mNetworkIndex = in_mNetworkIndex ;
  result.mProperty_mBytesCount = in_mBytesCount ;
  result.mProperty_mPriority = in_mPriority ;
  result.mProperty_mOffset = in_mOffset ;
  result.mProperty_mDeadline = in_mDeadline ;
  result.mProperty_mPeriod = in_mPeriod ;
  result.mProperty_mMessageKind = in_mMessageKind ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

bool GGS_M_5F_messages_2E_element::isValid (void) const {
  return mProperty_lkey.isValid () && mProperty_mIndex.isValid () && mProperty_mClass.isValid () && mProperty_mNetworkIndex.isValid () && mProperty_mBytesCount.isValid () && mProperty_mPriority.isValid () && mProperty_mOffset.isValid () && mProperty_mDeadline.isValid () && mProperty_mPeriod.isValid () && mProperty_mMessageKind.isValid () ;
}

//--------------------------------------------------------------------------------------------------

void GGS_M_5F_messages_2E_element::drop (void) {
  mProperty_lkey.drop () ;
  mProperty_mIndex.drop () ;
  mProperty_mClass.drop () ;
  mProperty_mNetworkIndex.drop () ;
  mProperty_mBytesCount.drop () ;
  mProperty_mPriority.drop () ;
  mProperty_mOffset.drop () ;
  mProperty_mDeadline.drop () ;
  mProperty_mPeriod.drop () ;
  mProperty_mMessageKind.drop () ;
}

//--------------------------------------------------------------------------------------------------

void GGS_M_5F_messages_2E_element::description (String & ioString,
                                                const int32_t inIndentation) const {
  ioString.appendCString ("<struct @M_messages.element:") ;
  if (! isValid ()) {
    ioString.appendCString (" not built") ;
  }else{
    mProperty_lkey.description (ioString, inIndentation+1) ;
    ioString.appendCString (", ") ;
    mProperty_mIndex.description (ioString, inIndentation+1) ;
    ioString.appendCString (", ") ;
    mProperty_mClass.description (ioString, inIndentation+1) ;
    ioString.appendCString (", ") ;
    mProperty_mNetworkIndex.description (ioString, inIndentation+1) ;
    ioString.appendCString (", ") ;
    mProperty_mBytesCount.description (ioString, inIndentation+1) ;
    ioString.appendCString (", ") ;
    mProperty_mPriority.description (ioString, inIndentation+1) ;
    ioString.appendCString (", ") ;
    mProperty_mOffset.description (ioString, inIndentation+1) ;
    ioString.appendCString (", ") ;
    mProperty_mDeadline.description (ioString, inIndentation+1) ;
    ioString.appendCString (", ") ;
    mProperty_mPeriod.description (ioString, inIndentation+1) ;
    ioString.appendCString (", ") ;
    mProperty_mMessageKind.description (ioString, inIndentation+1) ;
  }
  ioString.appendCString (">") ;
}

//--------------------------------------------------------------------------------------------------
//     @M_messages.element generic code implementation
//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor kTypeDescriptor_GALGAS_M_5F_messages_2E_element ("M_messages.element",
                                                                             nullptr) ;

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * GGS_M_5F_messages_2E_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_M_5F_messages_2E_element ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GGS_M_5F_messages_2E_element::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GGS_M_5F_messages_2E_element (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_M_5F_messages_2E_element GGS_M_5F_messages_2E_element::extractObject (const GGS_object & inObject,
                                                                          Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) {
  GGS_M_5F_messages_2E_element result ;
  const GGS_M_5F_messages_2E_element * p = (const GGS_M_5F_messages_2E_element *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GGS_M_5F_messages_2E_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("M_messages.element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//Optional @M_5F_messages_2E_element_3F_
//--------------------------------------------------------------------------------------------------

GGS_M_5F_messages_2E_element_3F_::GGS_M_5F_messages_2E_element_3F_ (void) :
AC_GALGAS_root (),
mValue (),
mState (OptionalState::invalid) {
}

//--------------------------------------------------------------------------------------------------

GGS_M_5F_messages_2E_element_3F_::GGS_M_5F_messages_2E_element_3F_ (const GGS_M_5F_messages_2E_element & inSource) :
AC_GALGAS_root (),
mValue (inSource),
mState (OptionalState::valuated) {
}


//--------------------------------------------------------------------------------------------------

GGS_M_5F_messages_2E_element_3F_ GGS_M_5F_messages_2E_element_3F_::init_nil (void) {
  GGS_M_5F_messages_2E_element_3F_ result ;
  result.mState = OptionalState::isNil ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

bool GGS_M_5F_messages_2E_element_3F_::isValid (void) const {
  bool result = false ;
  switch (mState) {
  case OptionalState::invalid :
    break ;
  case OptionalState::isNil :
    result = true ;
    break ;
  case OptionalState::valuated :
    result = mValue.isValid () ;
    break ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

bool GGS_M_5F_messages_2E_element_3F_::isValuated (void) const {
  return (mState == OptionalState::valuated) && mValue.isValid () ;
}

//--------------------------------------------------------------------------------------------------

void GGS_M_5F_messages_2E_element_3F_::drop (void) {
  mState = OptionalState::invalid ;
  mValue = GGS_M_5F_messages_2E_element () ;
}

//--------------------------------------------------------------------------------------------------

void GGS_M_5F_messages_2E_element_3F_::description (String & ioString,
                                                    const int32_t inIndentation) const {
  ioString.appendCString ("<optional @") ;
  ioString.appendString (staticTypeDescriptor ()->mGalgasTypeName) ;
  ioString.appendCString (": ") ;
  switch (mState) {
  case OptionalState::invalid :
    ioString.appendCString ("invalid") ;
    break ;
  case OptionalState::isNil :
    ioString.appendCString ("nil") ;
    break ;
  case OptionalState::valuated :
    mValue.description (ioString, inIndentation) ;
    break ;
  }
  ioString.appendCString (">") ;
}

//--------------------------------------------------------------------------------------------------
//     @M_messages.element? generic code implementation
//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor kTypeDescriptor_GALGAS_M_5F_messages_2E_element_3F_ ("M_messages.element?",
                                                                                 nullptr) ;

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * GGS_M_5F_messages_2E_element_3F_::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_M_5F_messages_2E_element_3F_ ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GGS_M_5F_messages_2E_element_3F_::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GGS_M_5F_messages_2E_element_3F_ (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_M_5F_messages_2E_element_3F_ GGS_M_5F_messages_2E_element_3F_::extractObject (const GGS_object & inObject,
                                                                                  Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) {
  GGS_M_5F_messages_2E_element_3F_ result ;
  const GGS_M_5F_messages_2E_element_3F_ * p = (const GGS_M_5F_messages_2E_element_3F_ *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GGS_M_5F_messages_2E_element_3F_ *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("M_messages.element?", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_M_5F_tasks_2E_element::GGS_M_5F_tasks_2E_element (void) :
mProperty_lkey (),
mProperty_mIndex (),
mProperty_mPriority (),
mProperty_mOffset (),
mProperty_mDeadline (),
mProperty_mDurationMin (),
mProperty_mDurationMax (),
mProperty_mProcessor (),
mProperty_mPeriod (),
mProperty_mTaskKind () {
}

//--------------------------------------------------------------------------------------------------

GGS_M_5F_tasks_2E_element::GGS_M_5F_tasks_2E_element (const GGS_M_5F_tasks_2E_element & inSource) :
mProperty_lkey (inSource.mProperty_lkey),
mProperty_mIndex (inSource.mProperty_mIndex),
mProperty_mPriority (inSource.mProperty_mPriority),
mProperty_mOffset (inSource.mProperty_mOffset),
mProperty_mDeadline (inSource.mProperty_mDeadline),
mProperty_mDurationMin (inSource.mProperty_mDurationMin),
mProperty_mDurationMax (inSource.mProperty_mDurationMax),
mProperty_mProcessor (inSource.mProperty_mProcessor),
mProperty_mPeriod (inSource.mProperty_mPeriod),
mProperty_mTaskKind (inSource.mProperty_mTaskKind) {
}

//--------------------------------------------------------------------------------------------------

GGS_M_5F_tasks_2E_element & GGS_M_5F_tasks_2E_element::operator = (const GGS_M_5F_tasks_2E_element & inSource) {
  mProperty_lkey = inSource.mProperty_lkey ;
  mProperty_mIndex = inSource.mProperty_mIndex ;
  mProperty_mPriority = inSource.mProperty_mPriority ;
  mProperty_mOffset = inSource.mProperty_mOffset ;
  mProperty_mDeadline = inSource.mProperty_mDeadline ;
  mProperty_mDurationMin = inSource.mProperty_mDurationMin ;
  mProperty_mDurationMax = inSource.mProperty_mDurationMax ;
  mProperty_mProcessor = inSource.mProperty_mProcessor ;
  mProperty_mPeriod = inSource.mProperty_mPeriod ;
  mProperty_mTaskKind = inSource.mProperty_mTaskKind ;
  return *this ;
}

//---Synthetized initializer -----------------------------------------------------------------------

GGS_M_5F_tasks_2E_element GGS_M_5F_tasks_2E_element::init_21__21__21__21__21__21__21__21__21__21_ (const GGS_lstring & in_lkey,
                                                                                                   const GGS_uint & in_mIndex,
                                                                                                   const GGS_luint & in_mPriority,
                                                                                                   const GGS_luint & in_mOffset,
                                                                                                   const GGS_luint & in_mDeadline,
                                                                                                   const GGS_luint & in_mDurationMin,
                                                                                                   const GGS_luint & in_mDurationMax,
                                                                                                   const GGS_uint & in_mProcessor,
                                                                                                   const GGS_luint & in_mPeriod,
                                                                                                   const GGS_AC_5F_task & in_mTaskKind,
                                                                                                   Compiler * inCompiler
                                                                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GGS_M_5F_tasks_2E_element result ;
  result.setInitializedProperties (inCompiler) ;
  result.mProperty_lkey = in_lkey ;
  result.mProperty_mIndex = in_mIndex ;
  result.mProperty_mPriority = in_mPriority ;
  result.mProperty_mOffset = in_mOffset ;
  result.mProperty_mDeadline = in_mDeadline ;
  result.mProperty_mDurationMin = in_mDurationMin ;
  result.mProperty_mDurationMax = in_mDurationMax ;
  result.mProperty_mProcessor = in_mProcessor ;
  result.mProperty_mPeriod = in_mPeriod ;
  result.mProperty_mTaskKind = in_mTaskKind ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

void GGS_M_5F_tasks_2E_element::setInitializedProperties (Compiler * /* inCompiler */) {
}

//--------------------------------------------------------------------------------------------------

GGS_M_5F_tasks_2E_element::GGS_M_5F_tasks_2E_element (const GGS_lstring & inOperand0,
                                                      const GGS_uint & inOperand1,
                                                      const GGS_luint & inOperand2,
                                                      const GGS_luint & inOperand3,
                                                      const GGS_luint & inOperand4,
                                                      const GGS_luint & inOperand5,
                                                      const GGS_luint & inOperand6,
                                                      const GGS_uint & inOperand7,
                                                      const GGS_luint & inOperand8,
                                                      const GGS_AC_5F_task & inOperand9) :
mProperty_lkey (inOperand0),
mProperty_mIndex (inOperand1),
mProperty_mPriority (inOperand2),
mProperty_mOffset (inOperand3),
mProperty_mDeadline (inOperand4),
mProperty_mDurationMin (inOperand5),
mProperty_mDurationMax (inOperand6),
mProperty_mProcessor (inOperand7),
mProperty_mPeriod (inOperand8),
mProperty_mTaskKind (inOperand9) {
}

//--------------------------------------------------------------------------------------------------

GGS_M_5F_tasks_2E_element GGS_M_5F_tasks_2E_element::class_func_new (const GGS_lstring & in_lkey,
                                                                     const GGS_uint & in_mIndex,
                                                                     const GGS_luint & in_mPriority,
                                                                     const GGS_luint & in_mOffset,
                                                                     const GGS_luint & in_mDeadline,
                                                                     const GGS_luint & in_mDurationMin,
                                                                     const GGS_luint & in_mDurationMax,
                                                                     const GGS_uint & in_mProcessor,
                                                                     const GGS_luint & in_mPeriod,
                                                                     const GGS_AC_5F_task & in_mTaskKind,
                                                                     Compiler * inCompiler
                                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GGS_M_5F_tasks_2E_element result ;
  result.setInitializedProperties (inCompiler) ;
  result.mProperty_lkey = in_lkey ;
  result.mProperty_mIndex = in_mIndex ;
  result.mProperty_mPriority = in_mPriority ;
  result.mProperty_mOffset = in_mOffset ;
  result.mProperty_mDeadline = in_mDeadline ;
  result.mProperty_mDurationMin = in_mDurationMin ;
  result.mProperty_mDurationMax = in_mDurationMax ;
  result.mProperty_mProcessor = in_mProcessor ;
  result.mProperty_mPeriod = in_mPeriod ;
  result.mProperty_mTaskKind = in_mTaskKind ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

bool GGS_M_5F_tasks_2E_element::isValid (void) const {
  return mProperty_lkey.isValid () && mProperty_mIndex.isValid () && mProperty_mPriority.isValid () && mProperty_mOffset.isValid () && mProperty_mDeadline.isValid () && mProperty_mDurationMin.isValid () && mProperty_mDurationMax.isValid () && mProperty_mProcessor.isValid () && mProperty_mPeriod.isValid () && mProperty_mTaskKind.isValid () ;
}

//--------------------------------------------------------------------------------------------------

void GGS_M_5F_tasks_2E_element::drop (void) {
  mProperty_lkey.drop () ;
  mProperty_mIndex.drop () ;
  mProperty_mPriority.drop () ;
  mProperty_mOffset.drop () ;
  mProperty_mDeadline.drop () ;
  mProperty_mDurationMin.drop () ;
  mProperty_mDurationMax.drop () ;
  mProperty_mProcessor.drop () ;
  mProperty_mPeriod.drop () ;
  mProperty_mTaskKind.drop () ;
}

//--------------------------------------------------------------------------------------------------

void GGS_M_5F_tasks_2E_element::description (String & ioString,
                                             const int32_t inIndentation) const {
  ioString.appendCString ("<struct @M_tasks.element:") ;
  if (! isValid ()) {
    ioString.appendCString (" not built") ;
  }else{
    mProperty_lkey.description (ioString, inIndentation+1) ;
    ioString.appendCString (", ") ;
    mProperty_mIndex.description (ioString, inIndentation+1) ;
    ioString.appendCString (", ") ;
    mProperty_mPriority.description (ioString, inIndentation+1) ;
    ioString.appendCString (", ") ;
    mProperty_mOffset.description (ioString, inIndentation+1) ;
    ioString.appendCString (", ") ;
    mProperty_mDeadline.description (ioString, inIndentation+1) ;
    ioString.appendCString (", ") ;
    mProperty_mDurationMin.description (ioString, inIndentation+1) ;
    ioString.appendCString (", ") ;
    mProperty_mDurationMax.description (ioString, inIndentation+1) ;
    ioString.appendCString (", ") ;
    mProperty_mProcessor.description (ioString, inIndentation+1) ;
    ioString.appendCString (", ") ;
    mProperty_mPeriod.description (ioString, inIndentation+1) ;
    ioString.appendCString (", ") ;
    mProperty_mTaskKind.description (ioString, inIndentation+1) ;
  }
  ioString.appendCString (">") ;
}

//--------------------------------------------------------------------------------------------------
//     @M_tasks.element generic code implementation
//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor kTypeDescriptor_GALGAS_M_5F_tasks_2E_element ("M_tasks.element",
                                                                          nullptr) ;

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * GGS_M_5F_tasks_2E_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_M_5F_tasks_2E_element ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GGS_M_5F_tasks_2E_element::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GGS_M_5F_tasks_2E_element (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_M_5F_tasks_2E_element GGS_M_5F_tasks_2E_element::extractObject (const GGS_object & inObject,
                                                                    Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) {
  GGS_M_5F_tasks_2E_element result ;
  const GGS_M_5F_tasks_2E_element * p = (const GGS_M_5F_tasks_2E_element *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GGS_M_5F_tasks_2E_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("M_tasks.element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//Optional @M_5F_tasks_2E_element_3F_
//--------------------------------------------------------------------------------------------------

GGS_M_5F_tasks_2E_element_3F_::GGS_M_5F_tasks_2E_element_3F_ (void) :
AC_GALGAS_root (),
mValue (),
mState (OptionalState::invalid) {
}

//--------------------------------------------------------------------------------------------------

GGS_M_5F_tasks_2E_element_3F_::GGS_M_5F_tasks_2E_element_3F_ (const GGS_M_5F_tasks_2E_element & inSource) :
AC_GALGAS_root (),
mValue (inSource),
mState (OptionalState::valuated) {
}


//--------------------------------------------------------------------------------------------------

GGS_M_5F_tasks_2E_element_3F_ GGS_M_5F_tasks_2E_element_3F_::init_nil (void) {
  GGS_M_5F_tasks_2E_element_3F_ result ;
  result.mState = OptionalState::isNil ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

bool GGS_M_5F_tasks_2E_element_3F_::isValid (void) const {
  bool result = false ;
  switch (mState) {
  case OptionalState::invalid :
    break ;
  case OptionalState::isNil :
    result = true ;
    break ;
  case OptionalState::valuated :
    result = mValue.isValid () ;
    break ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

bool GGS_M_5F_tasks_2E_element_3F_::isValuated (void) const {
  return (mState == OptionalState::valuated) && mValue.isValid () ;
}

//--------------------------------------------------------------------------------------------------

void GGS_M_5F_tasks_2E_element_3F_::drop (void) {
  mState = OptionalState::invalid ;
  mValue = GGS_M_5F_tasks_2E_element () ;
}

//--------------------------------------------------------------------------------------------------

void GGS_M_5F_tasks_2E_element_3F_::description (String & ioString,
                                                 const int32_t inIndentation) const {
  ioString.appendCString ("<optional @") ;
  ioString.appendString (staticTypeDescriptor ()->mGalgasTypeName) ;
  ioString.appendCString (": ") ;
  switch (mState) {
  case OptionalState::invalid :
    ioString.appendCString ("invalid") ;
    break ;
  case OptionalState::isNil :
    ioString.appendCString ("nil") ;
    break ;
  case OptionalState::valuated :
    mValue.description (ioString, inIndentation) ;
    break ;
  }
  ioString.appendCString (">") ;
}

//--------------------------------------------------------------------------------------------------
//     @M_tasks.element? generic code implementation
//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor kTypeDescriptor_GALGAS_M_5F_tasks_2E_element_3F_ ("M_tasks.element?",
                                                                              nullptr) ;

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * GGS_M_5F_tasks_2E_element_3F_::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_M_5F_tasks_2E_element_3F_ ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GGS_M_5F_tasks_2E_element_3F_::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GGS_M_5F_tasks_2E_element_3F_ (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_M_5F_tasks_2E_element_3F_ GGS_M_5F_tasks_2E_element_3F_::extractObject (const GGS_object & inObject,
                                                                            Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) {
  GGS_M_5F_tasks_2E_element_3F_ result ;
  const GGS_M_5F_tasks_2E_element_3F_ * p = (const GGS_M_5F_tasks_2E_element_3F_ *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GGS_M_5F_tasks_2E_element_3F_ *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("M_tasks.element?", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//
//                               Bool options                                                    
//
//--------------------------------------------------------------------------------------------------

BoolCommandLineOption gOption_oa_5F_cli_5F_options_createIntermediateFiles ("oa_cli_options",
                                         "createIntermediateFiles",
                                         67,
                                         "create-intermediate-files",
                                         "Create the intermediate files") ;

BoolCommandLineOption gOption_oa_5F_cli_5F_options_useCANmaxLegth ("oa_cli_options",
                                         "useCANmaxLegth",
                                         77,
                                         "use-can-max-length",
                                         "Use only CAN messages max length") ;

//--------------------------------------------------------------------------------------------------
//
//                               UInt options                                                    
//
//--------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------
//
//                              String options                                                   
//
//--------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------
//
//                              String List options                                              
//
//--------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------


#include "project_header.h"
#include "F_mainForLIBPM.h"
#include "analyzeCommandLineOptions.h"
#include "builtin-command-line-options.h"
#include "C_galgas_CLI_Options.h"
#include "F_verbose_output.h"
#include "LexiqueIntrospection.h"
#include "F_DisplayException.h"

//--------------------------------------------------------------------------------------------------
//                      print_tool_help_message                                                  
//--------------------------------------------------------------------------------------------------

static void print_tool_help_message (void) {
  gCout.appendCString ("Compiled with GALGAS revision NUMERO_REVISION_GALGAS\n") ;
}

//--------------------------------------------------------------------------------------------------

static const char * kSourceFileExtensions [] = {
  "nprt",
  nullptr
} ;    

//--------------------------------------------------------------------------------------------------

static const char * kSourceFileHelpMessages [] = {
  "an '.nprt' source file",
  nullptr
} ;    

//--------------------------------------------------------------------------------------------------

const char * projectVersionString (void) {
  return "1.2.0" ;
}

//--------------------------------------------------------------------------------------------------
//
//Routine 'before'
//
//--------------------------------------------------------------------------------------------------

static void routine_before (Compiler * /* inCompiler */
                            COMMA_UNUSED_LOCATION_ARGS) {
}


//--------------------------------------------------------------------------------------------------
//
//Routine 'after'
//
//--------------------------------------------------------------------------------------------------

static void routine_after (Compiler * /* inCompiler */
                           COMMA_UNUSED_LOCATION_ARGS) {
}


//--------------------------------------------------------------------------------------------------
//
//Routine 'programRule_0'
//
//--------------------------------------------------------------------------------------------------

static void routine_programRule_5F__30_ (const GGS_lstring constinArgument_inSourceFile,
                                         Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) {
  cGrammar_oa_5F_grammar::_performSourceFileParsing_ (inCompiler, constinArgument_inSourceFile  COMMA_SOURCE_FILE ("oa_main.galgas", 11)) ;
}


//--------------------------------------------------------------------------------------------------
//
//                      M A I N    F O R    L I B P M                                            
//
//--------------------------------------------------------------------------------------------------

int mainForLIBPM (int inArgc, const char * inArgv []) {
//--- Analyze Command Line Options
  GenericUniqueArray <String> sourceFilesArray ;
  analyzeCommandLineOptions (inArgc, inArgv,
                             sourceFilesArray,
                             kSourceFileExtensions,
                             kSourceFileHelpMessages,
                             print_tool_help_message) ;
//---
  int returnCode = 0 ; // No error
//--- Set Execution mode
  String executionModeOptionErrorMessage ;
  setExecutionMode (executionModeOptionErrorMessage) ;
  if (executionModeOptionErrorMessage.length () > 0) {
    gCout.appendString (executionModeOptionErrorMessage) ;
    returnCode = 1 ;
  }else{
  //--- Common lexique object
    Compiler * commonCompiler = nullptr ;
    macroMyNew (commonCompiler, Compiler (nullptr COMMA_HERE)) ;
    try{
      routine_before (commonCompiler COMMA_HERE) ;
      LexiqueIntrospection::handleGetKeywordListOption (commonCompiler) ;
      const bool verboseOptionOn = verboseOutput () ;
      for (int32_t i=0 ; i<sourceFilesArray.count () ; i++) {
        const String fileExtension = sourceFilesArray (i COMMA_HERE).pathExtension () ;
        const GGS_string sfp = GGS_string (sourceFilesArray (i COMMA_HERE)) ;
        const GGS_location location = commonCompiler->here () ;
        const GGS_lstring sourceFilePath (sfp, location) ;
        int r = 0 ;
        if (fileExtension == "nprt") {
          switch (executionMode ()) {
          case kExecutionModeNormal :
            routine_programRule_5F__30_ (sourceFilePath, commonCompiler COMMA_HERE) ;
            break ;
          case kExecutionModeLexicalAnalysisOnly :
            cGrammar_oa_5F_grammar::performOnlyLexicalAnalysis (commonCompiler, sourceFilesArray (i COMMA_HERE)) ;
            break ;
          case kExecutionModeSyntaxAnalysisOnly :
            cGrammar_oa_5F_grammar::performOnlySyntaxAnalysis (commonCompiler, sourceFilesArray (i COMMA_HERE)) ;
            break ;
          case kExecutionModeIndexing :
            cGrammar_oa_5F_grammar::performIndexing (commonCompiler, sourceFilesArray (i COMMA_HERE)) ;
            break ;
          case kExecutionModeLatex :
            cGrammar_oa_5F_grammar::performOnlyLexicalAnalysis (commonCompiler, sourceFilesArray (i COMMA_HERE)) ;
            break ;
          }
        }else{
          printf ("*** Error: unhandled extension for file '%s' ***\n", sourceFilesArray (i COMMA_HERE).cString ()) ;
          r = 1 ;
        }
        if (r != 0) {
          returnCode = r ;
        }
      }
    //--- Error or warnings ?
      if (totalErrorCount () > 0) {
        returnCode = 1 ; // Error code
      }else if (totalWarningCount () > 0) {
        if (gOption_galgas_5F_builtin_5F_options_treat_5F_warnings_5F_as_5F_error.mValue) {
          returnCode = 1 ; // Error code
          if (verboseOptionOn) {
            printf ("** Note: warnings are treated as errors. **\n") ;
          }
        }
      }
    //--- Epilogue
      routine_after (commonCompiler COMMA_HERE) ;
    //--- Emit JSON issue file ?
      if (gOption_generic_5F_cli_5F_options_emit_5F_issue_5F_json_5F_file.mValue != "") {
        commonCompiler->writeIssueJSONFile (gOption_generic_5F_cli_5F_options_emit_5F_issue_5F_json_5F_file.mValue) ;
      }
    //--- Display error and warnings count
      if (verboseOptionOn || (totalWarningCount () > 0) || (totalErrorCount () > 0)) {
        String message ;
        if (totalWarningCount () == 0) {
          message.appendCString ("No warning") ;
        }else if (totalWarningCount () == 1) {
          message.appendCString ("1 warning") ;
        }else{
          message.appendSigned (totalWarningCount ()) ;
          message.appendCString (" warnings") ;
        }
        message.appendCString (", ") ;
        if (totalErrorCount () == 0) {
          message.appendCString ("no error") ;
        }else if (totalErrorCount () == 1) {
          message.appendCString ("1 error") ;
        }else{
          message.appendSigned (totalErrorCount ()) ;
          message.appendCString (" errors") ;
        }
        message.appendCString (".\n") ;
        ggs_printMessage (message COMMA_HERE) ;
      }
    }catch (const ::std::exception & e) {
      F_default_display_exception (e) ;
      returnCode = 1 ; // Error code
    }catch (...) {
      printf ("**** Unknow exception ****\n") ;
      throw ;
    }
    macroDetachSharedObject (commonCompiler) ;
  }
  return returnCode ;
}

