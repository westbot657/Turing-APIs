// linear_algebra.ts

export class Vec2 {
    x: f32;
    y: f32;

    constructor(x: f32 = 0, y: f32 = 0) {
        this.x = x;
        this.y = y;
    }

    static add(a: Vec2, b: Vec2): Vec2 {
        return new Vec2(a.x + b.x, a.y + b.y);
    }

    static sub(a: Vec2, b: Vec2): Vec2 {
        return new Vec2(a.x - b.x, a.y - b.y);
    }

    static scale(a: Vec2, s: f32): Vec2 {
        return new Vec2(a.x * s, a.y * s);
    }

    static dot(a: Vec2, b: Vec2): f32 {
        return a.x * b.x + a.y * b.y;
    }

    length(): f32 {
        return Mathf.sqrt(this.x * this.x + this.y * this.y);
    }

    normalize(): Vec2 {
        let len = this.length();
        if (len == 0) return new Vec2(0, 0);
        return Vec2.scale(this, 1 / len);
    }
}

export class Vec3 {
    x: f32;
    y: f32;
    z: f32;

    constructor(x: f32 = 0, y: f32 = 0, z: f32 = 0) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    static add(a: Vec3, b: Vec3): Vec3 {
        return new Vec3(a.x + b.x, a.y + b.y, a.z + b.z);
    }

    static sub(a: Vec3, b: Vec3): Vec3 {
        return new Vec3(a.x - b.x, a.y - b.y, a.z - b.z);
    }

    static scale(a: Vec3, s: f32): Vec3 {
        return new Vec3(a.x * s, a.y * s, a.z * s);
    }

    static dot(a: Vec3, b: Vec3): f32 {
        return a.x * b.x + a.y * b.y + a.z * b.z;
    }

    static cross(a: Vec3, b: Vec3): Vec3 {
        return new Vec3(
            a.y * b.z - a.z * b.y,
            a.z * b.x - a.x * b.z,
            a.x * b.y - a.y * b.x
        );
    }

    length(): f32 {
        return Mathf.sqrt(this.x * this.x + this.y * this.y + this.z * this.z);
    }

    normalize(): Vec3 {
        let len = this.length();
        if (len == 0) return new Vec3(0, 0, 0);
        return Vec3.scale(this, 1 / len);
    }
}

export class Vec4 {
    x: f32;
    y: f32;
    z: f32;
    w: f32;

    constructor(x: f32 = 0, y: f32 = 0, z: f32 = 0, w: f32 = 0) {
        this.x = x;
        this.y = y;
        this.z = z;
        this.w = w;
    }

