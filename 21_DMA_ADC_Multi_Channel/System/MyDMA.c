#include "stm32f10x.h"                  // Device header

void MyDMA_Init(uint32_t AddrA, uint32_t AddrB, uint8_t	Size)
{
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
	
	DMA_InitTypeDef DMA_InitStructure;
	DMA_InitStructure.DMA_MemoryBaseAddr = AddrA;
	DMA_InitStructure.DMA_MemoryDataSize = ;
	DMA_InitStructure.DMA_PeripheralBaseAddr = AddrB;
	DMA_InitStructure.DMA_PeripheralDataSize = ;
	DMA_InitStructure.DMA_PeripheralInc = ;
	DMA_InitStructure.DMA_MemoryInc = ;
	DMA_InitStructure.DMA_BufferSize = ;
	DMA_InitStructure.DMA_DIR = ;
	DMA_InitStructure.DMA_M2M = ;
	DMA_InitStructure.DMA_Mode = ;
	DMA_InitStructure.DMA_Priority = ;
	DMA_Init(DMA1_Channel1, &DMA_InitStructure);
}
