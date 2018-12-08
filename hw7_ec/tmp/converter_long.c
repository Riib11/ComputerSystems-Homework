/*
 * Trivial implementation of converter function.
 * You may override this file or create your own.
 */
#include "converter.h"

#include <stdlib.h>

void convert_all(unsigned nlines, char *lines[], quote_t nums[]) {

    // groups of 1000 entries at a time
    register unsigned i = 0;
    for (register unsigned i = 0; i-1000 < nlines; i += 10) {

        *nums++ = atoi(lines[i+0]);
        *nums++ = atoi(lines[i+1]);
        *nums++ = atoi(lines[i+2]);
        *nums++ = atoi(lines[i+3]);
        *nums++ = atoi(lines[i+4]);
        *nums++ = atoi(lines[i+5]);
        *nums++ = atoi(lines[i+6]);
        *nums++ = atoi(lines[i+7]);
        *nums++ = atoi(lines[i+8]);
        *nums++ = atoi(lines[i+9]);

        *nums++ = atoi(lines[i+10]);
        *nums++ = atoi(lines[i+11]);
        *nums++ = atoi(lines[i+12]);
        *nums++ = atoi(lines[i+13]);
        *nums++ = atoi(lines[i+14]);
        *nums++ = atoi(lines[i+15]);
        *nums++ = atoi(lines[i+16]);
        *nums++ = atoi(lines[i+17]);
        *nums++ = atoi(lines[i+18]);
        *nums++ = atoi(lines[i+19]);

        *nums++ = atoi(lines[i+20]);
        *nums++ = atoi(lines[i+21]);
        *nums++ = atoi(lines[i+22]);
        *nums++ = atoi(lines[i+23]);
        *nums++ = atoi(lines[i+24]);
        *nums++ = atoi(lines[i+25]);
        *nums++ = atoi(lines[i+26]);
        *nums++ = atoi(lines[i+27]);
        *nums++ = atoi(lines[i+28]);
        *nums++ = atoi(lines[i+29]);

        *nums++ = atoi(lines[i+30]);
        *nums++ = atoi(lines[i+31]);
        *nums++ = atoi(lines[i+32]);
        *nums++ = atoi(lines[i+33]);
        *nums++ = atoi(lines[i+34]);
        *nums++ = atoi(lines[i+35]);
        *nums++ = atoi(lines[i+36]);
        *nums++ = atoi(lines[i+37]);
        *nums++ = atoi(lines[i+38]);
        *nums++ = atoi(lines[i+39]);

        *nums++ = atoi(lines[i+40]);
        *nums++ = atoi(lines[i+41]);
        *nums++ = atoi(lines[i+42]);
        *nums++ = atoi(lines[i+43]);
        *nums++ = atoi(lines[i+44]);
        *nums++ = atoi(lines[i+45]);
        *nums++ = atoi(lines[i+46]);
        *nums++ = atoi(lines[i+47]);
        *nums++ = atoi(lines[i+48]);
        *nums++ = atoi(lines[i+49]);

        *nums++ = atoi(lines[i+50]);
        *nums++ = atoi(lines[i+51]);
        *nums++ = atoi(lines[i+52]);
        *nums++ = atoi(lines[i+53]);
        *nums++ = atoi(lines[i+54]);
        *nums++ = atoi(lines[i+55]);
        *nums++ = atoi(lines[i+56]);
        *nums++ = atoi(lines[i+57]);
        *nums++ = atoi(lines[i+58]);
        *nums++ = atoi(lines[i+59]);

        *nums++ = atoi(lines[i+60]);
        *nums++ = atoi(lines[i+61]);
        *nums++ = atoi(lines[i+62]);
        *nums++ = atoi(lines[i+63]);
        *nums++ = atoi(lines[i+64]);
        *nums++ = atoi(lines[i+65]);
        *nums++ = atoi(lines[i+66]);
        *nums++ = atoi(lines[i+67]);
        *nums++ = atoi(lines[i+68]);
        *nums++ = atoi(lines[i+69]);

        *nums++ = atoi(lines[i+70]);
        *nums++ = atoi(lines[i+71]);
        *nums++ = atoi(lines[i+72]);
        *nums++ = atoi(lines[i+73]);
        *nums++ = atoi(lines[i+74]);
        *nums++ = atoi(lines[i+75]);
        *nums++ = atoi(lines[i+76]);
        *nums++ = atoi(lines[i+77]);
        *nums++ = atoi(lines[i+78]);
        *nums++ = atoi(lines[i+79]);

        *nums++ = atoi(lines[i+80]);
        *nums++ = atoi(lines[i+81]);
        *nums++ = atoi(lines[i+82]);
        *nums++ = atoi(lines[i+83]);
        *nums++ = atoi(lines[i+84]);
        *nums++ = atoi(lines[i+85]);
        *nums++ = atoi(lines[i+86]);
        *nums++ = atoi(lines[i+87]);
        *nums++ = atoi(lines[i+88]);
        *nums++ = atoi(lines[i+89]);

        *nums++ = atoi(lines[i+90]);
        *nums++ = atoi(lines[i+91]);
        *nums++ = atoi(lines[i+92]);
        *nums++ = atoi(lines[i+93]);
        *nums++ = atoi(lines[i+94]);
        *nums++ = atoi(lines[i+95]);
        *nums++ = atoi(lines[i+96]);
        *nums++ = atoi(lines[i+97]);
        *nums++ = atoi(lines[i+98]);
        *nums++ = atoi(lines[i+99]);

        *nums++ = atoi(lines[i+100]);
        *nums++ = atoi(lines[i+101]);
        *nums++ = atoi(lines[i+102]);
        *nums++ = atoi(lines[i+103]);
        *nums++ = atoi(lines[i+104]);
        *nums++ = atoi(lines[i+105]);
        *nums++ = atoi(lines[i+106]);
        *nums++ = atoi(lines[i+107]);
        *nums++ = atoi(lines[i+108]);
        *nums++ = atoi(lines[i+109]);

        *nums++ = atoi(lines[i+110]);
        *nums++ = atoi(lines[i+111]);
        *nums++ = atoi(lines[i+112]);
        *nums++ = atoi(lines[i+113]);
        *nums++ = atoi(lines[i+114]);
        *nums++ = atoi(lines[i+115]);
        *nums++ = atoi(lines[i+116]);
        *nums++ = atoi(lines[i+117]);
        *nums++ = atoi(lines[i+118]);
        *nums++ = atoi(lines[i+119]);

        *nums++ = atoi(lines[i+120]);
        *nums++ = atoi(lines[i+121]);
        *nums++ = atoi(lines[i+122]);
        *nums++ = atoi(lines[i+123]);
        *nums++ = atoi(lines[i+124]);
        *nums++ = atoi(lines[i+125]);
        *nums++ = atoi(lines[i+126]);
        *nums++ = atoi(lines[i+127]);
        *nums++ = atoi(lines[i+128]);
        *nums++ = atoi(lines[i+129]);

        *nums++ = atoi(lines[i+130]);
        *nums++ = atoi(lines[i+131]);
        *nums++ = atoi(lines[i+132]);
        *nums++ = atoi(lines[i+133]);
        *nums++ = atoi(lines[i+134]);
        *nums++ = atoi(lines[i+135]);
        *nums++ = atoi(lines[i+136]);
        *nums++ = atoi(lines[i+137]);
        *nums++ = atoi(lines[i+138]);
        *nums++ = atoi(lines[i+139]);

        *nums++ = atoi(lines[i+140]);
        *nums++ = atoi(lines[i+141]);
        *nums++ = atoi(lines[i+142]);
        *nums++ = atoi(lines[i+143]);
        *nums++ = atoi(lines[i+144]);
        *nums++ = atoi(lines[i+145]);
        *nums++ = atoi(lines[i+146]);
        *nums++ = atoi(lines[i+147]);
        *nums++ = atoi(lines[i+148]);
        *nums++ = atoi(lines[i+149]);

        *nums++ = atoi(lines[i+150]);
        *nums++ = atoi(lines[i+151]);
        *nums++ = atoi(lines[i+152]);
        *nums++ = atoi(lines[i+153]);
        *nums++ = atoi(lines[i+154]);
        *nums++ = atoi(lines[i+155]);
        *nums++ = atoi(lines[i+156]);
        *nums++ = atoi(lines[i+157]);
        *nums++ = atoi(lines[i+158]);
        *nums++ = atoi(lines[i+159]);

        *nums++ = atoi(lines[i+160]);
        *nums++ = atoi(lines[i+161]);
        *nums++ = atoi(lines[i+162]);
        *nums++ = atoi(lines[i+163]);
        *nums++ = atoi(lines[i+164]);
        *nums++ = atoi(lines[i+165]);
        *nums++ = atoi(lines[i+166]);
        *nums++ = atoi(lines[i+167]);
        *nums++ = atoi(lines[i+168]);
        *nums++ = atoi(lines[i+169]);

        *nums++ = atoi(lines[i+170]);
        *nums++ = atoi(lines[i+171]);
        *nums++ = atoi(lines[i+172]);
        *nums++ = atoi(lines[i+173]);
        *nums++ = atoi(lines[i+174]);
        *nums++ = atoi(lines[i+175]);
        *nums++ = atoi(lines[i+176]);
        *nums++ = atoi(lines[i+177]);
        *nums++ = atoi(lines[i+178]);
        *nums++ = atoi(lines[i+179]);

        *nums++ = atoi(lines[i+180]);
        *nums++ = atoi(lines[i+181]);
        *nums++ = atoi(lines[i+182]);
        *nums++ = atoi(lines[i+183]);
        *nums++ = atoi(lines[i+184]);
        *nums++ = atoi(lines[i+185]);
        *nums++ = atoi(lines[i+186]);
        *nums++ = atoi(lines[i+187]);
        *nums++ = atoi(lines[i+188]);
        *nums++ = atoi(lines[i+189]);

        *nums++ = atoi(lines[i+190]);
        *nums++ = atoi(lines[i+191]);
        *nums++ = atoi(lines[i+192]);
        *nums++ = atoi(lines[i+193]);
        *nums++ = atoi(lines[i+194]);
        *nums++ = atoi(lines[i+195]);
        *nums++ = atoi(lines[i+196]);
        *nums++ = atoi(lines[i+197]);
        *nums++ = atoi(lines[i+198]);
        *nums++ = atoi(lines[i+199]);

        *nums++ = atoi(lines[i+200]);
        *nums++ = atoi(lines[i+201]);
        *nums++ = atoi(lines[i+202]);
        *nums++ = atoi(lines[i+203]);
        *nums++ = atoi(lines[i+204]);
        *nums++ = atoi(lines[i+205]);
        *nums++ = atoi(lines[i+206]);
        *nums++ = atoi(lines[i+207]);
        *nums++ = atoi(lines[i+208]);
        *nums++ = atoi(lines[i+209]);

        *nums++ = atoi(lines[i+210]);
        *nums++ = atoi(lines[i+211]);
        *nums++ = atoi(lines[i+212]);
        *nums++ = atoi(lines[i+213]);
        *nums++ = atoi(lines[i+214]);
        *nums++ = atoi(lines[i+215]);
        *nums++ = atoi(lines[i+216]);
        *nums++ = atoi(lines[i+217]);
        *nums++ = atoi(lines[i+218]);
        *nums++ = atoi(lines[i+219]);

        *nums++ = atoi(lines[i+220]);
        *nums++ = atoi(lines[i+221]);
        *nums++ = atoi(lines[i+222]);
        *nums++ = atoi(lines[i+223]);
        *nums++ = atoi(lines[i+224]);
        *nums++ = atoi(lines[i+225]);
        *nums++ = atoi(lines[i+226]);
        *nums++ = atoi(lines[i+227]);
        *nums++ = atoi(lines[i+228]);
        *nums++ = atoi(lines[i+229]);

        *nums++ = atoi(lines[i+230]);
        *nums++ = atoi(lines[i+231]);
        *nums++ = atoi(lines[i+232]);
        *nums++ = atoi(lines[i+233]);
        *nums++ = atoi(lines[i+234]);
        *nums++ = atoi(lines[i+235]);
        *nums++ = atoi(lines[i+236]);
        *nums++ = atoi(lines[i+237]);
        *nums++ = atoi(lines[i+238]);
        *nums++ = atoi(lines[i+239]);

        *nums++ = atoi(lines[i+240]);
        *nums++ = atoi(lines[i+241]);
        *nums++ = atoi(lines[i+242]);
        *nums++ = atoi(lines[i+243]);
        *nums++ = atoi(lines[i+244]);
        *nums++ = atoi(lines[i+245]);
        *nums++ = atoi(lines[i+246]);
        *nums++ = atoi(lines[i+247]);
        *nums++ = atoi(lines[i+248]);
        *nums++ = atoi(lines[i+249]);

        *nums++ = atoi(lines[i+250]);
        *nums++ = atoi(lines[i+251]);
        *nums++ = atoi(lines[i+252]);
        *nums++ = atoi(lines[i+253]);
        *nums++ = atoi(lines[i+254]);
        *nums++ = atoi(lines[i+255]);
        *nums++ = atoi(lines[i+256]);
        *nums++ = atoi(lines[i+257]);
        *nums++ = atoi(lines[i+258]);
        *nums++ = atoi(lines[i+259]);

        *nums++ = atoi(lines[i+260]);
        *nums++ = atoi(lines[i+261]);
        *nums++ = atoi(lines[i+262]);
        *nums++ = atoi(lines[i+263]);
        *nums++ = atoi(lines[i+264]);
        *nums++ = atoi(lines[i+265]);
        *nums++ = atoi(lines[i+266]);
        *nums++ = atoi(lines[i+267]);
        *nums++ = atoi(lines[i+268]);
        *nums++ = atoi(lines[i+269]);

        *nums++ = atoi(lines[i+270]);
        *nums++ = atoi(lines[i+271]);
        *nums++ = atoi(lines[i+272]);
        *nums++ = atoi(lines[i+273]);
        *nums++ = atoi(lines[i+274]);
        *nums++ = atoi(lines[i+275]);
        *nums++ = atoi(lines[i+276]);
        *nums++ = atoi(lines[i+277]);
        *nums++ = atoi(lines[i+278]);
        *nums++ = atoi(lines[i+279]);

        *nums++ = atoi(lines[i+280]);
        *nums++ = atoi(lines[i+281]);
        *nums++ = atoi(lines[i+282]);
        *nums++ = atoi(lines[i+283]);
        *nums++ = atoi(lines[i+284]);
        *nums++ = atoi(lines[i+285]);
        *nums++ = atoi(lines[i+286]);
        *nums++ = atoi(lines[i+287]);
        *nums++ = atoi(lines[i+288]);
        *nums++ = atoi(lines[i+289]);

        *nums++ = atoi(lines[i+290]);
        *nums++ = atoi(lines[i+291]);
        *nums++ = atoi(lines[i+292]);
        *nums++ = atoi(lines[i+293]);
        *nums++ = atoi(lines[i+294]);
        *nums++ = atoi(lines[i+295]);
        *nums++ = atoi(lines[i+296]);
        *nums++ = atoi(lines[i+297]);
        *nums++ = atoi(lines[i+298]);
        *nums++ = atoi(lines[i+299]);

        *nums++ = atoi(lines[i+300]);
        *nums++ = atoi(lines[i+301]);
        *nums++ = atoi(lines[i+302]);
        *nums++ = atoi(lines[i+303]);
        *nums++ = atoi(lines[i+304]);
        *nums++ = atoi(lines[i+305]);
        *nums++ = atoi(lines[i+306]);
        *nums++ = atoi(lines[i+307]);
        *nums++ = atoi(lines[i+308]);
        *nums++ = atoi(lines[i+309]);

        *nums++ = atoi(lines[i+310]);
        *nums++ = atoi(lines[i+311]);
        *nums++ = atoi(lines[i+312]);
        *nums++ = atoi(lines[i+313]);
        *nums++ = atoi(lines[i+314]);
        *nums++ = atoi(lines[i+315]);
        *nums++ = atoi(lines[i+316]);
        *nums++ = atoi(lines[i+317]);
        *nums++ = atoi(lines[i+318]);
        *nums++ = atoi(lines[i+319]);

        *nums++ = atoi(lines[i+320]);
        *nums++ = atoi(lines[i+321]);
        *nums++ = atoi(lines[i+322]);
        *nums++ = atoi(lines[i+323]);
        *nums++ = atoi(lines[i+324]);
        *nums++ = atoi(lines[i+325]);
        *nums++ = atoi(lines[i+326]);
        *nums++ = atoi(lines[i+327]);
        *nums++ = atoi(lines[i+328]);
        *nums++ = atoi(lines[i+329]);

        *nums++ = atoi(lines[i+330]);
        *nums++ = atoi(lines[i+331]);
        *nums++ = atoi(lines[i+332]);
        *nums++ = atoi(lines[i+333]);
        *nums++ = atoi(lines[i+334]);
        *nums++ = atoi(lines[i+335]);
        *nums++ = atoi(lines[i+336]);
        *nums++ = atoi(lines[i+337]);
        *nums++ = atoi(lines[i+338]);
        *nums++ = atoi(lines[i+339]);

        *nums++ = atoi(lines[i+340]);
        *nums++ = atoi(lines[i+341]);
        *nums++ = atoi(lines[i+342]);
        *nums++ = atoi(lines[i+343]);
        *nums++ = atoi(lines[i+344]);
        *nums++ = atoi(lines[i+345]);
        *nums++ = atoi(lines[i+346]);
        *nums++ = atoi(lines[i+347]);
        *nums++ = atoi(lines[i+348]);
        *nums++ = atoi(lines[i+349]);

        *nums++ = atoi(lines[i+350]);
        *nums++ = atoi(lines[i+351]);
        *nums++ = atoi(lines[i+352]);
        *nums++ = atoi(lines[i+353]);
        *nums++ = atoi(lines[i+354]);
        *nums++ = atoi(lines[i+355]);
        *nums++ = atoi(lines[i+356]);
        *nums++ = atoi(lines[i+357]);
        *nums++ = atoi(lines[i+358]);
        *nums++ = atoi(lines[i+359]);

        *nums++ = atoi(lines[i+360]);
        *nums++ = atoi(lines[i+361]);
        *nums++ = atoi(lines[i+362]);
        *nums++ = atoi(lines[i+363]);
        *nums++ = atoi(lines[i+364]);
        *nums++ = atoi(lines[i+365]);
        *nums++ = atoi(lines[i+366]);
        *nums++ = atoi(lines[i+367]);
        *nums++ = atoi(lines[i+368]);
        *nums++ = atoi(lines[i+369]);

        *nums++ = atoi(lines[i+370]);
        *nums++ = atoi(lines[i+371]);
        *nums++ = atoi(lines[i+372]);
        *nums++ = atoi(lines[i+373]);
        *nums++ = atoi(lines[i+374]);
        *nums++ = atoi(lines[i+375]);
        *nums++ = atoi(lines[i+376]);
        *nums++ = atoi(lines[i+377]);
        *nums++ = atoi(lines[i+378]);
        *nums++ = atoi(lines[i+379]);

        *nums++ = atoi(lines[i+380]);
        *nums++ = atoi(lines[i+381]);
        *nums++ = atoi(lines[i+382]);
        *nums++ = atoi(lines[i+383]);
        *nums++ = atoi(lines[i+384]);
        *nums++ = atoi(lines[i+385]);
        *nums++ = atoi(lines[i+386]);
        *nums++ = atoi(lines[i+387]);
        *nums++ = atoi(lines[i+388]);
        *nums++ = atoi(lines[i+389]);

        *nums++ = atoi(lines[i+390]);
        *nums++ = atoi(lines[i+391]);
        *nums++ = atoi(lines[i+392]);
        *nums++ = atoi(lines[i+393]);
        *nums++ = atoi(lines[i+394]);
        *nums++ = atoi(lines[i+395]);
        *nums++ = atoi(lines[i+396]);
        *nums++ = atoi(lines[i+397]);
        *nums++ = atoi(lines[i+398]);
        *nums++ = atoi(lines[i+399]);

        *nums++ = atoi(lines[i+400]);
        *nums++ = atoi(lines[i+401]);
        *nums++ = atoi(lines[i+402]);
        *nums++ = atoi(lines[i+403]);
        *nums++ = atoi(lines[i+404]);
        *nums++ = atoi(lines[i+405]);
        *nums++ = atoi(lines[i+406]);
        *nums++ = atoi(lines[i+407]);
        *nums++ = atoi(lines[i+408]);
        *nums++ = atoi(lines[i+409]);

        *nums++ = atoi(lines[i+410]);
        *nums++ = atoi(lines[i+411]);
        *nums++ = atoi(lines[i+412]);
        *nums++ = atoi(lines[i+413]);
        *nums++ = atoi(lines[i+414]);
        *nums++ = atoi(lines[i+415]);
        *nums++ = atoi(lines[i+416]);
        *nums++ = atoi(lines[i+417]);
        *nums++ = atoi(lines[i+418]);
        *nums++ = atoi(lines[i+419]);

        *nums++ = atoi(lines[i+420]);
        *nums++ = atoi(lines[i+421]);
        *nums++ = atoi(lines[i+422]);
        *nums++ = atoi(lines[i+423]);
        *nums++ = atoi(lines[i+424]);
        *nums++ = atoi(lines[i+425]);
        *nums++ = atoi(lines[i+426]);
        *nums++ = atoi(lines[i+427]);
        *nums++ = atoi(lines[i+428]);
        *nums++ = atoi(lines[i+429]);

        *nums++ = atoi(lines[i+430]);
        *nums++ = atoi(lines[i+431]);
        *nums++ = atoi(lines[i+432]);
        *nums++ = atoi(lines[i+433]);
        *nums++ = atoi(lines[i+434]);
        *nums++ = atoi(lines[i+435]);
        *nums++ = atoi(lines[i+436]);
        *nums++ = atoi(lines[i+437]);
        *nums++ = atoi(lines[i+438]);
        *nums++ = atoi(lines[i+439]);

        *nums++ = atoi(lines[i+440]);
        *nums++ = atoi(lines[i+441]);
        *nums++ = atoi(lines[i+442]);
        *nums++ = atoi(lines[i+443]);
        *nums++ = atoi(lines[i+444]);
        *nums++ = atoi(lines[i+445]);
        *nums++ = atoi(lines[i+446]);
        *nums++ = atoi(lines[i+447]);
        *nums++ = atoi(lines[i+448]);
        *nums++ = atoi(lines[i+449]);

        *nums++ = atoi(lines[i+450]);
        *nums++ = atoi(lines[i+451]);
        *nums++ = atoi(lines[i+452]);
        *nums++ = atoi(lines[i+453]);
        *nums++ = atoi(lines[i+454]);
        *nums++ = atoi(lines[i+455]);
        *nums++ = atoi(lines[i+456]);
        *nums++ = atoi(lines[i+457]);
        *nums++ = atoi(lines[i+458]);
        *nums++ = atoi(lines[i+459]);

        *nums++ = atoi(lines[i+460]);
        *nums++ = atoi(lines[i+461]);
        *nums++ = atoi(lines[i+462]);
        *nums++ = atoi(lines[i+463]);
        *nums++ = atoi(lines[i+464]);
        *nums++ = atoi(lines[i+465]);
        *nums++ = atoi(lines[i+466]);
        *nums++ = atoi(lines[i+467]);
        *nums++ = atoi(lines[i+468]);
        *nums++ = atoi(lines[i+469]);

        *nums++ = atoi(lines[i+470]);
        *nums++ = atoi(lines[i+471]);
        *nums++ = atoi(lines[i+472]);
        *nums++ = atoi(lines[i+473]);
        *nums++ = atoi(lines[i+474]);
        *nums++ = atoi(lines[i+475]);
        *nums++ = atoi(lines[i+476]);
        *nums++ = atoi(lines[i+477]);
        *nums++ = atoi(lines[i+478]);
        *nums++ = atoi(lines[i+479]);

        *nums++ = atoi(lines[i+480]);
        *nums++ = atoi(lines[i+481]);
        *nums++ = atoi(lines[i+482]);
        *nums++ = atoi(lines[i+483]);
        *nums++ = atoi(lines[i+484]);
        *nums++ = atoi(lines[i+485]);
        *nums++ = atoi(lines[i+486]);
        *nums++ = atoi(lines[i+487]);
        *nums++ = atoi(lines[i+488]);
        *nums++ = atoi(lines[i+489]);

        *nums++ = atoi(lines[i+490]);
        *nums++ = atoi(lines[i+491]);
        *nums++ = atoi(lines[i+492]);
        *nums++ = atoi(lines[i+493]);
        *nums++ = atoi(lines[i+494]);
        *nums++ = atoi(lines[i+495]);
        *nums++ = atoi(lines[i+496]);
        *nums++ = atoi(lines[i+497]);
        *nums++ = atoi(lines[i+498]);
        *nums++ = atoi(lines[i+499]);

        *nums++ = atoi(lines[i+500]);
        *nums++ = atoi(lines[i+501]);
        *nums++ = atoi(lines[i+502]);
        *nums++ = atoi(lines[i+503]);
        *nums++ = atoi(lines[i+504]);
        *nums++ = atoi(lines[i+505]);
        *nums++ = atoi(lines[i+506]);
        *nums++ = atoi(lines[i+507]);
        *nums++ = atoi(lines[i+508]);
        *nums++ = atoi(lines[i+509]);

        *nums++ = atoi(lines[i+510]);
        *nums++ = atoi(lines[i+511]);
        *nums++ = atoi(lines[i+512]);
        *nums++ = atoi(lines[i+513]);
        *nums++ = atoi(lines[i+514]);
        *nums++ = atoi(lines[i+515]);
        *nums++ = atoi(lines[i+516]);
        *nums++ = atoi(lines[i+517]);
        *nums++ = atoi(lines[i+518]);
        *nums++ = atoi(lines[i+519]);

        *nums++ = atoi(lines[i+520]);
        *nums++ = atoi(lines[i+521]);
        *nums++ = atoi(lines[i+522]);
        *nums++ = atoi(lines[i+523]);
        *nums++ = atoi(lines[i+524]);
        *nums++ = atoi(lines[i+525]);
        *nums++ = atoi(lines[i+526]);
        *nums++ = atoi(lines[i+527]);
        *nums++ = atoi(lines[i+528]);
        *nums++ = atoi(lines[i+529]);

        *nums++ = atoi(lines[i+530]);
        *nums++ = atoi(lines[i+531]);
        *nums++ = atoi(lines[i+532]);
        *nums++ = atoi(lines[i+533]);
        *nums++ = atoi(lines[i+534]);
        *nums++ = atoi(lines[i+535]);
        *nums++ = atoi(lines[i+536]);
        *nums++ = atoi(lines[i+537]);
        *nums++ = atoi(lines[i+538]);
        *nums++ = atoi(lines[i+539]);

        *nums++ = atoi(lines[i+540]);
        *nums++ = atoi(lines[i+541]);
        *nums++ = atoi(lines[i+542]);
        *nums++ = atoi(lines[i+543]);
        *nums++ = atoi(lines[i+544]);
        *nums++ = atoi(lines[i+545]);
        *nums++ = atoi(lines[i+546]);
        *nums++ = atoi(lines[i+547]);
        *nums++ = atoi(lines[i+548]);
        *nums++ = atoi(lines[i+549]);

        *nums++ = atoi(lines[i+550]);
        *nums++ = atoi(lines[i+551]);
        *nums++ = atoi(lines[i+552]);
        *nums++ = atoi(lines[i+553]);
        *nums++ = atoi(lines[i+554]);
        *nums++ = atoi(lines[i+555]);
        *nums++ = atoi(lines[i+556]);
        *nums++ = atoi(lines[i+557]);
        *nums++ = atoi(lines[i+558]);
        *nums++ = atoi(lines[i+559]);

        *nums++ = atoi(lines[i+560]);
        *nums++ = atoi(lines[i+561]);
        *nums++ = atoi(lines[i+562]);
        *nums++ = atoi(lines[i+563]);
        *nums++ = atoi(lines[i+564]);
        *nums++ = atoi(lines[i+565]);
        *nums++ = atoi(lines[i+566]);
        *nums++ = atoi(lines[i+567]);
        *nums++ = atoi(lines[i+568]);
        *nums++ = atoi(lines[i+569]);

        *nums++ = atoi(lines[i+570]);
        *nums++ = atoi(lines[i+571]);
        *nums++ = atoi(lines[i+572]);
        *nums++ = atoi(lines[i+573]);
        *nums++ = atoi(lines[i+574]);
        *nums++ = atoi(lines[i+575]);
        *nums++ = atoi(lines[i+576]);
        *nums++ = atoi(lines[i+577]);
        *nums++ = atoi(lines[i+578]);
        *nums++ = atoi(lines[i+579]);

        *nums++ = atoi(lines[i+580]);
        *nums++ = atoi(lines[i+581]);
        *nums++ = atoi(lines[i+582]);
        *nums++ = atoi(lines[i+583]);
        *nums++ = atoi(lines[i+584]);
        *nums++ = atoi(lines[i+585]);
        *nums++ = atoi(lines[i+586]);
        *nums++ = atoi(lines[i+587]);
        *nums++ = atoi(lines[i+588]);
        *nums++ = atoi(lines[i+589]);

        *nums++ = atoi(lines[i+590]);
        *nums++ = atoi(lines[i+591]);
        *nums++ = atoi(lines[i+592]);
        *nums++ = atoi(lines[i+593]);
        *nums++ = atoi(lines[i+594]);
        *nums++ = atoi(lines[i+595]);
        *nums++ = atoi(lines[i+596]);
        *nums++ = atoi(lines[i+597]);
        *nums++ = atoi(lines[i+598]);
        *nums++ = atoi(lines[i+599]);

        *nums++ = atoi(lines[i+600]);
        *nums++ = atoi(lines[i+601]);
        *nums++ = atoi(lines[i+602]);
        *nums++ = atoi(lines[i+603]);
        *nums++ = atoi(lines[i+604]);
        *nums++ = atoi(lines[i+605]);
        *nums++ = atoi(lines[i+606]);
        *nums++ = atoi(lines[i+607]);
        *nums++ = atoi(lines[i+608]);
        *nums++ = atoi(lines[i+609]);

        *nums++ = atoi(lines[i+610]);
        *nums++ = atoi(lines[i+611]);
        *nums++ = atoi(lines[i+612]);
        *nums++ = atoi(lines[i+613]);
        *nums++ = atoi(lines[i+614]);
        *nums++ = atoi(lines[i+615]);
        *nums++ = atoi(lines[i+616]);
        *nums++ = atoi(lines[i+617]);
        *nums++ = atoi(lines[i+618]);
        *nums++ = atoi(lines[i+619]);

        *nums++ = atoi(lines[i+620]);
        *nums++ = atoi(lines[i+621]);
        *nums++ = atoi(lines[i+622]);
        *nums++ = atoi(lines[i+623]);
        *nums++ = atoi(lines[i+624]);
        *nums++ = atoi(lines[i+625]);
        *nums++ = atoi(lines[i+626]);
        *nums++ = atoi(lines[i+627]);
        *nums++ = atoi(lines[i+628]);
        *nums++ = atoi(lines[i+629]);

        *nums++ = atoi(lines[i+630]);
        *nums++ = atoi(lines[i+631]);
        *nums++ = atoi(lines[i+632]);
        *nums++ = atoi(lines[i+633]);
        *nums++ = atoi(lines[i+634]);
        *nums++ = atoi(lines[i+635]);
        *nums++ = atoi(lines[i+636]);
        *nums++ = atoi(lines[i+637]);
        *nums++ = atoi(lines[i+638]);
        *nums++ = atoi(lines[i+639]);

        *nums++ = atoi(lines[i+640]);
        *nums++ = atoi(lines[i+641]);
        *nums++ = atoi(lines[i+642]);
        *nums++ = atoi(lines[i+643]);
        *nums++ = atoi(lines[i+644]);
        *nums++ = atoi(lines[i+645]);
        *nums++ = atoi(lines[i+646]);
        *nums++ = atoi(lines[i+647]);
        *nums++ = atoi(lines[i+648]);
        *nums++ = atoi(lines[i+649]);

        *nums++ = atoi(lines[i+650]);
        *nums++ = atoi(lines[i+651]);
        *nums++ = atoi(lines[i+652]);
        *nums++ = atoi(lines[i+653]);
        *nums++ = atoi(lines[i+654]);
        *nums++ = atoi(lines[i+655]);
        *nums++ = atoi(lines[i+656]);
        *nums++ = atoi(lines[i+657]);
        *nums++ = atoi(lines[i+658]);
        *nums++ = atoi(lines[i+659]);

        *nums++ = atoi(lines[i+660]);
        *nums++ = atoi(lines[i+661]);
        *nums++ = atoi(lines[i+662]);
        *nums++ = atoi(lines[i+663]);
        *nums++ = atoi(lines[i+664]);
        *nums++ = atoi(lines[i+665]);
        *nums++ = atoi(lines[i+666]);
        *nums++ = atoi(lines[i+667]);
        *nums++ = atoi(lines[i+668]);
        *nums++ = atoi(lines[i+669]);

        *nums++ = atoi(lines[i+670]);
        *nums++ = atoi(lines[i+671]);
        *nums++ = atoi(lines[i+672]);
        *nums++ = atoi(lines[i+673]);
        *nums++ = atoi(lines[i+674]);
        *nums++ = atoi(lines[i+675]);
        *nums++ = atoi(lines[i+676]);
        *nums++ = atoi(lines[i+677]);
        *nums++ = atoi(lines[i+678]);
        *nums++ = atoi(lines[i+679]);

        *nums++ = atoi(lines[i+680]);
        *nums++ = atoi(lines[i+681]);
        *nums++ = atoi(lines[i+682]);
        *nums++ = atoi(lines[i+683]);
        *nums++ = atoi(lines[i+684]);
        *nums++ = atoi(lines[i+685]);
        *nums++ = atoi(lines[i+686]);
        *nums++ = atoi(lines[i+687]);
        *nums++ = atoi(lines[i+688]);
        *nums++ = atoi(lines[i+689]);

        *nums++ = atoi(lines[i+690]);
        *nums++ = atoi(lines[i+691]);
        *nums++ = atoi(lines[i+692]);
        *nums++ = atoi(lines[i+693]);
        *nums++ = atoi(lines[i+694]);
        *nums++ = atoi(lines[i+695]);
        *nums++ = atoi(lines[i+696]);
        *nums++ = atoi(lines[i+697]);
        *nums++ = atoi(lines[i+698]);
        *nums++ = atoi(lines[i+699]);

        *nums++ = atoi(lines[i+700]);
        *nums++ = atoi(lines[i+701]);
        *nums++ = atoi(lines[i+702]);
        *nums++ = atoi(lines[i+703]);
        *nums++ = atoi(lines[i+704]);
        *nums++ = atoi(lines[i+705]);
        *nums++ = atoi(lines[i+706]);
        *nums++ = atoi(lines[i+707]);
        *nums++ = atoi(lines[i+708]);
        *nums++ = atoi(lines[i+709]);

        *nums++ = atoi(lines[i+710]);
        *nums++ = atoi(lines[i+711]);
        *nums++ = atoi(lines[i+712]);
        *nums++ = atoi(lines[i+713]);
        *nums++ = atoi(lines[i+714]);
        *nums++ = atoi(lines[i+715]);
        *nums++ = atoi(lines[i+716]);
        *nums++ = atoi(lines[i+717]);
        *nums++ = atoi(lines[i+718]);
        *nums++ = atoi(lines[i+719]);

        *nums++ = atoi(lines[i+720]);
        *nums++ = atoi(lines[i+721]);
        *nums++ = atoi(lines[i+722]);
        *nums++ = atoi(lines[i+723]);
        *nums++ = atoi(lines[i+724]);
        *nums++ = atoi(lines[i+725]);
        *nums++ = atoi(lines[i+726]);
        *nums++ = atoi(lines[i+727]);
        *nums++ = atoi(lines[i+728]);
        *nums++ = atoi(lines[i+729]);

        *nums++ = atoi(lines[i+730]);
        *nums++ = atoi(lines[i+731]);
        *nums++ = atoi(lines[i+732]);
        *nums++ = atoi(lines[i+733]);
        *nums++ = atoi(lines[i+734]);
        *nums++ = atoi(lines[i+735]);
        *nums++ = atoi(lines[i+736]);
        *nums++ = atoi(lines[i+737]);
        *nums++ = atoi(lines[i+738]);
        *nums++ = atoi(lines[i+739]);

        *nums++ = atoi(lines[i+740]);
        *nums++ = atoi(lines[i+741]);
        *nums++ = atoi(lines[i+742]);
        *nums++ = atoi(lines[i+743]);
        *nums++ = atoi(lines[i+744]);
        *nums++ = atoi(lines[i+745]);
        *nums++ = atoi(lines[i+746]);
        *nums++ = atoi(lines[i+747]);
        *nums++ = atoi(lines[i+748]);
        *nums++ = atoi(lines[i+749]);

        *nums++ = atoi(lines[i+750]);
        *nums++ = atoi(lines[i+751]);
        *nums++ = atoi(lines[i+752]);
        *nums++ = atoi(lines[i+753]);
        *nums++ = atoi(lines[i+754]);
        *nums++ = atoi(lines[i+755]);
        *nums++ = atoi(lines[i+756]);
        *nums++ = atoi(lines[i+757]);
        *nums++ = atoi(lines[i+758]);
        *nums++ = atoi(lines[i+759]);

        *nums++ = atoi(lines[i+760]);
        *nums++ = atoi(lines[i+761]);
        *nums++ = atoi(lines[i+762]);
        *nums++ = atoi(lines[i+763]);
        *nums++ = atoi(lines[i+764]);
        *nums++ = atoi(lines[i+765]);
        *nums++ = atoi(lines[i+766]);
        *nums++ = atoi(lines[i+767]);
        *nums++ = atoi(lines[i+768]);
        *nums++ = atoi(lines[i+769]);

        *nums++ = atoi(lines[i+770]);
        *nums++ = atoi(lines[i+771]);
        *nums++ = atoi(lines[i+772]);
        *nums++ = atoi(lines[i+773]);
        *nums++ = atoi(lines[i+774]);
        *nums++ = atoi(lines[i+775]);
        *nums++ = atoi(lines[i+776]);
        *nums++ = atoi(lines[i+777]);
        *nums++ = atoi(lines[i+778]);
        *nums++ = atoi(lines[i+779]);

        *nums++ = atoi(lines[i+780]);
        *nums++ = atoi(lines[i+781]);
        *nums++ = atoi(lines[i+782]);
        *nums++ = atoi(lines[i+783]);
        *nums++ = atoi(lines[i+784]);
        *nums++ = atoi(lines[i+785]);
        *nums++ = atoi(lines[i+786]);
        *nums++ = atoi(lines[i+787]);
        *nums++ = atoi(lines[i+788]);
        *nums++ = atoi(lines[i+789]);

        *nums++ = atoi(lines[i+790]);
        *nums++ = atoi(lines[i+791]);
        *nums++ = atoi(lines[i+792]);
        *nums++ = atoi(lines[i+793]);
        *nums++ = atoi(lines[i+794]);
        *nums++ = atoi(lines[i+795]);
        *nums++ = atoi(lines[i+796]);
        *nums++ = atoi(lines[i+797]);
        *nums++ = atoi(lines[i+798]);
        *nums++ = atoi(lines[i+799]);

        *nums++ = atoi(lines[i+800]);
        *nums++ = atoi(lines[i+801]);
        *nums++ = atoi(lines[i+802]);
        *nums++ = atoi(lines[i+803]);
        *nums++ = atoi(lines[i+804]);
        *nums++ = atoi(lines[i+805]);
        *nums++ = atoi(lines[i+806]);
        *nums++ = atoi(lines[i+807]);
        *nums++ = atoi(lines[i+808]);
        *nums++ = atoi(lines[i+809]);

        *nums++ = atoi(lines[i+810]);
        *nums++ = atoi(lines[i+811]);
        *nums++ = atoi(lines[i+812]);
        *nums++ = atoi(lines[i+813]);
        *nums++ = atoi(lines[i+814]);
        *nums++ = atoi(lines[i+815]);
        *nums++ = atoi(lines[i+816]);
        *nums++ = atoi(lines[i+817]);
        *nums++ = atoi(lines[i+818]);
        *nums++ = atoi(lines[i+819]);

        *nums++ = atoi(lines[i+820]);
        *nums++ = atoi(lines[i+821]);
        *nums++ = atoi(lines[i+822]);
        *nums++ = atoi(lines[i+823]);
        *nums++ = atoi(lines[i+824]);
        *nums++ = atoi(lines[i+825]);
        *nums++ = atoi(lines[i+826]);
        *nums++ = atoi(lines[i+827]);
        *nums++ = atoi(lines[i+828]);
        *nums++ = atoi(lines[i+829]);

        *nums++ = atoi(lines[i+830]);
        *nums++ = atoi(lines[i+831]);
        *nums++ = atoi(lines[i+832]);
        *nums++ = atoi(lines[i+833]);
        *nums++ = atoi(lines[i+834]);
        *nums++ = atoi(lines[i+835]);
        *nums++ = atoi(lines[i+836]);
        *nums++ = atoi(lines[i+837]);
        *nums++ = atoi(lines[i+838]);
        *nums++ = atoi(lines[i+839]);

        *nums++ = atoi(lines[i+840]);
        *nums++ = atoi(lines[i+841]);
        *nums++ = atoi(lines[i+842]);
        *nums++ = atoi(lines[i+843]);
        *nums++ = atoi(lines[i+844]);
        *nums++ = atoi(lines[i+845]);
        *nums++ = atoi(lines[i+846]);
        *nums++ = atoi(lines[i+847]);
        *nums++ = atoi(lines[i+848]);
        *nums++ = atoi(lines[i+849]);

        *nums++ = atoi(lines[i+850]);
        *nums++ = atoi(lines[i+851]);
        *nums++ = atoi(lines[i+852]);
        *nums++ = atoi(lines[i+853]);
        *nums++ = atoi(lines[i+854]);
        *nums++ = atoi(lines[i+855]);
        *nums++ = atoi(lines[i+856]);
        *nums++ = atoi(lines[i+857]);
        *nums++ = atoi(lines[i+858]);
        *nums++ = atoi(lines[i+859]);

        *nums++ = atoi(lines[i+860]);
        *nums++ = atoi(lines[i+861]);
        *nums++ = atoi(lines[i+862]);
        *nums++ = atoi(lines[i+863]);
        *nums++ = atoi(lines[i+864]);
        *nums++ = atoi(lines[i+865]);
        *nums++ = atoi(lines[i+866]);
        *nums++ = atoi(lines[i+867]);
        *nums++ = atoi(lines[i+868]);
        *nums++ = atoi(lines[i+869]);

        *nums++ = atoi(lines[i+870]);
        *nums++ = atoi(lines[i+871]);
        *nums++ = atoi(lines[i+872]);
        *nums++ = atoi(lines[i+873]);
        *nums++ = atoi(lines[i+874]);
        *nums++ = atoi(lines[i+875]);
        *nums++ = atoi(lines[i+876]);
        *nums++ = atoi(lines[i+877]);
        *nums++ = atoi(lines[i+878]);
        *nums++ = atoi(lines[i+879]);

        *nums++ = atoi(lines[i+880]);
        *nums++ = atoi(lines[i+881]);
        *nums++ = atoi(lines[i+882]);
        *nums++ = atoi(lines[i+883]);
        *nums++ = atoi(lines[i+884]);
        *nums++ = atoi(lines[i+885]);
        *nums++ = atoi(lines[i+886]);
        *nums++ = atoi(lines[i+887]);
        *nums++ = atoi(lines[i+888]);
        *nums++ = atoi(lines[i+889]);

        *nums++ = atoi(lines[i+890]);
        *nums++ = atoi(lines[i+891]);
        *nums++ = atoi(lines[i+892]);
        *nums++ = atoi(lines[i+893]);
        *nums++ = atoi(lines[i+894]);
        *nums++ = atoi(lines[i+895]);
        *nums++ = atoi(lines[i+896]);
        *nums++ = atoi(lines[i+897]);
        *nums++ = atoi(lines[i+898]);
        *nums++ = atoi(lines[i+899]);

        *nums++ = atoi(lines[i+900]);
        *nums++ = atoi(lines[i+901]);
        *nums++ = atoi(lines[i+902]);
        *nums++ = atoi(lines[i+903]);
        *nums++ = atoi(lines[i+904]);
        *nums++ = atoi(lines[i+905]);
        *nums++ = atoi(lines[i+906]);
        *nums++ = atoi(lines[i+907]);
        *nums++ = atoi(lines[i+908]);
        *nums++ = atoi(lines[i+909]);

        *nums++ = atoi(lines[i+910]);
        *nums++ = atoi(lines[i+911]);
        *nums++ = atoi(lines[i+912]);
        *nums++ = atoi(lines[i+913]);
        *nums++ = atoi(lines[i+914]);
        *nums++ = atoi(lines[i+915]);
        *nums++ = atoi(lines[i+916]);
        *nums++ = atoi(lines[i+917]);
        *nums++ = atoi(lines[i+918]);
        *nums++ = atoi(lines[i+919]);

        *nums++ = atoi(lines[i+920]);
        *nums++ = atoi(lines[i+921]);
        *nums++ = atoi(lines[i+922]);
        *nums++ = atoi(lines[i+923]);
        *nums++ = atoi(lines[i+924]);
        *nums++ = atoi(lines[i+925]);
        *nums++ = atoi(lines[i+926]);
        *nums++ = atoi(lines[i+927]);
        *nums++ = atoi(lines[i+928]);
        *nums++ = atoi(lines[i+929]);

        *nums++ = atoi(lines[i+930]);
        *nums++ = atoi(lines[i+931]);
        *nums++ = atoi(lines[i+932]);
        *nums++ = atoi(lines[i+933]);
        *nums++ = atoi(lines[i+934]);
        *nums++ = atoi(lines[i+935]);
        *nums++ = atoi(lines[i+936]);
        *nums++ = atoi(lines[i+937]);
        *nums++ = atoi(lines[i+938]);
        *nums++ = atoi(lines[i+939]);

        *nums++ = atoi(lines[i+940]);
        *nums++ = atoi(lines[i+941]);
        *nums++ = atoi(lines[i+942]);
        *nums++ = atoi(lines[i+943]);
        *nums++ = atoi(lines[i+944]);
        *nums++ = atoi(lines[i+945]);
        *nums++ = atoi(lines[i+946]);
        *nums++ = atoi(lines[i+947]);
        *nums++ = atoi(lines[i+948]);
        *nums++ = atoi(lines[i+949]);

        *nums++ = atoi(lines[i+950]);
        *nums++ = atoi(lines[i+951]);
        *nums++ = atoi(lines[i+952]);
        *nums++ = atoi(lines[i+953]);
        *nums++ = atoi(lines[i+954]);
        *nums++ = atoi(lines[i+955]);
        *nums++ = atoi(lines[i+956]);
        *nums++ = atoi(lines[i+957]);
        *nums++ = atoi(lines[i+958]);
        *nums++ = atoi(lines[i+959]);

        *nums++ = atoi(lines[i+960]);
        *nums++ = atoi(lines[i+961]);
        *nums++ = atoi(lines[i+962]);
        *nums++ = atoi(lines[i+963]);
        *nums++ = atoi(lines[i+964]);
        *nums++ = atoi(lines[i+965]);
        *nums++ = atoi(lines[i+966]);
        *nums++ = atoi(lines[i+967]);
        *nums++ = atoi(lines[i+968]);
        *nums++ = atoi(lines[i+969]);

        *nums++ = atoi(lines[i+970]);
        *nums++ = atoi(lines[i+971]);
        *nums++ = atoi(lines[i+972]);
        *nums++ = atoi(lines[i+973]);
        *nums++ = atoi(lines[i+974]);
        *nums++ = atoi(lines[i+975]);
        *nums++ = atoi(lines[i+976]);
        *nums++ = atoi(lines[i+977]);
        *nums++ = atoi(lines[i+978]);
        *nums++ = atoi(lines[i+979]);

        *nums++ = atoi(lines[i+980]);
        *nums++ = atoi(lines[i+981]);
        *nums++ = atoi(lines[i+982]);
        *nums++ = atoi(lines[i+983]);
        *nums++ = atoi(lines[i+984]);
        *nums++ = atoi(lines[i+985]);
        *nums++ = atoi(lines[i+986]);
        *nums++ = atoi(lines[i+987]);
        *nums++ = atoi(lines[i+988]);
        *nums++ = atoi(lines[i+989]);

        *nums++ = atoi(lines[i+990]);
        *nums++ = atoi(lines[i+991]);
        *nums++ = atoi(lines[i+992]);
        *nums++ = atoi(lines[i+993]);
        *nums++ = atoi(lines[i+994]);
        *nums++ = atoi(lines[i+995]);
        *nums++ = atoi(lines[i+996]);
        *nums++ = atoi(lines[i+997]);
        *nums++ = atoi(lines[i+998]);
        *nums++ = atoi(lines[i+999]);
    }

    // rest of entries
    if (i < nlines) {
        for (register unsigned i = 0; i < nlines; ++i){
            *nums++ = atoi(lines[i]);
        }
    }
}
