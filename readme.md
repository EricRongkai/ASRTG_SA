## ASRTG_SA Source Code
### Title:
**Adaptive Symmetry Reference Trajectory Generation in Shared Autonomy for Active Knee Orthosis**<br>
### Author:
**Rongkai Liu, Tingting Ma, Ningguang Yao, Hao Li, Xinyan Zhao, Yu Wang,  Hongqing Pan, Quanjjun Song**<br>
![Image text](https://github.com/EricRongkai/ASRTG_SA/blob/master/Figure1.jpg)
***
Version：V2.1<br>
Update time：1/15/2023<br>
Operating environment：Ubuntu 20.04 LTS<br>
Language：python 3.8<br>
***
### Install dependency packages
`pip install -r requirements.txt`<br>
###  File description
* **Folder: DSP**<br>
C++ code for digital signal processing. Designed by simulink and packaged with pybind11. <br>
* **Folder: temp**<br>
The GKL data that was built by the offline demonstration
* **Folder: TestData**<br>
Offline test data for proposed framework.
* **ASRTG_SA.ipynb**<br>
An offline example of the proposed framework, running with jupyter notebook.
* **DataLoader.py**<br>
Offline data loading module.
* **Hopf_Oscillator.py**<br>
Dynamic model of Hopf coupled oscillator
* **ODEs.py**<br>
Numerical calculation of ordinary differential equations.
* **Output_Dynamic_System.py**<br>
pDMP model implementation.
* **pyDSP.py**<br>
Used for the DSP module initialization.