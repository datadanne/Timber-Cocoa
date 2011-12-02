test:
	timberc --make TestButton
	timberc --make TestDropDown
	timberc --make TestFocusHierarchy
	timberc --make TestScrolling
	timberc --make TestKeyboardLayout
	timberc --make Tutorial0App
	timberc --make Tutorial1CompHierarchy
	timberc --make Tutorial2Resizing
	timberc --make Tutorial3TabResponder
	timberc --make Tutorial4MultipleWindows
	timberc --make Tutorial5CompCreation

test-s:
	timberc -s --make TestButton
	timberc -s --make TestDropDown
	timberc -s --make TestFocusHierarchy
	timberc -s --make TestScrolling
	timberc -s --make TestKeyboardLayout
	timberc -s --make Tutorial0App
	timberc -s --make Tutorial1CompHierarchy
	timberc -s --make Tutorial2Resizing
	timberc -s --make Tutorial3TabResponder
	timberc -s --make Tutorial4MultipleWindows
	timberc -s --make Tutorial5CompCreation

demo:
	timberc --make Tetris
	timberc --make Paint

demo-s:
	timberc -s --make Tetris
	timberc -s --make Paint

clean:
	./cleanFolder
