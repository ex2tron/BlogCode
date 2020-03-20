/* 页面加载时获取参数 */
window.onload = () => {
    Init();
}

/* 初始化 */
function Init() {
    this.result = {};           // 评估结果
    this.isFinished = false;    // 评测是否完成

    this.index = 0;             // 当前索引
    this.fields = document.getElementsByClassName('qn-item');   // 所有评测问题

    // 进度条区域及实际进度
    this.progressArea = document.getElementById('qn-progress-container');
    this.progress = document.getElementById('qn-progress');
    UpdateProgress(this.index + 1);     // 初始化进度
}

/* 开始评测 */
function StartEval() {
    const tips = document.getElementById('tips');
    tips.style.display = 'none';
    // 显示第一条题目和进度条
    classMethods.add(this.fields[this.index], 'qn-current');
    this.progressArea.style.display = 'block'
}

/* 显示下一道问题 */
function ShowNext() {
    let isRequired = RequiredCheck();  // 必填字段检查
    if (!isRequired) {
        ShowToast('必须填写，不能为空噢～')
        return;
    }

    if (this.index < this.fields.length - 1) {
        classMethods.remove(this.fields[this.index], 'qn-current'); // 隐藏上一条

        this.index += 1;
        classMethods.add(this.fields[this.index], 'qn-current');    // 显示下一条
        UpdateProgress(this.index + 1);
    }
    else {
        classMethods.remove(this.fields[this.index], 'qn-current'); // 隐藏问题
        this.progressArea.style.display = 'none';                   // 隐藏进度

        const end = document.getElementById('end'); // 显示尾页
        end.style.display = 'block';
    }

    scrollTo(0, 0); // 跳转HTML开头
}

/* 必填字段检查 */
function RequiredCheck() {
    const field = this.fields[this.index];
    const input = field.querySelector('input[required]');
    if (!input) return true;

    let isRequired = false;
    switch (input.tagName.toLowerCase()) {
        case 'input':
            if (input.type === 'radio' || input.type === 'checkbox') {
                let options = field.querySelectorAll('input[type="' + input.type + '"]');
                options.forEach(item => {
                    if (item.checked) {
                        isRequired = true;
                        if (input.type === 'radio') {
                            this.result[this.index] = item.value;   // 记录结果
                        } else {
                            this.result[this.index] = this.result[this.index] || [];
                            this.result[this.index].push(item.value);
                        }
                    }
                });
            }
            else if (input.value !== '') {
                isRequired = true;
                this.result[this.index] = input.value;
            }
            break;
    }

    return isRequired;
}

/* 提交结果 */
function Submit() {   
    this.isFinished = true;
    ShowToast(JSON.stringify(this.result));

    /*
     此处发送HTTP请求
     */
    // HTTP POST Demo
    const data = {};
    const httpRequest = new XMLHttpRequest();
    httpRequest.open('POST', 'url', true);
    httpRequest.setRequestHeader("Content-type", "application/json");
    httpRequest.send(JSON.stringify(data));
    httpRequest.onreadystatechange = function () {
        if (httpRequest.status === 200) {
            console.log(httpRequest.responseText);
        }
    };
}

/* 获取URL参数 */
function getQueryVariable(variable) {
    var query = window.location.search.substring(1);
    var vars = query.split("&");
    for (var i = 0; i < vars.length; i++) {
        var pair = vars[i].split("=");
        if (pair[0] == variable) { return pair[1]; }
    }
    return false;
}

/* 更新进度 */
function UpdateProgress(index) {
    const progress = (index / this.fields.length) * 100;
    this.progress.style.width = progress + '%';
}

/* 显示Loading */
function ShowLoading() {
    const dialog = document.getElementById('loading-toast');
    dialog.style.display = 'block';
}

/* 隐藏Loading */
function HideLoading() {
    const dialog = document.getElementById('loading-toast');
    dialog.style.display = 'none';
}

/* 显示对话框弹窗 */
function ShowToast(msg) {
    const dialog = document.getElementById('msg-dialog');
    dialog.style.display = 'block';

    const dialogContent = document.getElementById('msg-dialog-content');
    dialogContent.innerText = msg;
}

/* 隐藏对话框弹窗 */
function HideToast() {
    const dialog = document.getElementById('msg-dialog');
    dialog.style.display = 'none';

    if (this.isFinished)    // 评测完成，返回
        wx.miniProgram.navigateBack();
}

/* 添加或移除class */
let classMethods = {
    add(element, className) {
        element.classList.add(className);
    },

    remove(element, className) {
        element.classList.remove(className);
    }
}