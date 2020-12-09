#define loop		10000
#define length      10

#pragma section farbss cpu0_data
unsigned int DataDSPR0[length];

#pragma section farbss cpu1_data
unsigned int DataDSPR1[length];

#pragma section farbss lmu_data
unsigned int DataLMU[length];

#pragma section farbss restore

#pragma section code cpu0_code // <- core0
void accessDSPR0data(volatile unsigned int *dataField) {
	volatile unsigned int info;
	unsigned int i;

	for (i = 0; i < loop; i++) {
		for (int j = 0; j < length; j++) {
			dataField[j] = j + 1;
			info = dataField[j];
		}
	}
}
void accessDSPR1data(volatile unsigned int *dataField) {
	volatile unsigned int info;
	unsigned int i;

	for (i = 0; i < 10000; i++) {
		for (int j = 0; j < length; j++) {
			dataField[j] = j + 1;
			info = dataField[j];
		}
	}
}
void accessLMURAMdata(volatile unsigned int *dataField) {
	volatile unsigned int info;
	unsigned int i;

	for (i = 0; i < 10000; i++) {
		for (int j = 0; j < length; j++) {
			dataField[j] = j + 1;
			info = dataField[j];
		}
	}
}

int main(void) {
	accessDSPR0data(DataDSPR0);
	accessDSPR1data(DataDSPR1);
	accessLMURAMdata(DataLMU);
}
#pragma section code restore

