/*

					
				                                          	                     * * *
				                                        	                   * start *
				                                        	                   *       *	
				                                         	                     * * *
	---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        |                |                      |                               |									                                     |
    **********      **************     ************	                  **********************				       	                           *************************
   | variable;|     | variable++; |   | ++variable; |	             | variable:=expression; |				                                   |   Special Keyword      |
    **********      **************     ************	                  **********************				      	                            *************************
         \		          |	           /                                /          	       \						                          /            |            \
	      \		          |	          /                                /                    \					                             /             |             \
	       \              |		     /	                              /	                     \					                            /              |              \
	        \	          |	        /			                     /                        \			               *********************** ************************  *****************
	         **********************		              ********************                   ***********************   | Special Keyword(){} || SpecialKeyword var|int | |SpecialKeyword |
	         |	                  |                   | with parentheses |                   | without parentheses |   *********************** ************************  *****************
	         |Endofline check and |			          ********************	                 ***********************
	         |	                  |			            /      \				                 /           \
	         ********************** 		           /	    \				                /	          \
					                   ****************     ********************   	****************      ********************
				                      | with variable |    | without variable |   	| with variable |     | without variable |
					                  *****************    ********************   	*****************     ********************
						                        \		      /			                   |                 /     |        \
							                     \ 	    	 /			                   |		        /      |         \
							                  **********************		      ******************   ********* *********** ***********
							                  | Remove parentheses |              | Remove variable|   | Error | | Integer | | String  |
							                   **********************		      ******************   ********* *********** ***********		
								                        |			               /       |        \       
						                    **************************   *********    ***********   ***********           
						                    |Make inside the brackets|   | Error |    | Integer |   | String  |
						                     **************************  *********    ***********   ***********	
						                      /        |           \
							                 /         |            \
						                    /          |             \
				                     *********    ***********   ***********
				                     | Error |    | Integer |   | String  |
	                                 *********    ***********   ***********	








//When the code read is analyzed lexicallyand passed successfully, it enters the syntax code.Syntax code has the tree structure specified aboveand the working logic of this tree structure is explained below.
//It represents the beginning of the code in the given tree structure (start). There are basically 5 situations we might encounter when starting to write any line (or code) of code:
//1.variable; -> In this case, it means that not initialize has been made in the written variable and only the existence of this variable has been defined in the code.
//2.variable++(--);->In this case, it may be increased or decreased provided that it is a variable integer previously defined in the code.
//3. (-) ++variable->In the case shown, it is started with an operator, not a variable, and if the specified variable is integer, changes can be made on the variable without any problem.
//4.variable: = term -> In this case, a value change is made on the defined variable. At this point, the type of the variable should be determined. While determining this type, make sure that the statement next to it is correct.
//We can say that the 4th stage is a very complicated stage. At this stage, the term variety we have is quite high. As seen in the tree above, term varieties can be basically divided into two, with and without parentheses.
//Even if we divide term types into two at the 4th stage, it still has a diversity within itself.
//If a term in the 4th stage contains parentheses in itself: it is checked whether it contains variable or not.
//In the 4th stage, if there is variable depending on this, control of each data is provided without removing the parentheses, it is decided which type the variable has. After this decision, the parentheses are removed.
//As a result of removing the parentheses, the variable type of the expression is decided. It can have 3 types: Integer, String or Error (It can be using String and Integer together or using an undefined variable in it.).
//Another type in the 4th stage is a term with brackets and no variables: In that case, the parentheses can be removed directly. Here, the parentheses only provide process priority for us, but the result of the process is not important in the design.
//Here, when the parentheses are removed, the remaining operations are checked and as a result, the variable type of the expression is decided. It can have 3 types: Integer, String or Error (It may be using String and Integer together or using an undefined variable in it.).
//If a term in stage 4 does not contain parentheses in itself : We can divide it again into two : term with Variable and without Variable.
//If a term in stage 4 contains variable and without a parenthesis, the variable in term is parsed and the action will be made as if the variable does not exist.
//At this point, even when there is no variable, term is scanned within itself againand can have 3 kinds of output : String, Integer or Error.
//The 5th stage is the start with specialkeyword. In this case, special keywords recognized by our language were determined and some conditions were written by creating various groups on the determined keywords.

//Okunan kod lexical olarak analiz edildi??inde ve ba??ar??l?? ile ge??ti??inde syntax koduna girmektedir. Syntax kodu yukar??da belirlenen a??a?? yap??s??na sahiptir ve a??a????da bu a??a?? yap??s??n??n ??al????ma mant?????? a????klanmaktad??r.
//Verilen a??a?? yap??s??ndaki (start) kodun ba??lang??c??n?? temsil etmektedir. Herhangi bir kod sat??r??(veya kodu) yazmaya ba??larken kar????labilece??imiz temelde 5 durum bulunmaktad??r: 
//1.variable; --> Bu durumda tan??mlanan de??i??kenin i??erisinde herhangi bir tan??mlanma yap??lmam???? ve yaln??zca bu de??i??kenin varl?????? kod i??erisinde tan??mlanm???? durumdad??r.
//2.variable++(--); --> Bu durumda ise ??nceden kod i??erisinde tan??mlanm???? olan bir variable integer olmak ko??ulu ile artt??r??lm???? veya azalt??lm???? olabilir.
//3.(--)++variable --> G??sterilen durumda bir variable ile de??il bir operator ile ba??lanm???? ve belirlenen de??i??kenin integer olmas?? durumunda herhangi bir sorun olmadan de??i??ken ??zerinde de??i??iklik yap??labilir.
//4.variable:=term --> Bu durumda tan??mlanan variable ??zerinde de??er de??i??ikli??i yap??lmaktad??r. Bu noktada variable'??n tipi belirlenmelidir. Bu tip belirlenirken, yan??ndaki term do??rulu??undan emin olunmal??d??r.
//4. a??ama olduk??a kar??????k bir a??amad??r diyebiliriz. Bu a??amada elimizde ki term ??e??itli??i olduk??a fazlad??r. Yukar??da tree de de g??r??ld?????? ??zere term ??e??itleri: parantezli ve parantezsiz olarak temelde ikiye ayr??labilir.
//4. a??amada term ??e??itlerini temelde ikiye ay??rsakta asl??nda halen kendi i??erisinde bir ??e??itlili??e sahiptir. 
//4. a??amadaki bir term e??er kendi i??erisinde parantez bar??nd??r??yorsa: i??erisinde variable bulunduruyor mu yoksa bulundurmuyor mu kontrol?? yap??l??r.
//4. a??amada buna ba??l?? olarak variable bulunuyor ise parantezler kald??r??lmadan her bir verinin kontrol?? sa??lan??r variable hangi tipe sahipmi?? karar verilir. Bu karar??n ard??ndan parantezler kald??r??l??r.
//Parantezlerin kald??r??lmas?? sonucunda da term'??n de??i??ken tipine karar verilir.3 tipe sahip olabilir: Integer , String veya Error(String ve Integer'??n birlikte kullan??lmas?? veya i??erisinde tan??mlanmam???? variable kullan??m?? olabilir.).
//4. a??amadaki bir di??er tip ise yine paranteze sahip olup variable bulundurmayan bir term: O halde parantezler do??rudan kald??r??labilir. Burada parantezler bizim i??in yaln??zca i??lem ??nceli??i sa??lar fakat yap??lan tasar??mda i??lemin sonucu ??nem te??kil etmemektedir.
//Burada parantezler kald??r??ld????nda kalan i??lemler kontrol edilir ve sonucunda da term'??n de??i??ken tipine karar verilir.3 tipe sahip olabilir: Integer , String veya Error(String ve Integer'??n birlikte kullan??lmas?? veya i??erisinde tan??mlanmam???? variable kullan??m?? olabilir.).
//4. a??amadaki bir term e??er kendi i??erisinde parantez bar??nd??rm??yorsa: Bunu da yeniden ikiye ay??rabiliriz: Variable i??eren ve Variable i??ermeyen term.
//4. a??amadaki bir term parantessiz ve variable i??eriyorsa: term i??erisindeki variable ayr????t??r??larak variable yokmu?? gibi i??lem yap??lacak hale getirilir.
//Bu noktada variable olmad??????nda da term yeniden kendi i??erisinde taran??r ve 3 ??e??it ????kt??ya sahip olabilir: String, Integer veya Error.
//5. A??ama ise specialkeyword ile ba??lama durumudur. Bu durumda dilimizin tan??d?????? special keywordler belirlenmi?? ve belirlenen keywordler ??zerine ??e??itli gruplar olu??turularak baz?? ko??ullar yaz??lm????t??r.

//Error 1:  Command Line is not open
//Error 2:  Command Line is not close 
//Error 3:  More than two consecutive operator is detected.
//Error 4:  The known operators are : ++, -- ,+,-,*,/,:=. The operand is not known by the Ceng Analyzer! --->
//Error 5:  A variable size cannot exceed twenty
//Error 6:  The number of digits that a number can have must be less than ten.
//Error 7:  Unknown character detected.
//Error 8:  String can not be null.
//Error 9:  Command Line is not finished.
//Error 10: Operand := expected.
//Error 11: Brackets are not correctly open or close.
//Error 12: The code can not start with endofline
//Error 13: The code must bu end with an end of line chracter (;).
//Error 14: The variable can use together with only three operator: := , ++ ,-- "
//Error 15: The operator must use with variable.
//Error 16: The operator must use with variable and variable must be Integer. 
//Error 17: The code can be start with an two operator: ++ , --.
//Error 18: Expression is not correctly design.
//Error 19: Expression include mismatch data type(s).
//Error 20: Unknown (or Object) data types can not be used in expression.
//Error 21: Variable declareted before int , it can not be redefined differant data type.
//Error 22: Special data types(long , char ... ) use with a variable name.
//Error 23: Special data types(long , char ... ) must be end with an endofline (;)

*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define FINISH -2
#define OPERATOR 1
#define LETTER 2
#define DIGIT 3
#define ENDOFLINE 4
#define BRACKET 5
#define UNKNOWN 6
#define STRING 7
#define INTEGER 8
#define VARIABLE 9
#define SPECIALKEYWORD 10
#define COMMENT 11
#define OBJECT 12

bool programFinish = false;
bool specialWordGroup1Flag = false;
bool returnStateController = false;
char input[4096];
int programCounter = 0;
char tempBuffer[30];
char currentChar;
int currentCharClass;
char str[1024];
int printCounter = 0;
char *errorMessage;

/////////////////////////////////////// GENERAL FUNCTIONS START \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/
//Bu struct yap??s?? kendi okudu??umuz de??i??kenlerin tiplerini(String,Integer,Object,Operator,...) ve i??erisindeki veriyi korumak amac??yla yaz??lm????t??r.
struct Object
{
    int itemClass;
    char data[1024];
};
//TwoArrayCopy ald?????? source array'ini destiantion arrayine e??itleyerek source i??erisinde bulunan t??m verilerin destination da da bulunmas??n?? sa??lar.

void TwoArrayCopy(struct Object *destination, struct Object *source, int l1)
{

    for (int i = 0; i < l1; i++)
    {
        destination[i] = source[i];
    }
    struct Object o;
    o.itemClass = FINISH;
    destination[l1] = o;
}
/////////////////////////////////////// GENERAL FUNCTIONS FINISH ////////////////////////////////////////

////////////////////////////////////// STORAGE OF PARSED VARIABLES START   \\\\\\\\\\\\\\\\\\\\\\\\\\\\\/
//Kod i??erisindeki her karakteri okuyup t??rlerine karar verdikten sonra her t??r?? i??erisinde saklad??????m??z array.
struct Object analysisArray[2048];
int analysisArrayIndex = 0;
//??nceden tan??mlanm???? de??i??kenleri saklad??????m??z array
struct Object knownVariable[256];
int knownVariableIndex = 0;
//Belirlenmi?? t??rlerin anaysisArray i??erisine atmak i??in kulland??????m??z fonksiyon. T??r??n?? ve verisini kendi i??erisinde saklar
void addSyntaxArray(int itemC, char *var)
{
    //Gelen t??r yarat??l??r ve bu t??r??n tipini ve verisini ald??????m??z parametrelerle g??ncelliyoruz.
    struct Object o;
    o.itemClass = itemC;
    strcpy(o.data, var);
    analysisArray[analysisArrayIndex++] = o;
}
///////////////////////////////////// STORAGE OF PARSED VARIABLES FINISH   \\\\\\\\\\\\\\\\\\\\\\\\\\\\\/

///////////////////////////////////// FILE READ AND DELETE SPACES AND ETC. START  \\\\\\\\\\\\\\\\\\\\\\/

bool spaceFlag = true; // String de??i??kenlerinde bo??luklar?? kald??rmamam??z i??in bu flag ile kontrol sa??l??yoruz
char *code;            // okudu??umuz de??erlerin tutuldu??u k??s??m
void read()
{
    FILE *file = fopen("code.Ceng", "r"); // dosyam??z
    size_t n = 0;
    int c;
    if (file == NULL)
        return NULL; //could not open file
    code = malloc(1000);
    while ((c = fgetc(file)) != EOF)
    {
        if ((char)c == '"')
        {
            spaceFlag = !spaceFlag;
        }
        if (!spaceFlag)
        {
            code[n++] = tolower((char)c); // okurken case sensitive durumundan hepsini k??????k yap??yoruz
        }
        else if ((char)c != '\n') // alt sat??ra inme ve tab bo??luklar?? gibi ??zel karakterlerin olmad?????? durumlar?? eklememiz i??in
        {
            if ((char)c == '\r' || (char)c == '\t')
            {
                code[n++] = ' ';
            }
            else
            {
                code[n++] = tolower((char)c); // okurken case sensitive durumundan hepsini k??????k yap??yoruz
            }
        }
    }
    code[n] = '\0'; // en son dosyan??n bitti??ini anlamam??z i??in null atamas?? yap??yoruz
    // printf("%s", code);  // Okuman??n do??rulu??unu test etmek i??in yorum sat??r??n?? kald??r??n
}
//////////////////////////////////// FILE READ AND DELETE SPACES AND ETC. FINISH  \\\\\\\\\\\\\\\\\\\\\\/

//////////////////////////////////// BRACKET CHECK START  \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/
static char bracketControlArray[256]; // bracker kontrol??n?? kontrol ederken stack mant??????n?? kullan??yoruz bunun i??in de stack olarak bu arrayi tan??mlad??k
static int bracketControlIndex = 0;   // buda stack pointer??m??z
bool bracketFlag = false;             // di??er ??zel durumlarda parantezlerin do??ru yanl???? dizilimlerini kontrol i??in bu de??i??kenler tutuldu
bool equalOperandFlag = false;
/// Burada standart stack yap??s??ndaki pop push peek i??lemleri bulunmakta
int pushBracket(char c)
{
    if (bracketControlIndex < 254)
    {
        bracketControlArray[bracketControlIndex++] = c;
        return 1;
    }
    return 0;
}
int popBracket()
{
    if (bracketControlIndex > 0)
    {
        bracketControlArray[bracketControlIndex--] = '\0';
        return 1;
    }
    return 0;
}
char peekBracket()
{
    return bracketControlArray[bracketControlIndex - 1];
}
int addBracket(char c) // bracket eklerken zaten bracketlar??n e??le??ip e??le??medi??ini kontrol ediyoruz e??er 0 d??nmesi durumunda hata vard??r
{
    switch (c)
    {
    case '(':
        //printf("Left Round Bracket\n");
        return pushBracket(c);

    case ')':
        if (peekBracket() == '(')
        {
            //    printf("Right Round Bracket\n");
            return popBracket();
        }
        return 0;
    case '{':
        //  printf("Left Curly Bracket ");
        return pushBracket(c);
    case '}':
        if (peekBracket() == '{')
        {
            //     printf("Right Curly Bracket \n");
            return popBracket();
        }
        return 0;
    case '[':
        //  printf("Left Square bracket \n");
        return pushBracket(c);
    case ']':
        if (peekBracket() == '[')
        {
            //     printf("Right Square Bracket \n");
            return popBracket();
        }
        return 0;
    }
}

//////////////////////////////////// BRACKET CHECK FINISH \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/

////////////////////////////////////  COMMAND CONTROL CHECK  START   \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/
int openComment = 0;           // komut sat??r??n??n a????lmas?? durumunda say?? bir artmakta bu sayede e??er a????lma tagi == kapanma tagi diye kontrol ederek yorum sat??r??n?? kontrol ediyoruz
int closeComment = 0;          // kapanma tagi sayac??
int checkCommandLine(char *ca) // komut sat??r??nda a????lma ve kapanmalar??n??n do??rulu??unu kontrol ediyoruz.
{
    if (ca == "(*")
    {
        openComment++;
        return 1;
    }
    else
    {
        if (openComment > 0)
        {
            openComment--;
            return 1;
        }
        else
        {
            errorMessage = "Error 1: Command Line is not open , expected : (* !!! \n";
            return 0;
        }
    }
}
//////////////////////////////////// COMMAND CONTROL CHECK  FINISH \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/

///////////////////////////////    LEXICAL ANALYSES STARTS HERE  ///////////////////////////////////////
char getCurrentChar()
{ // okudu??umuz txtyi char by char olarak analiz etti??imiz i??in
    if (code[programCounter] != '\0')
    {
        return code[programCounter++];
    }
    else
        return NULL;
}
int specialKeyword(char *str)
{
    ////////////////// Verilen d??k??mana g??re special keyword ise 1 de??ilse 0 olarak d??nd??r??yoruz.
    if (!strcmp(str, "break") ||
        !strcmp(str, "case") ||
        !strcmp(str, "char") ||
        !strcmp(str, "break") ||
        !strcmp(str, "const") ||
        !strcmp(str, "continue") ||
        !strcmp(str, "do") ||
        !strcmp(str, "else") ||
        !strcmp(str, "enum") ||
        !strcmp(str, "float") ||
        !strcmp(str, "for") ||
        !strcmp(str, "goto") ||
        !strcmp(str, "if") ||
        !strcmp(str, "int") ||
        !strcmp(str, "long") ||
        !strcmp(str, "record") ||
        !strcmp(str, "return") ||
        !strcmp(str, "static") ||
        !strcmp(str, "while"))
    {
        return 1;
    }
    return 0;
}
//Dosya i??erisindeki her bir karakteri ald??????m??z fonksiyondur.
void getChar()
{
    //E??er ald??????m??z karakter null de??ilse tipini bulmaya ??al??????yoruz.
    if ((currentChar = getCurrentChar()) != NULL)
    {
        //A??a????da g??sterilen operat??rlerden biri ise matematiksel operator olabilir veya atama operat??r?? olabilir comment line olabilir veya hatal?? bir yaz??ma sahip olabilir.
        if (currentChar == '+' || currentChar == '-' || currentChar == '*' || currentChar == '/' || currentChar == ':' || currentChar == '=')
        {
            //E??er comment line ise --> *)
            if ((currentChar == '*' && code[programCounter] == ')'))
            {
                if (checkCommandLine("*)"))
                {
                    currentChar = getCurrentChar();
                    currentCharClass = COMMENT;
                }
                else //Comment line hatal?? girildiyse
                {
                    errorMessage = "Error 2: Command Line is not close , expected : *) ! \n";
                    currentChar = '\0';
                    currentCharClass = FINISH;
                }
            }
            else //E??er comment line de??ilse ve := buna e??it ise hatal?? durumlar?? ile birlikte kontrol ediyoruz.
            {
                if (currentChar == ':' && code[programCounter] != '=')
                {
                    equalOperandFlag = true;
                    currentCharClass = FINISH;
                }
                else if (currentChar == '=' && code[programCounter - 2] != ':')
                {
                    equalOperandFlag = true;

                    currentCharClass = FINISH;
                }
                else
                {
                    equalOperandFlag = false;
                    currentCharClass = OPERATOR;
                }
            }
        }
        //String olmas?? durumu
        else if (currentChar == '"')
        {
            currentCharClass = STRING;
        }
        //Bir karakter olup alfabade bulunup bulunmad??????n?? kontrol ediyoruz.E??er do??ruysa harftir.
        else if (isalpha(currentChar))
        {
            currentCharClass = LETTER;
        }
        //Biti?? i??areti
        else if (currentChar == ';')
        {
            currentCharClass = ENDOFLINE;
        }
        //Rakamlardan biri midir bunu kontrol ediyoruz.E??er do??ruysa rakamd??r
        else if (isdigit(currentChar))
        {
            currentCharClass = DIGIT;
        }
        //E??er bracket ise
        else if (currentChar == '(' || currentChar == '{' || currentChar == '[' || currentChar == ')' || currentChar == '}' || currentChar == ']')
        {
            //Comment line olarak girilmi?? olabilir --> (*
            if (currentChar == '(' && code[programCounter] == '*')
            {
                checkCommandLine("(*");
                currentCharClass = COMMENT;
                currentChar = getCurrentChar();
            }
            else //Di??er durumda bir stack arac??l??????yla bracketlar??n do??rulu??u kontrol edilir. E??er bracket say??lar?? ve yap??lar?? do??ruysa bracket olarak d??ner di??er durumda hata mesaj?? g??ndeilir.
            {
                bracketFlag = false;
                if (addBracket(currentChar))
                {
                    currentCharClass = BRACKET;
                }
                else
                {
                    bracketFlag = true;
                    currentCharClass = FINISH;
                }
            }
        }
        //Bilinmeyen durumlard??r.
        else
        {
            currentCharClass = UNKNOWN;
        }
    }
    //Kodun tamamen bitmesi durumudur.
    else
    {
        currentCharClass = FINISH;
    }
}
int bufCounter = 0; // verilen ko??ullar??n (??rne??in integer 10 digit , variable 20 karakter olur gibi ??eylerdeki uzunlu??u analiz etmemiz i??in bu saya?? var)
void addBuffer()
{ /// Okudu??umuz ve analiz etti??imiz k??s??mdakilerin toplu olarak g??sterimi i??in bir buffera eklenmekte
    if (currentChar != '"')
    {
        tempBuffer[bufCounter++] = currentChar;
        if (bufCounter < 30)
        {
            tempBuffer[bufCounter] = '\0';
        }
    }
}
int lexicalAnalyser() // lexial analizi yapt??????m??z fonsiyon
{
    bufCounter = 0;
    int strCounter = 0;
    switch (currentCharClass) //okunan char'??n  hangi classta oldu??unu  swich-case ile kontrol ediyoruz
    {
    case OPERATOR:                           //okunan char OPERATOR ise bu case ??al??????yor
        addBuffer();                         // okunan char'?? addBuffer ile bir arrayde topluyoruz
        getChar();                           //bir sonraki char de??erini okuyoruz
        while (currentCharClass == OPERATOR) //sonras??nda okunan de??erin class?? OPERATOR oldu??u s??rece addBuffer fonsiyonunu ??a????r??p arraya char'?? ekliyoruz.
        {
            addBuffer();
            if (bufCounter > 2) //Operatorler ikiden fazla yanyana gelemez. ??kiyi gr??mesi durumunda hata mesaj?? veriyoruz.
            {

                errorMessage = "Error 3: The known operators are : ++, -- ,+,-,*,/,:=. The operand is not known by the Ceng Analyzer! --> \nMore than two consecutive operator is detected.\n";
                return FINISH;
            }
            getChar();
        }
        //yanyana gelen operator say??s?? iki ise bunlar sadece ++ -- veya := olabilir.Bunun haricinde herhangi iki opeartor yanyana gelirse hata mesaj?? veriyoruz.
        if (strcmp(tempBuffer, "++") && strcmp(tempBuffer, "--") && strcmp(tempBuffer, ":=") && bufCounter == 2)
        {

            errorMessage = "Error 4: The known operators are : ++, -- ,+,-,*,/,:=. The operand is not known by the Ceng Analyzer! --->\n";

            return FINISH;
        }
        addSyntaxArray(OPERATOR, tempBuffer); //Syntax fonsiyonunda kullanmak i??in okunan de??erin class??n?? ve de??erini addSyntaxArray ad??n?? verdi??imiz bir fonsiyon yard??m??yla bir struct array??nda topluyoruz.
        return OPERATOR;
    case LETTER:     //okunan char LETTER ise bu case ??al??????yor
        addBuffer(); // okunan char'?? addBuffer ile bir arrayde topluyoruz
        getChar();   //bir sonraki char de??erini okuyoruz
        // Okunan char letter ise bu variable olaca????ndan i??erisinde say?? veya _ karakteri bulunabilir. Bunda dolay?? okunan char'??n class??n??n LETTER DIGIT veya de??erinin _ olmas?? durumdan d??ng?? devam eder ve charlar arrayde tolan??r
        while (currentCharClass == LETTER || currentCharClass == DIGIT || currentChar == '_')
        {
            addBuffer();
            //variable uzunlu??u 20den fazla olamaz.20'yi ge??mesi durumunda hata mesaj?? veriyoruz.
            if (bufCounter > 20)
            {
                errorMessage = "Error 5: A variable size cannot exceed twenty \n";
                return FINISH;
            }
            getChar();
        }
        //Arrayde toplanan de??eri specialKeyword ad??n?? verdi??imiz fonsiyonda speacial keyword olup olmamad??????n?? kontrol ediyoruz.
        if (specialKeyword(tempBuffer))
        {
            //Eger okunan de??er special keyword ise class?? SPECIALKEYWORD olarak addSyntaxArray fonsiyonuna g??nderiliyor.
            addSyntaxArray(SPECIALKEYWORD, tempBuffer);
            return SPECIALKEYWORD;
        }
        //Eger okunan de??er variable ise class?? VARIABLE olarak addSyntaxArray fonsiyonuna g??nderiliyor.
        addSyntaxArray(VARIABLE, tempBuffer);
        return VARIABLE;

    case DIGIT:                           //okunan char DIGIT ise bu case ??al??????yor
        addBuffer();                      // okunan char'?? addBuffer ile bir arrayde topluyoruz
        getChar();                        //bir sonraki char de??erini okuyoruz
        while (currentCharClass == DIGIT) //sonras??nda okunan de??erin class?? DIGIT oldu??u s??rece addBuffer fonsiyonunu ??a????r??p arraya char'?? ekliyoruz.
        {
            addBuffer();
            //digit say??s?? 10 basamaktan fazla olamaz.E??er 10dan fazla olursa hata mesaj?? veriyoruz.
            if (bufCounter > 10)
            {
                errorMessage = "Error 6: The number of digits that a number can have must be less than ten. \n";
                return FINISH;
            }
            getChar();
        }
        addSyntaxArray(INTEGER, tempBuffer); //Syntax fonsiyonunda kullanmak i??in okunan de??erin class??n?? ve de??erini addSyntaxArray ad??n?? verdi??imiz bir fonsiyon yard??m??yla bir struct array??nda topluyoruz.
        return INTEGER;
    case ENDOFLINE:  //okunan char ENDOFL??NE ise bu case ??al??????yor
        addBuffer(); // okunan char'?? addBuffer ile bir arrayde topluyoruz
        getChar();   //bir sonraki char de??erini okuyoruz
        ///////////////////// BURADA SYNTAX ANAL??Z?? VAR //////////////////////////////////////////
        addSyntaxArray(ENDOFLINE, tempBuffer); //Syntax fonsiyonunda kullanmak i??in okunan de??erin class??n?? ve de??erini addSyntaxArray ad??n?? verdi??imiz bir fonsiyon yard??m??yla bir struct array??nda topluyoruz.
        ///////////////////// BURADA SYNTAX ANAL??Z?? B??T??YOR //////////////////////////////////////////
        return ENDOFLINE;
    case BRACKET:                            //okunan char BRACKET ise bu case ??al??????yor
        addBuffer();                         // okunan char'?? addBuffer ile bir arrayde topluyoruz
        getChar();                           //bir sonraki char de??erini okuyoruz
        addSyntaxArray(BRACKET, tempBuffer); //Syntax fonsiyonunda kullanmak i??in okunan de??erin class??n?? ve de??erini addSyntaxArray ad??n?? verdi??imiz bir fonsiyon yard??m??yla bir struct array??nda topluyoruz.
        return BRACKET;
    case UNKNOWN:               //okunan char UNKNOWN ise bu case ??al??????yor
        if (currentChar == ' ') //Bo??luk karakterinin tan??nmad?????? i??in UNKNOWN olarak tan??mlan??yor.
        {
            getChar();
            while (currentChar == ' ') //okunan char bo??luk oldu??u s??rece tekrar okuyoruz ve bo??l??klar?? ge??mi?? oluyoruz.
            {
                getChar();
            }
            return UNKNOWN;
        }
        else //Di??er t??m bilinmeyen karakterler i??in hata mesaj?? yaz??yoruz.
        {
            errorMessage = "Error 7: Unknown character detected. \n";
            return FINISH;
        }
    case STRING:                                          //okunan char t??rnak i??areti ise (") ise bu case ??al??????yor.
        getChar();                                        //bir sonraki char de??erini okuyoruz
        while (currentChar != '"' && currentChar != '\0') // okunan de??er tekrar t??rnak i??areti ve \0 olmad?????? s??rece getchar fonsiyonu ??al??????yor ve okunan char str array??nda toplan??yor.
        {
            str[strCounter++] = currentChar;
            getChar();
        }
        str[strCounter] = '\0';  //en sona '/0' ekliyoruz
        if (currentChar == '\0') // currentChar null ise hata mesaj?? yazd??r??yoruz.
        {
            errorMessage = "Error 8: String can not be null. \n";
            return FINISH;
        }
        getChar();
        addSyntaxArray(STRING, str); //Syntax fonsiyonunda kullanmak i??in okunan de??erin class??n?? ve de??erini addSyntaxArray ad??n?? verdi??imiz bir fonsiyon yard??m??yla bir struct array??nda topluyoruz.
        return STRING;
    case COMMENT: //okunan char (* ise bu case ??al??????yor.
        addBuffer();
        getChar();
        while (currentCharClass != COMMENT && currentChar != '\0') // *) i??areti gelene veya okunan de??er null olana kadar i??erisindeki de??erler yorum sat??r?? olarak alg??l??yoruz ve ge??iyoruz
        {
            addBuffer();
            getChar();
        }
        addBuffer();
        getChar();
        if (currentChar == '\0') // currentChar null ise hata mesaj?? yazd??r??yoruz.
        {
            errorMessage = "Error 9: Command Line is not finished , expected ';' \n";
            return FINISH;
        }
        return COMMENT;
    case FINISH:              //okunan char hi??bir durumu sa??lamad??????nda class?? FINISH olarak alg??lan??yor .
        if (equalOperandFlag) //e??er := ifadesi olmayan durumlarda hata vermesi i??in
        {
            errorMessage = "Error 10: Operand := expected. \n";
            return FINISH;
        }
        if (bracketControlIndex > 0 || bracketFlag) //parantezin a????l??p kapanmas??nda bir hata varsa hata mesaj?? veriyoruz.
        {
            errorMessage = "Error 11: Brackets are not correctly open or close. \n";
            return FINISH;
        }
        addSyntaxArray(-2, "FINISH"); //Program??m??z lexical analizden ba??ar??yla ge??erse syntax analizi i??in bunu ekliyoruz.
        programFinish = true;         //Syntax analizine girmesi i??in true yap??yoruz.
        return FINISH;
    }
}
///////////////////////////////    LEXICAL ANALYSES FINISH HERE  /////////////////////////////////////////

//////////////////////////////     SYNTAX ANALYSES START HERE ///////////////////////////////
int pushVariable(struct Object o) // Kodu analiz ederken syntax olarak var:45; gibi de??eri analiz etti??imizde altta var'??n bir ifadede kullan??lmas??n?? ve t??r??n?? tutmak i??in buraya ekliyoruz
{
    if (knownVariableIndex < 254)
    {
        knownVariable[knownVariableIndex++] = o;
        return 1;
    }
    return 0;
}
int searchVariable(char *param) // variable ile kar????la??t??????mda daha ??nce ge??ti mi ge??medi mi de??eri t??r?? ne onu bulduruyorum
{
    //return 7 ise string
    //return 8 ise integer
    //return 12 ise Object
    //return 0 ise bulunamad??
    for (int i = 0; i < knownVariableIndex; i++)
    {
        if (!strcmp(knownVariable[i].data, param))
        {
            return knownVariable[i].itemClass;
        }
    }
    return 0;
}
int nextLineAnalysisIndex = 0;
bool bracketExp = false;   // specialkeyword parantazlerini var:= ... ; daki atama parantezlerinden ay??rmay?? kontrol etmek i??in tuttu??umuz de??i??ken
int controlBrackets(int m) /// var :=  .... ; ya da var := .... k??sm??nda ... i??erisinde parantez var m?? yok mu kontrol ediyorum
{
    bracketExp = false; // special keywordlerdeki parantezler ile var:= ... ; daki kullan??lacak parantezlerin kar????mamas??n?? sa??layan flag
    for (int i = m; i < analysisArrayIndex; i++)
    {
        if (specialWordGroup1Flag)
        {
            if (analysisArray[i + 1].itemClass == BRACKET && !strcmp(analysisArray[i + 1].data, "{"))
            {
                nextLineAnalysisIndex = i; // burada var:= .........; ; k??sm?? hangi indexte bitiyor onu g??ncelliyorum!!!!! BURASI A??A??IDAK?? ANAL??ZLERDEK?? nextLineAnalysisIndexi Kontrol etmek i??in ??nemli
                specialWordGroup1Flag = false;
                break;
            }
        }
        if (analysisArray[i].itemClass == ENDOFLINE || analysisArray[i].itemClass == FINISH)
        {
            nextLineAnalysisIndex = i; ///////// burada var:= .........; ; k??sm?? hangi indexte bitiyor onu g??ncelliyorum!!!!! BURASI A??A??IDAK?? ANAL??ZLERDEK?? nextLineAnalysisIndexi Kontrol etmek i??in ??nemli
            break;
        }
        if (analysisArray[i].itemClass == BRACKET && !(strcmp(analysisArray[i].data, ")") && strcmp(analysisArray[i].data, "("))) //var ??n yan??ndaki k??s??mda sadece ) veya ( bu olabilir.
        {
            bracketExp = true;
        }
        if (analysisArray[i].itemClass == BRACKET && (strcmp(analysisArray[i].data, ")") && strcmp(analysisArray[i].data, "("))) //var ??n yan??ndaki k??s??mda sadece ) veya ( bu olabilir.
        {
            return -1;
        }
    }
    if (bracketExp)
    {
        return 1;
    }
    return 0;
}
int expressionBracketsCalculator(int start, int finish)
{
    // var:= ............ ; (var++) (++var+5)
    /// Bu fonksiyonda parantez i??lerindeki var++ gibi de??erlerin yerine do??rudan integer yaz??yoruz e??er bunu yapmaz isek parantezler kalkt??????nda operant hatas?? verir !!
    struct Object checkList[512]; /// Yeniden olu??turaca????m??z i??in (var++) yerine int yazaca????m??z i??in bir array tan??ml??yoruz
    int cI = 0;                   // bu arraye parantezleri ekleyemiyece??imiz i??in eklerkenki indexi ??zel olarak tutuyoruz

    for (int i = start; i < finish; i++)
    {
        /// --var ise
        if (analysisArray[i].itemClass == OPERATOR && !(strcmp(analysisArray[i].data, "++") && strcmp(analysisArray[i].data, "--")) && analysisArray[i + 1].itemClass == VARIABLE && searchVariable(analysisArray[i + 1].data) == INTEGER)
        {
            struct Object o;
            o.itemClass = INTEGER;
            strcpy(o.data, analysisArray[i + 1].data);
            checkList[cI++] = o;
            i = i + 1;
        }
        // var++ ??rne??in
        else if (analysisArray[i].itemClass == VARIABLE && searchVariable(analysisArray[i].data) == INTEGER && !(strcmp(analysisArray[i + 1].data, "++") && strcmp(analysisArray[i + 1].data, "--")))
        {
            struct Object o;
            o.itemClass = INTEGER;
            strcpy(o.data, analysisArray[i].data);
            checkList[cI++] = o;
            i = i + 1;
        }
        else
        {
            checkList[cI++] = analysisArray[i];
        }
    }
    /// ??uan elimizdeki varlar??n ++ veya -- olmas?? durumundan kurtulduk
    struct Object newItems[512];
    int secondIndex = 0;
    for (int i = 0; i < cI; i++)
    {
        if (checkList[i].itemClass != BRACKET)
        {
            newItems[secondIndex++] = checkList[i];
        }
    }
    struct Object backUp[2048];
    TwoArrayCopy(backUp, analysisArray, 2047);
    TwoArrayCopy(analysisArray, newItems, secondIndex);
    int res = expressionCalculator(newItems[0].itemClass, 0, secondIndex);
    if (res)
    {
        TwoArrayCopy(analysisArray, backUp, 2047);
        return 1;
    }
    return 0;
}
int controlVariable(int start, int finish) /// var := ..... ; .... i??erisinde variable var m?? yok mu onu kontrol ediyoruz parse treemiz i??in gerekli
{
    for (int i = start; i < finish; i++)
    {
        if (analysisArray[i].itemClass == VARIABLE)
        {
            return 1;
        }
    }
    return 0;
}
//Bir term kendi i??erisinde do??ru tiplerle mi i??lem yap??yor kontrol ediyoruz.
int expressionCalculator(int firstVariableType, int startIndex, int FinishIndex)
{
    //Operat??r variable integer string mi kotnrol?? i??in gerekli olan de??i??kenimiz.
    int j = 0;
    if (firstVariableType == STRING) // e??er var:= str....; diye gidiyor ise aradaki operatorler sadece + olabilir ve de??i??ken de varsa onun tipi sadece string olabilir
    {
        for (int i = startIndex; i < FinishIndex; i++)
        {
            if (j % 2 == 0 && (analysisArray[i].itemClass != STRING || (analysisArray[i].itemClass == VARIABLE && searchVariable(analysisArray[i].data) == STRING)))
            {
                return 0;
            }
            else if (j % 2 == 1 && strcmp(analysisArray[i].data, "+"))
            {
                return 0;
            }
            j++;
        }
        /////Burada o variablenin analizinde bir sorun yok ise ve analiz do??ru ise o de??i??ken var:= .. ; do??ru tan??mlanm????t??r ve bilinen de??i??kenlere eklenir.
        struct Object o = analysisArray[startIndex - 2];
        o.itemClass = STRING;
        pushVariable(o);
        return 1;
    }
    else if (firstVariableType == INTEGER)
    {
        //burada j ??ift say?? ise biliyorum ki bir variable veya integer de??i??ken olmal??d??r. e??er tek say?? ise operat??r olmal??d??r.
        for (int i = startIndex; i < FinishIndex; i++)
        {
            //e??er ??ift say??ysa j ve operat??r harici bir ??eyse hata vermelidir.
            if (j % 2 == 0 && (analysisArray[i].itemClass != INTEGER && analysisArray[i].itemClass != VARIABLE))
            {
                return 0;
            }
            //// e??er var:= int....; diye gidiyorsa ben biliyorum ki benim variable de??i??kenimin tipi mutlaka integer olmal??d??r.
            if (j % 2 == 0 && analysisArray[i].itemClass == VARIABLE && searchVariable(analysisArray[i].data) != INTEGER)
            {
                return 0;
            }
            //A??a????da belirtilen operat??rler harici herhangi ba??ka bir operat??r bulunamaz.
            else if (j % 2 == 1 && strcmp(analysisArray[i].data, "+") && strcmp(analysisArray[i].data, "-") && strcmp(analysisArray[i].data, "*") && strcmp(analysisArray[i].data, "/"))
            {
                return 0;
            }
            //++ ve -- durumun var ise variable??n t??r??ne bak??lmaktad??r.
            else if (j % 2 == 1 && !(strcmp(analysisArray[i].data, "++") || !strcmp(analysisArray[i].data, "--")) && (searchVariable(analysisArray[i - 1].data) != INTEGER || analysisArray[i + 1].itemClass != ENDOFLINE))
            {
                return 0;
            }
            j++;
        }
        /////Burada o variablenin analizinde bir sorun yok ise ve analiz do??ru ise o de??i??ken var:= .. ; do??ru tan??mlanm????t??r ve bilinen de??i??kenlere eklenir.
        struct Object o = analysisArray[startIndex - 2];
        o.itemClass = INTEGER;
        pushVariable(o);
        return 1;
    }
    //E??er integer ve string harici her hangi bir de??i??ken term i??erisinde bulunuyorsa hata veriyoruz.
    else if (firstVariableType != INTEGER && firstVariableType != STRING)
    {
        return 0;
    }
}

int specialWordGetGroup(char *param) // Special keywordleri bu ??ekilde kurallar??na g??re pars edece??imiz i??in hangi grupta oldu??unu buldurdu??umuz k??s??m
{
    /*
    Grup 1:
        if(){}
        while(){}
        for(){}
    Grup 2:
        break;
        goto;
        continue;
    Grup 3:
        int varName;
        long varName
        record varName
        char varName; 
        float varName;
        enum varName;
        const  varName;
        static varName;
    Group 4:
        return varName;
        return int | string;
    Group 5: 
        do ()
        else()
    Non Group 6:
        case;
    */
    if (!strcmp(param, "if") || !strcmp(param, "while") || !strcmp(param, "for"))
    {
        return 1;
    }
    else if (!strcmp(param, "break") || !strcmp(param, "goto") || !strcmp(param, "continue"))
    {
        return 2;
    }

    else if (!strcmp(param, "int") || !strcmp(param, "long") || !strcmp(param, "record") || !strcmp(param, "char") || !strcmp(param, "float") || !strcmp(param, "enum") || !strcmp(param, "const") || !strcmp(param, "static"))
    {
        return 3;
    }
    else if (!strcmp(param, "return"))
    {
        return 4;
    }
    else if (!strcmp(param, "do") || !strcmp(param, "else"))
    {
        return 5;
    }
    else
    {
        return 6;
    }
}

