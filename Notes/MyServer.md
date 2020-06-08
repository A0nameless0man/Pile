# 我的服务器

```puml
scale 0.4
cloud {
(i-NUIST) as eth
}
cloud {
  (gkdgkd.online) as gkd
}

package "Dell R510"{
  package "Phy Eth"{
    (eno1) as pe1
    note right: 虚拟交换机1
    (eno2) as pe2
    note left: 虚拟交换机0
  }
  package "Vir Eth"{
    (vmbr0) as ve0
    note left: 虚拟交换机0
    (vmbr1) as ve1
    note right: 虚拟交换机1
    ve0 <---> pe2
    ve1 <---> pe1
  }
  package "Virto Machine"{
    node "FreeNAS" as fn{
      note "10.0.3.2 \n82:D3:CB:40:D9:8F" as fnaddr
      [WebDav] as WebDav
      [SMB] as smb
      database Vault{

      }
      Vault ==> smb
      Vault ==> WebDav
    }
    node UtorrentLoader as ul{
      note "10.0.129 \nAA:97:FB:90:4D:FF" as uladdr
    }
    node "OpenWrt" as ow{
      (lan)
      note top : 10.0.3.16 \nAE:05:B9:A478:A6
      (wan)
      note top : A6:FA:44:C5:6C:13
      (lan) -l-> (wan)
      ve0 -up-> lan
      wan --down-> ve1
    }
    node ApacheProxy as ap{
      note "10.0.3.4" as apaddr
      [sakuar] as sa
      gkd -r-> sa
    }
    node pve{
      [WebConsle] as wc
      note "10.0.3.1" as pveaddr
    }
    fn -> ve0
    ul -> ve0
    wc -> ve0
    ap -> ve0
  }
}
package "DeskTop" as client{
    package "Client Phy Eth"{
    (built in) as cpe1
    (add on) as cpe2
  }
}
cpe2 -d-> pe2
pe1 --> eth
```
