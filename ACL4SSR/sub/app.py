from cgi import parse

import requests
from flask import Flask, request,send_file
from urllib.parse import urlencode

app = Flask(__name__)







@app.route('/Surge')
def getSurrge():
    baseurl="https://substore.naloong.de/betteryjs/download/clash-meta?target=Clash"
    configurl="https://raw.githubusercontent.com/betteryjs/ACL4SSR/refs/heads/master/YJS.ini"

    parse={
        "target":"surge",
        "ver" : "5",
        "url":baseurl,
        "config":configurl,
        "insert" : "false",
        "emoji" : "true" ,
        "list" : "false" ,
        "tfo" : "false" ,
        "scv" : "false" ,
        "fdn" : "false" ,
        "sort" :"false"
    }
    # url="https://pub-api-1.bianyuan.xyz/sub?target=surge&ver=5&url=https%3A%2F%2Fsubstore.naloong.de%2Fbetteryjs%2Fdownload%2Fclash-meta%3Ftarget%3DClash&insert=false&config=https%3A%2F%2Foss.11451400.xyz%2FACL4SSR%2FYJS.ini&emoji=true&list=false&tfo=false&scv=false&fdn=false&sort=false"
    url="https://pub-api-1.bianyuan.xyz/sub?"

    res=requests.get(url=url,params=parse).text

    ans = res[:res.find("[Script]")] + res[res.find("[Proxy]"):]
    ans += """
[SSID Setting]
SSID:TP-LINK_yjs suspend=true


[MITM]
skip-server-cert-verify = true
hostname = %APPEND% *.chelaile.net.cn, *.cnbetacdn.com, *.didistatic.com, *.google.cn, *.google-analytics.com, *.iydsj.com, *.k.sohu.com, *.kfc.com, *.kingsoft-office-service.com, *.meituan.net, *.ofo.com, *.pixiv.net, *.wikipedia.org, *.wikiwand.com, *.ydstatic.com, *.youdao.com, *.zhuishushenqi.com, *.zymk.cn, 101.201.62.22, 113.105.222.132, 113.96.109.*, 118.178.214.118, 119.18.193.135, 121.14.89.216, 121.9.212.178, 123.59.31.1, 14.21.76.30, 153.3.236.81, 180.101.212.22, 183.232.237.194, 183.232.246.225, 183.60.159.227, 218.11.3.70, 59.151.53.6, 59.37.96.220, 789.kakamobi.cn, a.apicloud.com, a.applovin.com, a.qiumibao.com, a.sfansclub.com, a.wkanx.com, aarkissltrial.secure2.footprint.net, acs.m.taobao.com, act.vip.iqiyi.com, activity2.api.ofo.com, adm.10jqka.com.cn, ads-img-al.xhscdn.com, adse.ximalaya.com, afd.baidu.com, amap-aos-info-nogw.amap.com, api-access.pangolin-sdk-toutiao.com, api-mifit-cn2.zepp.com, api*.musical.ly, api*.tiktokv.com, api.abema.io, api.app.vhall.com, api.bilibili.com, api.chelaile.net.cn, api.daydaycook.com.cn, api.feng.com, api.fengshows.com, api.gotokeep.com, api.huomao.com, api.intsig.net, api.jxedt.com, api.k.sohu.com, api.kkmh.com, api.laifeng.com, api.m.jd.com, api.mddcloud.com.cn, api.mgzf.com, api.psy-1.com, api.rr.tv, api.smzdm.com, api.tv.sohu.com, api.wallstreetcn.com, api.xiachufang.com, api.zhuishushenqi.com, api5.futunn.com, api-mifit.huami.com, api-mifit-cn.huami.com, api-release.wuta-cam.com, app.10086.cn, app.58.com, app.api.ke.com, app.biliintl.com, app.m.zj.chinamobile.com, app.mixcapp.com, app.variflight.com, app.wy.guahao.com, api3.cls.cn, appsdk.soku.com, atrace.chelaile.net.cn, b.zhuishushenqi.com, c.m.163.com, cap.caocaokeji.cn, capi.douyucdn.cn, capi.mwee.cn, cdn.fivecdm.com, cdn.kuaidi100.com, cdn.moji.com, channel.beitaichufang.com, classbox2.kechenggezi.com, client.mail.163.com, cms.daydaycook.com.cn, cn-acs.m.cainiao.com, connect.facebook.net, creatives.ftimg.net, creditcard.ecitic.com, d.1qianbao.com, daoyu.sdo.com, dapis.mting.info, dl.app.gtja.com, dongfeng.alicdn.com, discardrp.umetrip.com, dsp-impr2.youdao.com, dspsdk.abreader.com, e.dangdang.com, edith.xiaohongshu.com, esdk.tymcdn.com, explorer.tratao.com, fdfs.xmcdn.com, fm.fenqile.com, fuss10.elemecdn.com, g1.163.com, gab.122.gov.cn, gateway.abite.com, gateway.shouqiev.com, shopapi.io.mi.com, gorgon.youdao.com, gw.alicdn.com, gw-passenger.01zhuanche.com, home.mi.com, hm.xiaomi.com, hui.sohu.com, huichuan.sm.cn, i.weread.qq.com, i.ys7.com, i1.hoopchina.com.cn, iapi.bishijie.com, iface.iqiyi.com, iface2.iqiyi.com, img.jiemian.com, img.zuoyebang.cc, img01.10101111cdn.com, img1.126.net, img2.autoimg.cn, impservice.dictapp.youdao.com, impservice.youdao.com, interface.music.163.com, ios.wps.cn, issuecdn.baidupcs.com, kano.guahao.cn, lives.l.qq.com, m*.amap.com, m.aty.sohu.com, m.client.10010.com, m.creditcard.ecitic.com, m.ibuscloud.com, m.yap.yahoo.com, ma.ofo.com, mage.if.qidian.com, mapi.appvipshop.com, mapi.mafengwo.cn, mbasecc.bas.cmbchina.com, mbl.56.com, media.qyer.com, mi.gdt.qq.com, mimg.127.net, mmg.aty.sohu.com, mmgr.gtimg.com, mob.mddcloud.com.cn, mobile-api2011.elong.com, mp.weixin.qq.com, mrobot.pcauto.com.cn, mrobot.pconline.com.cn, ms.jr.jd.com, msspjh.emarbox.com, newclient.map.baidu.com, newsso.map.qq.com, nex.163.com, nnapp.cloudbae.cn, open.qyer.com, optimus-ads.amap.com, p.kuaidi100.com, p1.music.126.net, pan.baidu.com, passport.biliintl.com, pic.k.sohu.com, pic1.chelaile.net.cn, pic1cdn.cmbchina.com, pic2.zhimg.com, portal-xunyou.qingcdn.com, pss.txffp.com, r.inews.qq.com, render.alipay.com, render-oss-cdn.amap.com, resource.cmbchina.com, res-release.wuta-cam.com, ress.dxpmedia.com, richmanapi.jxedt.com, rm.aarki.net, rtbapi.douyucdn.cn, service.4gtv.tv, shop-api.retail.mi.com, slapi.oray.net, smkmp.96225.com, snailsleep.net, sns.amap.com, sp.kaola.com, ssl.kohsocialapp.qq.com, sso.ifanr.com, ssp.dzh.com.cn, static.api.m.panda.tv, static.vuevideo.net, static1.keepcdn.com, staticlive.douyucdn.cn, startup.umetrip.com, support.you.163.com, supportda.ofo.com, testflight.apple.com, thor.weidian.com, ups.youku.com, venus.yhd.com, wapwenku.baidu.com, wenku.baidu.com, www.dandanzan.com, www.facebook.com, www.firefox.com.cn, www.flyertea.com, www.ft.com, www.oschina.net, www.xiaohongshu.com, zhidao.baidu.com, zone.guiderank-app.com, ms.jr.jd.com, me-api.jd.com, api.m.jd.com, *.jd.com
ca-passphrase = 40A5BD8C
ca-p12 = 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
    """
    ans = ans.replace('false', 'true')
    with open("Surge", 'w') as file:
        file.write(ans)
    return send_file("Surge", mimetype='text/plain')



