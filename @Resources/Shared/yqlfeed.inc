; Measures for YQLFeed skins in Reader/ folder + shared vars

[Variables]
CurrentFeed=http://feeds.reuters.com/reuters/topNews
CurrentFeedTitle=Reuters Top News
Decoder="&#34;":"''","&quot;":"''","&#39;":"'","&apos;":"'","&#38;":"&","&amp;":"&","&#60;":"<","&lt;":"<","&#62;":">","&gt;":">","&160;":" ","nbsp;":" ","&#161;":"�","&iexcl;":"�","&#162;":"�","&cent;":"�","&#163;":"�","&pound;":"�","&#164;":"�","&curren;":"�","&#165;":"�","&yen;":"�","&#166;":"�","&brvbar;":"�","&#167;":"�","&sect;":"�","&#168;":"�","&uml;":"�","&#169;":"�","&copy;":"�","&#170;":"�","&ordf;":"�","&#171;":"�","&laquo;":"�","&#172;":"�","&not;":"�","&#174;":"�","&reg;":"�","&#175;":"�","&macr;":"�","&#176;":"�","&deg;":"�","&#177;":"�","&plusmn;":"�","&#178;":"�","&sup2;":"�","&#179;":"�","&sup3;":"�","&#180;":"�","&acute;":"�","&#181;":"�","&micro;":"�","&#182;":"�","&para;":"�","&#183;":"�","&middot;":"�","&#184;":"�","&cedil;":"�","&#185;":"�","&sup1;":"�","&#186;":"�","&ordm;":"�","&#187;":"�","&raquo;":"�","&#188;":"�","&frac14;":"�","&#189;":"�","&frac12;":"�","&#190;":"�","&frac34;":"�","&#191;":"�","&iquest;":"�","&#215;":"�","&times;":"�","&#247;":"�","&divide;":"�","&#192;":"�","&Agrave;":"�","&#193;":"�","&Aacute;":"�","&#194;":"�","&Acirc;":"�","&#195;":"�","&Atilde;":"�","&#196;":"�","&Auml;":"�","&#197;":"�","&Aring;":"�","&#198;":"�","&AElig;":"�","&#199;":"�","&Ccedil;":"�","&#200;":"�","&Egrave;":"�","&#201;":"�","&Eacute;":"�","&#202;":"�","&Ecirc;":"�","&#203;":"�","&Euml;":"�","&#204;":"�","&Igrave;":"�","&#205;":"�","&Iacute;":"�","&#206;":"�","&Icirc;":"�","&#207;":"�","&Iuml;":"�","&#208;":"�","&ETH;":"�","&#209;":"�","&Ntilde;":"�","&#210;":"�","&Ograve;":"�","&#211;":"�","&Oacute;":"�","&#212;":"�","&Ocirc;":"�","&#213;":"�","&Otilde;":"�","&#214;":"�","&Ouml;":"�","&#216;":"�","&Oslash;":"�","&#217;":"�","&Ugrave;":"�","&#218;":"�","&Uacute;":"�","&#219;":"�","&Ucirc;":"�","&#220;":"�","&Uuml;":"�","&#221;":"�","&Yacute;":"�","&#222;":"�","&THORN;":"�","&#223;":"","&szlig;":"�","&#224;":"�","&agrave;":"�","&#225;":"�","&aacute;":"�","&#226;":"�","&acirc;":"�","&#227;":"�","&atilde;":"�","&#228;":"�","&auml;":"�","&#229;":"�","&aring;":"�","&#230;":"�","&aelig;":"�","&#231;":"�","&ccedil;":"�","&#232;":"�","&egrave;":"�","&#233;":"�","&eacute;":"�","&#234;":"�","&ecirc;":"�","&#235;":"�","&euml;":"�","&#236;":"�","&igrave;":"�","&#237;":"�","&iacute;":"�","&#238;":"�","&icirc;":"�","&#239;":"�","&iuml;":"�","&#240;":"�","&eth;":"�","&#241;":"�","&ntilde;":"�","&#242;":"�","&ograve;":"�","&#243;":"�","&oacute;":"�","&#244;":"�","&ocirc;":"�","&#245;":"�","&otilde;":"�","&#246;":"�","&ouml;":"�","&#248;":"�","&oslash;":"�","&#249;":"�","&ugrave;":"�","&#250;":"�","&uacute;":"�","&#251;":"�","&ucirc;":"�","&#252;":"�","&uuml;":"�","&#253;":"�","&yacute;":"�","&#254;":"�","&thorn;":"�","&#255;":"�","&yuml;":"�","&#8220;":"�","&#8221;":"�"

