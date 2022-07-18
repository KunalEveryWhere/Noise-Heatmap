# Noise-Heatmap
This project utilises IoT KY-038 (D-010) MIC paired to ESP-32S Dual-Core mC, to collect noise dB data in urban environments, and map the data into a geographic 2D HeatMap

This is a pilot study and has some limitations which we aim to mitigate in near future iterative versions. The data was collected in 2 sessions on 18-July 2022. Metadata about this can be found in the '/Data Collected' folder.

The data was collcted at 115200 buad-rate, for a total of 10+12 location cordinates for this pilot study. The scope will be extended moving forward. Then, for each location, the average of dB value was taken in for the heatmap-plotting. The sound sensor generally, reads the analog value of sound which is then converted into the decibel using some mathematical formula.

![image][[https://user-images.githubusercontent.com/65479883/179546440-2f11c074-45d5-4ba1-ade6-5db22c567efe.png | width=100px]]

Here is a the heatmap output, using [kepler.GL](https://www.kepler.gl), a web data-visualization platform.

![kepler gl](https://user-images.githubusercontent.com/65479883/179546474-249b85bf-6f4f-4fa0-a0f4-a50ed39cdf81.png)

The sensor itself was a great limitifier, since it was not designed for this purpose in mind. The team also experiemnted with other sensors such as LM393 and D-007 (MIC-1 & 2) modules. All these sensors provided a very limited analog variablility and thus sensitivity for outdoor usage was limited. Also, these sensors were witness to wind and touch-vibration errors.

KY-038 ![image](https://user-images.githubusercontent.com/65479883/179550419-a40f31df-fc7e-4334-8560-6d6c9d69c05f.png  | width=100) LM-393 ![image](https://user-images.githubusercontent.com/65479883/179550639-e10224b2-696b-4293-b683-5059b70e5422.png  | width=100)

A better choice for sensors would be I2C Audio Input would be MAX4466, MAX9814, DFR0034, SPH0645 and the INMP441 sensor modules. INMP441 and SPH0645 are MEMS, and as pointed out by a detailed analysis by Chris Greening [here](https://www.atomic14.com/2020/09/12/esp32-audio-input.html) - usage of those would be deemed more useful in this use case. The team is waiting for the delivery for MAX4466, DFR0034 & INMP441 with high expectaions of MAX4466 and INMP441 for future experiments with more consice data collection.

MAX4466 ![image](https://user-images.githubusercontent.com/65479883/179550098-8d86321b-2456-4c15-873f-518714f97864.png  | width=100) DFR0034 ![image](https://user-images.githubusercontent.com/65479883/179550164-3a527001-244e-4887-9bbc-3c0517b4bf76.png  | width=100) INMP441 ![image](https://user-images.githubusercontent.com/65479883/179550260-d7320f8c-734d-4855-8a2b-a9dbd84f74dc.png  | width=100)
