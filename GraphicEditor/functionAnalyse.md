# The analyse of GraphicEditor
## 1. how to organize all functions in one application
1. QAction 
* newAction 
* openAction
* saveAction
* saveAsAction
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
    * insert
  * formatMenu
    * textAction
    * alignAction
    * imageAction
    * codeAction
  *  styleMenu(radiobox)
    * titleAction"
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
* statusBar
  * isModified

4. dialogue setting 
* exitDialog 
* find&replace dialog 
* insertDialog 
* insetImageDialog 

5. some common function
    setFont();
    
* 