char *getBracketNamet(char c) // bracket eklerken zaten bracketlar??n e??le??ip e??le??medi??ini kontrol ediyoruz e??er 0 d??nmesi durumunda hata vard??r
{
    switch (c)
    {
    case '(':
        return "Left Round Bracket\n";
    case ')':
        return "Right Round Bracket\n";
    case '{':
        return "Left Curly Bracket\n";
    case '}':
        return "Right Curly Bracket \n";
    case '[':
        return "Left Square Bracket \n";
    case ']':
        return "Right Square Bracket \n";
    }
}

int checkSyntax()
{
    //Lexical anayze fonksiyonunda Belirlenmi?? olan arrayin t??m lengthini buldu??umuz k??s??m.
    int lenghtofAll = sizeof(analysisArray) / sizeof(analysisArray[0]);
    //Analyze index i??erisinde bulunan her bir t??r?? al??yoruz ve belirlenen fonksiyonlar ar??c??????????yla kontrol ediyoruz.
    for (int i = 0; i < lenghtofAll; i++)
    {
        printCounter = i;
        //Kodun tamamen bitmesi durumu burada yaz??lm????t??r hem syntax hem de lexical olarak do??ru bir ??ekilde analiz edilmi??tir.
        if (!strcmp(analysisArray[i].data, "FINISH"))
        {
            break;
        }
        /////////////////////////////////////////// Kodumuzun ba??layabilece??i durumlar: ++var,var++,var; var:=, spec ///////////////////////////////////
        //!!!!!!!!!!!!!!!!!!!!!!e??er kodun en ba????ysa veya } bunun yan??ndaysa veya ; bunun yan??ndaysa en ba??ta say??labilir.

        int previusItemClass = analysisArray[i - 1].itemClass;
        int currentItemClass = analysisArray[i].itemClass;
        int nextItemClass = analysisArray[i + 1].itemClass;

        /////////////////////////////////////////// BEL??RT??LEN BA??LANGI??LARIN KONTROL??: ++var,var++,var;  BURADA BA??LIYOR ///////////////////////////////////
        //Kodun veya sat??r??n ba??lang??c??ysa anlam??na gelmektedir.
        if (i == 0 || (i > 0 && (previusItemClass == ENDOFLINE || !strcmp(analysisArray[i - 1].data, "}"))))
        {
            //var; -> B??yle bir durumda variable object kabul edilerek knownvariable i??erisine eklenmektedir.
            if (currentItemClass == VARIABLE && nextItemClass == ENDOFLINE)
            {
                struct Object o;
                o = analysisArray[i];
                o.itemClass = OBJECT;
                pushVariable(o);
                i = i + 1;
            }
            //E??er special bir keyword yok veya variable ile ba??lam??yorsa yine de endofline var ise hata vermelidir.
            if (currentItemClass != SPECIALKEYWORD && currentItemClass != VARIABLE && nextItemClass == ENDOFLINE)
            {
                errorMessage = "Error 12: The code can not start with endofline \n";
                return 0;
            }
            //variable ile ba??l??yor sonras??nda operat??r gelmi?? ve bu operat??r e??er := ise ve sonunda endofline bulunmuyorsa hata vermelidir.
            else if (currentItemClass == VARIABLE && nextItemClass == OPERATOR && strcmp(analysisArray[i + 1].data, ":=") && analysisArray[i + 2].itemClass != ENDOFLINE)
            {
                errorMessage = "Error 13: The code must bu end with an end of line chracter (;). \n";
                return 0;
            }
            //variable ile ba??lam???? ve sonraki oprat??rler: := , ++ , -- bunlardan farkl?? ise hata vermelidir.
            else if (currentItemClass == VARIABLE && nextItemClass == OPERATOR && strcmp(analysisArray[i + 1].data, ":=") && analysisArray[i + 2].itemClass == ENDOFLINE && strcmp(analysisArray[i + 1].data, "++") && strcmp(analysisArray[i + 1].data, "--"))
            {
                errorMessage = "Error 14: The variable can use together with only three operator: := , ++ ,-- \n";
                return 0;
            }
            //E??er ??uanda operat??r ise ve yan??dnda variable harici bir ??ey bulunuyorsa hatal??d??r.
            else if (currentItemClass == OPERATOR && nextItemClass != VARIABLE)
            {
                errorMessage = "Error 15: The operator must use with variable. \n";
                return 0;
            }
            //E??er operat??r ile ba??lam???? varibale olmas??na ra??men tipi integer harici bir de??i??ken ise hata vermektedir.
            else if (currentItemClass == OPERATOR && nextItemClass == VARIABLE && searchVariable(analysisArray[i + 1].data) != INTEGER)
            {
                errorMessage = "Error 16: The operator must use with variable and variable must be Integer. \n";
                return 0;
            }
            //Operat??r ile ba??lam???? ve variable do??ru gelmi?? end of line ile bitmemi?? ise hata vermelidir.
            else if (currentItemClass == OPERATOR && nextItemClass == VARIABLE && searchVariable(analysisArray[i + 1].data) == INTEGER && analysisArray[i + 2].itemClass != ENDOFLINE)
            {
                errorMessage = "Error 13: The code must bu end with an end of line chracter (;). \n";
                return 0;
            }
            //operat??r ile ba??lam???? ve variable do??ru ise endofline ile bitmi??se ama operat??rler ++ veya -- den farkl?? ise hata vermelidir.
            else if (currentItemClass == OPERATOR && nextItemClass == VARIABLE && searchVariable(analysisArray[i + 1].data) == INTEGER && analysisArray[i + 2].itemClass == ENDOFLINE && strcmp(analysisArray[i].data, "++") && strcmp(analysisArray[i].data, "--"))
            {
                errorMessage = "Error 17: The code can be start with an two operator: ++ , --. \n";
                return 0;
            }
        }
        /////////////////////////////////////////// BEL??RT??LEN BA??LANGI??LARIN KONTROL??: ++var,var++,var;  BURADA B??T??YOR ///////////////////////////////////

        // var=; i??in yap??lan kontrolleri i??eriyor. variable ??n??ne int special key word alabilir. Bu if blo??u bunu da kontrol ediyor.specialWordGroup1Flag , returnStateController flaglerini ise returnden sonra gelen veya if for veya while yap??s??n??n parantezi i??erisindeki yaz??m??n do??rulu??unu kontrol etmek i??in kullan??yoruz.
        if (specialWordGroup1Flag || returnStateController || (currentItemClass == VARIABLE && !strcmp(analysisArray[i + 1].data, ":=") && (i == 0 || (i > 0 && (previusItemClass == ENDOFLINE || !strcmp(analysisArray[i - 1].data, "int") || !strcmp(analysisArray[i - 1].data, "}"))))))
        {
            int lineStart = i + 2;                    /// var:= dan sonra ki ilk gelen char??n indexini lineStart de??i??keninde sakl??yoruz.
            int phranthases = controlBrackets(i + 2); /// var:= den sonra gelen ilk k??s??mdan itibaren ENDOFLINE g??rene kadar parantez olup olmad?????? kontrol ediliyor ve ENDOFLINE g??r??len yerin indexi nextLineAnalysis ile tutuluyor.
            if (phranthases == -1)                    // parantez kontrol?? yaparken e??er hatal?? bir durum varsa -1 d??n??yoruz  bu durumda  hata mesaj?? yaz??yoruz.
            {
                errorMessage = "Error 11: Brackets are not correctly open or close. \n";
                return 0;
            }
            if (phranthases) // var := den sonra parantez var ise  1 d??n??yoruz ve bu if blo??u ??al??????yor.
            {
                int isThereVariable = controlVariable(lineStart, nextLineAnalysisIndex); // var := den sonra ,yani lineStart ve nextLineAnalysisIndex aras??nda variable var ise 1 yok ise 0 d??n??yoruz.
                if (isThereVariable)                                                     // E??er parantez var ise bu if blo??u ??al??????yor
                {
                    int res = expressionBracketsCalculator(lineStart, nextLineAnalysisIndex); // Variablelar??n t??rlerinin kontrollerinin yap??ld?????? ve t??m parantezlerin kontrollerinin yap??ld?????? fonsiyondur.E??erki i??lem i??erisinde ayn?? t??rde olmayan variableler veya farkl?? bir t??rler aras?? i??em var ise 0 d??n??yoruz. Yok ise do??ru kbul edip 1 d??n??yoruz.
                    if (res != 1)                                                             //0 d??nm???? ise hatal??d??r. Hata mesaj?? yaz??yoruz.
                    {
                        errorMessage = "Error 18: Expression is not correctly design.  \n";
                        return 0;
                    }

                    i = nextLineAnalysisIndex; // ENDOFL??NE a kadar kontrol edildi??i i??in gelinen indexi i'ye e??itliyoruz.
                }
                else //E??er variable i??ermiyorsa else blo??u ??al??????yor.
                {    // Parantezli ve variables??z yap??lar oldu??u i??in parantezleri kald??rarak kontrolleri yap??yoruz
                    struct Object backup[2048];
                    TwoArrayCopy(backup, analysisArray, 2047); // Parantezleri kad??rmadan ??nce t??m yap??lar??n i??inde bulundu??u analysisArray'??n yede??ini al??yoruz.
                    struct Object newItems[512];               // parantezlerin kald??r??lm???? halini newItems arrayi i??erisinde topluyoruz.
                    int f = 0;
                    for (int k = lineStart; k < nextLineAnalysisIndex; k++) //Parantezlerin kald??r??larak newItems i??erisinde topland?????? k??s??m.
                    {

                        if (analysisArray[k].itemClass != BRACKET) // bracketlar?? kald??r??yorum var:= ..... ; / ... olan yerdeki bracketlar?? kald??rd??m
                        {
                            newItems[f] = analysisArray[k];
                            f = f + 1;
                        }
                    }
                    TwoArrayCopy(analysisArray, newItems, 511);              //Parantezleri kald??r??lm???? halini tutan array?? analysisArray'a kopyal??yoruz.
                    int firstVariableType = analysisArray[2].itemClass;      // var := sonra gelen ilk yap??n??n hangi classta oldu??unu firstVariableType ad??ndaki de????kende tutuyoruz.
                    int res = expressionCalculator(firstVariableType, 2, f); // Bu fonksiyon ile var := sonraki i??lemlerin tamam??n??n ayn?? t??rler aras??nda yap??l??p yap??lmad??????n?? kontrol ediyoruz e??er ayr?? t??rler aras??nda yap??lan bir i??lem var ise ( ??rne??in "aa"+2) 0 d??n??yoruz.E??er hata yok ise 1 d??n??yoruz.
                    if (res)                                                 // e??er d??nen de??er 1 ise hata yoktur
                    {
                        i = nextLineAnalysisIndex; // var:= .... ; ... k??sm??n?? analiz etti??im i??in atl??yorum ve endoflin??n oldu??u yere geldim
                    }
                    else // 0 d??n??yorsa hata vard??r ve hata mesaj?? yaz??yoruz.
                    {
                        errorMessage = "Error 19: Expression include mismatch data type(s). \n";
                        return 0;
                    }
                    TwoArrayCopy(analysisArray, backup, 2047); // Yukar??da analsisArrayin tamam??n?? backup array??na kopyalay??p saklam????t??k.????lemler bittikten sonra tekrar AlaysisArraya geri kopyal??yoruz.
                }
            }
            else /// var:= yap??s??ndan sonra ENDOFL??NE a kadar parantez yok ise else blo??u ??al??????yor.
            {
                int isThereVariable = 0;
                isThereVariable = controlVariable(lineStart, nextLineAnalysisIndex); // var:= yap??s??ndan sonra variable i??erip i??ermedi??ini kontrol ediyoruz.

                if (analysisArray[nextLineAnalysisIndex].itemClass == FINISH) // e??er var :=; ??eklinde bir yap?? varsa hatal?? bir yaz??md??r.Hata mesaj?? veriyoruz.
                {
                    errorMessage = "Error 13: The code must bu end with an end of line chracter (;). \n";
                    return 0;
                }

                if (isThereVariable) // E??er variable var ise if blo??u ??al??????yor.
                {
                    int firstVariableType;
                    if (analysisArray[lineStart].itemClass == VARIABLE) // E??er var:= sonra gelen ilk yap?? variable ise  bu variable'??n class??n?? (Satring variable m?? integer variable m?? object variable m?? yoksa hi??bir bilgi yok mu) konrol ediyoruz.
                    {
                        firstVariableType = searchVariable(analysisArray[lineStart].data);
                        if (firstVariableType == OBJECT || firstVariableType == 0) //E??er object ise veya class?? belli de??ise herhangi bir i??eme dahil olamayaca????ndan hata mesaj?? yaz??yoruz.
                        {
                            errorMessage = "Error 20: Unknown (or Object) data types can not be used in expression. \n";
                            return 0;
                        }
                    }
                    else //e??er var:= sonra gelen ilk yap?? variable de??ilse else blo??u ??al??????yor.
                    {
                        firstVariableType = analysisArray[lineStart].itemClass; // Bu yap??n??n hangi classta oldu??unu kontrol ediyoruz.
                    }
                    int res = expressionCalculator(firstVariableType, lineStart, nextLineAnalysisIndex); // var := den sonra gelen ilk yap??n??n class?? bilindikten sonra i??leme dahil olan yap??lar??n tamam??n??n ayn?? classtan olup olmad??????n?? kontrol ediyoruz.
                    if (res)                                                                             //e??er hepsi ayn?? t??r ise 1 herhangi bir hata yoktur.
                    {
                        i = nextLineAnalysisIndex; // tekrardan var:= ... ; ... k??sm??n?? atlat??yorum
                    }
                    else //E??er 0 d??ner ise farkl?? t??rler aras?? i??lem yap??lmaya ??al??????ld?????? anla????laca????ndan hata mesaj?? yaz??yoruz.
                    {
                        errorMessage = "Error 19: Expression include mismatch data type(s). \n";
                        return 0;
                    }
                }
                else // E??er var:= yap??s?? parantez ve variable i??ermiyorsa else blo??u ??al??????r.
                {
                    int firstVariableType = analysisArray[lineStart].itemClass;                                       // var := sonra gelen ilk yap??n??n hangi classta oldu??unu belirliyoruz.
                    if (searchVariable(analysisArray[lineStart - 2].data) == INTEGER && firstVariableType != INTEGER) //E??er i??ine atama yapaca????m??z variable (var := ??eklinde belirtti??imiz k??s??m) ineteger bir variable ise := yap??s??ndan sonra gelen yap??da integer olmak zorunda .E??er integer olan bir variable'a farkl?? t??rden bir atama yap??l??yorsa hata verir.
                    {
                        errorMessage = "Error 21: Variable declareted before int , it can not be redefined differant data type . \n";
                        return 0;
                    }
                    int res = expressionCalculator(firstVariableType, lineStart, nextLineAnalysisIndex); //  var := den sonra gelen ilk yap??n??n class?? bilindikten sonra i??leme dahil olan yap??lar??n tamam??n??n ayn?? classtan olup olmad??????n?? kontrol ediyoruz.
                    if (res)                                                                             //e??er hepsi ayn?? t??r ise 1 herhangi bir hata yoktur.
                    {
                        i = nextLineAnalysisIndex; // tekrardan var:= ... ; ... k??sm??n?? atlat??yorum
                    }
                    else //E??er 0 d??ner ise farkl?? t??rler aras?? i??lem yap??lmaya ??al??????ld?????? anla????laca????ndan hata mesaj?? yaz??yoruz.
                    {
                        errorMessage = "Error 19: Expression include mismatch data type(s). \n";
                        return 0;
                    }
                }
            }
        }
        returnStateController = false;
        //??ncelikle yeni bir sat??r??n ba??lamas?? i??in ya kodun en ba???? olmas?? laz??m ya ENDOFLINE'dan sonra ba??layan k??s??m olmas?? laz??m ya da '}' yap??s??ndan sonra ba??lyan k??s??m olmal?? bu durumlar haricindeki durumlar hatal??d??r.
        if (i == 0 || (i > 0 && (analysisArray[i - 1].itemClass == ENDOFLINE || !strcmp(analysisArray[i - 1].data, "}"))))
        { //S??radaki yap?? special keyword ise bu if blo??u ??al??????yor.
            if (analysisArray[i].itemClass == SPECIALKEYWORD)
            {
                int groupID = specialWordGetGroup(analysisArray[i].data); //Special keywordlari benzerlikleri a????s??ndan gruplara ay??rd??k. ??lk ??nce special keyword??n hangi gropta oldu??unu belirliyoruz.
                if (groupID == 3)                                         // E??er groupID 3 ise special keyword int,long,record,char,float,enum,const veya static olabilir. Bu special keywordlerin yan??na sadece variable ismi gelebilir.
                {
                    if (analysisArray[i + 1].itemClass != VARIABLE) //e??er bu special keywordlerin yan??na gelen yap?? variable de??ilse hatal?? yaz??m mevcuttur.Hata mesaj?? yaz??yoruz.
                    {
                        errorMessage = "Error 22: Special data types(long , char ... ) use with a variable name. \n";
                        return 0;
                    }
                    else                                           //e??er yan??nda variable varsa else blo??u ??al??????r.
                    {                                              // Variable var long var1; gibi
                        if (!strcmp(analysisArray[i].data, "int")) //E??er special keyword int ise yan??na gelen variable da integer variable ya da class?? olmayan bir variable olmal?? .Yani ??rene??in ??nceden string olarak tan??mlanm???? bir variable??n ba????na int yaz??lamaz.
                        {
                            if (searchVariable(analysisArray[i + 1].data) != INTEGER && searchVariable(analysisArray[i + 1].data) != 0) //e??er variable??n class?? INTEGER veya class??z de??ilse hatal?? bir yaz??md??r.Hata mesaj?? veriyoruz.
                            {
                                errorMessage = "Error 13: The code must bu end with an end of line chracter (;). \n";
                                return 0;
                            }
                            else //e??er integer veya class??z ise class??n?? INTEGER olarak g??ncelliyoruz.
                            {
                                struct Object o;
                                strcpy(o.data, analysisArray[i + 1].data);
                                o.itemClass = INTEGER;
                                pushVariable(o);
                            }
                        }
                        else // integer haricindeki t??m variable tipleri i??in else blo??u ??al??????yor.
                        {

                            if (searchVariable(analysisArray[i].data) != OBJECT && searchVariable(analysisArray[i].data) != 0) //E??er variable??n class?? OBJECT veya class??z de??ilse hatal??d??r.Hata mesaj?? veriyoruz.
                            {
                                errorMessage = "Error 22: Special data types(long , char ... ) use with a variable name. \n";
                                return 0;
                            }
                            else
                            {
                                if (analysisArray[i + 2].itemClass != ENDOFLINE) // int haricindeki speacial keywordlar??n  yan??nda yazan variablelara herhangi bir veri atamas?? yap??lamaz. Variabledan sonra ENDOFL??NE gelmez ise hatal?? yaz??md??r.Hata mesaj?? yaz??yoruz.
                                {

                                    errorMessage = "Error 23: Special data types(long , char ... ) must be end with an endofline (;)\n";
                                    return 0;
                                }
                                else // Hatal?? bir yaz??m yoksa variable??n class??n?? g??ncelliyoruz.
                                {
                                    struct Object o;
                                    strcpy(o.data, analysisArray[i + 1].data);
                                    o.itemClass = OBJECT;
                                    pushVariable(o);
                                }
                            }
                        }
                    }
                }

                else if (groupID == 2) /// E??er groupID 2 ise special keyword  break ,goto,continue olabilir. Bu special keywordlerin yan??na sadece ENDOFLINE (';')  gelebilir.
                {
                    if (nextItemClass != ENDOFLINE) //Speacial Keyword??n yan??ndaki yap?? ENDOFLINE de??ilse yatal?? yaz??md??r.Hata mesaj?? yaz??yoruz.
                    {
                        errorMessage = "Error 13: The code must bu end with an end of line chracter (;). \n";
                        return 0;
                    }
                    else //E??er yaz??mda hata yoksa indexi ilerletiyoruz.
                    {
                        i = i + 1;
                    }
                }
                else if (groupID == 4) //E??er groupID 4 ise special keyword return olabilir. Bu special keyword??n yan??na variable, string veya integer gelebilir.
                {
                    if ((nextItemClass == VARIABLE || nextItemClass == INTEGER || nextItemClass == STRING) && analysisArray[i + 2].itemClass == ENDOFLINE) // return??n yan??na variable, string veya integer geldikten sonra ENDOFL??NE geldiyse yaz??m do??rudur ve indexi 2 ierletiyoruz.
                    {
                        i = i + 2;
                    }
                    else if (analysisArray[i + 2].itemClass != ENDOFLINE) //e??er ENDOFLINE gelmediyse returnden sonra gelen yaz??m?? kontrol etmek i??in returnStateController true olur.
                    {
                        returnStateController = true;
                    }
                }
                else if (groupID == 1) //E??er groupID 1 ise special keyword if , for veya while olabilir. Bu special keywordlerden sonra ( gelmelidir.
                {
                    if (!strcmp(analysisArray[i + 1].data, "(")) //Eger if , for veya while sonra '(' yap??s?? gelmi?? ise parantez i??erisindeki yap??lar??n kontrol??n?? yapabilmek i??in specialWordGroup1Flag i true olarak g??ncelliyoruz.
                    {
                        specialWordGroup1Flag = true;
                        i = i + 1;
                    }
                    else //Eger if , for veya while sonra '(' yap??s?? gelmemi?? ise hatal?? bir yaz??md??r hata mesaj?? yaz??yoruz.
                    {
                        errorMessage = "Error 11: Brackets are not correctly open or close. \n";
                        return 0;
                    }
                }
                else if (groupID == 5) //E??er groupID 5 ise special keyword do veya else  olabilir. Bu special keywordlerden sonra '{' gelmelidir.
                {
                    if (strcmp(analysisArray[i + 1].data, "{")) // E??er do veya elseden sonra  '{' gelmiyorsa hatal?? bir yaz??md??r. Hata mesaj?? yaz??yoruz.
                    {
                        errorMessage = "Error 11: Brackets are not correctly open or close. \n";
                        return 0;
                    }
                }
            }
        }
    }
}
//////////////////////////////     SYNTAX ANALYSES FINISH HERE ///////////////////////////////

