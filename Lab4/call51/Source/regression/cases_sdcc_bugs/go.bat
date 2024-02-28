@echo off
del reg.txt
for %%i in (*.c) do call sim %%i
find "Assertion" reg.txt > ass.txt
find "error" reg.txt > err.txt
find "LINK ERROR" reg.txt > lnk.txt

del reg_m.txt
for %%i in (*.c) do call sim_m %%i
find "Assertion" reg_m.txt > ass_m.txt
find "error" reg_m.txt > err_m.txt
find "LINK ERROR" reg_m.txt > lkr_m.txt

del reg_l.txt
for %%i in (*.c) do call sim_l %%i
find "Assertion" reg_l.txt > ass_l.txt
find "error" reg_l.txt > err_l.txt
find "LINK ERROR" reg_l.txt > lkr_l.txt