[MeasureURLEncoder]
Measure=Calc
Formula=1
UpdateDivider=-1
RegExpSubstitute=1
Substitute="1":"#CurrentFeed#","\$":"%24","&":"%26","\+":"%2B","/":"%2F",":":"%3A",";":"%3B",",":"%2C","=":"%3D","\?":"%3F","@":"%40"," ":"%20","<":"%3C",">":"%3E","#":"%23","\(":"%28","\)":"%29","{":"%7B","}":"%7D","\|":"%7C","\\":"%5C","\^":"%5E","~":"%7E","\[":"%5B","\]":"%5D","`":"%60","\+":"%2B","\{":"%7B","\}":"%7D","^(.+)$":"http://query.yahooapis.com/v1/public/yql?q=select%20title%2C%20link%2C%20updated%2C%20entry.title%2C%20entry.link%2C%20entry.updated%20from%20feednormalizer%20where%20url%3D%22\1%22%20AND%20output%3D%22atom_1.0%22%20%7C%20sort(field%3D%22entry.updated%22%2C%20descending%3D%22true%22)%20%7C%20unique(field%3D%22entry.title%22%2C%20field%3D%22entry.updated%22)&diagnostics=true"

[MeasureFeed]
Measure=Plugin
Plugin=WebParser
URL=[&MeasureURLEncoder]
RegExp=(?siU)#FeedInfo##Entry##Entry##Entry##Entry##Entry#
ForceReload=1
UpdateRate=300
DynamicVariables=1
FinishAction=[!CommandMeasure MeasureNew """CheckNew("MeasureEntry1Time", "MeterEntry1Title", "MeasureEntry1Age")"""][!CommandMeasure MeasureNew """CheckNew("MeasureEntry2Time", "MeterEntry2Title", "MeasureEntry2Age")"""][!CommandMeasure MeasureNew """CheckNew("MeasureEntry3Time", "MeterEntry3Title", "MeasureEntry3Age")"""][!CommandMeasure MeasureNew """CheckNew("MeasureEntry4Time", "MeterEntry4Title", "MeasureEntry4Age")"""][!CommandMeasure MeasureNew """CheckNew("MeasureEntry5Time", "MeterEntry5Title", "MeasureEntry5Age")"""]

; Feed Information

[MeasureFeedTitle]
Measure=Plugin
Plugin=WebParser
URL=[MeasureFeed]
StringIndex=1
Substitute=#Decoder#
DecodeCharacterReference=1

[MeasureFeedLink]
Measure=Plugin
Plugin=WebParser
URL=[MeasureFeed]
StringIndex=2
Substitute=#Decoder#
DecodeCharacterReference=1

; Entry 1
[MeasureEntry1Title]
Measure=Plugin
Plugin=WebParser
URL=[MeasureFeed]
StringIndex=3
RegExp=(?siU)#EntryItem#
StringIndex2=1
Substitute=#Decoder#
DecodeCharacterReference=1

[MeasureEntry1Link]
Measure=Plugin
Plugin=WebParser
URL=[MeasureFeed]
StringIndex=3
RegExp=(?siU)#EntryItem#
StringIndex2=2
Substitute=#Decoder#
DecodeCharacterReference=1

[MeasureEntry1Time]
Measure=Plugin
Plugin=WebParser
URL=[MeasureFeed]
StringIndex=3
RegExp=(?siU)#EntryItem#
StringIndex2=3

[MeasureEntry1Age]
Measure=Time
Format=" "

; Entry 2

