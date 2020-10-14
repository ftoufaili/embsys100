An example of embedded system is the Electro Cardiogram (ECG) device. As shown in the Figure below:

![Figure- ECG system diagram](https://github.com/ftoufaili/embsys310/blob/main/assignment01/ECGBlockDiagram.jpg?)


<br/>Low impedance electrodes transmit the heart electrical signals to the device where it get processed and filtered out. The analog signal is then digitized and transferred over to the computer for display and analysis. The main ECG subsystems are as follows:
* FE Data Acquisition
* ECG Signal Processing 
* A/D conversion
* Transmit ECG out for display 
  
  
<br/>Some of the design challenges involve:

**1- Throughput Handling**: the system should acquire and process real-time ECG data at 5000 Hz frequency.

**2- Response**: The system should be able to respond quickly when it detects 1) a loss in the input ECG signal(s) or 2) data/signal corruption or 3) if the user tries to interact with the device. 

**3- Testability Difficulties**: this system requires special ECG simulators to verify it performance and accuracy

**4- Debugability**: It is preferred to have a probe available for debugging the embedded software. 

**5- Reliability**: The system has a low Annual Failure Rate (AFR) < 0.01%. Therefore, the **combination** of software and hardware failures can’t exceed that number. 

**6- Memory Space**: The small stack memory on the system restricts how the input ECG data is streamed and processed in small chunks. This results in additional processing cycles and power consumption but is a necessary trade off to accommodate for the limited stack memory  being able to have big memory buffers to process the ECG signal. s saving too many ECG studies into the system. To 

**7- Program Installation and Field Upgrade**: The device should be upgradable in the field via a USB thumb drive **only after authenticating and verifying the binary image on the thumb drive**

**8- Power consumption**: To conserve battery power, the software and hardware should support low-power or “sleep” mode. This low power mode should be automatically activated by the system any time the it is not in use or is not performing any internal operations. 

**9- Security**: All system ports (USB, Ethernet, etc.) accessible to the user should be secured to stop any potential hacking or cyberattack. In addition, all sensitive data on the device should be encrypted at rest as well. System communication with external devices via Ethernet port can only be initiated by the ECG device and should only establish a connection after authenticating the destination. Lastly, network communication is encrypted. 

**10- Cost Reducing**: The system BOM cost is determined by the Sales and Marketing department with input from R&D. The total system cost should be at or below target BOM as much as possible.

**11- Hardware availability**: The system design should take into account the anticipated product availability and support in the market. For example, if the product is to be sold and serviced for the next 20 years, the choice of hardware parts used in the system should take this into account to make sure the selected hardware will be available for the next 20 years and even beyond (for extended serviceability if needed). 

**12- Software technology**: Software evolves very rapidly so the choice of toolchain used for product development and software used in the device should take this into account and make sure a mature development toolchain and the particular software (e.g. RTOS, USB stack, network stack, etc.) that are well established and have higher probability of continuous support in the future.
