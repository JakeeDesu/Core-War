.name "supernova"
.comment "smta k7la fla voiture"

		sti		r1, %:xlive, %1
xlive:	live	%1
		ld		%0, r16
		fork	%:last
		zjmp	%:xlive
last:	zjmp	%511
