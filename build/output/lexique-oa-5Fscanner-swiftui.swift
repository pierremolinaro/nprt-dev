//--- START OF USER ZONE 1


//--- END OF USER ZONE 1
//--------------------------------------------------------------------------------------------------
//   LEXIQUE oa_scanner
//--------------------------------------------------------------------------------------------------

import SwiftUI

//--------------------------------------------------------------------------------------------------

struct SettingViewFor_oa_scanner : View {

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  @AppStorage("FontFor_oa_scanner")
  private var mFont = CustomFont (nsFont: NSFont.monospacedSystemFont (ofSize: 13.0, weight: .regular))

  @AppStorage("LineHeightFor_oa_scanner")
  private var mLineHeight : Int = 12

  @AppStorage("ColorFor_oa_scanner")
  private var mDefaultColor : Color = .black

  @AppStorage("ColorFor_oa_scanner-identifier")
  private var mColorFor_identifier : Color = .black

  @AppStorage("BoldFor_oa_scanner-identifier")
  private var mBoldFor_identifier : Bool = false

  @AppStorage("ItalicFor_oa_scanner-identifier")
  private var mItalicFor_identifier : Bool = false

  @AppStorage("ColorFor_oa_scanner-keyWords")
  private var mColorFor_keyWords : Color = .black

  @AppStorage("BoldFor_oa_scanner-keyWords")
  private var mBoldFor_keyWords : Bool = false

  @AppStorage("ItalicFor_oa_scanner-keyWords")
  private var mItalicFor_keyWords : Bool = false

  @AppStorage("ColorFor_oa_scanner-delimitors")
  private var mColorFor_delimitors : Color = .black

  @AppStorage("BoldFor_oa_scanner-delimitors")
  private var mBoldFor_delimitors : Bool = false

  @AppStorage("ItalicFor_oa_scanner-delimitors")
  private var mItalicFor_delimitors : Bool = false

  @AppStorage("ColorFor_oa_scanner-integerStyle")
  private var mColorFor_integerStyle : Color = .black

  @AppStorage("BoldFor_oa_scanner-integerStyle")
  private var mBoldFor_integerStyle : Bool = false

  @AppStorage("ItalicFor_oa_scanner-integerStyle")
  private var mItalicFor_integerStyle : Bool = false


  @AppStorage("ColorFor_oa_scanner_lexical_error")
  private var mColorFor_lexical_error : Color = .red

  @AppStorage("BoldFor_oa_scanner_lexical_error")
  private var mBoldFor_lexical_error : Bool = false

  @AppStorage("ItalicFor_oa_scanner_lexical_error")
  private var mItalicFor_lexical_error : Bool = false

  @AppStorage("ColorFor_oa_scanner_template")
  private var mColorFor_template : Color = .gray

  @AppStorage("BoldFor_oa_scanner_template")
  private var mBoldFor_template : Bool = false

  @AppStorage("ItalicFor_oa_scanner_template")
  private var mItalicFor_template : Bool = false

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  var body : some View {
    Form {
      LabeledContent ("Font") { CustomFontPicker (fontBinding: self.$mFont) }
      Picker("Line Height", selection: self.$mLineHeight) {
        Text("1.0").tag(10)
        Text("1.1").tag(11)
        Text("1.2").tag(12)
        Text("1.5").tag(15)
        Text("1.7").tag(17)
        Text("2.0").tag(20)
      }.pickerStyle(.automatic)
      ColorPicker ("Default Color", selection: self.$mDefaultColor)
      LabeledContent ("Identifiers") {
        HStack {
          ColorPicker ("", selection: self.$mColorFor_identifier).labelsHidden ()
          Toggle ("Bold", isOn: self.$mBoldFor_identifier)
          Toggle ("Italic", isOn: self.$mItalicFor_identifier)
        }
      }
      LabeledContent ("Key words") {
        HStack {
          ColorPicker ("", selection: self.$mColorFor_keyWords).labelsHidden ()
          Toggle ("Bold", isOn: self.$mBoldFor_keyWords)
          Toggle ("Italic", isOn: self.$mItalicFor_keyWords)
        }
      }
      LabeledContent ("Delimitors") {
        HStack {
          ColorPicker ("", selection: self.$mColorFor_delimitors).labelsHidden ()
          Toggle ("Bold", isOn: self.$mBoldFor_delimitors)
          Toggle ("Italic", isOn: self.$mItalicFor_delimitors)
        }
      }
      LabeledContent ("Integer constants") {
        HStack {
          ColorPicker ("", selection: self.$mColorFor_integerStyle).labelsHidden ()
          Toggle ("Bold", isOn: self.$mBoldFor_integerStyle)
          Toggle ("Italic", isOn: self.$mItalicFor_integerStyle)
        }
      }
      LabeledContent ("Lexical Error") {
        HStack {
          ColorPicker ("", selection: self.$mColorFor_lexical_error).labelsHidden ()
          Toggle ("Bold", isOn: self.$mBoldFor_lexical_error)
          Toggle ("Italic", isOn: self.$mItalicFor_lexical_error)
        }
      }
      LabeledContent ("Template") {
        HStack {
          ColorPicker ("", selection: self.$mColorFor_template).labelsHidden ()
          Toggle ("Bold", isOn: self.$mBoldFor_template)
          Toggle ("Italic", isOn: self.$mItalicFor_template)
        }
      }
    }.padding (20)
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

}

//--------------------------------------------------------------------------------------------------

#Preview {
  SettingViewFor_oa_scanner ()
}