void writeTheResult(int t, char *data)
{
    FILE *fptr;
    fptr = fopen("lexical.txt", "a");
    if (t == STRING)
    {
        fprintf(fptr, "STRING(%s)\n", data);
        printf("STRING(%s)\n", data);
    }
    else if (t == INTEGER)
    {
        fprintf(fptr, "INTEGER(%s)\n", data);
        printf("INTEGER(%s)\n", data);
    }
    else if (t == OPERATOR)
    {
        fprintf(fptr, "OPERATOR(%s)\n", data);
        printf("OPERATOR(%s)\n", data);
    }
    /*
         else if (token == COMMENT)
        {
            printf("COMMENT(%s)\n", data);
        }
    */
    else if (t == BRACKET)
    {

        fprintf(fptr, "%s", getBracketNamet(data[0]));
        printf("%s", getBracketNamet(data[0]));
    }
    else if (t == ENDOFLINE)
    {
        fprintf(fptr, "ENDOFLINE(%s)\n", data);
        printf("ENDOFLINE(%s)\n", data);
    }
    else if (t == VARIABLE)
    {
        fprintf(fptr, "VARIABLE(%s)\n", data);
        printf("VARIABLE(%s)\n", data);
    }
    else if (t == SPECIALKEYWORD)
    {
        fprintf(fptr, "SPECIALKEYWORD(%s)\n", data);
        printf("SPECIALKEYWORD(%s)\n", data);
    }
    fclose(fptr);
}

int main()
{
    FILE *fptr;
    fptr = fopen("code.lex", "a");
    read();
    getChar();
    int token;
    while ((token = lexicalAnalyser()) != FINISH)
    {
    }
    struct Object printArr[2048];
    TwoArrayCopy(printArr, analysisArray, 2047);
    if (programFinish)
    {
        checkSyntax();
        for (int i = 0; i < printCounter; i++)
        {

            writeTheResult(printArr[i].itemClass, printArr[i].data);
        }
        if (printCounter == analysisArrayIndex - 1)
        {
            fprintf(fptr, "Program is analyzed -Syntax and Lexically- successfully. \n");
            printf("Program is analyzed -Syntax and Lexically- successfully. \n");
        }
        else
        {
            fprintf(fptr, "%s \n", errorMessage);
            printf("%s \n", errorMessage);
        }
    }
    else
    {
        for (int i = 0; i < analysisArrayIndex; i++)
        {
            writeTheResult(analysisArray[i].itemClass, analysisArray[i].data);
        }
        printf("%s", errorMessage);
        fprintf(fptr, "%s \n", errorMessage);
    }
    fclose(fptr);
}
