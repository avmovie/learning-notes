# The analyse of GraphicEditor
## 1. how to organize all functions in one application
1. QAction 
* newAction 
* openAction
* saveAction
* saveAsAction
* closeAction
* printAction
* exitAction
* ExportAction

2. QMenu
* fileMenu
* insertMenu
* editMenu
* formatMenu
* toolsMenu
* aboutMenu

3. layout of application
* QmenuBar 
  * fileMenu
    * newAction
    * openAction
    * saveAction
    * saveAsAction
    * exportAction
    * closeAction
    * exitAction
  * editMenu
    * undoAction
    * redoAction
    * cutAction
    * copyAction
    * pasteAction
    * selectAllAction
  * insertMenu
    * insertImageAction
    * insetTableAction
    * insertCurTimeAction
  * formatMenu
    * fontAction
    * paragraphAction
    * colorAction
  *  styleMenu(radiobox)
    * titleAction
    * subtitleAction
    * heading1Action
    * heading2Action
    * heading3Action
    * codeStyleAction
  * toolsMenu
    * showLineNumberAction
    * findAction
    * replaceAction
    * newFormatAction
  * helpMenu
    * userguide
    * about
    * about Qt
1. dialogue setting 
* exitDialog 
* find&replace dialog 
* insertDialog 
* insetImageDialog 

5. some common function
  
  setFont();

6. statusBar setting
  * modified 
  * position
    * row number & columu number 
  * format prompt
    * text format(font-family,font-style,font-size,font-color) 
  * current document title
    * show current filename 
  *  