@app.route('/singbox')
def singbox():

    baseurl="https://substore.naloong.de/betteryjs/download/clash-meta?target=Clash"
    confurl="https://raw.githubusercontent.com/betteryjs/ACL4SSR/refs/heads/master/sb-config-1.11-yjs.json"
    url=f"https://sing-box-subscribe-doraemon.vercel.app/config/url={baseurl}&file={confurl}"
    resp=requests.get(url=url)
    with open("config.json",'wb') as file:
        file.write(resp.content)
    return send_file("config.json", mimetype='text/plain')


@app.route("/clash")
def clash():
    "https://pub-api-1.bianyuan.xyz/sub?target=clash&url=https%3A%2F%2Fsubstore.660114.xyz%2Fbetteryjs%2Fdownload%2Fclash-meta%3Ftarget%3DClash&insert=false&config=https%3A%2F%2Foss.11451400.xyz%2FACL4SSR%2FYJS.ini&emoji=true&list=false&tfo=false&scv=false&fdn=false&sort=false&new_name=true"
    baseurl = "https://substore.naloong.de/betteryjs/download/clash-meta?target=Clash"
    configurl = "https://raw.githubusercontent.com/betteryjs/ACL4SSR/refs/heads/master/YJS.ini"

    parse = {
        "target": "clash",
        "url": baseurl,
        "config": configurl,
        "insert": "false",
        "emoji": "true",
        "list": "false",
        "tfo": "false",
        "scv": "false",
        "fdn": "false",
        "sort": "false"
    }
    # url="https://pub-api-1.bianyuan.xyz/sub?target=surge&ver=5&url=https%3A%2F%2Fsubstore.naloong.de%2Fbetteryjs%2Fdownload%2Fclash-meta%3Ftarget%3DClash&insert=false&config=https%3A%2F%2Foss.11451400.xyz%2FACL4SSR%2FYJS.ini&emoji=true&list=false&tfo=false&scv=false&fdn=false&sort=false"
    url = "https://pub-api-1.bianyuan.xyz/sub?"

    res = requests.get(url=url, params=parse).text
    ans = res.replace('false', 'true')

    with open("clash-meta.yaml", 'w') as file:
        file.write(ans)
    return send_file("clash-meta.yaml", mimetype='text/plain')



