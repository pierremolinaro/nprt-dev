//
//  AutoLayoutTableView-column-NSImage.swift
//  ElCanari
//
//  Created by Pierre Molinaro on 16/12/2021.
//
//--------------------------------------------------------------------------------------------------

import AppKit

//--------------------------------------------------------------------------------------------------

extension AutoLayoutTableView {

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func addColumn_NSImage (valueGetterDelegate inGetterDelegate : @escaping (_ inRow : Int) -> NSImage?,
                          valueSetterDelegate _ : Optional < (_ inRow : Int, _ inNewValue : NSImage) -> Void >,
                          sortDelegate inSortDelegate : Optional < (_ inAscending : Bool) -> Void>,
                          title inTitle : String,
                          minWidth inMinWidth : Int,
                          maxWidth inMaxWidth : Int,
                          headerAlignment inHeaderAlignment : NSTextAlignment,
                          contentAlignment inContentAlignment : NSTextAlignment) {
    let column = InternalImageValueTableColumn (
      sortDelegate: inSortDelegate,
      title: inTitle,
      minWidth: inMinWidth,
      maxWidth: inMaxWidth,
      headerAlignment: inHeaderAlignment,
      contentAlignment: inContentAlignment,
      valueGetterDelegate: inGetterDelegate
    )
  //--- Add Column
    self.appendTableColumn (column)
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

}

//--------------------------------------------------------------------------------------------------
// InternalImageValueTableColumn
//--------------------------------------------------------------------------------------------------

fileprivate final class InternalImageValueTableColumn : AutoLayoutTableColumn {

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  private let mValueGetterDelegate : (_ inRow : Int) -> NSImage?

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // INIT
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  init (sortDelegate inSortDelegate : Optional < (_ inAscending : Bool) -> Void>,
        title inTitle : String,
        minWidth inMinWidth : Int,
        maxWidth inMaxWidth : Int,
        headerAlignment inHeaderAlignment : NSTextAlignment,
        contentAlignment inContentAlignment : NSTextAlignment,
        valueGetterDelegate inGetterDelegate : @escaping (_ inRow : Int) -> NSImage?) {
    self.mValueGetterDelegate = inGetterDelegate
    super.init (
      sortDelegate: inSortDelegate,
      title: inTitle,
      minWidth: inMinWidth,
      maxWidth: inMaxWidth,
      headerAlignment: inHeaderAlignment,
      contentAlignment: inContentAlignment
    )
    self.isEditable = false
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  required init (coder inCoder : NSCoder) {
    fatalError ("init(coder:) has not been implemented")
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  override func configureTableCellView (forRowIndex inRowIndex : Int) -> NSView? {
    let imageView = NSImageView ()
    imageView.translatesAutoresizingMaskIntoConstraints = false

    imageView.tag = inRowIndex
    imageView.isEditable = false
    imageView.image = self.mValueGetterDelegate (inRowIndex)
    return imageView
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

}

