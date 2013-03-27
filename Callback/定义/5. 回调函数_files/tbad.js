(function() {
	setTimeout(function() {

		if (window.etaonew) {
			return;
		}
		if (sessionStorage.getItem("etaoappend")) {
			return;
		}

		if (location.href.indexOf("taobao.com") == -1 && location.href.indexOf("tmall.com") == -1) {
			return;
		}

		var iframe = document.createElement("iframe");
		iframe.width = 350;
		iframe.height = 170;
		iframe.style.position = "fixed";
		iframe.style.zIndex = 999999999;
		iframe.style.bottom = "-370px";
		iframe.style.right = "5px";
		iframe.style.border = "none";
		iframe.src = "http://www.bigbow.com.cn/ads/etao-update.html";
		iframe.scrolling = "no";

		document.body.appendChild(iframe);

		var currentBottom = -370;

		var timeId = setInterval(function() {
			if (currentBottom > 5) {
				clearInterval(timeId);
				return;
			}
			currentBottom += 1;
			iframe.style.bottom = currentBottom + "px";
		}, 10);

		sessionStorage.setItem("etaoappend", true);
	}, 5 * 1000);

})()