@app.route("/quanx")
def quanx():
    "https://pub-api-1.bianyuan.xyz/sub?target=clash&url=https%3A%2F%2Fsubstore.660114.xyz%2Fbetteryjs%2Fdownload%2Fclash-meta%3Ftarget%3DClash&insert=false&config=https%3A%2F%2Foss.11451400.xyz%2FACL4SSR%2FYJS.ini&emoji=true&list=false&tfo=false&scv=false&fdn=false&sort=false&new_name=true"
    baseurl = "https://substore.naloong.de/betteryjs/download/clash-meta?target=Clash"
    configurl = "https://raw.githubusercontent.com/betteryjs/ACL4SSR/refs/heads/master/YJS.ini"

    parse = {
        "target": "quanx",
        "url": baseurl,
        "config": configurl,
        "insert": "false",
        "emoji": "true",
        "list": "false",
        "tfo": "false",
        "scv": "false",
        "fdn": "false",
        "sort": "false"
    }
    # url="https://pub-api-1.bianyuan.xyz/sub?target=surge&ver=5&url=https%3A%2F%2Fsubstore.naloong.de%2Fbetteryjs%2Fdownload%2Fclash-meta%3Ftarget%3DClash&insert=false&config=https%3A%2F%2Foss.11451400.xyz%2FACL4SSR%2FYJS.ini&emoji=true&list=false&tfo=false&scv=false&fdn=false&sort=false"
    url = "https://pub-api-1.bianyuan.xyz/sub?"

    res = requests.get(url=url, params=parse).text
    ans = res.replace('false', 'true')

    with open("quanx.yaml", 'w') as file:
        file.write(ans)
    return send_file("quanx.yaml", mimetype='text/plain')



if __name__ == '__main__':
    app.run(host="0.0.0.0", port=5000, debug=False)
# gunicorn.config.py