    static add(a: Vec4, b: Vec4): Vec4 {
        return new Vec4(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
    }

    static sub(a: Vec4, b: Vec4): Vec4 {
        return new Vec4(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
    }

    static scale(a: Vec4, s: f32): Vec4 {
        return new Vec4(a.x * s, a.y * s, a.z * s, a.w * s);
    }

    static dot(a: Vec4, b: Vec4): f32 {
        return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
    }

    length(): f32 {
        return Mathf.sqrt(this.x * this.x + this.y * this.y + this.z * this.z + this.w * this.w);
    }

    normalize(): Vec4 {
        let len = this.length();
        if (len == 0) return new Vec4(0, 0, 0, 0);
        return Vec4.scale(this, 1 / len);
    }
}

export class Quat {
    x: f32;
    y: f32;
    z: f32;
    w: f32;

    constructor(x: f32 = 0, y: f32 = 0, z: f32 = 0, w: f32 = 1) {
        this.x = x;
        this.y = y;
        this.z = z;
        this.w = w;
    }

    static identity(): Quat {
        return new Quat(0, 0, 0, 1);
    }

    static multiply(a: Quat, b: Quat): Quat {
        return new Quat(
            a.w * b.x + a.x * b.w + a.y * b.z - a.z * b.y,
            a.w * b.y - a.x * b.z + a.y * b.w + a.z * b.x,
            a.w * b.z + a.x * b.y - a.y * b.x + a.z * b.w,
            a.w * b.w - a.x * b.x - a.y * b.y - a.z * b.z
        );
    }

    normalize(): Quat {
        let len = Mathf.sqrt(this.x * this.x + this.y * this.y + this.z * this.z + this.w * this.w);
        if (len == 0) return Quat.identity();
        return new Quat(this.x / len, this.y / len, this.z / len, this.w / len);
    }
}

export class Mat4 {
    // Column-major 4x4 matrix
    m: StaticArray<f32>;

    constructor() {
        this.m = new StaticArray<f32>(16);
        this.identity();
    }

    identity(): void {
        for (let i = 0; i < 16; i++) this.m[i] = 0;
        this.m[0] = 1;
        this.m[5] = 1;
        this.m[10] = 1;
        this.m[15] = 1;
    }

    static multiply(a: Mat4, b: Mat4): Mat4 {
        let out = new Mat4();
        for (let i = 0; i < 4; i++) {
            for (let j = 0; j < 4; j++) {
                let sum: f32 = 0;
                for (let k = 0; k < 4; k++) {
                    sum += a.m[k * 4 + j] * b.m[i * 4 + k];
                }
                out.m[i * 4 + j] = sum;
            }
        }
        return out;
    }

    static translation(v: Vec3): Mat4 {
        let out = new Mat4();
        out.identity();
        out.m[12] = v.x;
        out.m[13] = v.y;
        out.m[14] = v.z;
        return out;
    }

    static scale(v: Vec3): Mat4 {
        let out = new Mat4();
        out.identity();
        out.m[0] = v.x;
        out.m[5] = v.y;
        out.m[10] = v.z;
        return out;
    }

    static rotationX(angle: f32): Mat4 {
        let out = new Mat4();
        let c = Mathf.cos(angle);
        let s = Mathf.sin(angle);
        out.identity();
        out.m[5] = c;
        out.m[6] = s;
        out.m[9] = -s;
        out.m[10] = c;
        return out;
    }

    static rotationY(angle: f32): Mat4 {
        let out = new Mat4();
        let c = Mathf.cos(angle);
        let s = Mathf.sin(angle);
        out.identity();
        out.m[0] = c;
        out.m[2] = -s;
        out.m[8] = s;
        out.m[10] = c;
        return out;
    }

    static rotationZ(angle: f32): Mat4 {
        let out = new Mat4();
        let c = Mathf.cos(angle);
        let s = Mathf.sin(angle);
        out.identity();
        out.m[0] = c;
        out.m[1] = s;
        out.m[4] = -s;
        out.m[5] = c;
        return out;
    }

    static fromQuat(q: Quat): Mat4 {
        let out = new Mat4();

        let x = q.x, y = q.y, z = q.z, w = q.w;
        let x2 = x + x;
        let y2 = y + y;
        let z2 = z + z;

        let xx = x * x2;
        let yy = y * y2;
        let zz = z * z2;
        let xy = x * y2;
        let xz = x * z2;
        let yz = y * z2;
        let wx = w * x2;
        let wy = w * y2;
        let wz = w * z2;

        out.m[0] = 1.0 - (yy + zz);
        out.m[1] = xy + wz;
        out.m[2] = xz - wy;
        out.m[3] = 0.0;

        out.m[4] = xy - wz;
        out.m[5] = 1.0 - (xx + zz);
        out.m[6] = yz + wx;
        out.m[7] = 0.0;

        out.m[8] = xz + wy;
        out.m[9] = yz - wx;
        out.m[10] = 1.0 - (xx + yy);
        out.m[11] = 0.0;

        out.m[12] = 0.0;
        out.m[13] = 0.0;
        out.m[14] = 0.0;
        out.m[15] = 1.0;

        return out;
    }

}
