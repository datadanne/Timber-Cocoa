test:
	timberc --make TestButton
	timberc --make TestDropDown
	timberc --make TestFocusHierarchy
	timberc --make TestScrolling
	timberc --make Tutorial0App
	timberc --make Tutorial1ComponentsAndHierarchies
	timberc --make Tutorial2Resizing
	timberc --make Tutorial3TabResponder
	timberc --make Tutorial4MultipleWindows
	timberc --make Tutorial5ComponentCreation

demo:
	timberc --make Tetris
	timberc --make Paint

clean:
	./cleanFolder
