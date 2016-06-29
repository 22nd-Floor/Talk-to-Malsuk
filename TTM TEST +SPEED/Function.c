r B=/^(?:parents|prev(?:Until|All))/,C={children:!0,contents:!0,next:!0,prev:!0};n.extend({dir:function(a,b,c){var d=[],e=void 0!==c;while((a=a[b])&&9!==a.nodeType)if(1===a.nodeType){if(e&&n(a).is(c))break;d.push(a)}return d},sibling:function(a,b){for(var c=[];a;a=a.nextSibling)1===a.nodeType&&a!==b&&c.push(a);return c}}),n.fn.extend({has:function(a){var b=n(a,this),c=b.length;return this.filter(function(){for(var a=0;c>a;a++)if(n.contains(this,b[a]))return!0})},closest:function(a,b){for(var c,d=0,e=this.length,f=[],g=u.test(a)||"string"!=typeof a?n(a,b||this.context):0;e>d;d++)for(c=this[d];c&&c!==b;c=c.parentNode)if(c.nodeType<11&&(g?g.index(c)>-1:1===c.nodeType&&n.find.matchesSelector(c,a))){f.push(c);break}return this.pushStack(f.length>1?n.unique(f):f)},index:function(a){return a?"string"==typeof a?g.call(n(a),this[0]):g.call(this,a.jquery?a[0]:a):this[0]&&this[0].parentNode?this.first().prevAll().length:-1},add:function(a,b){return this.pushStack(n.unique(n.merge(this.get(),n(a,b))))},addBack:function(a){return this.add(null==a?this.prevObject:this.prevObject.filter(a))}});function D(a,b){while((a=a[b])&&1!==a.nodeType);return a}n.each({parent:function(a){var b=a.parentNode;return b&&11!==b.nodeType?b:null},parents:function(a){return n.dir(a,"parentNode")},parentsUntil:function(a,b,c){return n.dir(a,"parentNode",c)},next:function(a){return D(a,"nextSibling")},prev:function(a){return D(a,"previousSibling")},nextAll:function(a){return n.dir(a,"nextSibling")},prevAll:function(a){return n.dir(a,"previousSibling")},nextUntil:function(a,b,c){return n.dir(a,"nextSibling",c)},prevUntil:function(a,b,c){return n.dir(a,"previousSibling",c)},siblings:function(a){return n.sibling((a.parentNode||{}).firstChild,a)},children:function(a){return n.sibling(a.firstChild)},contents:function(a){return a.contentDocument||n.merge([],a.childNodes)}},function(a,b){n.fn[a]=function(c,d){var e=n.map(this,b,c);return"Until"!==a.slice(-5)&&(d=c),d&&"string"==typeof d&&(e=n.filter(d,e)),this.length>1&&(C[a]||n.unique(e),B.test(a)&&e.reverse()),this.pushStack(e)}});var E=/\S+/g,F={};function G(a){var b=F[a]={};return n.each(a.match(E)||[],function(a,c){b[c]=!0}),b}n.Callbacks=function(a){a="string"==typeof a?F[a]||G(a):n.extend({},a);var b,c,d,e,f,g,h=[],i=!a.once&&[],j=function(l){for(b=a.memory&&l,c=!0,g=e||0,e=0,f=h.length,d=!0;h&&f>g;g++)if(h[g].apply(l[0],l[1])===!1&&a.stopOnFalse){b=!1;break}d=!1,h&&(i?i.length&&j(i.shift()):b?h=[]:k.disable())},k={add:function(){if(h){var c=h.length;!function g(b){n.each(b,function(b,c){var d=n.type(c);"function"===d?a.unique&&k.has(c)||h.push(c):c&&c.length&&"string"!==d&&g(c)})}(arguments),d?f=h.length:b&&(e=c,j(b))}return this},remove:function(){return h&&n.each(arguments,function(a,b){var c;while((c=n.inArray(b,h,c))>-1)h.splice(c,1),d&&(f>=c&&f--,g>=c&&g--)}),this},has:function(a){return a?n.inArray(a,h)>-1:!(!h||!h.length)},empty:function(){return h=[],f=0,this},disable:function(){return h=i=b=void 0,this},disabled:function(){return!h},lock:function(){return i=void 0,b||k.disable(),this},locked:function(){return!i},fireWith:function(a,b){return!h||c&&!i||(b=b||[],b=[a,b.slice?b.slice():b],d?i.push(b):j(b)),this},fire:function(){return k.fireWith(this,arguments),this},fired:function(){return!!c}};return k},n.extend({Deferred:function(a){var b=[["resolve","done",n.Callbacks("once memory"),"resolved"],["reject","fail",n.Callbacks("once memory"),"rejected"],["notify","progress",n.Callbacks("memory")]],c="pending",d={state:function(){return c},always:function(){return e.done(arguments).fail(arguments),this},then:function(){var a=arguments;return n.Deferred(function(c){n.each(b,function(b,f){var g=n.isFunction(a[b])&&a[b];e[f[1]](function(){var a=g&&g.apply(this,arguments);a&&n.isFunction(a.promise)?a.promise().done(c.resolve).fail(c.reject).progress(c.notify):c[f[0]+"With"](this===d?c.promise():this,g?[a]:arguments)})}),a=null}).promise()},promise:function(a){return null!=a?n.extend(a,d):d}},e={};return d.pipe=d.then,n.each(b,function(a,f){var g=f[2],h=f[3];d[f[1]]=g.add,h&&g.add(function(){c=h},b[1^a][2].disable,b[2][2].lock),e[f[0]]=function(){return e[f[0]+"With"](this===e?d:this,arguments),this},e[f[0]+"With"]=g.fireWith}),d.promise(e),a&&a.call(e,e),e},when:function(a){var b=0,c=d.call(arguments),e=c.length,f=1!==e||a&&n.isFunction(a.promise)?e:0,g=1===f?a:n.Deferred(),h=function(a,b,c){return function(e){b[a]=this,c[a]=arguments.length>1?d.call(arguments):e,c===i?g.notifyWith(b,c):--f||g.resolveWith(b,c)}},i,j,k;if(e>1)for(i=new Array(e),j=new Array(e),k=new Array(e);e>b;b++)c[b]&&n.isFunction(c[b].promise)?c[b].promise().done(h(b,k,c)).fail(g.reject).progress(h(b,j,i)):--f;return f||g.resolveWith(k,c),g.promise()}});var H;n.fn.ready=function(a){return n.ready.promise().done(a),this},n.extend({isReady:!1,readyWait:1,holdReady:function(a){a?n.readyWait++:n.ready(!0)},ready:function(a){(a===!0?--n.readyWait:n.isReady)||(n.isReady=!0,a!==!0&&--n.readyWait>0||(H.resolveWith(l,[n]),n.fn.triggerHandler&&(n(l).triggerHandler("ready"),n(l).off("ready"))))}});function I(){l.removeEventListener("DOMContentLoaded",I,!1),a.removeEventListener("load",I,!1),n.ready()}n.ready.promise=function(b){return H||(H=n.Deferred(),"complete"===l.readyState?setTimeout(n.ready):(l.addEventListener("DOMContentLoaded",I,!1),a.addEventListener("load",I,!1))),H.promise(b)},n.ready.promise();var J=n.access=function(a,b,c,d,e,f,g){var h=0,i=a.length,j=null==c;if("object"===n.type(c)){e=!0;for(h in c)n.access(a,b,h,c[h],!0,f,g)}else if(void 0!==d&&(e=!0,n.isFunction(d)||(g=!0),j&&(g?(b.call(a,d),b=null):(j=b,b=function(a,b,c){return j.call(n(a),c)})),b))for(;i>h;h++)b(a[h],c,g?d:d.call(a[h],h,b(a[h],c)));return e?a:j?b.call(a):i?b(a[0],c):f};n.acceptData=function(a){return 1===a.nodeType||9===a.nodeType||!+a.nodeType};function K(){Object.defineProperty(this.cache={},0,{get:function(){return{}}}),this.expando=n.expando+Math.random()}K.uid=1,K.accepts=n.acceptData,K.prototype={key:function(a){if(!K.accepts(a))return 0;var b={},c=a[this.expando];if(!c){c=K.uid++;try{b[this.expando]={value:c},Object.defineProperties(a,b)}catch(d){b[this.expando]=c,n.extend(a,b)}}return this.cache[c]||(this.cache[c]={}),c},set:function(a,b,c){var d,e=this.key(a),f=this.cache[e];if("string"==typeof b)f[b]=c;else if(n.isEmptyObject(f))n.extend(this.cache[e],b);else for(d in b)f[d]=b[d];return f},get:function(a,b){var c=this.cache[this.key(a)];return void 0===b?c:c[b]},access:function(a,b,c){var d;return void 0===b||b&&"string"==typeof b&&void 0===c?(d=this.get(a,b),void 0!==d?d:this.get(a,n.camelCase(b))):(this.set(a,b,c),void 0!==c?c:b)},remove:function(a,b){var c,d,e,f=this.key(a),g=this.cache[f];if(void 0===b)this.cache[f]={};else{n.isArray(b)?d=b.concat(b.map(n.camelCase)):(e=n.camelCase(b),b in g?d=[b,e]:(d=e,d=d in g?[d]:d.match(E)||[])),c=d.length;while(c--)delete g[d[c]]}},hasData:function(a){return!n.isEmptyObject(this.cache[a[this.expando]]||{})},discard:function(a){a[this.expando]&&delete this.cache[a[this.expando]]}};var L=new K,M=new K,N=/^(?:\{[\w\W]*\}|\[[\w\W]*\])$/,O=/([A-Z])/g;function P(a,b,c){var d;if(void 0===c&&1===a.nodeType)if(d="data-"+b.replace(O,"-$1").toLowerCase(),c=a.getAttribute(d),"string"==typeof c){try{c="true"===c?!0:"false"===c?!1:"null"===c?null:+c+""===c?+c:N.test(c)?n.parseJSON(c):c}catch(e){}M.set(a,b,c)}else c=void 0;return c}n.extend({hasData:function(a){return M.hasData(a)||L.hasData(a)},data:function(a,b,c){return M.access(a,b,c)},removeData:function(a,b){M.remove(a,b)
},_data:function(a,b,c){return L.access(a,b,c)},_removeData:function(a,b){L.remove(a,b)}}),n.fn.extend({data:function(a,b){var c,d,e,f=this[0],g=f&&f.attributes;if(void 0===a){if(this.length&&(e=M.get(f),1===f.nodeType&&!L.get(f,"hasDataAttrs"))){c=g.length;while(c--)g[c]&&(d=g[c].name,0===d.indexOf("data-")&&(d=n.camelCase(d.slice(5)),P(f,d,e[d])));L.set(f,"hasDataAttrs",!0)}return e}return"object"==typeof a?this.each(function(){M.set(this,a)}):J(this,function(b){var c,d=n.camelCase(a);if(f&&void 0===b){if(c=M.get(f,a),void 0!==c)return c;if(c=M.get(f,d),void 0!==c)return c;if(c=P(f,d,void 0),void 0!==c)return c}else this.each(function(){var c=M.get(this,d);M.set(i = 1; i <= length; i++)
		printf("─");
	printf("┐");

	puts("");

	printf(" │");
	if (realen % 2 == 1)
		printf(" ");
	printf("%s", str);
	printf("│");

	puts("");

	printf(" └");
	for (i = 1; i <= length; i++)
		printf("─");
	printf("┘");

	puts("");
}

// 페메 오른쪽 박스
void RightBox(char *str)
{
	int i, length, length2, realen;

	realen = strlen(str);

	if (str[0] == 7)
		realen--;

	if (realen % 2 == 0){
		length = realen / 2;
		length2 = 75 - realen;
	}
	else{
		length = (realen + 1) / 2;
		length2 = 74 - realen;
	}
	for (i = 1; i <= length2; i++)
		printf(" ");
	printf("┌");
	for (i = 1; i <= length; i++)
		printf("─");
	printf("┐");

	puts("");

	for (i = 1; i <= length2; i++)
		printf(" ");
	printf("│");
	if (realen % 2 == 1)
		printf(" ");
	printf("%s", str);
	printf("│");

	puts("");

	for (i = 1; i <= length2; i++)
		printf(" ");
	printf("└");
	for (i = 1; i <= length; i++)
		printf("─");
	printf("┘");

	puts("");
}

// 시간 설정함수
void setTime()
{
	time_t t;

	time(&t);
	Hour[0] = localtime(&t)->tm_hour;
	Min[0] = localtime(&t)->tm_min;

	Hour[1] = Hour[0];
	Min[1] = Min[0] + 36;
	if (Min[1] >= 60){
		Min[1] -= 60;
		Hour[1]++;
	}

	Hour[2] = Hour[1];
	Min[2] = Min[1] + 14;
	if (Min[2] >= 60){
		Min[2] -= 60;
		Hour[2]++;
	}

	Hour[3] = Hour[2] + 3;
	Min[3] = Min[2] + 47;
	if (Min[3] >= 60){
		Min[3] -= 60;
		Hour[3]++;
	}
}

// 페이스북 대화창 함수
void message(MESSAGE m)
{
	switch (m){
	case NAME:
		puts("윾말숙");
		printf("Messenger 1분 전에 활동%55s\n", "☎");
		puts("-------------------------------------------------------------------------------");
		break;
	case FIRSTMSG:
		message(NAME);
		printTime(Hour[0], Min[0]); //"오후 6:37"
		RightBox("안녕");
		break;
	case SECONDMSG:
		message(FIRSTMSG);
		printTime(Hour[1], Min[1]); //"오후 7:13"
		LeftBox("ㅎㅇ");
		break;
	case THIRDMSG:
		message(SECONDMSG);
		printTime(Hour[2], Min[2]); //"오후 7:27"
		RightBox("전번점ㅋㅋ");
		break;
	case FOURTHMSG:
		message(THIRDMSG);
		printTime(Hour[3], Min[3]); //오후 11:14"
		LeftBox("싫어미안ㅋㅋ");
		break;
	case FIFTHMSG:
		message(FOURTHMSG);
		RightBox("ㅇ..어 ㅈㅅ");
		RightBox("잘자");
		break;
	case SIXTHMSG:
		message(FIFTHMSG);
		LeftBox("미안다음에줄께");
		LeftBox("너도잘자");
		break;
	}
}

// 개행 함수 - 삭제 예정
void LineFeed(int a){
	for (int i = 0; i < a; i++)
		puts("");
}

// 한글자씩 출력 함수 
void printLetter(char *str, int time)
{
	int i = 0;

	while (str[i] != '\0'){
		if (str[i] < 0){
			Sleep(time);
			printf("%c%c", str[i], str[i + 1]);
			i += 2;
		}
		else{
			Sleep(time);
			printf("%c", str[i]);
			i++;
		}
	}
}

// 안내 함수 - 삭제 예정
void intro(char *str, int time)
{
	printf("\t\t");
	printLetter(str, time);
	puts("");
}

// 말하기 함수 
void say(char *str, int time)
{
	puts(" 　　　　　　　　　　　 　 　 　 　 　 　 _,,t------､,-----+-､");
	puts("　　　　　　　　　　　　 　 　 　 　 三'::.............. .....::::::`ｙ,.");
	puts("　　　　　　　　 　 　 　 　 　 　 ナ::::::::::::::::::::::::: ::::::::::::ヾ");
	puts("　　　　　　　 　 　 　 |￣|　　 V:::::::::::::_{{ （{∫∬ﾉノｊヾ:::::{");
	puts("　　　　　　 　 　　|￣| |￣| 　 ﾅ:::::::::::i`__,,,,,,ｧ_　 _,,,,,_ t;;:ﾇ");
	puts("　　 　 　　　　　　| 　| |　 |　 イﾍ:::::(ヾ~!,ｬt､　!'''i ｨｔﾝ )=f }ｆ");
	puts(" 　　　　　　 　 　　| 　| | 　| 　 i {t) テ\" ﾍ' '___, ｲ 　ヽ_＿ / 介'");
	puts("　　　　　　　　 　 | 　| |　 |　_,rﾍ_,ｊ|!' 　 　 /ｰ---''! 　　　|'");
	puts("　　　　　　　　 　 |,.ｨ―''''￣　　／| |　 　 　 ／二二ｸ　 　　 !");
	puts("　　　　　　 　 　 /;;:::'';;::''::;;:／ {　!　、　 　 ヾニﾝ　　 　ﾉ＼");
	puts(" 　 　　　 　　 　 /''':::;r|'''::;;;|　　|　!　＼　　　　　 _,,.／|:;;''＼");
	puts(" 　　　　　　 　 /:;;／　|;;;''::;;| 　　丶＼ 　｀_＿＞-ｰ´　 　　!;;;:''::iヽ、");
	puts(" 　　　 　 　 　 i／　　 |'::;;;;''|　　 　 　三 ―''\"　　　 　　　!''::;;;; |/");
	puts("　　　　　　　 /⌒ヽ　 |;;''':::;|　　　　　　　＼　 　 　 　 　 !;;::''|/　 i");
	puts("　 　 　 　 / 　 　 ＼{'';;;::''}　　　　　　　　　￣二ニ＝　 　 !::;;|　　 |");
	puts("　　　 　 　 /ﾍ　　　　 |;;:::::;{　　　　　　　　　　　　‐-　　　 　 !/　 　|");
	puts("　 　 　 　 /　　i　　 　 |:::;;;''!　　　　　　　　　　 　 ー　　 　 　 !　 /");
	puts("　　　　　/　　　l　　 　 |;;'';ｲ　　　　　　　　　　　　　　　　　｝　　 {、");
	puts("-------------------------------------------------------------------------------");

	printf(" <준필> \n\n ");
	printLetter(str, time);
	puts("");
}

void say_(char *str, int time)
{
	printf(" ");
	printLetter(str, time);
	puts("");
}

// 시간 출력함수
void printTime(int hour, int min)
{
	if (hour == 0 || hour == 24){
		if (min < 10)
			printf("%40s 12:0%d\n", "오전", min);
		else
			printf("%40s 12:%d\n", "오전", min);
	}
	else if (hour < 12){
		if (min < 10)
			printf("%40s %d:0%d\n", "오전", hour, min);
		else
			printf("%40s %d:%d\n", "오전", hour, min);
	}
	else if (hour == 12){
		if (min < 10)
			printf("%40s 12:0%d\n", "오후", min);
		else
			printf("%40s 12:%d\n", "오후", min);
	}
	else if (hour < 24){
		if (min < 10)
			printf("%40s %d:0%d\n", "오후", hour - 12, min);
		else
			printf("%40s %d:%d\n", "오후", hour - 12, min);
	}
	else{
		if (min < 10)
			printf("%40s %d:0%d\n", "오전", hour - 24, min);
		else
			printf("%40s %d:%d\n", "오전", hour - 24, min);
	}
}

// 타이틀 함수
void Title()
{
	char *ttm[13] = {
		"                                                ",
		" ━┳━  ┏━┓  ┃      ┃  ／                 ",
		"   ┃    ┣━┫  ┃      ┣━                   ",
		"   ┃    ┃  ┃  ┗━━  ┃  ＼                 ",
		"                                                ",
		" ━┳━  ┏━┓                                 ",
		"   ┃    ┃  ┃                                 ",
		"   ┃    ┗━┛                                 ",
		"                                                ",
		" ┏┳┓  ┏━┓  ┃      ┏━━  ┃  ┃  ┃  ／ ",
		" ┃┃┃  ┣━┫  ┃      ┗━┓  ┃  ┃  ┣━   ",
		" ┃  ┃  ┃  ┃  ┗━━  ━━┛  ┗━┛  ┃  ＼ ",
		"                                                "
	};
	system("color f0");
	TITLECOLOR;
	for (int i = 0; i < 13; i++){
		printMiddle(ttm[i], 4 + i);
	}
	MAINCOLOR;
	printMiddle("beta. 1.5.0.0", 18);

	while (!kbhit()){
		printMiddle("press any key!", 20);
		Sleep(500);
		printMiddle("              ", 20);
		Sleep(500);
	}
	getch();
	system("cls");
}

// 크레딧 함수
void Credit()
{
	gotoxy(16, 5); puts("제작 전성우");
	gotoxy(16, 6); puts("원작 황준필과 미림이의 페메 사진");
	gotoxy(16, 8); puts("이 저작물은 배포가 가능합니다.");
	gotoxy(16, 9); puts("단, 배포시 저작물의 원작자를 표시해야 하며");
	gotoxy(16, 10); puts("저작물을 영리 목적으로 이용을 허락하지 않고");
	gotoxy(16, 11); puts("저작물의 변경 또는 2차 저작을 허락하지 않습니다.");
	gotoxy(16, 13); puts("ⓒ 2015 전성우. All rights reserved.\n");
	gotoxy(16, 15);
}

// 헬프 함수 - 삭제 예정
void Help(int time)
{
	gotoxy(16, 3); printLetter("이 프로그램 TTM은\n", time);
	gotoxy(16, 4); printLetter("엔터를 입력하며 진행되는 프로그램이니\n", time);
	gotoxy(16, 5); printLetter("엔터를 연타하시지 마시고\n", time);
	gotoxy(16, 6); printLetter("엔터를 입력하라는 문구를 확인하며 진행해주세요.\n\n\n", time);
}

// 중간 값 알아내기 private
int GetConsoleMiddle(int length)
{
	if (length % 2 == 0){
		return (80 - length) / 2;
	}
	else{
		return (80 - length - 1) / 2;
	}
}

// 중앙 정렬 출력 함수
void printMiddle(char *str, int lineNum)
{
	gotoxy(GetConsoleMiddle(strlen(str)), lineNum); puts(str);
}