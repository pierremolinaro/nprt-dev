//--------------------------------------------------------------------------------------------------

import AppKit

//--------------------------------------------------------------------------------------------------

public extension String {

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  var lastPathComponent : String { return (self as NSString).lastPathComponent }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  var deletingPathExtension : String { return (self as NSString).deletingPathExtension }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  var pathExtension : String { return (self as NSString).pathExtension }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  var deletingLastPathComponent : String { return (self as NSString).deletingLastPathComponent }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func appendingPathComponent (_ path : String) -> String {
    return (self as NSString).appendingPathComponent (path)
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  var unicodeArray : [UnicodeScalar] {
    var array = [UnicodeScalar] ()
    for scalar in self.unicodeScalars {
      array.append (scalar)
    }
    return array
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  static func numericCompare (_ inLeft : String, _ inAscending : Bool, _ inRight : String) -> Bool {
    let comparisonResult = inLeft.compare (inRight, options: [.numeric])
    return inAscending ? (comparisonResult == .orderedAscending) : (comparisonResult == .orderedDescending)
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  static func numericCompare (_ inLeft : String, _ inRight : String) -> Bool {
    return numericCompare (inLeft, true, inRight)
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  static func numeriCaseInsensitiveCompare (_ inLeft : String, _ inRight : String) -> Bool {
    return numericCompare (inLeft.uppercased (), true, inRight.uppercased ())
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func capitalizingFirstLetter () -> String {
    return self.prefix (1).capitalized + self.dropFirst ()
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

//  mutating func capitalizeFirstLetter () {
//    self = self.capitalizingFirstLetter ()
//  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

}

//--------------------------------------------------------------------------------------------------

func values_String_are_ordered (_ inLeft : String,
                                _ inAscending : Bool,
                                _ inRight : String) -> Bool {
  let left  = inAscending ? inLeft  : inRight
  let right = inAscending ? inRight : inLeft
  return left.localizedStandardCompare (right) == .orderedAscending
}

//--------------------------------------------------------------------------------------------------

@MainActor func compare_String_properties (_ inLeft : EBObservableProperty <String>,
                                           _ inAscending : Bool,
                                           _ inRight : EBObservableProperty <String>) -> ComparisonResult {
  let left  = inAscending ? inLeft  : inRight
  let right = inAscending ? inRight : inLeft
  switch left.selection {
  case .empty :
    switch right.selection {
    case .empty :
      return .orderedSame
    default:
      return .orderedAscending
    }
  case .multiple :
    switch right.selection {
    case .empty :
      return .orderedDescending
    case .multiple :
      return .orderedSame
   case .single (_) :
      return .orderedAscending
   }
 case .single (let currentValue) :
    switch right.selection {
    case .empty, .multiple :
      return .orderedDescending
    case .single (let otherValue) :
      return currentValue.localizedStandardCompare (otherValue)
    }
  }
}

//--------------------------------------------------------------------------------------------------

extension Array where Element == String {

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func numericallySorted () -> [String] {
    return self.sorted (by: String.numericCompare)
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

}

//--------------------------------------------------------------------------------------------------
