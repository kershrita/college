
(Polyline consisting of 2 segments.)

M300 S30.00 (pen down)
G4 P150 (wait 150ms)
G1 X0 Y0 F3500.00
G1 X20 Y0 F3500.00
G1 X20 Y20 F3500.00
G1 X0 Y20 F3500.00
G1 X0 Y0 F3500.00

G1 X10 Y0 F3500.00
G1 X20 Y10 F3500.00
G1 X10 Y20 F3500.00
G1 X0 Y10 F3500.00
G1 X10 Y0 F3500.00

G1 X10 Y20 F3500.00
M300 S50.00 (pen up)
G1 X20 Y10 F3500.00
G4 P150 (wait 150ms)

M300 S30.00 (pen down)
G4 P150 (wait 150ms)
G1 X0 Y10 F3500.00

M300 S50.00 (pen up)
G4 P150 (wait 150ms)


(end of print job)
M300 S50.00 (pen up)
G4 P150 (wait 150ms)
M300 S255 (turn off servo)
G1 X0 Y0 F3500.00
G1 Z0.00 F150.00 (go up to finished level)
G1 X0.00 Y0.00 F3500.00 (go home)
M18 (drives off)
