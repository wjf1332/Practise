# **Git的使用笔记**
- config --global user.name "Your Name" 
- config --global user.email "email@example.com"
    > --global表示本机器所有的仓库都使用该配置
- init
    > 仓库初始化（会在当前目录下创建.git目录，用来跟踪版本库）
## 常用操作命令
    - 和svn本地管理类似
    - 相关概念
        - 版本库（Repository），即.git中所存放的内容，不可手动修改
        - 暂存区stage（或者叫index），add命令之后，则修改进入stage，而commit之后，才真正的提交到版本库中
        - 工作区，即我们认为操作的文件夹
        - master 自动创建的第一个分支
        - HEAD 是指向master的指针
- add
    > 提交修改/新文件
- status
    > 查看当前仓库的状态
- diff
    > (可以在提交前)查看当前修改的内容
    > git diff HEAD -- *.* 用来查看工作区和版本库里最新版的区别

- log
    > 查看历史提交信息(是从当前HEAD开始算起)
    - --pretty=oneline
        > 一行显示
- reflog
    > git reflog 查看命令历史，以便确定要回到未来的哪个版本
- reset 
    > 回退到上一个版本
    > 格式：git reset --hard HEAD^ 表示上一个版本，HEAD^^是上上个版本，HEAD~100是上100个版本 ？(我测试的时候，为什么会出现More？)

- checkout 
    - -- file
        > 其中--命令必须有，否则就会成为“切换另一个分支”了
        >
        >1.当工作区被乱改，想丢弃，则直接checkout -- file即可。
        >
        >2.若乱改后且已经添加到暂存区，reset HEAD file,可以回到场景1，然后按1操作
        >
        >3.若已经提交， 则可以考虑版本回退（当然了，你若已经提交到了远程库，则某些不合适的修改必然可以被大伙看到，且没法撤销了）
    - checkout恢复本地被删除的文件（前提库中没有删除，和svn中的checkout道理一样）
- rm
    > 从版本库中删除文件

## 远程操作
- GitHub
### 创建SSH Key
1. Git Bash
    > 打开Git Bash之后，通过输入ssh-keygen -t rsa -C "youremail@example.com"
    创建密钥
    >
    >会在用户主目录，生成.ssh目录，里面包括RSA公钥和私钥
2. Github
    > 登录之后，在Account settings中找到Add SSH Key。输入title之后，将你的公钥内容复制到相应位置去

### 常用的命令
- remote
    > 在github上创建新仓库之后，通过该命令将本地仓库和新仓库关联，随后推送
    >
    > git remote add origin git@github.com:michaelliao/learngit.git
    >(后面的地址，在github上复制一下即可)
    > origin是远程库的名称，可以修改

- push
    -git push -u origin master
        > 第一次推送，添加-u参数，推送+关联。此时，远程库和本地库内容就一样了。

    - git push origin master
        > 以后，只要本地提交，那么就可以通过该命令推送到github了





