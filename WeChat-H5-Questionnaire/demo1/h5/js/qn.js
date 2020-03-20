function SendMsg() {
    // 下面这句话触发小程序后退事件
    // 这句话不加，则后面两句发送的消息小程序接收不到
    wx.miniProgram.navigateBack();

    // 发送消息
    wx.miniProgram.postMessage({ data: 'tencent' });
    wx.miniProgram.postMessage({ data: { name: 'wang' } });

    // 判断环境
    wx.miniProgram.getEnv(function (res) { console.log(res) });
}