[MeasureEntry2Title]
Measure=Plugin
Plugin=WebParser
URL=[MeasureFeed]
StringIndex=4
RegExp=(?siU)#EntryItem#
StringIndex2=1
Substitute=#Decoder#
DecodeCharacterReference=1

[MeasureEntry2Link]
Measure=Plugin
Plugin=WebParser
URL=[MeasureFeed]
StringIndex=4
RegExp=(?siU)#EntryItem#
StringIndex2=2
Substitute=#Decoder#
DecodeCharacterReference=1

[MeasureEntry2Time]
Measure=Plugin
Plugin=WebParser
URL=[MeasureFeed]
StringIndex=4
RegExp=(?siU)#EntryItem#
StringIndex2=3

[MeasureEntry2Age]
Measure=Time
Format=" "

; Entry 3

[MeasureEntry3Title]
Measure=Plugin
Plugin=WebParser
URL=[MeasureFeed]
StringIndex=5
RegExp=(?siU)#EntryItem#
StringIndex2=1
Substitute=#Decoder#
DecodeCharacterReference=1

[MeasureEntry3Link]
Measure=Plugin
Plugin=WebParser
URL=[MeasureFeed]
StringIndex=5
RegExp=(?siU)#EntryItem#
StringIndex2=2
Substitute=#Decoder#
DecodeCharacterReference=1

[MeasureEntry3Time]
Measure=Plugin
Plugin=WebParser
URL=[MeasureFeed]
StringIndex=5
RegExp=(?siU)#EntryItem#
StringIndex2=3

[MeasureEntry3Age]
Measure=Time
Format=" "

; Entry 4

[MeasureEntry4Title]
Measure=Plugin
Plugin=WebParser
URL=[MeasureFeed]
StringIndex=6
RegExp=(?siU)#EntryItem#
StringIndex2=1
Substitute=#Decoder#
DecodeCharacterReference=1

[MeasureEntry4Link]
Measure=Plugin
Plugin=WebParser
URL=[MeasureFeed]
StringIndex=6
RegExp=(?siU)#EntryItem#
StringIndex2=2
Substitute=#Decoder#
DecodeCharacterReference=1

[MeasureEntry4Time]
Measure=Plugin
Plugin=WebParser
URL=[MeasureFeed]
StringIndex=6
RegExp=(?siU)#EntryItem#
StringIndex2=3

[MeasureEntry4Age]
Measure=Time
Format=" "

; Entry 5

[MeasureEntry5Title]
Measure=Plugin
Plugin=WebParser
URL=[MeasureFeed]
StringIndex=7
RegExp=(?siU)#EntryItem#
StringIndex2=1
Substitute=#Decoder#
DecodeCharacterReference=1

[MeasureEntry5Link]
Measure=Plugin
Plugin=WebParser
URL=[MeasureFeed]
StringIndex=7
RegExp=(?siU)#EntryItem#
StringIndex2=2
Substitute=#Decoder#
DecodeCharacterReference=1

[MeasureEntry5Time]
Measure=Plugin
Plugin=WebParser
URL=[MeasureFeed]
StringIndex=7
RegExp=(?siU)#EntryItem#
StringIndex2=3

[MeasureEntry5Age]
Measure=Time
Format=" "

; Check entry ages

[MeasureNew]
Measure=Script
ScriptFile="#@#Scripts\YQLFeed.lua"
UpdateDivider=-1

[MeasureEntryAges]
Measure=Time
Format=%M
OnChangeAction=[!CommandMeasure MeasureNew """CheckNew("MeasureEntry1Time", "MeterEntry1Title", "MeasureEntry1Age")"""][!CommandMeasure MeasureNew """CheckNew("MeasureEntry2Time", "MeterEntry2Title", "MeasureEntry2Age")"""][!CommandMeasure MeasureNew """CheckNew("MeasureEntry3Time", "MeterEntry3Title", "MeasureEntry3Age")"""][!CommandMeasure MeasureNew """CheckNew("MeasureEntry4Time", "MeterEntry4Title", "MeasureEntry4Age")"""][!CommandMeasure MeasureNew """CheckNew("MeasureEntry5Time", "MeterEntry5Title", "MeasureEntry5Age")"""]