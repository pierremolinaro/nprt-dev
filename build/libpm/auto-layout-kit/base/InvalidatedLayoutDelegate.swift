//--------------------------------------------------------------------------------------------------

import AppKit

//--------------------------------------------------------------------------------------------------

@MainActor public protocol InvalidatedLayoutDelegate : AnyObject {

  func layoutHasBeenInvalidated (for inView : BaseView)

}

//--------------------------------------------------------------------------------------------------

