#include "type.h"
#include "file.h"

// ==================================== File 基本接口 ====================================
//-----------------------(^_^)-------------------------
// 函数: bFileWrite
// 时间: 2017/4/21__Original__10:45:54
// 功能：给文件写入内容
// 参数:
// 		const char * pcName		文件名称（字符串）
// 		uint32_t uiAddr			写入地址
// 		uint8_t * pucIn			写入长度
// 		uint32_t uidlen			写入的数据
// 返回:
// 		bool
//-----------------------------------------------------
bool FileWrite(const char * pcName,uint32_t uiAddr,uint8_t *pucIn,uint32_t uidlen)
{
	FILE * pf;
	//printf("---------------------------\n");
	if((pf = fopen(pcName,"rb+")) == NULL)
	{
		printf("[%s] File Read Error\n",pcName);
		if((pf = fopen(pcName,"wb")) != NULL)
		{
			printf("[ %s ] Create File Succeed!\n",pcName);
		}
		else
		{
			printf("[ %s ] Create File Failed!\n",pcName);
			return FALSE;
		}
	}
	fseek(pf,uiAddr,SEEK_SET);
	fwrite(pucIn,sizeof(uint8_t),uidlen,pf);
	fclose(pf);
	//printf("[ %s ] Write File Succeed!\n",pcName);
	return TRUE;
}

//-----------------------(^_^)-------------------------
// 函数: bFileRead
// 时间: 2017/4/21__Original__10:46:30
// 功能：读出文件内容
// 参数:
// 		const char * pcName		文件名称（字符串）
// 		uint32_t uiAddr			读出地址
// 		uint8_t * pucOut		读出的数据
// 		uint32_t uidlen			期望读出长度
// 返回:
// 		uint32_t 0.读取失败或者不读任何数据
//		other.实际读取的数据长度
//-----------------------------------------------------
uint32_t FileRead(const char * pcName,uint32_t uiAddr,uint8_t *pucOut,uint32_t uidlen)
{
	FILE * pf;
	uint32_t datalen = 0;
	//printf("---------------------------\n");
	//之前直接"r"，读取到0x19之后的数据就读不出来了。现在使用二进制读取，则全部读出
	if((pf = fopen(pcName,"rb")) == NULL)
	{
		printf("[%s] File Read Error\n",pcName);
		if((pf = fopen(pcName,"wb")) != NULL)
		{
			printf("[ %s ] Create File Succeed!\n",pcName);
		}
		else
		{
			printf("[ %s ] Create File Failed!\n",pcName);
			return 0;
		}
	}

	//-------------------------------------------
	// 此处的目的，仅仅是为了定位文件的结尾。
	// 这样ftell就能够返回文件结尾的地址
	//-------------------------------------------
	fseek(pf,0,SEEK_END);
	//-------------------------------------------
	// 若长度+偏移超出文件，则返回实际读取的长度
	//-------------------------------------------
	datalen = ftell(pf) - uiAddr;
	if(uidlen < datalen)
	{
		datalen = uidlen;
	}

	fseek(pf,uiAddr,SEEK_SET);
	fread(pucOut,sizeof(uint8_t),datalen,pf);
	fclose(pf);
	//printf("[ %s ] Read File Succeed!\n",pcName);
	return datalen;
}

//-----------------------(^_^)-------------------------
// 函数: vFileEraseAll
// 时间: 2017/4/21__Original__11:07:50
// 功能：若文件存在则擦除。若不存在，则提示
// 参数:
// 		const char * pcName
// 返回:
// 		void
//-----------------------------------------------------
void FileEraseAll(const char * pcName)
{
	FILE * pf;
	//printf("---------------------------\n");
	if((pf = fopen(pcName,"rb")) == NULL)
	{
		printf("[ %s ] File not exist!\n",pcName);
		return;
	}
	else
	{
		//若文件存在
		if((pf = fopen(pcName,"wb")) != NULL)
		{
			printf("[ %s ] Clear File Succeed!\n",pcName);
		}
		else
		{
			printf("[ %s ] Clear File Failed!\n",pcName);
			return;
		}
	}
	fclose(pf);
}