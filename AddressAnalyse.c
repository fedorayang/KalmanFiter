#include "common.h"	//包含系统配置
			/******************************************
			#include    "system_MKL.h"      //系统配置
			#include    "PORT_cfg.h"      	//管脚复用配置
			#include    "MKL_mcg.h"         //K60 时钟模块
			*******************************************/
#include "include.h"//包含用户定义的头文件

//256个电磁信号与距离的关系
const u32 DistanceTable[256]={
909090909,
909015783,
908790482,
908415228,
907890392,
907216494,
906394199,
905424314,
904307793,
903045726,
901639344,
900090009,
898399215,
896568587,
894599869,
892494929,
890255746,
887884413,
885383129,
882754193,
880000000,
877123036,
874125874,
871011164,
867781634,
864440078,
860989355,
857432379,
853772120,
850011591,
846153846,
842201975,
838159097,
834028356,
829812914,
825515947,
821140638,
816690177,
812167749,
807576536,
802919708,
798200420,
793421811,
788586995,
783699059,
778761061,
773776027,
768746942,
763676756,
758568374,
753424657,
748248418,
743042420,
737809376,
732551944,
727272727,
721974271,
716659065,
711329539,
705988062,
700636942,
695278427,
689914701,
684547887,
679180044,
673813169,
668449197,
663089999,
657737383,
652393096,
647058823,
641736188,
636426753,
631132021,
625853436,
620592383,
615350190,
610128126,
604927408,
599749195,
594594594,
589464658,
584360390,
579282742,
574232616,
569210866,
564218301,
559255681,
554323725,
549423105,
544554455,
539718365,
534915386,
530146031,
525410775,
520710059,
516044285,
511413826,
506819019,
502260170,
497737556,
493251423,
488801990,
484389449,
480013964,
475675675,
471374700,
467111129,
462885036,
458696468,
454545454,
450432005,
446356111,
442317744,
438316863,
434353405,
430427296,
426538446,
422686750,
418872091,
415094339,
411353352,
407648977,
403981049,
400349395,
396753832,
393194166,
389670197,
386181716,
382728506,
379310344,
375927001,
372578241,
369263822,
365983497,
362737015,
359524120,
356344552,
353198047,
350084338,
347003154,
343954222,
340937267,
337952010,
334998172,
332075471,
329183624,
326322347,
323491353,
320690358,
317919075,
315177215,
312464492,
309780618,
307125307,
304498269,
301899220,
299327872,
296783941,
294267141,
291777188,
289313800,
286876695,
284465592,
282080213,
279720279,
277385515,
275075645,
272790397,
270529500,
268292682,
266079678,
263890221,
261724047,
259580894,
257460503,
255362614,
253286974,
251233327,
249201422,
247191011,
245201845,
243233681,
241286275,
239359387,
237452779,
235566215,
233699462,
231852289,
230024466,
228215767,
226425969,
224654848,
222902186,
221167765,
219451371,
217752791,
216071814,
214408233,
212761842,
211132437,
209519818,
207923786,
206344144,
204780698,
203233256,
201701628,
200185626,
198685066,
197199763,
195729537,
194274209,
192833602,
191407541,
189995854,
188598371,
187214922,
185845342,
184489467,
183147133,
181818181,
180502453,
179199791,
177910042,
176633052,
175368672,
174116753,
172877147,
171649709,
170434297,
169230769,
168038985,
166858807,
165690099,
164532727,
163386557,
162251460,
161127305,
160013964,
158911313,
157819225,
156737578,
155666251,
154605124,
153554078,
152512998,
151481767,
150460271,
149448399,
148446039,
147453083,
146469421,
145494947,
144529556,
143573143,
142625607
};






//根据三个电感数据计算偏离距离
//距离变换算法
u8 DistanceTransmit(u32 L,u32 M,u32 R)
{
	double Length=0;
    	u32 error1=0,error2=4000000000;
	u32 J=(L+M-R)/3;
	u32 i;
	for(i=0;i<255;i++)
	{
		error1=(u32)fabs(J-(double)DistanceTable[i]);
		if(error2>error1){
			printf("error2 %d",error2);
			error2=error1;
			Length =i;
		
		}
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	return (u8)Length;
}