//--------------------------------------------------------------------------------------------------

class ScannerFor_oa_scanner : SWIFT_Scanner {

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  private let mDebug = false
  private let mVerboseDebug = false
  private var mTokenArray = [SWIFT_Token] ()

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  override func selectionRange (forProposedRange inProposedSelectionRange : NSRange,
                                granularity inGranularity : NSSelectionGranularity,
                                nsTextViewComputedRange inTextViewComputedRange : NSRange) -> NSRange {
    var result = inTextViewComputedRange
    switch inGranularity {
    case .selectByCharacter :
      ()
    case .selectByWord :
      var found = false
      var idx = 0
      while idx < self.mTokenArray.count, !found {
        let token = self.mTokenArray [idx]
        idx += 1
        let tokenRange = token.range
        found = ((tokenRange.location + tokenRange.length) > inProposedSelectionRange.location)
           && (tokenRange.location <= inProposedSelectionRange.location)
        if found, self.atomicSelectionFor (token: token.tokenCode) {
          result = tokenRange
        }
      }
    case .selectByParagraph :
      var found = false
      var idx = 0
      while idx < self.mTokenArray.count, !found {
        let token = self.mTokenArray [idx]
        idx += 1
        let tokenRange = token.range
        found = ((tokenRange.location + tokenRange.length) > inProposedSelectionRange.location)
           && (tokenRange.location <= inProposedSelectionRange.location)
        if found {
          result = tokenRange
        }
      }
    @unknown default:
      ()
    }
    return result
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  //   Scanner
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  private var mLexicalAttribute_identifierString : String = ""
  private var mLexicalAttribute_ulongValue : UInt32 = 0

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func lexiqueIdentifier () -> String {
    return oa_scanner_lexiqueIdentifier ()
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func isTemplateLexique () -> Bool {
    return false
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func terminalVocabularyCount () -> Int {
    return 24
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func styleIndexFor (token inTokenIndex : UInt16) -> UInt8 {
    let kTerminalSymbolStyles : [UInt8] = [
      0, // Default
      1, // 1 : oa_scanner_1_identifier
      4, // 2 : oa_scanner_1_literal_5F_integer
      2, // 3 : oa_scanner_1_system
      2, // 4 : oa_scanner_1_end
      2, // 5 : oa_scanner_1_task
      2, // 6 : oa_scanner_1_standard
      2, // 7 : oa_scanner_1_extended
      2, // 8 : oa_scanner_1_message
      2, // 9 : oa_scanner_1_length
      2, // 10 : oa_scanner_1_priority
      2, // 11 : oa_scanner_1_period
      2, // 12 : oa_scanner_1_offset
      2, // 13 : oa_scanner_1_on
      2, // 14 : oa_scanner_1_deadline
      2, // 15 : oa_scanner_1_duration
      2, // 16 : oa_scanner_1_processor
      2, // 17 : oa_scanner_1_can
      2, // 18 : oa_scanner_1_van
      2, // 19 : oa_scanner_1_network
      2, // 20 : oa_scanner_1_scalingfactor
      2, // 21 : oa_scanner_1_every
      3, // 22 : oa_scanner_1__2C_
      3, // 23 : oa_scanner_1__3B_
      3, // 24 : oa_scanner_1__2E__2E_
      5, // 25 : oa_scanner_2_ERROR
      6  // 26 : oa_scanner_2_TEMPLATE
    ]
    return kTerminalSymbolStyles [Int (inTokenIndex)]
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func atomicSelectionFor (token inTokenIndex : UInt16) -> Bool {
    let kTerminalAtomicSelection : [Bool] = [
      false, // Default
      true, // 1 : oa_scanner_1_identifier
      true, // 2 : oa_scanner_1_literal_5F_integer
      true, // 3 : oa_scanner_1_system
      true, // 4 : oa_scanner_1_end
      true, // 5 : oa_scanner_1_task
      true, // 6 : oa_scanner_1_standard
      true, // 7 : oa_scanner_1_extended
      true, // 8 : oa_scanner_1_message
      true, // 9 : oa_scanner_1_length
      true, // 10 : oa_scanner_1_priority
      true, // 11 : oa_scanner_1_period
      true, // 12 : oa_scanner_1_offset
      true, // 13 : oa_scanner_1_on
      true, // 14 : oa_scanner_1_deadline
      true, // 15 : oa_scanner_1_duration
      true, // 16 : oa_scanner_1_processor
      true, // 17 : oa_scanner_1_can
      true, // 18 : oa_scanner_1_van
      true, // 19 : oa_scanner_1_network
      true, // 20 : oa_scanner_1_scalingfactor
      true, // 21 : oa_scanner_1_every
      true, // 22 : oa_scanner_1__2C_
      true, // 23 : oa_scanner_1__3B_
      true, // 24 : oa_scanner_1__2E__2E_
      false, // 25 : oa_scanner_2_ERROR
      false  // 26 : oa_scanner_2_TEMPLATE
    ]
    return kTerminalAtomicSelection [Int (inTokenIndex)]
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func indexingTitles () -> [String] {

    return []
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  //  S T Y L E S
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func styleCount () -> UInt8 {
    return 4
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func styleNameFor (styleIndex inIndex : UInt8) -> String {
    return oa_scanner_styleNameFor (styleIndex: inIndex)
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func styleIdentifierFor (styleIndex inIndex : UInt8) -> String {
    return oa_scanner_styleIdentifierFor (styleIndex: inIndex)
  }

 // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  final var mFont = CustomFont (nsFont: NSFont.monospacedSystemFont (ofSize: 13.0, weight: .regular))
  final var mLineHeight : Int = 12
  final var mDefaultColor : Color = .black
  final var mColorFor_identifier : Color = .black
  final var mBoldFor_identifier : Bool = false
  final var mItalicFor_identifier : Bool = false
  final var mColorFor_keyWords : Color = .black
  final var mBoldFor_keyWords : Bool = false
  final var mItalicFor_keyWords : Bool = false
  final var mColorFor_delimitors : Color = .black
  final var mBoldFor_delimitors : Bool = false
  final var mItalicFor_delimitors : Bool = false
  final var mColorFor_integerStyle : Color = .black
  final var mBoldFor_integerStyle : Bool = false
  final var mItalicFor_integerStyle : Bool = false
  final var mColorFor_lexical_error : Color = .red
  final var mBoldFor_lexical_error : Bool = false
  final var mItalicFor_lexical_error : Bool = false
  final var mColorFor_template : Color = .gray
  final var mBoldFor_template : Bool = false
  final var mItalicFor_template : Bool = false
  final var mTokenAttributeArray = [[NSAttributedString.Key : Any]?] ()

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func updateTokenStyleArrays (_ ioStyleDidChange : inout Bool) {
    ioStyleDidChange = false
    let ud = UserDefaults.standard
    if let s = ud.string (forKey: "FontFor_oa_scanner"), let v = CustomFont (rawValue: s) {
      if self.mFont != v {
        self.mFont = v
        ioStyleDidChange = true
      }
    }
    if let s = ud.string (forKey: "LineHeightFor_oa_scanner"), let v = Int (s) {
      if self.mLineHeight != v {
        self.mLineHeight = v
        ioStyleDidChange = true
      }
    }
    if let s = ud.string (forKey: "ColorFor_oa_scanner"), let v = Color (rawValue: s) {
      if self.mDefaultColor != v {
        self.mDefaultColor = v
        ioStyleDidChange = true
      }
    }
    if let s = ud.string (forKey: "ColorFor_oa_scanner-identifier"), let v = Color (rawValue: s) {
      if self.mColorFor_identifier != v {
        self.mColorFor_identifier = v
        ioStyleDidChange = true
      }
    }
    if ud.string (forKey: "BoldFor_oa_scanner-identifier") != nil {
      let v = ud.bool (forKey: "BoldFor_oa_scanner-identifier")
      if self.mBoldFor_identifier != v {
        self.mBoldFor_identifier = v
        ioStyleDidChange = true
      }
    }
    if ud.string (forKey: "ItalicFor_oa_scanner-identifier") != nil {
      let v = ud.bool (forKey: "ItalicFor_oa_scanner-identifier")
      if self.mItalicFor_identifier != v {
        self.mItalicFor_identifier = v
        ioStyleDidChange = true
      }
    }
    if let s = ud.string (forKey: "ColorFor_oa_scanner-keyWords"), let v = Color (rawValue: s) {
      if self.mColorFor_keyWords != v {
        self.mColorFor_keyWords = v
        ioStyleDidChange = true
      }
    }
    if ud.string (forKey: "BoldFor_oa_scanner-keyWords") != nil {
      let v = ud.bool (forKey: "BoldFor_oa_scanner-keyWords")
      if self.mBoldFor_keyWords != v {
        self.mBoldFor_keyWords = v
        ioStyleDidChange = true
      }
    }
    if ud.string (forKey: "ItalicFor_oa_scanner-keyWords") != nil {
      let v = ud.bool (forKey: "ItalicFor_oa_scanner-keyWords")
      if self.mItalicFor_keyWords != v {
        self.mItalicFor_keyWords = v
        ioStyleDidChange = true
      }
    }
    if let s = ud.string (forKey: "ColorFor_oa_scanner-delimitors"), let v = Color (rawValue: s) {
      if self.mColorFor_delimitors != v {
        self.mColorFor_delimitors = v
        ioStyleDidChange = true
      }
    }
    if ud.string (forKey: "BoldFor_oa_scanner-delimitors") != nil {
      let v = ud.bool (forKey: "BoldFor_oa_scanner-delimitors")
      if self.mBoldFor_delimitors != v {
        self.mBoldFor_delimitors = v
        ioStyleDidChange = true
      }
    }
    if ud.string (forKey: "ItalicFor_oa_scanner-delimitors") != nil {
      let v = ud.bool (forKey: "ItalicFor_oa_scanner-delimitors")
      if self.mItalicFor_delimitors != v {
        self.mItalicFor_delimitors = v
        ioStyleDidChange = true
      }
    }
    if let s = ud.string (forKey: "ColorFor_oa_scanner-integerStyle"), let v = Color (rawValue: s) {
      if self.mColorFor_integerStyle != v {
        self.mColorFor_integerStyle = v
        ioStyleDidChange = true
      }
    }
    if ud.string (forKey: "BoldFor_oa_scanner-integerStyle") != nil {
      let v = ud.bool (forKey: "BoldFor_oa_scanner-integerStyle")
      if self.mBoldFor_integerStyle != v {
        self.mBoldFor_integerStyle = v
        ioStyleDidChange = true
      }
    }
    if ud.string (forKey: "ItalicFor_oa_scanner-integerStyle") != nil {
      let v = ud.bool (forKey: "ItalicFor_oa_scanner-integerStyle")
      if self.mItalicFor_integerStyle != v {
        self.mItalicFor_integerStyle = v
        ioStyleDidChange = true
      }
    }
    if let s = ud.string (forKey: "ColorFor_oa_scanner_lexical_error"), let v = Color (rawValue: s) {
      if self.mColorFor_lexical_error != v {
        self.mColorFor_lexical_error = v
        ioStyleDidChange = true
      }
    }
    if ud.string (forKey: "BoldFor_oa_scanner_lexical_error") != nil {
      let v = ud.bool (forKey: "BoldFor_oa_scanner_lexical_error")
      if self.mBoldFor_lexical_error != v {
        self.mBoldFor_lexical_error = v
        ioStyleDidChange = true
      }
    }
    if ud.string (forKey: "ItalicFor_oa_scanner_lexical_error") != nil {
      let v = ud.bool (forKey: "ItalicFor_oa_scanner_lexical_error")
      if self.mItalicFor_lexical_error != v {
        self.mItalicFor_lexical_error = v
        ioStyleDidChange = true
      }
    }
    if let s = ud.string (forKey: "ColorFor_oa_scanner_template"), let v = Color (rawValue: s) {
      if self.mColorFor_template != v {
        self.mColorFor_template = v
        ioStyleDidChange = true
      }
    }
    if ud.string (forKey: "BoldFor_oa_scanner_template") != nil {
      let v = ud.bool (forKey: "BoldFor_oa_scanner_template")
      if self.mBoldFor_template != v {
        self.mBoldFor_template = v
        ioStyleDidChange = true
      }
    }
    if ud.string (forKey: "ItalicFor_oa_scanner_template") != nil {
      let v = ud.bool (forKey: "ItalicFor_oa_scanner_template")
      if self.mItalicFor_template != v {
        self.mItalicFor_template = v
        ioStyleDidChange = true
      }
    }
  //--- Build token attribute array
    if ioStyleDidChange {
      let fontManager = NSFontManager.shared
      let boldFont = fontManager.convert (self.mFont.nsFont, toHaveTrait: .boldFontMask)
      let italicFont = fontManager.convert (self.mFont.nsFont, toHaveTrait: .italicFontMask)
      let boldItalicFont = fontManager.convert (boldFont, toHaveTrait: .italicFontMask)
      self.mTokenAttributeArray.removeAll (keepingCapacity: true)
      var attributes = [NSAttributedString.Key : Any] ()
    //--- Attributes for identifier
      if self.mColorFor_identifier != self.mDefaultColor {
        attributes [.foregroundColor] = NSColor (self.mColorFor_identifier)
      }
      if self.mBoldFor_identifier && self.mItalicFor_identifier {
        attributes [.font] = boldItalicFont
      }else if self.mBoldFor_identifier {
        attributes [.font] = boldFont
      }else if self.mItalicFor_identifier {
        attributes [.font] = italicFont
      }
      self.mTokenAttributeArray.append (attributes.isEmpty ? nil : attributes)
      attributes.removeAll (keepingCapacity: true)
    //--- Attributes for keyWords
      if self.mColorFor_keyWords != self.mDefaultColor {
        attributes [.foregroundColor] = NSColor (self.mColorFor_keyWords)
      }
      if self.mBoldFor_keyWords && self.mItalicFor_keyWords {
        attributes [.font] = boldItalicFont
      }else if self.mBoldFor_keyWords {
        attributes [.font] = boldFont
      }else if self.mItalicFor_keyWords {
        attributes [.font] = italicFont
      }
      self.mTokenAttributeArray.append (attributes.isEmpty ? nil : attributes)
      attributes.removeAll (keepingCapacity: true)
    //--- Attributes for delimitors
      if self.mColorFor_delimitors != self.mDefaultColor {
        attributes [.foregroundColor] = NSColor (self.mColorFor_delimitors)
      }
      if self.mBoldFor_delimitors && self.mItalicFor_delimitors {
        attributes [.font] = boldItalicFont
      }else if self.mBoldFor_delimitors {
        attributes [.font] = boldFont
      }else if self.mItalicFor_delimitors {
        attributes [.font] = italicFont
      }
      self.mTokenAttributeArray.append (attributes.isEmpty ? nil : attributes)
      attributes.removeAll (keepingCapacity: true)
    //--- Attributes for integerStyle
      if self.mColorFor_integerStyle != self.mDefaultColor {
        attributes [.foregroundColor] = NSColor (self.mColorFor_integerStyle)
      }
      if self.mBoldFor_integerStyle && self.mItalicFor_integerStyle {
        attributes [.font] = boldItalicFont
      }else if self.mBoldFor_integerStyle {
        attributes [.font] = boldFont
      }else if self.mItalicFor_integerStyle {
        attributes [.font] = italicFont
      }
      self.mTokenAttributeArray.append (attributes.isEmpty ? nil : attributes)
      attributes.removeAll (keepingCapacity: true)
    //--- Lexical error
      if self.mColorFor_lexical_error != self.mDefaultColor {
        attributes [.foregroundColor] = NSColor (self.mColorFor_lexical_error)
      }
      if self.mBoldFor_lexical_error && self.mItalicFor_lexical_error {
        attributes [.font] = boldItalicFont
      }else if self.mBoldFor_lexical_error {
        attributes [.font] = boldFont
      }else if self.mItalicFor_lexical_error {
        attributes [.font] = italicFont
      }
      self.mTokenAttributeArray.append (attributes.isEmpty ? nil : attributes)
      attributes.removeAll (keepingCapacity: true)
    //--- Template
      if self.mColorFor_template != self.mDefaultColor {
        attributes [.foregroundColor] = NSColor (self.mColorFor_template)
      }
      if self.mBoldFor_template && self.mItalicFor_template {
        attributes [.font] = boldItalicFont
      }else if self.mBoldFor_template {
        attributes [.font] = boldFont
      }else if self.mItalicFor_template {
        attributes [.font] = italicFont
      }
      self.mTokenAttributeArray.append (attributes.isEmpty ? nil : attributes)
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  override func performLexicalColoringAfterUserDefaultChange (textStorage inTextStorage : NSTextStorage) {
    if self.mDebug { Swift.print ("performLexicalColoringAfterUserDefaultChange") }
    let start = Date ()
    var styleDidChange = false
    self.updateTokenStyleArrays (&styleDidChange)
    if styleDidChange {
      let nsString = inTextStorage.string as NSString
      let fullRange = NSRange (location: 0, length: nsString.length)
    //---- Apply default attributes
      let tsDelegate : (any NSTextStorageDelegate)? = inTextStorage.delegate
      inTextStorage.delegate = nil // NSTextStorageDelegate
      inTextStorage.beginEditing ()
      let defaultFont = self.mFont.nsFont
      inTextStorage.font = defaultFont
      let ps = NSMutableParagraphStyle ()
      ps.lineHeightMultiple = CGFloat (self.mLineHeight) / 10.0
      let defaultAttributes : [NSAttributedString.Key : Any] = [
        .font: defaultFont,
        .foregroundColor: NSColor (self.mDefaultColor),
        .paragraphStyle : ps
      ]
      inTextStorage.setAttributes (defaultAttributes, range: fullRange)
    //--- Apply styles
      for token in self.mTokenArray {
        let idx = Int (self.styleIndexFor (token: token.tokenCode))
        if idx > 0, let attributes = self.mTokenAttributeArray [idx - 1] {
          inTextStorage.addAttributes (attributes, range: token.range)
        }
      }
      inTextStorage.endEditing ()
      inTextStorage.delegate = tsDelegate // NSTextStorageDelegate
    }
    if self.mDebug { Swift.print ("  done: \(Int (Date ().timeIntervalSince (start) * 1000.0)) ms") }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  override func performLexicalAnalysisAndColoring (textStorage inTextStorage : NSTextStorage,
                                                   editedRange inEditedRange : NSRange,
                                                   changeInLength inDelta : Int) {
    if self.mDebug { Swift.print ("performLexicalAnalysisAndColoring \(inEditedRange), delta \(inDelta)") }
    let nsString = inTextStorage.string as NSString
  //---
    var savedTokenCount = 0
    var found = false
    while savedTokenCount < self.mTokenArray.count, !found {
      if self.mTokenArray [savedTokenCount].range.upperBound < inEditedRange.location {
        savedTokenCount += 1
      }else{
        found = true
      }
    }
    if self.mDebug { Swift.print ("  savedTokenCount \(savedTokenCount), currently \(self.mTokenArray.count) tokens") }
  //--- Eliminate tokens beyond end of source string
    while let lastToken = self.mTokenArray.last, lastToken.range.upperBound > nsString.length {
      if self.mVerboseDebug { Swift.print ("Remove last token \(lastToken.range), beyond end") }
      _ = self.mTokenArray.removeLast ()
    }
    if self.mDebug { Swift.print ("  Eliminate token beyond end: \(self.mTokenArray.count) tokens") }
  //--- Translater les tokens suivants
    var i = savedTokenCount + 1
    while i < self.mTokenArray.count {
      let token = self.mTokenArray [i]
      let newToken = SWIFT_Token (
        range: NSRange (location: token.range.location + inDelta, length: token.range.length),
        tokenCode: token.tokenCode,
        templateDelimiterIndex: token.templateDelimiterIndex
      )
      self.mTokenArray [i] = newToken
      i += 1
    }
  //--- Eliminate tokens beyond end of source string
    while let lastToken = self.mTokenArray.last, lastToken.range.upperBound > nsString.length {
      if self.mVerboseDebug { Swift.print ("Remove last token \(lastToken.range), beyond end") }
      _ = self.mTokenArray.removeLast ()
    }
    if self.mDebug { Swift.print ("  Eliminate token beyond end, after delta correction: \(self.mTokenArray.count) tokens") }
  //--- Perform lexical analysis
    let start = Date ()
    if savedTokenCount == 0 {
      self.resetScannerLocation (withString: nsString)
    }else{
      self.resetScanner (
        withString: nsString,
        location: self.mTokenArray [savedTokenCount-1].range.upperBound,
        templateDelimiterIndex : self.mTokenArray [savedTokenCount-1].templateDelimiterIndex
      )
    }
    if self.mDebug { Swift.print ("  Scanning start location: \(self.currentLocation)") }
    var stop = false
    var insertionIndex = savedTokenCount
    while self.currentLocation < nsString.length, !stop {
      let token : SWIFT_Token = self.parseLexicalTokenForLexicalColoring ()
      if token.tokenCode > 0 { // For eliminating separators
        if self.mVerboseDebug { Swift.print ("  -> new token \(token.range) '\(nsString.substring (with: token.range))'") }
      //--- Eliminate previous tokens before new token location
        if insertionIndex < self.mTokenArray.count,
              self.mTokenArray [insertionIndex] == token,
              token.range.location > inEditedRange.upperBound {
          if self.mVerboseDebug { Swift.print ("    stop at \(insertionIndex)") }
          stop = true
        }else{
          while insertionIndex < self.mTokenArray.count,
                self.mTokenArray [insertionIndex].range.lowerBound <= token.range.location {
            if self.mVerboseDebug { Swift.print ("    remove token \(self.mTokenArray [insertionIndex].range) at \(insertionIndex)") }
            self.mTokenArray.remove (at: insertionIndex)
          }
          if insertionIndex == self.mTokenArray.count {
            if self.mVerboseDebug { Swift.print ("    append token \(token.range) at \(insertionIndex)") }
            self.mTokenArray.append (token)
            insertionIndex += 1
          }else{
            if self.mVerboseDebug {  Swift.print ("    insert token \(token.range) at \(insertionIndex)") }
            self.mTokenArray.insert (token, at: insertionIndex)
            insertionIndex += 1
          }
        }
      }
    }
    if self.mDebug { Swift.print ("  Lexical analysis time: \(Int (Date ().timeIntervalSince (start) * 1000.0)) ms") }
  //---- Apply default attributes
    let modificationStart = min (inEditedRange.location, (savedTokenCount == 0) ? 0 : self.mTokenArray [savedTokenCount - 1].range.upperBound)
    let modificationEnd = max (inEditedRange.upperBound, (insertionIndex == self.mTokenArray.count)
       ? nsString.length
       : self.mTokenArray [insertionIndex].range.upperBound
    )
    if self.mDebug { Swift.print ("  Attributes will change from char index \(modificationStart) to \(modificationEnd)") }
    let start2 = Date ()
    if modificationStart < modificationEnd {
      let modifiedRange = NSRange (location: modificationStart, length: modificationEnd - modificationStart)
      let tsDelegate : (any NSTextStorageDelegate)? = inTextStorage.delegate
      inTextStorage.delegate = nil // NSTextStorageDelegate
      inTextStorage.beginEditing ()
      let defaultFont = self.mFont.nsFont
      let ps = NSMutableParagraphStyle ()
      ps.lineHeightMultiple = CGFloat (self.mLineHeight) / 10.0
      let defaultAttributes : [NSAttributedString.Key : Any] = [
        .font: defaultFont,
        .foregroundColor: NSColor (self.mDefaultColor),
        .paragraphStyle : ps
      ]
      if self.mVerboseDebug { Swift.print ("Apply default attributes \(modifiedRange)") }
      inTextStorage.setAttributes (defaultAttributes, range: modifiedRange)
    //--- Apply styles
      var idx = 0
      stop = false
      while idx < self.mTokenArray.count, !stop { // Apply token styles
        let token = self.mTokenArray [idx]
        idx += 1
        if token.range.lowerBound >= modifiedRange.upperBound {
          stop = true
        }else if token.range.upperBound > modifiedRange.lowerBound {
          let styleIndex = Int (self.styleIndexFor (token: token.tokenCode))
          if styleIndex > 0, let attributes = self.mTokenAttributeArray [styleIndex - 1] {
            inTextStorage.addAttributes (attributes, range: token.range)
          }
        }
      }
      inTextStorage.endEditing ()
      inTextStorage.delegate = tsDelegate // NSTextStorageDelegate
    }
    if self.mDebug { Swift.print ("  Adding attributes: \(Int (Date ().timeIntervalSince (start2) * 1000.0)) ms") }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  //   Lexical analysis
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func parseLexicalTokenForLexicalColoring () -> SWIFT_Token {
    var loop = true
    var scanningOk = true
    self.mLexicalAttribute_identifierString = ""
    self.mLexicalAttribute_ulongValue = 0
    var tokenCode : UInt16 = 0
    let startLocation = self.currentLocation
    if scanningOk && (self.testForInputFromChar (97, toChar:122) || self.testForInputFromChar (65, toChar:90)) {
      while (loop && scanningOk) {
        scanner_cocoa_routine_enterCharacterIntoString (&scanningOk, &self.mLexicalAttribute_identifierString, self.previousChar)
        if scanningOk && (self.testForInputFromChar (97, toChar:122) || self.testForInputFromChar (65, toChar:90) || self.testForInputChar (95) || self.testForInputFromChar (48, toChar:57)) {
        }else{
          loop = false
        }
      }
      loop = true
      if (tokenCode == 0) {
        tokenCode = search_into_oa_5F_scanner_keyWordList (mLexicalAttribute_identifierString) ;
      }
      if tokenCode == 0 {
        tokenCode = oa_scanner_1_identifier ;
      }
    }else if scanningOk && self.testForInputString ("..", advance: true) {
      tokenCode = oa_scanner_1__2E__2E_
    }else if scanningOk && self.testForInputString (";", advance: true) {
      tokenCode = oa_scanner_1__3B_
    }else if scanningOk && self.testForInputString (",", advance: true) {
      tokenCode = oa_scanner_1__2C_
    }else if scanningOk && (self.testForInputFromChar (48, toChar:57)) {
      scanner_cocoa_routine_enterDigitIntoUInt (&scanningOk, self.previousChar, &self.mLexicalAttribute_ulongValue)
      while (loop && scanningOk) {
        if scanningOk && (self.testForInputFromChar (48, toChar:57)) {
          scanner_cocoa_routine_enterDigitIntoUInt (&scanningOk, self.previousChar, &self.mLexicalAttribute_ulongValue)
        }else if scanningOk && (self.testForInputChar (95)) {
        }else{
          loop = false
        }
      }
      loop = true
      tokenCode = oa_scanner_1_literal_5F_integer
    }else if scanningOk && (self.testForInputFromChar (1, toChar:32)) {
    }else if scanningOk && (self.testForInputChar (35)) {
      while (loop && scanningOk) {
        if scanningOk && (self.testForInputFromChar (1, toChar:9) || self.testForInputFromChar (11, toChar:126)) {
        }else{
          loop = false
        }
      }
      loop = true
      if scanningOk && (self.testForInputChar (10)) {
      }else{
        scanningOk = false
      }
    }else if self.testForInputChar (0) { // End of source text ?
      tokenCode = oa_scanner_1_ ; // Empty string code
    }else{ // Unknown input character
      tokenCode = oa_scanner_2_TEMPLATE
      self.advance ()
    }
    return SWIFT_Token (
      range: NSRange (location: startLocation, length: self.currentLocation - startLocation),
      tokenCode: tokenCode,
      templateDelimiterIndex: self.mEndTemplateDelimiterIndex
    )
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

}

//--------------------------------------------------------------------------------------------------
//             Key words table 'keyWordList'      
//--------------------------------------------------------------------------------------------------

fileprivate let kDictionary_oa_5F_scanner_keyWordList : [String : UInt16] = [
  "on" : oa_scanner_1_on,
  "can" : oa_scanner_1_can,
  "end" : oa_scanner_1_end,
  "van" : oa_scanner_1_van,
  "task" : oa_scanner_1_task,
  "every" : oa_scanner_1_every,
  "length" : oa_scanner_1_length,
  "offset" : oa_scanner_1_offset,
  "period" : oa_scanner_1_period,
  "system" : oa_scanner_1_system,
  "message" : oa_scanner_1_message,
  "network" : oa_scanner_1_network,
  "deadline" : oa_scanner_1_deadline,
  "duration" : oa_scanner_1_duration,
  "extended" : oa_scanner_1_extended,
  "priority" : oa_scanner_1_priority,
  "standard" : oa_scanner_1_standard,
  "processor" : oa_scanner_1_processor,
  "scalingfactor" : oa_scanner_1_scalingfactor
]

fileprivate func search_into_oa_5F_scanner_keyWordList (_ inSearchedString : String) -> UInt16 {
  return kDictionary_oa_5F_scanner_keyWordList [inSearchedString, default: oa_scanner_1_]
}



//--------------------------------------------------------------------------------------------------

func oa_scanner_lexiqueIdentifier () -> String {
  return "oa_scanner"
}

//--------------------------------------------------------------------------------------------------

func oa_scanner_styleNameFor (styleIndex inIndex : UInt8) -> String {
  let kStyleArray : [String] = [
    "Default Style", // 0
    "Identifiers", // 1
    "Key words", // 2
    "Delimitors", // 3
    "Integer constants", // 4
    "Lexical error", // 5
    "Template" // 6
  ]
  return kStyleArray [Int (inIndex)]
}

//--------------------------------------------------------------------------------------------------

func oa_scanner_styleIdentifierFor (styleIndex inIndex : UInt8) -> String {
  let kStyleArray : [String] = [
    "oa_scanner", // 0
    "oa_scanner-identifier", // 1
    "oa_scanner-keyWords", // 2
    "oa_scanner-delimitors", // 3
    "oa_scanner-integerStyle", // 4
    "oa_scanner.ERROR", // 5
    "oa_scanner.TEMPLATE" // 6
  ]
  return kStyleArray [Int (inIndex)]
}

//--------------------------------------------------------------------------------------------------
//                           Template Replacements
//--------------------------------------------------------------------------------------------------



//--------------------------------------------------------------------------------------------------
//                           Template Delimiters
//--------------------------------------------------------------------------------------------------



//--------------------------------------------------------------------------------------------------
//         T E R M I N A L    S Y M B O L    E N U M E R A T I O N
//--------------------------------------------------------------------------------------------------

let oa_scanner_1_ : UInt16 = 0
let oa_scanner_1_identifier : UInt16 = 1
let oa_scanner_1_literal_5F_integer : UInt16 = 2
let oa_scanner_1_system : UInt16 = 3
let oa_scanner_1_end : UInt16 = 4
let oa_scanner_1_task : UInt16 = 5
let oa_scanner_1_standard : UInt16 = 6
let oa_scanner_1_extended : UInt16 = 7
let oa_scanner_1_message : UInt16 = 8
let oa_scanner_1_length : UInt16 = 9
let oa_scanner_1_priority : UInt16 = 10
let oa_scanner_1_period : UInt16 = 11
let oa_scanner_1_offset : UInt16 = 12
let oa_scanner_1_on : UInt16 = 13
let oa_scanner_1_deadline : UInt16 = 14
let oa_scanner_1_duration : UInt16 = 15
let oa_scanner_1_processor : UInt16 = 16
let oa_scanner_1_can : UInt16 = 17
let oa_scanner_1_van : UInt16 = 18
let oa_scanner_1_network : UInt16 = 19
let oa_scanner_1_scalingfactor : UInt16 = 20
let oa_scanner_1_every : UInt16 = 21
let oa_scanner_1__2C_ : UInt16 = 22
let oa_scanner_1__3B_ : UInt16 = 23
let oa_scanner_1__2E__2E_ : UInt16 = 24
let oa_scanner_2_ERROR : UInt16 = 25
let oa_scanner_2_TEMPLATE : UInt16 = 26

//--------------------------------------------------------------------------------------------------

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2


